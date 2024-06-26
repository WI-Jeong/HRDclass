#pragma once
#include "UObject.h"

/**
 * An object class.
 */
class UClass : public UObject
{
private:
	UClass* SuperClass;
	UObject* ClassDefaultObject;

public:
	FStringView ClassName;
	const type_info& ClassTypeInfo;
	const uint64 ClassSize;

	using ClassConstructorType = function<void(const FObjectInitializer&)>;
	ClassConstructorType ClassConstructor;

	using StaticClassFunctionType = function<UClass* (void)>;

	UClass() = delete;
	CORE_API UClass(FStringView InClassName, const type_info& InClassTypeInfo,
		const uint64 InClassSize, ClassConstructorType InClassConstructor,
		StaticClassFunctionType InSuperClassFunction);

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