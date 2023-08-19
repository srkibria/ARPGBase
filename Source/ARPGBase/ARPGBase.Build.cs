// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ARPGBase : ModuleRules
{
	public ARPGBase(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", 
			"CoreUObject", 
			"Engine", 
			"InputCore", 
			"HeadMountedDisplay", 
			"EnhancedInput", 
			"UMG",
			"GameplayAbilities", 
			"GameplayTags", 
			"GameplayTasks"
		});
	}
}
