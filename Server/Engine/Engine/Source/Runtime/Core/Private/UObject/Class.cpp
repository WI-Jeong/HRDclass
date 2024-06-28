#include "UObject/Class.h"
#include "UObject/UObjectArray.h"

CORE_API map<FString, UClass*> MapClass;

UClass::UClass(FString InClassName, const type_info& InClassTypeInfo, const uint64 InClassSize, ClassConstructorType InClassConstructor, StaticClassFunctionType InSuperClassFunction)
	: SuperClass(nullptr)
	, ClassDefaultObject(nullptr)
	, ClassName(InClassName)
	, ClassTypeInfo(InClassTypeInfo)
	, ClassSize(InClassSize)
	, ClassConstructor(InClassConstructor)
{
	if (InSuperClassFunction)
	{
		SuperClass = InSuperClassFunction();
	}
}

UObject* UClass::GetDefaultObject(bool bNoCreate) const
{
	if (ClassDefaultObject == nullptr && !bNoCreate)
	{
		// CDO를 만든다
		InternalCreateDefaultObjectWrapper();
	}
	return ClassDefaultObject.get();
}

CORE_API bool UClass::IsChildOf(const UClass* SomeBase) const
{
	_ASSERT(this);

	if (SomeBase == nullptr)
	{
		return false;
	}

	bool bOldResult = false;
	for (const UClass* TempClass = this; TempClass; TempClass = TempClass->GetSuperClass())
	{
		if (TempClass == SomeBase)
		{
			bOldResult = true;
			break;
		}
	}

	return bOldResult;
}

CORE_API void UClass::InternalCreateDefaultObjectWrapper() const
{
	const_cast<UClass*>(this)->CreateDefaultObject();
}

CORE_API UObject* UClass::CreateDefaultObject()
{
	_ASSERT(!ClassDefaultObject);

	const uint64 SharedPtrSize = sizeof(_Ref_count_obj_alloc3<UObject, FAllocator<UObject>>) - sizeof(UObject);
	GUObjectArray.Create(ClassTypeInfo, SharedPtrSize + ClassSize);

	FStaticConstructObjectParameters StaticConstructObjectParameters{ this };
	StaticConstructObjectParameters.SetFlags = EObjectFlags::RF_ClassDefaultObject;

	FObjectInitializer ObjectInitializer{ StaticConstructObjectParameters };
	ClassConstructor(ObjectInitializer);

	ClassDefaultObject = ObjectInitializer.SharedObj;

	return ClassDefaultObject.get();
}

CORE_API UClass* RegisterEngineClass(FString InClassName,
	UClass::ClassConstructorType InClassConstructor,
	UClass::StaticClassFunctionType InSuperClassFunction,
	function<void()> InClassReflection,
	const type_info& InClassTypeInfo, const uint64 InClassSize)
{
	GUObjectArray.Create(typeid(UClass), sizeof(UClass));
	UObjectBase* ObjectBase = (UObjectBase*)GUObjectArray.Malloc(typeid(UClass));

	new(ObjectBase)UObjectBase(nullptr, EObjectFlags::RF_Class, nullptr);

	UClass* NewClass = new(ObjectBase)UClass(InClassName, InClassTypeInfo, InClassSize,
		InClassConstructor, InSuperClassFunction);
	NewClass->Name = TEXT("UClass");

	MapClass.insert(make_pair(InClassName, NewClass));

	return NewClass;
}
