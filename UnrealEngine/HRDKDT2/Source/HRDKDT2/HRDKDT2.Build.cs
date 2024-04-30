// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class HRDKDT2 : ModuleRules
{
	public HRDKDT2(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] {            
            "Core", "CoreUObject", "Engine", "InputCore", "UMG",
            "MoviePlayer",
            "EnhancedInput",
            "AIModule",
            "LevelSequence", "MovieScene",
            "Niagara",
            "Paper2D" });

		PrivateDependencyModuleNames.AddRange(new string[] { });

        PublicIncludePaths.Add("HRDKDT2");
        PublicIncludePaths.Add("HRDKDT2/Actors");
        PublicIncludePaths.Add("HRDKDT2/Actors/SolarSystem");



        // Uncomment if you are using Slate UI
        // PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

        // Uncomment if you are using online features
        // PrivateDependencyModuleNames.Add("OnlineSubsystem");

        // To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
    }
}
