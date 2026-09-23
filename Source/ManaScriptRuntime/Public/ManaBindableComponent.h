/**
 * @author		Shun Moriya
 * @copyright	2026- Shun Moriya
 * All Rights Reserved.
 */

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ManaBindableComponent.generated.h"

class AManaVirtualMachine;
namespace mana { class Actor; }

UCLASS(ClassGroup = (Mana), meta = (BlueprintSpawnableComponent))
class MANASCRIPTRUNTIME_API UManaBindableComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UManaBindableComponent();
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	bool CanBind(const AManaVirtualMachine* VM) const;
	bool TryBind(AManaVirtualMachine* VM, bool bLogFailure = true);
	void Unbind();

	UFUNCTION(BlueprintCallable, Category = "Mana")
	bool RequestTo(UManaBindableComponent* Target, int32 Priority, const FString& ActionName, bool bLogFailure = true);

	FName GetManaActorName() const;

protected:
#if WITH_EDITOR
	// 詳細パネルの候補を作るためだけの関数です。バイトコードからアクター名を
	// 引くのでエディタ専用になります
	UFUNCTION()
	TArray<FString> GetManaActorNameOptions() const;
#endif

	UPROPERTY(EditAnywhere, Category = "Mana", meta = (GetOptions = "GetManaActorNameOptions"))
	FName ManaActorName;

private:
	TWeakObjectPtr<AManaVirtualMachine> BoundVM;
	mana::Actor* BoundHandle = nullptr;
	uint32_t EventName = 0;
	bool bIsBound = false;
};
