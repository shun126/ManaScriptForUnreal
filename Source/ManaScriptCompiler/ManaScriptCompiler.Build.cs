/**
 * @author		Shun Moriya
 * @copyright	2026- Shun Moriya
 * All Rights Reserved.
 */

using System.IO;
using UnrealBuildTool;

/**
 * Mana のコンパイラを抱えるモジュール。
 *
 * コンパイラ本体を専用モジュールへ隔離しているのは、ここで必要になるビルド設定が
 * プラグインの他のコードと両立しないためです。設定はこのモジュールだけに閉じます。
 *
 * Type は Editor なので、シッピングビルドからは自動的に外れます。
 */
public class ManaScriptCompiler : ModuleRules
{
	public ManaScriptCompiler(ReadOnlyTargetRules Target) : base(Target)
	{
		// flex / bison の生成物に Unreal のヘッダーを一切差し込ませない。
		//
		// NoSharedPCHs では足りません。専用 PCH を指定していない場合、UE 5.1 系の
		// UBT はモジュール用の PCH を勝手に作って /FI で強制インクルードします。
		// それが WindowsPlatformCompilerSetup.h を引き込み、C4065 (case のない
		// switch) を含む多数の警告を #pragma warning(error:) で error へ昇格させる
		// ため、bison の生成物が通らなくなります。
		PCHUsage = ModuleRules.PCHUsageMode.NoPCHs;

		// mana::Compile() 自体は例外を送出しませんが、内部では例外で
		// 工程間の中断を伝え、境界で捕らえて診断へ変換しています。
		// 例外を無効にするとこの仕組みが成立しません
		bEnableExceptions = true;

		// flex / bison の生成物は yyin・yytext・yylineno などのグローバルと
		// YY_* マクロを撒くため、他の翻訳単位と連結されると壊れます
		bUseUnity = false;

		// Mana は C++17 で書かれていますが、UE 5.8 で Cpp17 は指定できなくなりました
		// (CppStandardVersion.Minimum = Cpp20)。上位互換なので、エンジンに追従して
		// コンパイラが扱える最新の規格へ載せます。
		CppStandard = CppStandardVersion.Latest;

		// Lexer.cpp と Parser.cpp は生成物で、Unreal の警告設定では通りません。
		//
		// 警告の設定は UE 5.6 で CppCompileWarningSettings へ移りました。旧プロパティも
		// 残ってはいますが [Obsolete] 扱いで、bEnableUndefinedIdentifierWarnings に
		// 至っては 5.6 以降まったく効きません。UBT は Build.cs をコンパイルする際に
		// UE_5_x_OR_LATER を定義してくれるので、そこで書き分けます。
#if UE_5_6_OR_LATER
		CppCompileWarningSettings.ShadowVariableWarningLevel = WarningLevel.Off;
		CppCompileWarningSettings.UnsafeTypeCastWarningLevel = WarningLevel.Off;
		CppCompileWarningSettings.UndefinedIdentifierWarningLevel = WarningLevel.Off;
#else
		ShadowVariableWarningLevel = WarningLevel.Off;
		UnsafeTypeCastWarningLevel = WarningLevel.Off;
		bEnableUndefinedIdentifierWarnings = false;
#endif

		// 取り込んだソースは無改変なので、Unreal のインクルード規約は適用しない
#if UE_5_2_OR_LATER
		IWYUSupport = IWYUSupport.None;
#else
		bEnforceIWYU = false;
#endif

		// 生成物が fopen などを使います
		PrivateDefinitions.Add("_CRT_SECURE_NO_WARNINGS=1");

		// 取り込んだコンパイラは仮想マシンを "../runner/..." という相対パスで
		// 参照します。仮想マシンの複製は ManaScriptRuntime 側の一箇所だけに
		// 置きたいので、書き換えるのではなくインクルードパスで解決します。
		//
		// 引用形式のインクルードは、まず読み込む側のディレクトリを見た後、
		// インクルードパスの各ディレクトリからも探されます。runner 自身を
		// 渡すと "<runner>/../runner/common/Setup.h" として解決されます。
		// この一行を消すとコンパイラ側が丸ごと通らなくなります。
		PrivateIncludePaths.Add(
			Path.Combine(ModuleDirectory, "..", "ManaScriptRuntime", "Public", "Mana", "runner"));

		// 取り込んだコンパイラは bison の生成物を <Parser.hpp> と山括弧で参照します。
		// 山括弧形式は読み込む側のディレクトリを探さないため、compiler 自身を渡します。
		PrivateIncludePaths.Add(
			Path.Combine(ModuleDirectory, "Private", "Mana", "compiler"));

		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				// バイトコードの形式定義 (Mana/runner/common/FileFormat.h) を
				// 仮想マシンと共有します
				"ManaScriptRuntime",
			});

		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
			});
	}
}
