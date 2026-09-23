/**
 * @author		Shun Moriya
 * @copyright	2026- Shun Moriya
 * All Rights Reserved.
 */

using UnrealBuildTool;

public class ManaScriptEditor : ModuleRules
{
	public ManaScriptEditor(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"CoreUObject",
				"Engine",
				"ManaScriptCompiler",
				"ManaScriptRuntime",
				"UnrealEd"
			});

		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"AssetRegistry",
				"AssetTools",
				"MessageLog",
				"Projects",
				"SourceCodeAccess",
				"Slate",
				"SlateCore"
			});
	}
}
