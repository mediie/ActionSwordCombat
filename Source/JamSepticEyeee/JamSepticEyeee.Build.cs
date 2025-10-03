// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class JamSepticEyeee : ModuleRules
{
	public JamSepticEyeee(ReadOnlyTargetRules Target) : base(Target)
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
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"JamSepticEyeee",
			"JamSepticEyeee/Variant_Platforming",
			"JamSepticEyeee/Variant_Platforming/Animation",
			"JamSepticEyeee/Variant_Combat",
			"JamSepticEyeee/Variant_Combat/AI",
			"JamSepticEyeee/Variant_Combat/Animation",
			"JamSepticEyeee/Variant_Combat/Gameplay",
			"JamSepticEyeee/Variant_Combat/Interfaces",
			"JamSepticEyeee/Variant_Combat/UI",
			"JamSepticEyeee/Variant_SideScrolling",
			"JamSepticEyeee/Variant_SideScrolling/AI",
			"JamSepticEyeee/Variant_SideScrolling/Gameplay",
			"JamSepticEyeee/Variant_SideScrolling/Interfaces",
			"JamSepticEyeee/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
