/**
 * @author		Shun Moriya
 * @copyright	2026- Shun Moriya
 * All Rights Reserved.
 */

#pragma once

#include "CoreMinimal.h"

// 下で std::shared_ptr を直に使います。UE 5.7 は他のヘッダー経由で
// <memory> が入って来ないので、自分で読み込みます
#include <memory>

#include "ManaRuntimeVM.generated.h"

class UManaProgramAsset;
class UManaBlueprintCommandRegistry;
class FManaRuntimeBindings;
class AActor;
class UAnimMontage;
class UAnimInstance;
class USkeletalMeshComponent;

namespace mana
{
	class VM;
	class Actor;
}

UCLASS()
class MANASCRIPTRUNTIME_API UManaRuntimeVM : public UObject
{
	GENERATED_BODY()

public:
	void SetBlueprintCommandRegistry(UManaBlueprintCommandRegistry* InBlueprintCommandRegistry);

	void Initialize(AActor* InOwner, UManaProgramAsset* InProgram);
	void Tick(float DeltaTime);
	void Shutdown();

	bool SetActorLocationImmediate(const mana::Actor* Handle, const FVector& Location, bool bSweep, bool bTeleport) const;
	bool PlayMontageImmediate(const mana::Actor* Handle, const FString& MontageName, float PlayRate, const FString& SectionName) const;
	bool MoveToLocationImmediate(const mana::Actor* Handle, const FVector& Location) const;
	bool MoveToActorImmediate(const mana::Actor* Handle, const mana::Actor* TargetHandle) const;
	bool LookAtLocationImmediate(const mana::Actor* Handle, const FVector& Location) const;
	bool LookAtActorImmediate(const mana::Actor* Handle, const mana::Actor* TargetHandle) const;
	bool SetAnimParamImmediate(const mana::Actor* Handle, FName ParamName, float Value) const;
	std::shared_ptr<mana::Actor> FindActorByName(FName Name) const;
	bool RequestActorAction(FName TargetName, const FString& ActionName, int32 Priority, FName SenderName) const;
	mana::Actor* RegisterBoundActor(const std::shared_ptr<mana::Actor>& ManaActor, AActor* Actor);
	void UnregisterBoundActor(const mana::Actor* Handle, const std::shared_ptr<mana::Actor>& ManaActor);


	AActor* ResolveActor(const mana::Actor* Handle) const;


private:
	static USkeletalMeshComponent* ResolveMeshComponent(AActor* TargetActor);

	UPROPERTY()
	TObjectPtr<AActor> OwnerActor;

	UPROPERTY()
	TObjectPtr<UManaProgramAsset> ProgramAsset;

	UPROPERTY()
	TObjectPtr<UManaBlueprintCommandRegistry> BlueprintCommandRegistry;

	TMap<mana::Actor*, TWeakObjectPtr<AActor>> HandleToActor;

	std::shared_ptr<FManaRuntimeBindings> RuntimeBindings;

	std::shared_ptr<mana::VM> mVM;

	bool bIsReady = false;
};
