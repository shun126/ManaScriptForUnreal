/**
 * @author		Shun Moriya
 * @copyright	2026- Shun Moriya
 * All Rights Reserved.
 */

#include "ManaProgramAssetFactory.h"

#include "ManaProgramAsset.h"

UManaProgramAssetFactory::UManaProgramAssetFactory()
{
	SupportedClass = UManaProgramAsset::StaticClass();
	bCreateNew = true;
	bEditAfterNew = true;
}

UObject* UManaProgramAssetFactory::FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn)
{
	return NewObject<UManaProgramAsset>(InParent, InClass, InName, Flags);
}
