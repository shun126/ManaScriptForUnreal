/**
 * @author		Shun Moriya
 * @copyright	2026- Shun Moriya
 * All Rights Reserved.
 */

#pragma once

#include "CoreMinimal.h"
#include "AssetTypeActions_Base.h"

class UManaProgramAsset;

class FAssetTypeActions_ManaProgramAsset : public FAssetTypeActions_Base
{
public:
	explicit FAssetTypeActions_ManaProgramAsset(EAssetTypeCategories::Type InAssetCategory);

	virtual FText GetName() const override;
	virtual FColor GetTypeColor() const override;
	virtual UClass* GetSupportedClass() const override;
	virtual uint32 GetCategories() override;
	virtual void GetActions(const TArray<UObject*>& InObjects, FMenuBuilder& MenuBuilder) override;

private:
	void ExecuteCompile(TArray<TWeakObjectPtr<UManaProgramAsset>> Assets);
	void ExecuteValidate(TArray<TWeakObjectPtr<UManaProgramAsset>> Assets);
	void ExecuteOpenSource(TArray<TWeakObjectPtr<UManaProgramAsset>> Assets);

private:
	EAssetTypeCategories::Type AssetCategory;
};
