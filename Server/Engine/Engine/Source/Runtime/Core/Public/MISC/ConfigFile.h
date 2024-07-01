#pragma once
#include "CoreTypes.h"

class CORE_API FConfigFile
{
public:
	bool Load(FStringView InPath);
	bool TryOverride(FStringView InPath);

private:
	bool bLoaded = false;
	bool bOverride = false;

	ini::IniFile File;
	ini::IniFile OverrideFile;
};