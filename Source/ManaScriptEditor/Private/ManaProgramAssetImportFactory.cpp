/**
 * @author		Shun Moriya
 * @copyright	2026- Shun Moriya
 * All Rights Reserved.
 */

#include "ManaProgramAssetImportFactory.h"

#include "ManaCompiler.h"
#include "ManaProgramAsset.h"
#include "EditorFramework/AssetImportData.h"

UManaProgramAssetImportFactory::UManaProgramAssetImportFactory()
{
	SupportedClass = UManaProgramAsset::StaticClass();
	bCreateNew = false;
	bEditorImport = true;
	Formats.Add(TEXT("mn;Mana Script"));
}

UObject* UManaProgramAssetImportFactory::FactoryCreateFile(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, const FString& Filename, const TCHAR* Parms, FFeedbackContext* Warn, bool& bOutOperationCanceled)
{
	UManaProgramAsset* Asset = NewObject<UManaProgramAsset>(InParent, InClass, InName, Flags);
	if (!Asset)
	{
		return nullptr;
	}

	if (!Asset->AssetImportData)
	{
		Asset->AssetImportData = NewObject<UAssetImportData>(Asset, TEXT("AssetImportData"));
	}
	Asset->AssetImportData->Update(Filename);

	const FManaAssetCompileResult Result = FManaCompiler::CompileSource(Filename);
	FManaCompiler::ApplyResult(*Asset, Result);

	return Asset;
}

bool UManaProgramAssetImportFactory::CanReimport(UObject* Obj, TArray<FString>& OutFilenames)
{
	UManaProgramAsset* Asset = Cast<UManaProgramAsset>(Obj);
	if (!Asset)
	{
		return false;
	}

	if (Asset->AssetImportData)
	{
		Asset->AssetImportData->ExtractFilenames(OutFilenames);
	}

	return true;
}

void UManaProgramAssetImportFactory::SetReimportPaths(UObject* Obj, const TArray<FString>& NewReimportPaths)
{
	UManaProgramAsset* Asset = Cast<UManaProgramAsset>(Obj);
	if (!Asset || NewReimportPaths.Num() == 0)
	{
		return;
	}

	if (!Asset->AssetImportData)
	{
		Asset->AssetImportData = NewObject<UAssetImportData>(Asset, TEXT("AssetImportData"));
	}
	Asset->AssetImportData->Update(NewReimportPaths[0]);
}

EReimportResult::Type UManaProgramAssetImportFactory::Reimport(UObject* Obj)
{
	UManaProgramAsset* Asset = Cast<UManaProgramAsset>(Obj);
	if (!Asset)
	{
		return EReimportResult::Failed;
	}

	FString SourceFile;
	if (Asset->AssetImportData)
	{
		TArray<FString> Filenames;
		Asset->AssetImportData->ExtractFilenames(Filenames);
		if (Filenames.Num() > 0)
		{
			SourceFile = Filenames[0];
		}
	}

	if (SourceFile.IsEmpty())
	{
		return EReimportResult::Failed;
	}

	if (!Asset->AssetImportData)
	{
		Asset->AssetImportData = NewObject<UAssetImportData>(Asset, TEXT("AssetImportData"));
	}
	Asset->AssetImportData->Update(SourceFile);

	const FManaAssetCompileResult Result = FManaCompiler::CompileSource(SourceFile);
	FManaCompiler::ApplyResult(*Asset, Result);
	Asset->MarkPackageDirty();

	return Result.bSuccess ? EReimportResult::Succeeded : EReimportResult::Failed;
}
