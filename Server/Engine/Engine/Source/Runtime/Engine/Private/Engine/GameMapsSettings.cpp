#include "Engine/GameMapsSettings.h"

UGameMapsSettings::UGameMapsSettings()
{
	{
		FString ClassName;
		GConfig->GetConfig(GEngineIni).Get("/Script/EngineSettings.GameMapsSettings", "GameInstanceClass", ClassName);
		E_LOG(trace, "{} GameInstance class", to_string(ClassName));
		GameInstanceClass = UClass::FindClass(ClassName);
	}
	{
		FString ClassName;
		GConfig->GetConfig(GEngineIni).Get("/Script/EngineSettings.GameMapsSettings", "GameModeClass", ClassName);
		E_LOG(trace, "{} GameMode class", to_string(ClassName));
		GameModeClass = UClass::FindClass(ClassName);
	}
}