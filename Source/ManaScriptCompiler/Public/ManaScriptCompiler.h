/**
 * @author		Shun Moriya
 * @copyright	2026- Shun Moriya
 * All Rights Reserved.
 */

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

DECLARE_LOG_CATEGORY_EXTERN(LogManaScriptCompiler, Log, All);

/**
 * 診断の重大度。mana::DiagnosticSeverity に対応します。
 */
enum class EManaDiagnosticSeverity : uint8
{
	/** 警告。コンパイルは継続します */
	Warning,
	/** エラー。コンパイルは継続しますが成果物は生成されません */
	Error,
	/** 致命的エラー。コンパイルを継続できません */
	Fatal
};

/**
 * 診断が発生した工程。mana::DiagnosticPhase に対応します。
 */
enum class EManaDiagnosticPhase : uint8
{
	/** 字句解析・構文解析・意味解析・コード生成 */
	Compile,
	/** シンボルの解決とプログラムイメージの生成 */
	Link
};

/**
 * コンパイラが報告する診断1件。
 *
 * 整形前の状態で保持しているので、ファイル名と行番号を使った独自の表示ができます。
 * FMessageLog へ FTokenizedMessage として流せば、該当行を開くところまで作れます。
 */
struct MANASCRIPTCOMPILER_API FManaDiagnostic
{
	EManaDiagnosticSeverity Severity = EManaDiagnosticSeverity::Error;

	EManaDiagnosticPhase Phase = EManaDiagnosticPhase::Compile;

	/** 発生したファイル名 */
	FString Filename;

	/** 発生した行番号。0 ならば行情報がない事を表します */
	int32 LineNo = 0;

	/** 本文 */
	FString Message;

	/** "file(line): error: message" の形へ整形します（末尾に改行を含みません） */
	FString ToString() const;
};

/**
 * コンパイルの入力。
 */
struct FManaCompileOptions
{
	/** コンパイルするソースファイルの絶対パス */
	FString SourceFilePath;

	/** ソースファイルより先に読み込むファイル */
	TArray<FString> ForcedIncludeFiles;

	/** 真ならばシンボル表・構文木・中間コードのダンプを生成します */
	bool bGenerateDump = false;

	/** 真ならば C++ の型宣言ヘッダーを生成します */
	bool bGeneratePublicTypeDecl = false;
};

/**
 * コンパイルの結果。
 *
 * mana::Compile() はファイルを一切書きません。生成物は全てここに入るので、
 * 保存するかどうかは呼び出し側が決めます。
 */
struct MANASCRIPTCOMPILER_API FManaCompileResult
{
	/** エラーが1件も発生しなければ真 */
	bool bSucceeded = false;

	/** 生成されたプログラムイメージ。失敗した場合は空 */
	TArray<uint8> ProgramImage;

	/** bGeneratePublicTypeDecl が真で成功した場合の C++ ヘッダー */
	FString PublicTypeDecl;

	/** bGenerateDump が真の場合のマークダウン */
	FString Dump;

	/** 発生した全ての診断 */
	TArray<FManaDiagnostic> Diagnostics;

	/** 診断を1行ずつの文字列にして返します */
	TArray<FString> ToStringArray() const;
};

/**
 * Mana のコンパイラ。
 */
class MANASCRIPTCOMPILER_API FManaScriptCompiler
{
public:
	/**
	 * mana のソースファイルをコンパイルします。
	 *
	 * この関数は例外を送出しません。内部で発生した例外は捕らえられ、
	 * 致命的な診断として結果に格納されます。
	 *
	 * コンパイラはグローバルな状態を持つため同時に複数のスレッドから
	 * 呼び出せません。ここで直列化しているので、呼び出し側は意識しなくて
	 * 構いませんが、待たされる事はあります。
	 */
	static FManaCompileResult Compile(const FManaCompileOptions& Options);

	/** 取り込んでいるコンパイラの版数 */
	static FString GetCompilerVersion();

	/** 生成されるバイトコードの版数。仮想マシンは完全一致を要求します */
	static void GetBytecodeVersion(uint8& OutMajorVersion, uint8& OutMinorVersion);
};

class FManaScriptCompilerModule : public IModuleInterface
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
