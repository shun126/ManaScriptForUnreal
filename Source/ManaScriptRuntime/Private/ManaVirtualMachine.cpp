/**
 * @author		Shun Moriya
 * @copyright	2026- Shun Moriya
 * All Rights Reserved.
 */

#include "ManaVirtualMachine.h"

#include "Engine/World.h"
#include "EngineUtils.h"
#include "ManaBindableComponent.h"
#include "ManaProgramAsset.h"
#include "ManaRuntimeVM.h"
#include "ManaScriptRuntime.h"

AManaVirtualMachine::AManaVirtualMachine()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AManaVirtualMachine::BeginPlay()
{
	Super::BeginPlay();

	if (!HasAuthority())
	{
		UE_LOG(LogManaScriptRuntime, Warning, TEXT("ManaVirtualMachine: Not authority, VM will not start."));
		SetActorTickEnabled(false);
		return;
	}

	if (HasMultipleWorldRunners())
	{
		UE_LOG(LogManaScriptRuntime, Error, TEXT("ManaVirtualMachine: Multiple VM actors detected. Disabling this instance."));
		SetActorTickEnabled(false);
		return;
	}

	RuntimeVM = NewObject<UManaRuntimeVM>(this);
	RuntimeVM->SetBlueprintCommandRegistry(BlueprintCommandRegistry);
	RuntimeVM->Initialize(this, Program);

	DiscoverBindables();

	if (UWorld* World = GetWorld())
	{
		ActorSpawnedHandle = World->AddOnActorSpawnedHandler(
			FOnActorSpawned::FDelegate::CreateUObject(this, &AManaVirtualMachine::HandleActorSpawned));
	}
}

void AManaVirtualMachine::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if (!HasAuthority() || !RuntimeVM)
	{
		return;
	}

	RuntimeVM->Tick(DeltaSeconds);
	RetryPendingBindings(DeltaSeconds);
}

UManaRuntimeVM* AManaVirtualMachine::GetRuntimeVM() const
{
	return RuntimeVM;
}

void AManaVirtualMachine::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	if (UWorld* World = GetWorld())
	{
		if (ActorSpawnedHandle.IsValid())
		{
			World->RemoveOnActorSpawnedHandler(ActorSpawnedHandle);
			ActorSpawnedHandle.Reset();
		}
	}

	ClearBindings();
	PendingBindings.Empty();

	if (RuntimeVM)
	{
		RuntimeVM->Shutdown();
		RuntimeVM = nullptr;
	}

	Super::EndPlay(EndPlayReason);
}

bool AManaVirtualMachine::RegisterBinding(UManaBindableComponent* BindableComponent, mana::Actor*& OutHandle, bool bLogFailure)
{
	OutHandle = nullptr;

	if (!RuntimeVM || !BindableComponent)
	{
		return false;
	}

	const FName ManaActorName = BindableComponent->GetManaActorName();
	if (ManaActorName.IsNone())
	{
		if (bLogFailure)
		{
			UE_LOG(LogManaScriptRuntime, Warning, TEXT("Mana binding failed: ManaActorName is None on %s."),
				*GetNameSafe(BindableComponent->GetOwner()));
		}
		return false;
	}

	AActor* BindableActor = BindableComponent->GetOwner();
	if (!BindableActor)
	{
		return false;
	}

	if (FManaBindingEntry* ExistingEntry = BindingRegistry.Find(ManaActorName))
	{
		if (!ExistingEntry->Actor.IsValid())
		{
			BindingRegistry.Remove(ManaActorName);
			ExistingEntry = nullptr;
		}
		else if (ExistingEntry->Actor.Get() != BindableActor)
		{
			UE_LOG(LogManaScriptRuntime, Error,
				TEXT("Mana binding conflict: %s is already bound to %s, cannot bind %s."),
				*ManaActorName.ToString(),
				*GetNameSafe(ExistingEntry->Actor.Get()),
				*GetNameSafe(BindableActor));
			return false;
		}
	}

	if (FManaBindingEntry* ExistingEntry = BindingRegistry.Find(ManaActorName))
	{
		OutHandle = ExistingEntry->Handle;
		return OutHandle != nullptr;
	}

	std::shared_ptr<mana::Actor> ManaActor = RuntimeVM->FindActorByName(ManaActorName);
	if (!ManaActor)
	{
		if (bLogFailure)
		{
			UE_LOG(LogManaScriptRuntime, Warning, TEXT("Mana binding pending: actor %s not found for %s."),
				*ManaActorName.ToString(),
				*GetNameSafe(BindableActor));
		}
		return false;
	}

	OutHandle = RuntimeVM->RegisterBoundActor(ManaActor, BindableActor);
	if (!OutHandle)
	{
		if (bLogFailure)
		{
			UE_LOG(LogManaScriptRuntime, Warning, TEXT("Mana binding failed: unable to register handle for %s."),
				*ManaActorName.ToString());
		}
		return false;
	}

	FManaBindingEntry Entry;
	Entry.Actor = BindableActor;
	Entry.Component = BindableComponent;
	Entry.Handle = OutHandle;
	BindingRegistry.Add(ManaActorName, Entry);

	UE_LOG(LogManaScriptRuntime, Log, TEXT("Mana binding succeeded: %s -> %s (Handle %p)."),
		*ManaActorName.ToString(),
		*GetNameSafe(BindableActor),
		OutHandle);
	return true;
}

void AManaVirtualMachine::UnregisterBinding(UManaBindableComponent* BindableComponent)
{
	if (!BindableComponent)
	{
		return;
	}

	const FName ManaActorName = BindableComponent->GetManaActorName();
	FManaBindingEntry* Entry = BindingRegistry.Find(ManaActorName);
	if (!Entry)
	{
		PendingBindings.Remove(BindableComponent);
		return;
	}

	AActor* BindableActor = BindableComponent->GetOwner();
	if (Entry->Actor.IsValid() && Entry->Actor.Get() != BindableActor)
	{
		return;
	}

	mana::Actor* Handle = Entry->Handle;
	BindingRegistry.Remove(ManaActorName);
	PendingBindings.Remove(BindableComponent);

	if (RuntimeVM)
	{
		std::shared_ptr<mana::Actor> ManaActor = RuntimeVM->FindActorByName(ManaActorName);
		RuntimeVM->UnregisterBoundActor(Handle, ManaActor);
	}

	UE_LOG(LogManaScriptRuntime, Log, TEXT("Mana binding removed: %s -> %s (Handle %p)."),
		*ManaActorName.ToString(),
		*GetNameSafe(BindableActor),
		Handle);
}

void AManaVirtualMachine::DebugDumpBindings() const
{
	UE_LOG(LogManaScriptRuntime, Log, TEXT("Mana bindings: %d entries."), BindingRegistry.Num());
	for (const TPair<FName, FManaBindingEntry>& Pair : BindingRegistry)
	{
		const AActor* BoundActor = Pair.Value.Actor.Get();
		UE_LOG(LogManaScriptRuntime, Log, TEXT("  %s -> %s (Handle %p)"),
			*Pair.Key.ToString(),
			*GetNameSafe(BoundActor),
			Pair.Value.Handle);
	}
}

bool AManaVirtualMachine::RequestBetweenBindings(UManaBindableComponent* Sender, UManaBindableComponent* Target, const int32 Priority, const FString& ActionName, const bool bLogFailure)
{
	if (!RuntimeVM || !Sender || !Target)
	{
		return false;
	}

	if (ActionName.IsEmpty())
	{
		if (bLogFailure)
		{
			UE_LOG(LogManaScriptRuntime, Warning, TEXT("Mana request failed: ActionName is empty."));
		}
		return false;
	}

	const FName SenderName = Sender->GetManaActorName();
	const FName TargetName = Target->GetManaActorName();
	if (SenderName.IsNone() || TargetName.IsNone())
	{
		if (bLogFailure)
		{
			UE_LOG(LogManaScriptRuntime, Warning, TEXT("Mana request failed: Sender or Target ManaActorName is None."));
		}
		return false;
	}

	const FManaBindingEntry* SenderEntry = BindingRegistry.Find(SenderName);
	if (!SenderEntry || SenderEntry->Component.Get() != Sender)
	{
		if (bLogFailure)
		{
			UE_LOG(LogManaScriptRuntime, Warning, TEXT("Mana request failed: Sender binding not found for %s."),
				*SenderName.ToString());
		}
		return false;
	}

	const FManaBindingEntry* TargetEntry = BindingRegistry.Find(TargetName);
	if (!TargetEntry || TargetEntry->Component.Get() != Target)
	{
		if (bLogFailure)
		{
			UE_LOG(LogManaScriptRuntime, Warning, TEXT("Mana request failed: Target binding not found for %s."),
				*TargetName.ToString());
		}
		return false;
	}

	if (!RuntimeVM->RequestActorAction(TargetName, ActionName, Priority, SenderName))
	{
		if (bLogFailure)
		{
			UE_LOG(LogManaScriptRuntime, Warning, TEXT("Mana request failed: %s -> %s (%s)."),
				*SenderName.ToString(),
				*TargetName.ToString(),
				*ActionName);
		}
		return false;
	}

	return true;
}

bool AManaVirtualMachine::HasMultipleWorldRunners() const
{
	UWorld* World = GetWorld();
	if (!World)
	{
		return false;
	}

	int32 Count = 0;
	for (TActorIterator<AManaVirtualMachine> It(World); It; ++It)
	{
		if (!IsValid(*It))
		{
			continue;
		}

		++Count;
		if (Count > 1)
		{
			return true;
		}
	}

	return false;
}

void AManaVirtualMachine::DiscoverBindables()
{
	UWorld* World = GetWorld();
	if (!World)
	{
		return;
	}

	for (TActorIterator<AActor> It(World); It; ++It)
	{
		AActor* Actor = *It;
		if (!IsValid(Actor))
		{
			continue;
		}

		TArray<UManaBindableComponent*> BindableComponents;
		Actor->GetComponents<UManaBindableComponent>(BindableComponents);
		for (UManaBindableComponent* BindableComponent : BindableComponents)
		{
			if (!BindableComponent)
			{
				continue;
			}

			if (BindableComponent->TryBind(this))
			{
				PendingBindings.Remove(BindableComponent);
			}
			else
			{
				PendingBindings.Add(BindableComponent);
			}
		}
	}
}

void AManaVirtualMachine::HandleActorSpawned(AActor* SpawnedActor)
{
	if (!SpawnedActor)
	{
		return;
	}

	TArray<UManaBindableComponent*> BindableComponents;
	SpawnedActor->GetComponents<UManaBindableComponent>(BindableComponents);
	for (UManaBindableComponent* BindableComponent : BindableComponents)
	{
		if (!BindableComponent)
		{
			continue;
		}

		if (BindableComponent->TryBind(this))
		{
			PendingBindings.Remove(BindableComponent);
		}
		else
		{
			PendingBindings.Add(BindableComponent);
		}
	}
}

void AManaVirtualMachine::RetryPendingBindings(float DeltaSeconds)
{
	if (PendingBindings.IsEmpty())
	{
		return;
	}

	PendingRetryElapsed += DeltaSeconds;
	if (PendingRetryElapsed < PendingRetryInterval)
	{
		return;
	}

	PendingRetryElapsed = 0.0f;
	TArray<TWeakObjectPtr<UManaBindableComponent>> PendingArray = PendingBindings.Array();
	for (const TWeakObjectPtr<UManaBindableComponent>& WeakComponent : PendingArray)
	{
		UManaBindableComponent* BindableComponent = WeakComponent.Get();
		if (!BindableComponent)
		{
			PendingBindings.Remove(WeakComponent);
			continue;
		}

		if (BindableComponent->TryBind(this, false))
		{
			PendingBindings.Remove(BindableComponent);
		}
	}
}

void AManaVirtualMachine::ClearBindings()
{
	if (!RuntimeVM)
	{
		BindingRegistry.Empty();
		return;
	}

	for (const TPair<FName, FManaBindingEntry>& Pair : BindingRegistry)
	{
		mana::Actor* Handle = Pair.Value.Handle;
		const FName ManaActorName = Pair.Key;
		std::shared_ptr<mana::Actor> ManaActor = RuntimeVM->FindActorByName(ManaActorName);
		RuntimeVM->UnregisterBoundActor(Handle, ManaActor);
	}

	BindingRegistry.Empty();
}
