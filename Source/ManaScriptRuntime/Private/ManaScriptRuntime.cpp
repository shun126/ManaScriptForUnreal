/**
 * @author		Shun Moriya
 * @copyright	2026- Shun Moriya
 * All Rights Reserved.
 */

 #include "ManaScriptRuntime.h"

#include "ManaDiagnosticBridge.h"

#define LOCTEXT_NAMESPACE "FManaScriptRuntimeModule"

DEFINE_LOG_CATEGORY(LogManaScriptRuntime);

void FManaScriptRuntimeModule::StartupModule()
{
	// Mana は利用開始前に一度だけ出力先を設定する契約なので、
	// 仮想マシンにもコンパイラにも触れる前のここで済ませる
	FManaDiagnosticBridge::Install();
}

void FManaScriptRuntimeModule::ShutdownModule()
{
	FManaDiagnosticBridge::Uninstall();
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FManaScriptRuntimeModule, ManaScriptRuntime)
