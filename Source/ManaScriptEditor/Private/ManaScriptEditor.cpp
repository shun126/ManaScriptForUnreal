/**
 * @author		Shun Moriya
 * @copyright	2026- Shun Moriya
 * All Rights Reserved.
 */

#include "ManaScriptEditor.h"

#include "AssetToolsModule.h"
#include "Editor.h"
#include "EditorFramework/AssetImportData.h"
#include "EngineUtils.h"
#include "ManaBindableComponent.h"
#include "ManaCompiler.h"
#include "ManaProgramAsset.h"
#include "ManaProgramAssetFactory.h"
#include "AssetTypeActions_ManaProgramAsset.h"
#include "ManaVirtualMachine.h"

#define LOCTEXT_NAMESPACE "FManaScriptEditorModule"

void FManaScriptEditorModule::StartupModule()
{
	IAssetTools& AssetTools = FAssetToolsModule::GetModule().Get();

	EAssetTypeCategories::Type ManaAssetCategory = AssetTools.RegisterAdvancedAssetCategory(
		FName(TEXT("ManaScriptAssets")),
		FText::FromName(TEXT("ManaScript"))
	);

	RegisterAssetTypeActions(ManaAssetCategory);

	CompiledBinaryUpdatedHandle = UManaProgramAsset::OnCompiledBinaryUpdated().AddRaw(
		this,
		&FManaScriptEditorModule::HandleCompiledBinaryUpdated);

	// Mana のバイトコード版数が上がると、既に保存されているアセットの中身は
	// そのままでは読めなくなります。エディタでは原文から作り直せるので、
	// 読み込み時の要求をここで受けます
	UManaProgramAsset::OnRecompileRequest().BindRaw(
		this,
		&FManaScriptEditorModule::HandleRecompileRequest);
}

void FManaScriptEditorModule::ShutdownModule()
{
	UManaProgramAsset::OnRecompileRequest().Unbind();

	if (CompiledBinaryUpdatedHandle.IsValid())
	{
		UManaProgramAsset::OnCompiledBinaryUpdated().Remove(CompiledBinaryUpdatedHandle);
		CompiledBinaryUpdatedHandle.Reset();
	}

	UnregisterAssetTypeActions();
}

void FManaScriptEditorModule::HandleRecompileRequest(UManaProgramAsset& Asset)
{
	FString SourceFilePath;
	if (Asset.AssetImportData)
	{
		TArray<FString> Filenames;
		Asset.AssetImportData->ExtractFilenames(Filenames);
		if (Filenames.Num() > 0)
		{
			SourceFilePath = Filenames[0];
		}
	}

	if (SourceFilePath.IsEmpty())
	{
		// 原文の位置が分からなければ、呼び出し元がバイトコードを捨てます
		return;
	}

	const FManaAssetCompileResult Result = FManaCompiler::CompileSource(SourceFilePath);
	FManaCompiler::ApplyResult(Asset, Result);
	if (Result.bSuccess)
	{
		Asset.MarkPackageDirty();
	}
}

void FManaScriptEditorModule::RegisterAssetTypeActions(EAssetTypeCategories::Type ManaAssetCategory)
{
	IAssetTools& AssetTools = FAssetToolsModule::GetModule().Get();

	TSharedRef<IAssetTypeActions> Action = MakeShared<FAssetTypeActions_ManaProgramAsset>(ManaAssetCategory);
	AssetTools.RegisterAssetTypeActions(Action);
	RegisteredAssetActions.Add(Action);
}

void FManaScriptEditorModule::UnregisterAssetTypeActions()
{
	if (!FModuleManager::Get().IsModuleLoaded("AssetTools"))
	{
		return;
	}

	IAssetTools& AssetTools = FAssetToolsModule::GetModule().Get();
	for (const TSharedRef<IAssetTypeActions>& Action : RegisteredAssetActions)
	{
		AssetTools.UnregisterAssetTypeActions(Action);
	}
	RegisteredAssetActions.Empty();
}

void FManaScriptEditorModule::HandleCompiledBinaryUpdated(UManaProgramAsset* Asset)
{
	if (!Asset || !GEditor)
	{
		return;
	}

	TSet<UWorld*> WorldsWithAsset;
	for (const FWorldContext& Context : GEditor->GetWorldContexts())
	{
		UWorld* World = Context.World();
		if (!World)
		{
			continue;
		}

		bool bUsesAsset = false;
		for (TActorIterator<AManaVirtualMachine> It(World); It; ++It)
		{
			const AManaVirtualMachine* VirtualMachine = *It;
			if (VirtualMachine && VirtualMachine->Program == Asset)
			{
				bUsesAsset = true;
				break;
			}
		}

		if (bUsesAsset)
		{
			WorldsWithAsset.Add(World);
		}
	}

	for (UWorld* World : WorldsWithAsset)
	{
		for (TActorIterator<AActor> It(World); It; ++It)
		{
			AActor* Actor = *It;
			if (!Actor)
			{
				continue;
			}

			TArray<UManaBindableComponent*> BindableComponents;
			Actor->GetComponents<UManaBindableComponent>(BindableComponents);
			for (UManaBindableComponent* BindableComponent : BindableComponents)
			{
				if (!BindableComponent)
				{
					continue;
				}

				BindableComponent->PostEditChange();
			}
		}
	}
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FManaScriptEditorModule, ManaScriptEditor)
