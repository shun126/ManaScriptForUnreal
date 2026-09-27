/**
 * @author		Shun Moriya
 * @copyright	2026- Shun Moriya
 * All Rights Reserved.
 */

#include "ManaRuntimeVM.h"

#include "AIController.h"
// UE 5.8 の AIController.h は EPathFollowingRequestResult を前方宣言するだけなので、
// 列挙子を参照するにはこちらが要ります
#include "Navigation/PathFollowingComponent.h"
#include "ManaBlueprintCommandRegistry.h"
#include "Mana/runner/Actor.h"
#include "Mana/runner/Mana.h"
#include "Mana/runner/VM.h"

#include <exception>

#include "Animation/AnimInstance.h"
#include "Animation/AnimMontage.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Character.h"
#include "ManaProgramAsset.h"
#include "ManaRuntimeBindings.h"
#include "ManaScriptRuntime.h"
#include "GameFramework/PawnMovementComponent.h"

void UManaRuntimeVM::SetBlueprintCommandRegistry(UManaBlueprintCommandRegistry* InBlueprintCommandRegistry)
{
	BlueprintCommandRegistry = InBlueprintCommandRegistry;
	if (BlueprintCommandRegistry)
	{
		BlueprintCommandRegistry->SetRuntimeVM(this);
	}
}

void UManaRuntimeVM::Initialize(AActor* InOwner, UManaProgramAsset* InProgram)
{
	OwnerActor = InOwner;
	ProgramAsset = InProgram;
	HandleToActor.Empty();
	HandleToActor.Add(nullptr, OwnerActor);

	bIsReady = false;
	if (!ProgramAsset)
	{
		UE_LOG(LogManaScriptRuntime, Error, TEXT("Mana VM initialization failed: ProgramAsset is null."));
		return;
	}

	mVM = std::make_shared<mana::VM>();
	if (mVM)
	{
		//mVM->LoadPlugin(const std::string & filename);
		//mVM->LoadPlugins(const std::string & directoryName);

		TConstArrayView<uint8> BinaryView;
		FString BinaryError;
		if (!ProgramAsset->TryGetCompiledBinary(BinaryView, BinaryError))
		{
			UE_LOG(LogManaScriptRuntime, Error, TEXT("Mana VM initialization failed: %s"), *BinaryError);
			return;
		}

		const size_t BinarySize = static_cast<size_t>(BinaryView.Num());
		auto ProgramBuffer = std::shared_ptr<uint8_t[]>(new uint8_t[BinarySize], std::default_delete<uint8_t[]>());
		FMemory::Memcpy(ProgramBuffer.get(), BinaryView.GetData(), BinarySize);
		// LoadProgram は渡した shared_ptr を保持し続けるので、実体ごと握らせる
		std::shared_ptr<const void> Program(ProgramBuffer, ProgramBuffer.get());

		// LoadProgram は署名・版数・ポインタ幅の食い違いを例外で報せます。
		// 素通しするとエディタやゲームのプロセスごと落ちるため、ここで受けます
		try
		{
			mVM->LoadProgram(Program);
		}
		catch (const std::exception& Exception)
		{
			UE_LOG(LogManaScriptRuntime, Error,
				TEXT("Mana VM initialization failed while loading the program of %s: %s"),
				*GetNameSafe(ProgramAsset),
				UTF8_TO_TCHAR(Exception.what()));
			mVM.reset();
			return;
		}

		RuntimeBindings = std::make_shared<FManaRuntimeBindings>(*this);
		RuntimeBindings->Register(*mVM);
		if (BlueprintCommandRegistry)
		{
			BlueprintCommandRegistry->Register(*mVM);
		}
	}

	bIsReady = true;
}

void UManaRuntimeVM::Tick(float DeltaTime)
{
	if (!bIsReady)
	{
		return;
	}

	if (mVM)
	{
		// Run はスクリプト側の誤り (0除算・配列の範囲外など) と Mana の
		// 不変条件の破れを、そのアクターだけを止める形で内部処理します。
		// ここへ出てくるのはそれ以外の、仮想マシンごと続行できない事態です。
		// 毎フレーム同じ内容を吐き続けないよう、受けたら走行を止めます
		//
		// 時間は UE の DeltaTime で進めます。引数なしの Run() は実時間で進むため、
		// ポーズやタイムダイレーションが wait() などに反映されません
		try
		{
			mVM->Run(DeltaTime);
		}
		catch (const std::exception& Exception)
		{
			bIsReady = false;
			UE_LOG(LogManaScriptRuntime, Error,
				TEXT("Mana VM halted while running the program of %s: %s"),
				*GetNameSafe(ProgramAsset),
				UTF8_TO_TCHAR(Exception.what()));
		}
	}
}

void UManaRuntimeVM::Shutdown()
{
	bIsReady = false;
}

bool UManaRuntimeVM::SetActorLocationImmediate(const mana::Actor* Handle, const FVector& Location, const bool bSweep, const bool bTeleport) const
{
	AActor* TargetActor = ResolveActor(Handle);
	if (!TargetActor)
	{
		return false;
	}

	FHitResult SweepResult;
	return TargetActor->SetActorLocation(Location, bSweep, bSweep ? &SweepResult : nullptr, bTeleport ? ETeleportType::TeleportPhysics : ETeleportType::None);
}

bool UManaRuntimeVM::PlayMontageImmediate(const mana::Actor* Handle, const FString& MontageName, const float PlayRate, const FString& SectionName) const
{
	AActor* TargetActor = ResolveActor(Handle);
	if (!TargetActor)
	{
		return false;
	}

	USkeletalMeshComponent* MeshComponent = ResolveMeshComponent(TargetActor);
	if (!MeshComponent)
	{
		return false;
	}

	UAnimInstance* AnimInstance = MeshComponent->GetAnimInstance();
	if (!AnimInstance)
	{
		return false;
	}

	if (MontageName.IsEmpty())
	{
		return false;
	}

	UAnimMontage* Montage = LoadObject<UAnimMontage>(nullptr, *MontageName);
	if (!Montage)
	{
		return false;
	}

	const float PlayResult = AnimInstance->Montage_Play(Montage, PlayRate);
	if (PlayResult <= 0.0f)
	{
		return false;
	}

	if (!SectionName.IsEmpty())
	{
		AnimInstance->Montage_JumpToSection(FName(*SectionName), Montage);
	}

	return true;
}

bool UManaRuntimeVM::MoveToLocationImmediate(const mana::Actor* Handle, const FVector& Location) const
{
	const auto TargetActor = ResolveActor(Handle);
	const auto TargetPawn = Cast<APawn>(TargetActor);
	if (!TargetPawn)
		return false;
	const auto TargetController = Cast<AAIController>(TargetPawn->GetController());
	if (!TargetController)
		return false;
	const auto PathFollowingRequestResult = TargetController->MoveToLocation(Location);
	return PathFollowingRequestResult != EPathFollowingRequestResult::Failed;
}

bool UManaRuntimeVM::MoveToActorImmediate(const mana::Actor* Handle, const mana::Actor* TargetHandle) const
{
	const auto MoveTargetActor = ResolveActor(TargetHandle);
	if (!MoveTargetActor)
		return false;
	const auto TargetActor = ResolveActor(Handle);
	const auto TargetPawn = Cast<APawn>(TargetActor);
	if (!TargetPawn)
		return false;
	const auto TargetController = Cast<AAIController>(TargetPawn->GetController());
	if (!TargetController)
		return false;
	const auto PathFollowingRequestResult = TargetController->MoveToActor(MoveTargetActor);
	return PathFollowingRequestResult != EPathFollowingRequestResult::Failed;
}

bool UManaRuntimeVM::LookAtLocationImmediate(const mana::Actor* Handle, const FVector& Location) const
{
	AActor* TargetActor = ResolveActor(Handle);
	if (!TargetActor)
	{
		return false;
	}

	const FVector Direction = Location - TargetActor->GetActorLocation();
	if (Direction.IsNearlyZero())
	{
		return false;
	}

	TargetActor->SetActorRotation(Direction.Rotation());
	return true;
}

bool UManaRuntimeVM::LookAtActorImmediate(const mana::Actor* Handle, const mana::Actor* TargetHandle) const
{
	AActor* TargetActor = ResolveActor(Handle);
	AActor* LookTarget = ResolveActor(TargetHandle);
	if (!TargetActor || !LookTarget)
	{
		return false;
	}

	const FVector Direction = LookTarget->GetActorLocation() - TargetActor->GetActorLocation();
	if (Direction.IsNearlyZero())
	{
		return false;
	}

	TargetActor->SetActorRotation(Direction.Rotation());
	return true;
}

bool UManaRuntimeVM::SetAnimParamImmediate(const mana::Actor* Handle, const FName ParamName, const float Value) const
{
	AActor* TargetActor = ResolveActor(Handle);
	if (!TargetActor)
	{
		return false;
	}

	USkeletalMeshComponent* MeshComponent = ResolveMeshComponent(TargetActor);
	if (!MeshComponent)
	{
		return false;
	}

	UAnimInstance* AnimInstance = MeshComponent->GetAnimInstance();
	if (!AnimInstance)
	{
		return false;
	}

	if (ParamName.IsNone())
	{
		return false;
	}

	AnimInstance->AddCurveValue(ParamName, Value);
	return true;
}

std::shared_ptr<mana::Actor> UManaRuntimeVM::FindActorByName(const FName Name) const
{
	if (!mVM || Name.IsNone())
	{
		return nullptr;
	}

	const std::string NameUtf8 = TCHAR_TO_UTF8(*Name.ToString());
	return mVM->FindActor(NameUtf8.c_str());
}

bool UManaRuntimeVM::RequestActorAction(const FName TargetName, const FString& ActionName, const int32 Priority, const FName SenderName) const
{
	if (!mVM || TargetName.IsNone() || ActionName.IsEmpty())
	{
		return false;
	}

	std::shared_ptr<mana::Actor> SenderActor = nullptr;
	if (!SenderName.IsNone())
	{
		SenderActor = FindActorByName(SenderName);
		if (!SenderActor)
		{
			return false;
		}
	}

	const std::string TargetUtf8 = TCHAR_TO_UTF8(*TargetName.ToString());
	const std::string ActionUtf8 = TCHAR_TO_UTF8(*ActionName);
	return mVM->Request(Priority, TargetUtf8.c_str(), ActionUtf8.c_str(), SenderActor);
}

mana::Actor* UManaRuntimeVM::RegisterBoundActor(const std::shared_ptr<mana::Actor>& ManaActor, AActor* Actor)
{
	if (!ManaActor || !Actor)
	{
		return nullptr;
	}

	mana::Actor* Key = ManaActor.get();
	HandleToActor.Add(Key, Actor);
	return Key;
}

void UManaRuntimeVM::UnregisterBoundActor(const mana::Actor* Handle, const std::shared_ptr<mana::Actor>& /*ManaActor*/)
{
	if (Handle)
	{
		HandleToActor.Remove(Handle);
	}
}

AActor* UManaRuntimeVM::ResolveActor(const mana::Actor* Handle) const
{
	if (!Handle)
	{
		return OwnerActor.Get();
	}

	if (const TWeakObjectPtr<AActor>* Entry = HandleToActor.Find(Handle))
	{
		return Entry->Get();
	}

	return nullptr;
}

USkeletalMeshComponent* UManaRuntimeVM::ResolveMeshComponent(AActor* TargetActor)
{
	if (ACharacter* Character = Cast<ACharacter>(TargetActor))
	{
		return Character->GetMesh();
	}

	return TargetActor->FindComponentByClass<USkeletalMeshComponent>();
}
