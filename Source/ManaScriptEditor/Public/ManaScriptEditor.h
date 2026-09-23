/**
 * @author		Shun Moriya
 * @copyright	2026- Shun Moriya
 * All Rights Reserved.
 */

#pragma once

#include "AssetTypeCategories.h"
#include "Modules/ModuleManager.h"

class FManaScriptEditorModule : public IModuleInterface
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

private:
	void RegisterAssetTypeActions(EAssetTypeCategories::Type ManaAssetCategory);
	void UnregisterAssetTypeActions();
	void HandleCompiledBinaryUpdated(class UManaProgramAsset* Asset);

	/** バイトコードの版数が食い違ったアセットを、原文から作り直します */
	void HandleRecompileRequest(class UManaProgramAsset& Asset);

	TArray<TSharedRef<class IAssetTypeActions>> RegisteredAssetActions;
	FDelegateHandle CompiledBinaryUpdatedHandle;
};
