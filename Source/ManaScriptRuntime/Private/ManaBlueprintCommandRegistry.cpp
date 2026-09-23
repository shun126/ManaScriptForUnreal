/**
 * @author		Shun Moriya
 * @copyright	2026- Shun Moriya
 * All Rights Reserved.
 */

#include "ManaBlueprintCommandRegistry.h"

#include "ManaRuntimeVM.h"
#include "ManaScriptRuntime.h"
#include "Mana/runner/Actor.h"
#include "Mana/runner/VM.h"

void UManaBlueprintCommandRegistry::AddCommandName(
	const FName CommandName,
	const TArray<EManaBlueprintCommandArgType>& ArgumentTypes,
	const FManaBlueprintCommandDelegate& Delegate)
{
	if (CommandName.IsNone())
	{
		return;
	}

	FManaBlueprintCommandBinding Binding;
	Binding.ArgumentTypes = ArgumentTypes;
	Binding.Delegate = Delegate;
	CommandBindings.Add(CommandName, Binding);
}

void UManaBlueprintCommandRegistry::RemoveCommandName(const FName CommandName)
{
	if (!CommandName.IsNone())
	{
		CommandBindings.Remove(CommandName);
	}
}

void UManaBlueprintCommandRegistry::SetRuntimeVM(UManaRuntimeVM* InRuntimeVM)
{
	RuntimeVM = InRuntimeVM;
}

void UManaBlueprintCommandRegistry::Register(mana::VM& VM)
{
	OnRegister();

	TWeakObjectPtr<UManaBlueprintCommandRegistry> WeakRegistry(this);
	for (const TPair<FName, FManaBlueprintCommandBinding>& Pair : CommandBindings)
	{
		const FName CommandName = Pair.Key;
		if (CommandName.IsNone())
		{
			continue;
		}

		const std::string CommandNameUtf8 = TCHAR_TO_UTF8(*CommandName.ToString());
		VM.RegisterFunction(CommandNameUtf8, [WeakRegistry, CommandName](const std::shared_ptr<mana::Actor>& Actor, void*)
		{
			if (const UManaBlueprintCommandRegistry* Registry = WeakRegistry.Get())
			{
				Registry->ExecuteRegisteredCommand(CommandName, Actor);
			}
		});
	}
}

bool UManaBlueprintCommandRegistry::ExecuteRegisteredCommand(const FName CommandName, const std::shared_ptr<mana::Actor>& Actor) const
{
	const FManaBlueprintCommandBinding* Binding = CommandBindings.Find(CommandName);
	if (!Binding)
	{
		UE_LOG(LogManaScriptRuntime, Warning, TEXT("Mana blueprint command '%s' has no binding."), *CommandName.ToString());
		return false;
	}

	if (!Binding->Delegate.IsBound())
	{
		UE_LOG(LogManaScriptRuntime, Warning, TEXT("Mana blueprint command '%s' delegate is not bound."), *CommandName.ToString());
		return false;
	}

	if (!Actor)
	{
		UE_LOG(LogManaScriptRuntime, Warning, TEXT("Mana blueprint command '%s' actor context is null."), *CommandName.ToString());
		return false;
	}

	TArray<FManaBlueprintCommandArgument> Arguments;
	Arguments.Reserve(Binding->ArgumentTypes.Num());

	const UManaRuntimeVM* LocalRuntimeVM = RuntimeVM.Get();
	for (int32 Index = 0; Index < Binding->ArgumentTypes.Num(); ++Index)
	{
		const EManaBlueprintCommandArgType ArgType = Binding->ArgumentTypes[Index];
		FManaBlueprintCommandArgument Argument;
		Argument.Type = ArgType;

		switch (ArgType)
		{
		case EManaBlueprintCommandArgType::Bool:
			Argument.BoolValue = Actor->GetParameterInteger(Index) != 0;
			break;
		case EManaBlueprintCommandArgType::Int32:
			Argument.Int32Value = Actor->GetParameterInteger(Index);
			break;
		case EManaBlueprintCommandArgType::Float:
			Argument.FloatValue = Actor->GetParameterFloat(Index);
			break;
		case EManaBlueprintCommandArgType::String:
			Argument.StringValue = UTF8_TO_TCHAR(Actor->GetParameterString(Index));
			break;
		case EManaBlueprintCommandArgType::Actor:
			if (LocalRuntimeVM)
			{
				const mana::Actor* Handle = Actor->GetParameterActorPointer(Index);
				Argument.ActorValue = LocalRuntimeVM->ResolveActor(Handle);
			}
			break;
		default:
			break;
		}

		Arguments.Add(MoveTemp(Argument));
	}

	FManaBlueprintCommandArgument ReturnValue;
	Binding->Delegate.Execute(Arguments, ReturnValue);

	switch (ReturnValue.Type)
	{
	case EManaBlueprintCommandArgType::Bool:
		Actor->SetReturnInteger(ReturnValue.BoolValue ? 1 : 0);
		break;
	case EManaBlueprintCommandArgType::Int32:
		Actor->SetReturnInteger(ReturnValue.Int32Value);
		break;
	case EManaBlueprintCommandArgType::Float:
		Actor->SetReturnFloat(ReturnValue.FloatValue);
		break;
	case EManaBlueprintCommandArgType::String:
		Actor->SetReturnString(TCHAR_TO_UTF8(*ReturnValue.StringValue));
		break;
	case EManaBlueprintCommandArgType::Actor:
		//Actor->SetReturnActor(ReturnValue.ActorValue);
		break;
	default:
		break;
	}

	return true;
}

void UManaBlueprintCommandRegistry::SetArgumentBool(FManaBlueprintCommandArgument& OutResult, const bool Value)
{
	OutResult.Type = EManaBlueprintCommandArgType::Bool;
	OutResult.BoolValue = Value ? 1 : 0;
}

void UManaBlueprintCommandRegistry::SetArgumentInt(FManaBlueprintCommandArgument& OutResult, const int32 Value)
{
	OutResult.Type = EManaBlueprintCommandArgType::Int32;
	OutResult.Int32Value = Value;
}

void UManaBlueprintCommandRegistry::SetArgumentFloat(FManaBlueprintCommandArgument& OutResult, const float Value)
{
	OutResult.Type = EManaBlueprintCommandArgType::Float;
	OutResult.FloatValue = Value;
}

void UManaBlueprintCommandRegistry::SetArgumentString(FManaBlueprintCommandArgument& OutResult, const FString Value)
{
	OutResult.Type = EManaBlueprintCommandArgType::String;
	OutResult.StringValue = Value;
}

void UManaBlueprintCommandRegistry::SetArgumentActor(FManaBlueprintCommandArgument& OutResult, const AActor* Value)
{
}
