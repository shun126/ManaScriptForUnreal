/**
 * @author		Shun Moriya
 * @copyright	2026- Shun Moriya
 * All Rights Reserved.
 */

#include "ManaBindableComponent.h"

#include "ManaProgramAsset.h"
#include "ManaScriptRuntime.h"
#include "ManaVirtualMachine.h"
#include "Mana/runner/Actor.h"

#include "Engine/Engine.h"
#include "EngineUtils.h"

UManaBindableComponent::UManaBindableComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UManaBindableComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Unbind();

	Super::EndPlay(EndPlayReason);
}

bool UManaBindableComponent::CanBind(const AManaVirtualMachine* VM) const
{
	return VM && !ManaActorName.IsNone() && GetOwner();
}

bool UManaBindableComponent::TryBind(AManaVirtualMachine* VM, bool bLogFailure)
{
	if (bIsBound && BoundVM.Get() == VM)
	{
		return true;
	}

	if (!CanBind(VM))
	{
		return false;
	}

	mana::Actor* NewHandle = nullptr;
	if (!VM->RegisterBinding(this, NewHandle, bLogFailure))
	{
		return false;
	}

	if (NewHandle)
	{
		EventName = NewHandle->AddPriorityChangedEvent(
			[this](int32_t OldPriority, int32_t NewPriority)
			{
				UE_LOG(LogManaScriptRuntime, Warning, TEXT("Mana requested !"));
			}
		);
	}

	BoundVM = VM;
	BoundHandle = NewHandle;
	bIsBound = true;
	return true;
}

void UManaBindableComponent::Unbind()
{
	if (!bIsBound)
	{
		return;
	}

	if (BoundHandle && EventName)
	{
		BoundHandle->RemovePriorityChangedEvent(EventName);
	}

	if (AManaVirtualMachine* VM = BoundVM.Get())
	{
		VM->UnregisterBinding(this);
	}

	BoundHandle = nullptr;
	bIsBound = false;
	BoundVM.Reset();
}

bool UManaBindableComponent::RequestTo(UManaBindableComponent* Target, const int32 Priority, const FString& ActionName, const bool bLogFailure)
{
	AManaVirtualMachine* VM = BoundVM.Get();
	if (!VM)
	{
		if (bLogFailure)
		{
			UE_LOG(LogManaScriptRuntime, Warning, TEXT("Mana request failed: component is not bound to a VM."));
		}
		return false;
	}

	return VM->RequestBetweenBindings(this, Target, Priority, ActionName, bLogFailure);
}

FName UManaBindableComponent::GetManaActorName() const
{
	return ManaActorName;
}

#if WITH_EDITOR

TArray<FString> UManaBindableComponent::GetManaActorNameOptions() const
{
	TArray<FString> Options;
	Options.Add(TEXT("None"));

	UWorld* World = nullptr;
	if (const AActor* Owner = GetOwner())
	{
		World = Owner->GetWorld();
	}

	if (!World && GEngine)
	{
		for (const FWorldContext& Context : GEngine->GetWorldContexts())
		{
			if (Context.WorldType == EWorldType::Editor ||
				Context.WorldType == EWorldType::EditorPreview ||
				Context.WorldType == EWorldType::PIE)
			{
				World = Context.World();
				if (World)
				{
					break;
				}
			}
		}
	}

	if (!World)
	{
		return Options;
	}

	TSet<FString> ActorNames;
	for (TActorIterator<AManaVirtualMachine> It(World); It; ++It)
	{
		const AManaVirtualMachine* VirtualMachine = *It;
		if (!VirtualMachine || !VirtualMachine->Program)
		{
			continue;
		}

		TArray<FString> ActorNameStrings;
		FString Error;
		if (!VirtualMachine->Program->GetActorNames(ActorNameStrings, Error))
		{
			continue;
		}

		for (const FString& Name : ActorNameStrings)
		{
			ActorNames.Add(Name);
		}
	}
	if (!ManaActorName.IsNone())
	{
		ActorNames.Add(ManaActorName.ToString());
	}

	TArray<FString> SortedNames = ActorNames.Array();
	SortedNames.Sort();
	Options.Append(SortedNames);
	return Options;
}

#endif
