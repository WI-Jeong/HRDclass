#include "UObject/UObject.h"

UObjectBase::UObjectBase(UClass* InClass, EObjectFlags InObjectFlags, UObject* InOuter, const FString& InName)
	: ObjectFlags(InObjectFlags)
	, OuterPrivate(InOuter)
	, ClassPrivate(InClass)
	, NamePrivate(InName)
{
}
