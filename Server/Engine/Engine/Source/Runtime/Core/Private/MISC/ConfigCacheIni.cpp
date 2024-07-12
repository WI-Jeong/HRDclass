#include "MISC/ConfigCacheIni.h"
#include "MISC/Paths.h"
#include "Logging/Logger.h"
#include "UObject/UObjectGlobals.h"

CORE_API FConfigCacheIni* GConfig = nullptr;

void FConfigCacheIni::InitializeConfigSystem()
{
	if (GConfig)
	{
		E_LOG(error, "GConfig exist");
		return;
	}

	GConfig = new FConfigCacheIni;
	if (GConfig->LoadIniFile(GEngineIni, GBaseEngineIni))
	{
		GConfig->LoadIniFile(GEngineIni, GDefaultEngineIni, true);
	}
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
		bLoad = ConfigFile.Load(LoadIniFilePath);
		if (!bLoad)
		{
			E_LOG(error, "Load Failed: {}", to_string(LoadIniFilePath));
		}
	}
	else
	{
		bLoad = ConfigFile.TryOverride(LoadIniFilePath);
	}

	return bLoad;
}

bool FConfigCacheIni::UnLoadIniFile(FStringView InKey)
{
	auto It = MapCachedConfig.find(InKey.data());
	if (It == MapCachedConfig.end())
	{
		E_LOG(fatal, "{} not found", to_string(InKey));
		return false;
	}
	MapCachedConfig.erase(It);
	return true;
}

FConfigFile& FConfigCacheIni::GetConfig(FStringView InKey)
{
	if (MapCachedConfig.find(InKey.data()) == MapCachedConfig.end())
	{
		E_LOG(fatal, "{} not found", to_string(InKey));
	}

	return MapCachedConfig[InKey.data()];
}
