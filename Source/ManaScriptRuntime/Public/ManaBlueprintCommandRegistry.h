/**
 * @author		Shun Moriya
 * @copyright	2026- Shun Moriya
 * All Rights Reserved.
 */

#pragma once

#include "CoreMinimal.h"
#include <memory>
#include "ManaBlueprintCommandRegistry.generated.h"

class AActor;
class UManaRuntimeVM;

namespace mana
{
	class Actor;
	class VM;
}

UENUM(BlueprintType)
enum class EManaBlueprintCommandArgType : uint8
{
	None UMETA(DisplayName = "None"),
	Bool UMETA(DisplayName = "Bool"),
	Int32 UMETA(DisplayName = "Int32"),
	Float UMETA(DisplayName = "Float"),
	String UMETA(DisplayName = "String"),
	Actor UMETA(DisplayName = "Actor")
};

USTRUCT(BlueprintType)
struct FManaBlueprintCommandArgument
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mana")
	EManaBlueprintCommandArgType Type = EManaBlueprintCommandArgType::None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mana")
	bool BoolValue = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mana")
	int32 Int32Value = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mana")
	float FloatValue = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mana")
	FString StringValue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mana")
	TObjectPtr<AActor> ActorValue = nullptr;
};

DECLARE_DYNAMIC_DELEGATE_TwoParams(FManaBlueprintCommandDelegate, const TArray<FManaBlueprintCommandArgument>&, Arguments, FManaBlueprintCommandArgument&, OutResult);

USTRUCT(BlueprintType)
struct FManaBlueprintCommandBinding
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mana")
	TArray<EManaBlueprintCommandArgType> ArgumentTypes;

	UPROPERTY(BlueprintReadWrite, Category = "Mana")
	FManaBlueprintCommandDelegate Delegate;
};

UCLASS(BlueprintType, Blueprintable, EditInlineNew, DefaultToInstanced)
class MANASCRIPTRUNTIME_API UManaBlueprintCommandRegistry : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Mana")
	void AddCommandName(FName CommandName, const TArray<EManaBlueprintCommandArgType>& ArgumentTypes, const FManaBlueprintCommandDelegate& Delegate);

	UFUNCTION(BlueprintCallable, Category = "Mana")
	void RemoveCommandName(FName CommandName);

	void SetRuntimeVM(UManaRuntimeVM* InRuntimeVM);

	void Register(mana::VM& VM);

	UFUNCTION(BlueprintPure, Category = "Mana")
	static bool GetArgumentBool(const TArray<FManaBlueprintCommandArgument>& Arguments, const int32 Index)
	{
		if (Arguments.IsValidIndex(Index) && Arguments[Index].Type == EManaBlueprintCommandArgType::Bool)
		{
			return Arguments[Index].BoolValue;
		}
		return false;
	}

	UFUNCTION(BlueprintPure, Category = "Mana")
	static int32 GetArgumentInt(const TArray<FManaBlueprintCommandArgument>& Arguments, const int32 Index)
	{
		if (Arguments.IsValidIndex(Index) && Arguments[Index].Type == EManaBlueprintCommandArgType::Int32)
		{
			return Arguments[Index].Int32Value;
		}
		return 0;
	}

	UFUNCTION(BlueprintPure, Category = "Mana")
	static float GetArgumentFloat(const TArray<FManaBlueprintCommandArgument>& Arguments, const int32 Index)
	{
		if (Arguments.IsValidIndex(Index) && Arguments[Index].Type == EManaBlueprintCommandArgType::Float)
		{
			return Arguments[Index].FloatValue;
		}
		return 0.f;
	}

	UFUNCTION(BlueprintPure, Category = "Mana")
	static FString GetArgumentString(const TArray<FManaBlueprintCommandArgument>& Arguments, const int32 Index)
	{
		if (Arguments.IsValidIndex(Index) && Arguments[Index].Type == EManaBlueprintCommandArgType::String)
		{
			return Arguments[Index].StringValue;
		}
		return "";
	}

	UFUNCTION(BlueprintPure, Category = "Mana")
	static AActor* GetArgumentActor(const TArray<FManaBlueprintCommandArgument>& Arguments, const int32 Index)
	{
		if (Arguments.IsValidIndex(Index) && Arguments[Index].Type == EManaBlueprintCommandArgType::Actor)
		{
			return Arguments[Index].ActorValue;
		}
		return nullptr;
	}

	UFUNCTION(BlueprintCallable, Category = "Mana")
	static void SetArgumentBool(FManaBlueprintCommandArgument& OutResult, const bool Value);

	UFUNCTION(BlueprintCallable, Category = "Mana")
	static void SetArgumentInt(FManaBlueprintCommandArgument& OutResult, const int32 Value);

	UFUNCTION(BlueprintCallable, Category = "Mana")
	static void SetArgumentFloat(FManaBlueprintCommandArgument& OutResult, const float Value);

	UFUNCTION(BlueprintCallable, Category = "Mana")
	static void SetArgumentString(FManaBlueprintCommandArgument& OutResult, const FString Value);

	UFUNCTION(BlueprintCallable, Category = "Mana")
	static void SetArgumentActor(FManaBlueprintCommandArgument& OutResult, const AActor* Value);

protected:
	UFUNCTION(BlueprintImplementableEvent, Category = "Mana")
	void OnRegister();
	
private:
	bool ExecuteRegisteredCommand(FName CommandName, const std::shared_ptr<mana::Actor>& Actor) const;

	UPROPERTY(Transient)
	TWeakObjectPtr<UManaRuntimeVM> RuntimeVM;

	UPROPERTY(Transient)
	TMap<FName, FManaBlueprintCommandBinding> CommandBindings;
};
