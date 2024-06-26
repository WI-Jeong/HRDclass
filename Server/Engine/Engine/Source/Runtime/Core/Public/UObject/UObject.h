#pragma once
#include "CoreTypes.h"

class UClass;
class UObject;

struct CORE_API FObjectInitializer
{
	UClass* Class = nullptr;
	EObjectFlags ObjectFlags = EObjectFlags::RF_NoFlags;

	/** Object this object resides in. */
	UObject* OuterPrivate = nullptr;
	FString Name;

	FObjectInitializer() {}
	FObjectInitializer(const EObjectFlags InObjectFlags);
};

// 의도된 사항으로 일부 경고를 무시합니다.
#pragma warning(disable:26495)
class CORE_API UObjectBase : public std::enable_shared_from_this<UObjectBase>
{
public:
	UObjectBase() {}
	UObjectBase(UClass* InClass, EObjectFlags InObjectFlags, UObject* InOuter);
	virtual ~UObjectBase() {}

	EObjectFlags GetFlags() const { return ObjectFlags; }
	UObject* GetOuter() const { return OuterPrivate; }
	UClass* GetClass() const { return Class; }

protected:
	EObjectFlags ObjectFlags;
	/** Object this object resides in. */
	UObject* OuterPrivate;
	UClass* Class;
};
#pragma warning(default:26495)

class CORE_API UObject : public UObjectBase
{
public:
	UObject() {}

	bool HasAnyFlags(const EObjectFlags FlagToCheck) const
	{
		return (GetFlags() & FlagToCheck) != 0;
	}

	const FString& GetName() const { return Name; }

	FString Name;
};