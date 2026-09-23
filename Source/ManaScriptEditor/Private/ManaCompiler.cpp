/**
 * @author		Shun Moriya
 * @copyright	2026- Shun Moriya
 * All Rights Reserved.
 */

#include "ManaCompiler.h"

#include "ManaProgramAsset.h"
#include "Misc/FileHelper.h"
#include "Misc/Paths.h"
#include "Misc/SecureHash.h"

namespace
{
	/** 診断を1件足します。コンパイラを呼ぶ前に失敗した場合に使います */
	void AddFatal(FManaAssetCompileResult& Result, const FString& Message)
	{
		FManaDiagnostic& Diagnostic = Result.Diagnostics.AddDefaulted_GetRef();
		Diagnostic.Severity = EManaDiagnosticSeverity::Fatal;
		Diagnostic.Message = Message;
		Result.bSuccess = false;
	}
}

FManaAssetCompileResult FManaCompiler::CompileSource(const FString& SourceFilePath)
{
	FManaAssetCompileResult Result;
	Result.CompilerVersion = FManaScriptCompiler::GetCompilerVersion();
	FManaScriptCompiler::GetBytecodeVersion(Result.BytecodeMajorVersion, Result.BytecodeMinorVersion);

	if (SourceFilePath.IsEmpty())
	{
		AddFatal(Result, TEXT("SourceFilePath is empty. Provide a Mana source file path."));
		return Result;
	}

	const FString AbsoluteSourcePath = FPaths::ConvertRelativePathToFull(SourceFilePath);
	if (!FPaths::FileExists(AbsoluteSourcePath))
	{
		AddFatal(Result, FString::Printf(TEXT("Source file does not exist: %s"), *AbsoluteSourcePath));
		return Result;
	}

	// ソースのハッシュは、再コンパイルが要るかどうかの判断に使います
	TArray<uint8> SourceBytes;
	if (!FFileHelper::LoadFileToArray(SourceBytes, *AbsoluteSourcePath))
	{
		AddFatal(Result, FString::Printf(TEXT("Failed to read source file: %s"), *AbsoluteSourcePath));
		return Result;
	}

	constexpr int32 Sha1DigestSize = 20; // 160 bits
	FSHA1 Hasher;
	Hasher.Update(SourceBytes.GetData(), SourceBytes.Num());
	Hasher.Final();
	uint8 HashBytes[Sha1DigestSize];
	Hasher.GetHash(HashBytes);
	Result.SourceHash = BytesToHex(HashBytes, Sha1DigestSize);

	FManaCompileOptions Options;
	Options.SourceFilePath = AbsoluteSourcePath;
	// bGenerateDump を真にすると、シンボル表・構文木・中間コードが
	// FManaCompileResult::Dump にマークダウンで入ります

	// mana::Compile() はファイルを書きません。生成物は全て値で返ります
	const FManaCompileResult Compiled = FManaScriptCompiler::Compile(Options);

	Result.bSuccess = Compiled.bSucceeded;
	Result.Diagnostics = Compiled.Diagnostics;
	Result.Binary = Compiled.ProgramImage;

	return Result;
}

void FManaCompiler::ApplyResult(UManaProgramAsset& Asset, const FManaAssetCompileResult& Result)
{
	Asset.Diagnostics.Reset(Result.Diagnostics.Num());
	for (const FManaDiagnostic& Diagnostic : Result.Diagnostics)
	{
		Asset.Diagnostics.Add(Diagnostic.ToString());
	}

	Asset.ManaCompilerVersion = Result.CompilerVersion;
	Asset.SourceHash = Result.SourceHash;
	Asset.FormatVersion = UManaProgramAsset::CurrentFormatVersion;
	Asset.BytecodeMajorVersion = Result.BytecodeMajorVersion;
	Asset.BytecodeMinorVersion = Result.BytecodeMinorVersion;

	if (Result.bSuccess)
	{
		Asset.UpdateCompiledBinary(Result.Binary);
	}
	else
	{
		Asset.ResetCompiledBinary();
	}
}
