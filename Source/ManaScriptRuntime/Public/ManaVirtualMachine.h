/**
 * @author		Shun Moriya
 * @copyright	2026- Shun Moriya
 * All Rights Reserved.
 */

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ManaVirtualMachine.generated.h"

class UManaProgramAsset;
class UManaRuntimeVM;
class UManaBlueprintCommandRegistry;
class UManaBindableComponent;
namespace mana { class Actor; }

UCLASS()
class MANASCRIPTRUNTIME_API AManaVirtualMachine : public AActor
{
	GENERATED_BODY()

public:
	AManaVirtualMachine();

	UPROPERTY(EditInstanceOnly, Category = "Mana")
	TObjectPtr<UManaProgramAsset> Program;

	UPROPERTY(EditAnywhere, Instanced, Category = "Mana")
	TObjectPtr<UManaBlueprintCommandRegistry> BlueprintCommandRegistry;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	UFUNCTION(BlueprintCallable, Category = "Mana")
	UManaRuntimeVM* GetRuntimeVM() const;

	bool RegisterBinding(UManaBindableComponent* BindableComponent, mana::Actor*& OutHandle, bool bLogFailure = true);
	void UnregisterBinding(UManaBindableComponent* BindableComponent);

	UFUNCTION(BlueprintCallable, Category = "Mana")
	void DebugDumpBindings() const;

	UFUNCTION(BlueprintCallable, Category = "Mana")
	bool RequestBetweenBindings(UManaBindableComponent* Sender, UManaBindableComponent* Target, int32 Priority, const FString& ActionName, bool bLogFailure = true);

private:
	bool HasMultipleWorldRunners() const;
	void DiscoverBindables();
	void HandleActorSpawned(AActor* SpawnedActor);
	void RetryPendingBindings(float DeltaSeconds);
	void ClearBindings();

	struct FManaBindingEntry
	{
		TWeakObjectPtr<AActor> Actor;
		TWeakObjectPtr<UManaBindableComponent> Component;
		mana::Actor* Handle = nullptr;
	};

	UPROPERTY(Transient)
	TObjectPtr<UManaRuntimeVM> RuntimeVM;

	TMap<FName, FManaBindingEntry> BindingRegistry;
	TSet<TWeakObjectPtr<UManaBindableComponent>> PendingBindings;
	FDelegateHandle ActorSpawnedHandle;
	float PendingRetryInterval = 1.0f;
	float PendingRetryElapsed = 0.0f;
};
