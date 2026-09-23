/**
 * @author		Shun Moriya
 * @copyright	2026- Shun Moriya
 * All Rights Reserved.
 */

#pragma once

#include "CoreMinimal.h"

namespace mana
{
	class Actor;
	class VM;
}

class UManaRuntimeVM;

class FManaRuntimeBindings
{
public:
	explicit FManaRuntimeBindings(UManaRuntimeVM& InRuntimeVM);

	void Register(mana::VM& VM);

private:
	void SetLocation(const std::shared_ptr<mana::Actor>& Actor, void*) const;
	void PlayMontage(const std::shared_ptr<mana::Actor>& Actor, void*) const;
	void MoveToLocation(const std::shared_ptr<mana::Actor>& Actor, void*) const;
	void MoveToActor(const std::shared_ptr<mana::Actor>& Actor, void*) const;
	void LookAtLocation(const std::shared_ptr<mana::Actor>& Actor, void*) const;
	void LookAtActor(const std::shared_ptr<mana::Actor>& Actor, void*) const;
	void SetAnimParam(const std::shared_ptr<mana::Actor>& Actor, void*) const;

	bool TryGetRuntimeVM(UManaRuntimeVM*& OutRuntimeVM) const;

	TWeakObjectPtr<UManaRuntimeVM> RuntimeVM;
};
