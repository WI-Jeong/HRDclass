#include "MISC/ConfigFile.h"
#include "UObject/UObjectGlobals.h"
#include "Logging/Logger.h"

bool FConfigFile::Load(FStringView InPath)
{
    if (bLoaded)
    {
        E_Log(error, "bLoaded is true {}", to_string(InPath));
        return false;
    }

    bLoaded = File.load(to_string(InPath));
    return bLoaded;
}

bool FConfigFile::TryOverride(FStringView InPath)
{
    if (!bLoaded)
    {
        E_Log(error, "bLoaded is false. {}", to_string(InPath));
        return false;
    }

    if (bOverride)
    {
        E_Log(error, "bOverride is true. {}", to_string(InPath));
        return false;
    }

    bOverride = OverrideFile.load(to_string(InPath));
    return bOverride;
}

bool FConfigFile::Get(const ANSICHAR* InSection, const ANSICHAR* InKey, ini::IniField& OutField)
{
    if (bOverride)
    {
        bool bFind = Get(OverrideFile, InSection, InKey, OutField);
        if (bFind) { return true; }
    }

    return Get(File, InSection, InKey, OutField);
}

bool FConfigFile::Get(ini::IniFile& InTarget, const ANSICHAR* InSection, const ANSICHAR* InKey, ini::IniField& OutField)
{
    auto& It = InTarget[InSection];
    if (It.empty())
    {
        return false;
    }

    if (It.find(InKey) == It.end())
    {
        return false;
    }

    OutField = It[InKey];

    return true;
}