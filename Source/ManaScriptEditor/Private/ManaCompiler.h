/**
 * @author		Shun Moriya
 * @copyright	2026- Shun Moriya
 * All Rights Reserved.
 */

#pragma once

#include "CoreMinimal.h"
#include "ManaScriptCompiler.h"

/**
 * アセットへ書き戻す事を前提にしたコンパイル結果。
 *
 * ManaScriptCompiler モジュールの FManaCompileResult に、アセット側で
 * 保持したい情報 (ソースのハッシュ、コンパイラとバイトコードの版数) を
 * 添えたものです。
 */
struct FManaAssetCompileResult
{
	bool bSuccess = false;

	/** 生成されたプログラムイメージ */
	TArray<uint8> Binary;

	/** 発生した診断。ファイル名と行番号を保ったまま持ちます */
	TArray<FManaDiagnostic> Diagnostics;

	/** コンパイルしたソースの SHA-1 */
	FString SourceHash;

	/** コンパイラの版数 */
	FString CompilerVersion;

	/** 生成したバイトコードの版数。仮想マシンは完全一致を要求します */
	uint8 BytecodeMajorVersion = 0;
	uint8 BytecodeMinorVersion = 0;
};

class FManaCompiler
{
public:
	static FManaAssetCompileResult CompileSource(const FString& SourceFilePath);
	static void ApplyResult(class UManaProgramAsset& Asset, const FManaAssetCompileResult& Result);
};
