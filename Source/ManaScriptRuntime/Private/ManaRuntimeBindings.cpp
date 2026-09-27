/**
 * @author		Shun Moriya
 * @copyright	2026- Shun Moriya
 * All Rights Reserved.
 */

#include "ManaRuntimeBindings.h"

#include "GameFramework/Actor.h"
#include "ManaRuntimeVM.h"
#include "ManaScriptRuntime.h"
#include "Mana/runner/Actor.h"
#include "Mana/runner/VM.h"
#include "Mana/runner/common/Setup.h"

FManaRuntimeBindings::FManaRuntimeBindings(UManaRuntimeVM& InRuntimeVM)
	: RuntimeVM(&InRuntimeVM)
{
}

void FManaRuntimeBindings::Register(mana::VM& VM)
{
	VM.RegisterMemberFunction("set_location", this, &FManaRuntimeBindings::SetLocation);
	VM.RegisterMemberFunction("play_montage", this, &FManaRuntimeBindings::PlayMontage);
	VM.RegisterMemberFunction("move_to_location", this, &FManaRuntimeBindings::MoveToLocation);
	VM.RegisterMemberFunction("move_to_actor", this, &FManaRuntimeBindings::MoveToActor);
	VM.RegisterMemberFunction("look_at_location", this, &FManaRuntimeBindings::LookAtLocation);
	VM.RegisterMemberFunction("look_at_actor", this, &FManaRuntimeBindings::LookAtActor);
	VM.RegisterMemberFunction("set_anim_param", this, &FManaRuntimeBindings::SetAnimParam);
}

void FManaRuntimeBindings::SetLocation(const std::shared_ptr<mana::Actor>& Actor, void*) const
{
	MANA_ASSERT_PARAMETER(Actor, 6);

	UManaRuntimeVM* VM = nullptr;
	if (!TryGetRuntimeVM(VM))
	{
		Actor->SetReturnInteger(0);
		return;
	}

	const auto Handle = Actor->GetParameterActorPointer(0);
	const float X = Actor->GetParameterFloat(1);
	const float Y = Actor->GetParameterFloat(2);
	const float Z = Actor->GetParameterFloat(3);
	const bool bSweep = Actor->GetParameterInteger(4) != 0;
	const bool bTeleport = Actor->GetParameterInteger(5) != 0;

	const bool bSuccess = VM->SetActorLocationImmediate(Handle, FVector(X, Y, Z), bSweep, bTeleport);
	Actor->SetReturnInteger(bSuccess ? 1 : 0);
}

void FManaRuntimeBindings::PlayMontage(const std::shared_ptr<mana::Actor>& Actor, void*) const
{
	MANA_ASSERT_PARAMETER(Actor, 4);

	UManaRuntimeVM* VM = nullptr;
	if (!TryGetRuntimeVM(VM))
	{
		Actor->SetReturnInteger(0);
		return;
	}

	const auto Handle = Actor->GetParameterActorPointer(0);
	const FString MontageName = UTF8_TO_TCHAR(Actor->GetParameterString(1));
	const float PlayRate = Actor->GetParameterFloat(2);
	const FString SectionName = UTF8_TO_TCHAR(Actor->GetParameterString(3));
	const bool bSuccess = VM->PlayMontageImmediate(Handle, MontageName, PlayRate, SectionName);
	Actor->SetReturnInteger(bSuccess ? 1 : 0);
}

void FManaRuntimeBindings::MoveToLocation(const std::shared_ptr<mana::Actor>& Actor, void*) const
{
	MANA_ASSERT_PARAMETER(Actor, 4);

	UManaRuntimeVM* VM = nullptr;
	if (!TryGetRuntimeVM(VM))
	{
		Actor->SetReturnInteger(0);
		return;
	}

	const auto Handle = Actor->GetParameterActorPointer(0);
	const float X = Actor->GetParameterFloat(1);
	const float Y = Actor->GetParameterFloat(2);
	const float Z = Actor->GetParameterFloat(3);
	if (!Actor->IsCommandInitialized())
	{
		const bool bSuccess = VM->MoveToLocationImmediate(Handle, FVector(X, Y, Z));
		Actor->SetReturnInteger(bSuccess ? 1 : 0);
		Actor->Repeat(true);
	}
	else
	{
		if (AActor* aaa = VM->ResolveActor(Actor.get()))
		{
			const auto distanceSquared = FVector::DistSquared(aaa->GetActorLocation(), FVector(X, Y, Z));
			if (distanceSquared > 100.0 * 100.0)
				Actor->Repeat(true);
		}
	}
}

void FManaRuntimeBindings::MoveToActor(const std::shared_ptr<mana::Actor>& Actor, void*) const
{
	MANA_ASSERT_PARAMETER(Actor, 2);

	UManaRuntimeVM* VM = nullptr;
	if (!TryGetRuntimeVM(VM))
	{
		Actor->SetReturnInteger(0);
		return;
	}

	const auto Handle = Actor->GetParameterActorPointer(0);
	mana::Actor* TargetHandle = Actor->GetParameterActorPointer(1);
	const bool bSuccess = VM->MoveToActorImmediate(Handle, TargetHandle);
	Actor->SetReturnInteger(bSuccess ? 1 : 0);
}

void FManaRuntimeBindings::LookAtLocation(const std::shared_ptr<mana::Actor>& Actor, void*) const
{
	MANA_ASSERT_PARAMETER(Actor, 4);

	UManaRuntimeVM* VM = nullptr;
	if (!TryGetRuntimeVM(VM))
	{
		Actor->SetReturnInteger(0);
		return;
	}

	const auto Handle = Actor->GetParameterActorPointer(0);
	const float X = Actor->GetParameterFloat(1);
	const float Y = Actor->GetParameterFloat(2);
	const float Z = Actor->GetParameterFloat(3);
	const bool bSuccess = VM->LookAtLocationImmediate(Handle, FVector(X, Y, Z));
	Actor->SetReturnInteger(bSuccess ? 1 : 0);
}

void FManaRuntimeBindings::LookAtActor(const std::shared_ptr<mana::Actor>& Actor, void*) const
{
	MANA_ASSERT_PARAMETER(Actor, 2);

	UManaRuntimeVM* VM = nullptr;
	if (!TryGetRuntimeVM(VM))
	{
		Actor->SetReturnInteger(0);
		return;
	}

	const auto Handle = Actor->GetParameterActorPointer(0);
	mana::Actor* TargetHandle = Actor->GetParameterActorPointer(1);
	const bool bSuccess = VM->LookAtActorImmediate(Handle, TargetHandle);
	Actor->SetReturnInteger(bSuccess ? 1 : 0);
}

void FManaRuntimeBindings::SetAnimParam(const std::shared_ptr<mana::Actor>& Actor, void*) const
{
	MANA_ASSERT_PARAMETER(Actor, 3);

	UManaRuntimeVM* VM = nullptr;
	if (!TryGetRuntimeVM(VM))
	{
		Actor->SetReturnInteger(0);
		return;
	}

	const auto Handle = Actor->GetParameterActorPointer(0);
	const FName ParamName = FName(UTF8_TO_TCHAR(Actor->GetParameterString(1)));
	const float Value = Actor->GetParameterFloat(2);
	const bool bSuccess = VM->SetAnimParamImmediate(Handle, ParamName, Value);
	Actor->SetReturnInteger(bSuccess ? 1 : 0);
}

bool FManaRuntimeBindings::TryGetRuntimeVM(UManaRuntimeVM*& OutRuntimeVM) const
{
	OutRuntimeVM = RuntimeVM.Get();
	if (!OutRuntimeVM)
	{
		UE_LOG(LogManaScriptRuntime, Warning, TEXT("Mana runtime bindings: RuntimeVM is no longer valid."));
		return false;
	}

	return true;
}
