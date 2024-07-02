#include "UObject/UObject.h"

UObjectBase::UObjectBase(UClass* InClass, EObjectFlags InObjectFlags, UObject* InOuter)
	: ObjectFlags(InObjectFlags)
	, OuterPrivate(InOuter)
	, ClassPrivate(InClass)
{
}
