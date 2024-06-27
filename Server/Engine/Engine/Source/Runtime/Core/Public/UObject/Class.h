#pragma once
#include "UObject.h"
#include "UObjectArray.h"

/**
 * An object class.
 */
class UClass : public UObject
{
private:
	UClass* SuperClass;
	shared_ptr<UObject> ClassDefaultObject;

public:
	FString ClassName;
	const type_info& ClassTypeInfo;
	const uint64 ClassSize;

	using ClassConstructorType = function<void(const FObjectInitializer&)>;
	ClassConstructorType ClassConstructor;

	using StaticClassFunctionType = function<UClass* (void)>;

	UClass() = delete;
	CORE_API UClass(FString InClassName, const type_info& InClassTypeInfo,
		const uint64 InClassSize, ClassConstructorType InClassConstructor,
		StaticClassFunctionType InSuperClassFunction);
	~UClass() {}
	UClass* GetSuperClass() const { return SuperClass; }

	template<class T>
	T* GetDefaultObject() { return (T*)GetDefaultObject(); }
	CORE_API UObject* GetDefaultObject(bool bNoCreate = true) const;

	/** Returns true if this class either is class T, or is a child of class T. This will not crash on null class */
	template<class T>
	bool IsChildOf() const { return IsChildOf(T::StaticClass()); }
	CORE_API bool IsChildOf(const UClass* SomeBase) const { _ASSERT(false); return false; }

protected:
	CORE_API void InternalCreateDefaultObjectWrapper() const;
	CORE_API UObject* CreateDefaultObject();
};

CORE_API UClass* RegisterEngineClass(
	FString InClassName,
	UClass::ClassConstructorType InClassConstructor,
	UClass::StaticClassFunctionType InSuperClassFunction,
	function<void()> InClassReflection,
	const type_info& InClassTypeInfo,
	const uint64 InClassSize
);

template<class T>
UClass* GetPrivateStaticClassBody(
	FString InClassName,
	UClass::ClassConstructorType InClassConstructor,
	UClass::StaticClassFunctionType InSuperClassFunction,
	function<void()> InClassReflection)
{
	const type_info& ClassTypeInfo = typeid(T);
	const uint64 ClassSize = sizeof(T);

	UClass* NewClass = RegisterEngineClass(InClassName, InClassConstructor, InSuperClassFunction, InClassReflection,
		ClassTypeInfo, ClassSize);

	return NewClass;
}

template<class T>
void InternalConstructor(const FObjectInitializer& X)
{
	FObjectInitializer* ObjectInitializer = const_cast<FObjectInitializer*>(&X);
	ObjectInitializer->SharedObj = allocate_shared<T>(FAllocator<T>(ObjectInitializer));
}