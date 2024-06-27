#include "UObject/UObjectGlobals.h"
#include "UObject/Class.h"
#include "Logging/Logger.h"

FStaticConstructObjectParameters::FStaticConstructObjectParameters(UClass* InClass)
	: Class(InClass)
{
	if (!Class)
	{
		E_Log(error, "Class is nullptr")
	}
}

FObjectInitializer::FObjectInitializer(const EObjectFlags InObjectFlags)
	: ObjectFlags(InObjectFlags)
{
}

FObjectInitializer::FObjectInitializer(const FStaticConstructObjectParameters& StaticConstructParams)
	: Class(StaticConstructParams.Class)
	, OuterPrivate(StaticConstructParams.Outer)
	, ObjectFlags(StaticConstructParams.SetFlags)
	, Name(StaticConstructParams.Name)
{
}
