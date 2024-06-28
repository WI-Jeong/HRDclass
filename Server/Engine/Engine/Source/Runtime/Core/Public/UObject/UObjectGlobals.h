#pragma once
#include "CoreTypes.h"

class UClass;
class UObject;
struct CORE_API FStaticConstructObjectParameters
{
	UClass* Class = nullptr;
	UObject* Outer = nullptr;
	FString Name;
	EObjectFlags SetFlags = RF_NoFlags;

	FStaticConstructObjectParameters(UClass* InClass);
};

struct CORE_API FObjectInitializer
{
	UClass* Class = nullptr;
	/** Object this object resides in. */
	UObject* OuterPrivate = nullptr;
	EObjectFlags ObjectFlags = EObjectFlags::RF_NoFlags;
	FString Name;

	UObject* GetObj() const { return Obj; }

	FObjectInitializer() {}
	FObjectInitializer(const EObjectFlags InObjectFlags);
	FObjectInitializer(const FStaticConstructObjectParameters& StaticConstructParams);

	// FObjectInitializer를 사용해서 신규로 만들어진 UObject 객체
	shared_ptr<UObject> SharedObj;

	// FAllocator 내부에서 MamoryPool로 부터 얻어온 주소(shared_ptr 크기를 고려해서 계산된 주소)
	UObject* Obj = nullptr;
};

template<typename T>
shared_ptr<T> NewObject(UObject* Outer, UClass* Class = nullptr, FString Name = NAME_NONE, EObjectFlags Flags = RF_NoFlags)
{
	if (!Class)
	{
		Class = T::StaticClass();
	}

	FStaticConstructObjectParameters Params(Class);
	Params.Outer = Outer;
	Params.Name = Name;
	Params.SetFlags = Flags;
	// 
}