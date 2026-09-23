/**
 * @author		Shun Moriya
 * @copyright	2026- Shun Moriya
 * All Rights Reserved.
 */

#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "ManaProgramAssetFactory.generated.h"

UCLASS()
class UManaProgramAssetFactory : public UFactory
{
	GENERATED_BODY()

public:
	UManaProgramAssetFactory();

	virtual UObject* FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;
};
