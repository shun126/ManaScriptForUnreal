/**
 * @author		Shun Moriya
 * @copyright	2026- Shun Moriya
 * All Rights Reserved.
 */

#include "AssetTypeActions_ManaProgramAsset.h"

#include "ManaCompiler.h"
#include "ManaProgramAsset.h"
//#include "EditorFileUtils.h"
#include "EditorFramework/AssetImportData.h"
#include "FileHelpers.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"
#include "HAL/PlatformProcess.h"
#include "Logging/MessageLog.h"
#include "Logging/TokenizedMessage.h"
#include "Misc/MessageDialog.h"
#include "Misc/Paths.h"
#include "SourceCodeNavigation.h"

namespace
{
	/** 診断1件を、該当行を開けるメッセージに仕立てます */
	TSharedRef<FTokenizedMessage> BuildDiagnosticMessage(const FManaDiagnostic& Diagnostic)
	{
		EMessageSeverity::Type Severity = EMessageSeverity::Error;
		switch (Diagnostic.Severity)
		{
		case EManaDiagnosticSeverity::Warning:	Severity = EMessageSeverity::Warning;	break;
		case EManaDiagnosticSeverity::Fatal:	Severity = EMessageSeverity::Error;		break;
		default:																		break;
		}

		const TSharedRef<FTokenizedMessage> Message = FTokenizedMessage::Create(Severity);
		Message->AddToken(FTextToken::Create(FText::FromString(Diagnostic.Message)));

		// 行情報があるなら、押すとその行が開くようにする
		if (!Diagnostic.Filename.IsEmpty() && Diagnostic.LineNo > 0)
		{
			const FString Filename = Diagnostic.Filename;
			const int32 LineNo = Diagnostic.LineNo;
			Message->AddToken(FActionToken::Create(
				FText::FromString(FString::Printf(TEXT("%s(%d)"), *FPaths::GetCleanFilename(Filename), LineNo)),
				FText::FromString(Filename),
				FOnActionTokenExecuted::CreateLambda([Filename, LineNo]()
					{
						FSourceCodeNavigation::OpenSourceFile(Filename, LineNo, 1);
					})));
		}
		else if (!Diagnostic.Filename.IsEmpty())
		{
			Message->AddToken(FTextToken::Create(FText::FromString(Diagnostic.Filename)));
		}

		return Message;
	}

	void LogCompileDiagnostics(const UManaProgramAsset& Asset, const FManaAssetCompileResult& Result, const FString& SourceFilePath)
	{
		FMessageLog MessageLog(TEXT("ManaCompiler"));
		const FText AssetName = FText::FromString(Asset.GetName());
		const FString SourcePath = SourceFilePath.IsEmpty() ? TEXT("<unknown>") : SourceFilePath;

		if (!Result.bSuccess)
		{
			MessageLog.Error(FText::Format(
				NSLOCTEXT("Mana", "ManaCompileFailed", "Mana compile failed for {0}."),
				AssetName));
		}
		else
		{
			MessageLog.Info(FText::Format(
				NSLOCTEXT("Mana", "ManaCompileSucceeded", "Mana compile succeeded for {0}."),
				AssetName));
		}

		MessageLog.Info(FText::Format(
			NSLOCTEXT("Mana", "ManaCompileSourcePath", "Source: {0}"),
			FText::FromString(SourcePath)));

		// 診断はコンパイラが付けた重大度のまま出す。成功していても警告は警告として残る
		for (const FManaDiagnostic& Diagnostic : Result.Diagnostics)
		{
			MessageLog.AddMessage(BuildDiagnosticMessage(Diagnostic));
		}

		if (!Result.bSuccess)
		{
			MessageLog.Open(EMessageSeverity::Error);
		}
	}
}

FAssetTypeActions_ManaProgramAsset::FAssetTypeActions_ManaProgramAsset(EAssetTypeCategories::Type InAssetCategory)
	: AssetCategory(InAssetCategory)
{
}

FText FAssetTypeActions_ManaProgramAsset::GetName() const
{
	return NSLOCTEXT("Mana", "ManaProgramAsset", "Mana Program Asset");
}

FColor FAssetTypeActions_ManaProgramAsset::GetTypeColor() const
{
	return FColor(90, 200, 255);
}

UClass* FAssetTypeActions_ManaProgramAsset::GetSupportedClass() const
{
	return UManaProgramAsset::StaticClass();
}

uint32 FAssetTypeActions_ManaProgramAsset::GetCategories()
{
	return AssetCategory;
}

void FAssetTypeActions_ManaProgramAsset::GetActions(const TArray<UObject*>& InObjects, FMenuBuilder& MenuBuilder)
{
	TArray<TWeakObjectPtr<UManaProgramAsset>> Assets = GetTypedWeakObjectPtrs<UManaProgramAsset>(InObjects);

	MenuBuilder.AddMenuEntry(
		NSLOCTEXT("Mana", "CompileManaProgram", "Compile"),
		NSLOCTEXT("Mana", "CompileManaProgramTooltip", "Compile Mana source into the ProgramAsset."),
		FSlateIcon(),
		FUIAction(FExecuteAction::CreateSP(this, &FAssetTypeActions_ManaProgramAsset::ExecuteCompile, Assets)));
#if 0
	MenuBuilder.AddMenuEntry(
		NSLOCTEXT("Mana", "RecompileManaProgram", "Recompile"),
		NSLOCTEXT("Mana", "RecompileManaProgramTooltip", "Recompile Mana source into the ProgramAsset."),
		FSlateIcon(),
		FUIAction(FExecuteAction::CreateSP(this, &FAssetTypeActions_ManaProgramAsset::ExecuteCompile, Assets)));
#endif
	MenuBuilder.AddMenuEntry(
		NSLOCTEXT("Mana", "ValidateManaProgram", "Validate"),
		NSLOCTEXT("Mana", "ValidateManaProgramTooltip", "Validate compiled binary compatibility."),
		FSlateIcon(),
		FUIAction(FExecuteAction::CreateSP(this, &FAssetTypeActions_ManaProgramAsset::ExecuteValidate, Assets)));

	MenuBuilder.AddMenuEntry(
		NSLOCTEXT("Mana", "OpenManaProgramSource", "Open Source"),
		NSLOCTEXT("Mana", "OpenManaProgramSourceTooltip", "Open the Mana source file in the configured text editor."),
		FSlateIcon(),
		FUIAction(FExecuteAction::CreateSP(this, &FAssetTypeActions_ManaProgramAsset::ExecuteOpenSource, Assets)));
}

void FAssetTypeActions_ManaProgramAsset::ExecuteCompile(TArray<TWeakObjectPtr<UManaProgramAsset>> Assets)
{
	TArray<UPackage*> PackagesToSave;
	for (const TWeakObjectPtr<UManaProgramAsset>& AssetPtr : Assets)
	{
		UManaProgramAsset* Asset = AssetPtr.Get();
		if (!Asset)
		{
			continue;
		}

		FString SourceFilePath;
		if (Asset->AssetImportData)
		{
			TArray<FString> Filenames;
			Asset->AssetImportData->ExtractFilenames(Filenames);
			if (Filenames.Num() > 0)
			{
				SourceFilePath = Filenames[0];
			}
		}
		const FManaAssetCompileResult Result = FManaCompiler::CompileSource(SourceFilePath);
		FManaCompiler::ApplyResult(*Asset, Result);
		LogCompileDiagnostics(*Asset, Result, SourceFilePath);
		Asset->MarkPackageDirty();
		PackagesToSave.AddUnique(Asset->GetOutermost());
	}

	if (PackagesToSave.Num() > 0)
	{
		FEditorFileUtils::PromptForCheckoutAndSave(PackagesToSave, false, false);
	}
}

void FAssetTypeActions_ManaProgramAsset::ExecuteValidate(TArray<TWeakObjectPtr<UManaProgramAsset>> Assets)
{
	for (const TWeakObjectPtr<UManaProgramAsset>& AssetPtr : Assets)
	{
		UManaProgramAsset* Asset = AssetPtr.Get();
		if (!Asset)
		{
			continue;
		}

		const bool bValid = Asset->IsCompiled();
		const FText Message = bValid
			? NSLOCTEXT("Mana", "ManaProgramValid", "ProgramAsset is compiled and ready.")
			: NSLOCTEXT("Mana", "ManaProgramInvalid", "ProgramAsset is missing compiled data or has a format mismatch.");
		FMessageDialog::Open(EAppMsgType::Ok, Message);
	}
}

void FAssetTypeActions_ManaProgramAsset::ExecuteOpenSource(TArray<TWeakObjectPtr<UManaProgramAsset>> Assets)
{
	for (const TWeakObjectPtr<UManaProgramAsset>& AssetPtr : Assets)
	{
		UManaProgramAsset* Asset = AssetPtr.Get();
		if (!Asset)
		{
			continue;
		}

		FString SourceFilePath;
		if (Asset->AssetImportData)
		{
			TArray<FString> Filenames;
			Asset->AssetImportData->ExtractFilenames(Filenames);
			if (Filenames.Num() > 0)
			{
				SourceFilePath = Filenames[0];
			}
		}

		if (SourceFilePath.IsEmpty())
		{
			FMessageDialog::Open(
				EAppMsgType::Ok,
				NSLOCTEXT("Mana", "OpenManaProgramSourceEmpty", "SourceFilePath is empty. Reimport the asset or set the source path."));
			continue;
		}

		const FString AbsoluteSourcePath = FPaths::ConvertRelativePathToFull(SourceFilePath);
		if (!FPaths::FileExists(AbsoluteSourcePath))
		{
			FMessageDialog::Open(
				EAppMsgType::Ok,
				FText::Format(
					NSLOCTEXT("Mana", "OpenManaProgramSourceMissing", "Source file not found: {0}"),
					FText::FromString(AbsoluteSourcePath)));
			continue;
		}

		const bool bOpened = FSourceCodeNavigation::OpenSourceFile(AbsoluteSourcePath)
			|| FPlatformProcess::LaunchFileInDefaultExternalApplication(*AbsoluteSourcePath);

		if (!bOpened)
		{
			FMessageDialog::Open(
				EAppMsgType::Ok,
				NSLOCTEXT("Mana", "OpenManaProgramSourceFailed", "Failed to open the source file in a text editor."));
		}
	}
}
