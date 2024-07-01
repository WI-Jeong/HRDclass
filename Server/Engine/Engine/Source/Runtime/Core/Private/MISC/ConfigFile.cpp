#include "MISC/ConfigFile.h"
#include "UObject/UObjectGlobals.h"
#include "Logging/Logger.h"

bool FConfigFile::Load(FStringView InPath)
{
    bLoaded = File.load(to_string(InPath));
    return bLoaded;
}

bool FConfigFile::TryOverride(FStringView InPath)
{
    if (!bLoaded)
    {
        E_Log(error, "bLoaded is false. {}", InPath);
        return false;
    }

    if (bOverride)
    {
        E_Log(error, "bOverride is true. {}", InPath);
        return false;
    }

    bOverride = OverrideFile.load(to_string(InPath));
    return bOverride;
}
