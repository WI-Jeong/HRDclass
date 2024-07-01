#include "MISC/ConfigCacheIni.h"
#include "MISC/Paths.h"
#include "Logging/Logger.h"
#include "UObject/UObjectGlobals.h"

CORE_API FConfigCacheIni* GConfig = nullptr;

void FConfigCacheIni::InitializeConfigSystem()
{
	if (GConfig)
	{
		E_Log(error, "GConfig exist");
		return;
	}

	GConfig = new FConfigCacheIni;
}

void FConfigCacheIni::DestroyConfigSystem()
{
	if (GConfig)
	{
		delete GConfig;
		GConfig = nullptr;
	}
}

bool FConfigCacheIni::LoadIniFile(FStringView InKey, const FString& InIniFileName, const bool bTryOverride)
{
	FConfigFile& ConfigFile = MapCachedConfig[InKey.data()];

	const FString LoadIniFilePath = FPaths::EngineConfigDir() + TEXT("\\") + InIniFileName;

	bool bLoad = false;

	if (!bTryOverride)
	{
		//bLoad = ConfigFile.Load(LoadIniFilePath);
		if (!bLoad)
		{
			E_Log(error, "Load Failed: {}", LoadIniFilePath);
		}
	}
	else
	{
		//bLoad = ConfigFile.TryOverride(LoadIniFilePath);
	}

	return bLoad;
}

FConfigFile& FConfigCacheIni::GetConfig(FStringView InKey)
{
	if (MapCachedConfig.find(InKey.data()) == MapCachedConfig.end())
	{
		string String = to_string(InKey);
		E_Log(fatal, "{} not found", String);
	}

	return MapCachedConfig[InKey.data()];
}
