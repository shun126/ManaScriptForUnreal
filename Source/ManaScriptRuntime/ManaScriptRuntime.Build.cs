/**
 * @author		Shun Moriya
 * @copyright	2026- Shun Moriya
 * All Rights Reserved.
 */

using UnrealBuildTool;

public class ManaScriptRuntime : ModuleRules
{
	public ManaScriptRuntime(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

		// Mana の仮想マシンは例外で障害を通知します。
		//
		//   mana::ScriptError  0除算・配列の範囲外など、スクリプト側の誤り。
		//                      そのアクターだけを停止させ、他のアクターとホストは継続します
		//   mana::FatalError   不変条件が壊れた事。同上に加え FaultHandler が呼ばれます
		//
		// いずれも Release でも検査されます。例外を無効にすると、これらが
		// 「アクターだけ停止」ではなく「プロセス消滅」に化けるため、
		// 製品ビルドでスクリプトを走らせる以上は有効にしておく必要があります。
		bEnableExceptions = true;

		PublicIncludePaths.AddRange(
			new string[] {
				// Public/Mana/runner に Mana の仮想マシンを無改変で置いています。
				// Public/ は自動でインクルードパスに入るため、
				// #include "Mana/runner/VM.h" の形で参照できます
			}
			);


		PrivateIncludePaths.AddRange(
			new string[] {
				// ... add other private include paths required here ...
			}
			);

		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				// ... add other public dependencies that you statically link with here ...
			}
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
				// ... add private dependencies that you statically link with here ...	
				"AIModule",
			}
			);
		
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
			);
	}
}
