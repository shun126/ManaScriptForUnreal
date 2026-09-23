/**
 * @author		Shun Moriya
 * @copyright	2026- Shun Moriya
 * All Rights Reserved.
 */

#include "ManaScriptCompiler.h"

#include "Containers/StringConv.h"

#include "Mana/compiler/Compiler.h"
#include "Mana/compiler/Version.h"
#include "Mana/runner/common/FileFormat.h"

#include <string>
#include <vector>

#define LOCTEXT_NAMESPACE "FManaScriptCompilerModule"

DEFINE_LOG_CATEGORY(LogManaScriptCompiler);

namespace
{
	/**
	 * コンパイラはグローバルな状態を持ち、同時に複数のスレッドから
	 * 呼び出せません。ここで直列化します。
	 */
	FCriticalSection& GetCompilerLock()
	{
		static FCriticalSection Lock;
		return Lock;
	}

	std::string ToUtf8(const FString& Text)
	{
		const FTCHARToUTF8 Converter(*Text);
		return std::string(Converter.Get(), static_cast<size_t>(Converter.Length()));
	}

	FString FromUtf8(const std::string& Text)
	{
		const FUTF8ToTCHAR Converter(Text.c_str(), static_cast<int32>(Text.size()));
		return FString(Converter.Length(), Converter.Get());
	}

	EManaDiagnosticSeverity ToSeverity(const mana::DiagnosticSeverity Severity)
	{
		switch (Severity)
		{
		case mana::DiagnosticSeverity::Warning:	return EManaDiagnosticSeverity::Warning;
		case mana::DiagnosticSeverity::Fatal:	return EManaDiagnosticSeverity::Fatal;
		case mana::DiagnosticSeverity::Error:
		default:								return EManaDiagnosticSeverity::Error;
		}
	}

	EManaDiagnosticPhase ToPhase(const mana::DiagnosticPhase Phase)
	{
		return Phase == mana::DiagnosticPhase::Link
			? EManaDiagnosticPhase::Link
			: EManaDiagnosticPhase::Compile;
	}
}

FString FManaDiagnostic::ToString() const
{
	const TCHAR* Label = TEXT("error");
	switch (Severity)
	{
	case EManaDiagnosticSeverity::Warning:	Label = TEXT("warning");	break;
	case EManaDiagnosticSeverity::Fatal:	Label = TEXT("fatal");		break;
	default:															break;
	}

	if (LineNo > 0)
	{
		return FString::Printf(TEXT("%s(%d): %s: %s"), *Filename, LineNo, Label, *Message);
	}
	if (!Filename.IsEmpty())
	{
		return FString::Printf(TEXT("%s: %s: %s"), *Filename, Label, *Message);
	}
	return FString::Printf(TEXT("%s: %s"), Label, *Message);
}

TArray<FString> FManaCompileResult::ToStringArray() const
{
	TArray<FString> Lines;
	Lines.Reserve(Diagnostics.Num());
	for (const FManaDiagnostic& Diagnostic : Diagnostics)
	{
		Lines.Add(Diagnostic.ToString());
	}
	return Lines;
}

FManaCompileResult FManaScriptCompiler::Compile(const FManaCompileOptions& Options)
{
	FManaCompileResult Result;

	if (Options.SourceFilePath.IsEmpty())
	{
		FManaDiagnostic& Diagnostic = Result.Diagnostics.AddDefaulted_GetRef();
		Diagnostic.Severity = EManaDiagnosticSeverity::Fatal;
		Diagnostic.Message = TEXT("SourceFilePath is empty.");
		return Result;
	}

	mana::CompileOptions NativeOptions;
	NativeOptions.mSourceFilename = ToUtf8(Options.SourceFilePath);
	NativeOptions.mGenerateDump = Options.bGenerateDump;
	NativeOptions.mGeneratePublicTypeDecl = Options.bGeneratePublicTypeDecl;
	NativeOptions.mForcedIncludeFiles.reserve(static_cast<size_t>(Options.ForcedIncludeFiles.Num()));
	for (const FString& Include : Options.ForcedIncludeFiles)
	{
		NativeOptions.mForcedIncludeFiles.push_back(ToUtf8(Include));
	}
	// mSourceResolver は省略。既定のファイルシステムから読み込みます。
	// 未保存のエディタバッファからコンパイルしたくなったら、ここへ
	// mana::SourceResolver の実装を渡して下さい
	// mDiagnosticHandler も省略。全ての診断は mDiagnostics に入ります

	mana::CompileResult NativeResult;
	{
		FScopeLock Lock(&GetCompilerLock());
		NativeResult = mana::Compile(NativeOptions);
	}

	Result.bSucceeded = NativeResult.mSucceeded;
	Result.PublicTypeDecl = FromUtf8(NativeResult.mPublicTypeDecl);
	Result.Dump = FromUtf8(NativeResult.mDump);

	Result.Diagnostics.Reserve(static_cast<int32>(NativeResult.mDiagnostics.size()));
	for (const mana::Diagnostic& Native : NativeResult.mDiagnostics)
	{
		FManaDiagnostic& Diagnostic = Result.Diagnostics.AddDefaulted_GetRef();
		Diagnostic.Severity = ToSeverity(Native.mSeverity);
		Diagnostic.Phase = ToPhase(Native.mPhase);
		Diagnostic.Filename = FromUtf8(Native.mFilename);
		Diagnostic.LineNo = Native.mLineNo;
		Diagnostic.Message = FromUtf8(Native.mMessage);
	}

	if (!NativeResult.mProgramImage.empty())
	{
		Result.ProgramImage.SetNumUninitialized(static_cast<int32>(NativeResult.mProgramImage.size()));
		FMemory::Memcpy(
			Result.ProgramImage.GetData(),
			NativeResult.mProgramImage.data(),
			NativeResult.mProgramImage.size());
	}

	return Result;
}

FString FManaScriptCompiler::GetCompilerVersion()
{
	return FString::Printf(TEXT("mana %s.%s (%04d-%02d-%02d)"),
		UTF8_TO_TCHAR(mana::build::MajorVersion),
		UTF8_TO_TCHAR(mana::build::MinorVersion),
		mana::build::Year,
		mana::build::Month,
		mana::build::Day);
}

void FManaScriptCompiler::GetBytecodeVersion(uint8& OutMajorVersion, uint8& OutMinorVersion)
{
	OutMajorVersion = mana::MajorVersion;
	OutMinorVersion = mana::MinorVersion;
}

void FManaScriptCompilerModule::StartupModule()
{
}

void FManaScriptCompilerModule::ShutdownModule()
{
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FManaScriptCompilerModule, ManaScriptCompiler)
