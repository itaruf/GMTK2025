// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class GMTK2025 : ModuleRules
{
	public GMTK2025(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"GMTK2025",
			"GMTK2025/Variant_Platforming",
			"GMTK2025/Variant_Combat",
			"GMTK2025/Variant_Combat/AI",
			"GMTK2025/Variant_SideScrolling",
			"GMTK2025/Variant_SideScrolling/Gameplay",
			"GMTK2025/Variant_SideScrolling/AI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
