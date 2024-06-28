#include "LaunchEngineLoop.h"

class LAUNCH_API UTest : public UObject
{
public:
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UTest);
	static UClass* StaticClass() { return UTestRegisterEngineClass; }
	static inline UClass* UTestRegisterEngineClass = GetPrivateStaticClassBody<UTest>(TEXT("UTest"),
		(UClass::ClassConstructorType)InternalConstructor<UTest>, &UObject::StaticClass, nullptr);

	UTest() {}
	int a = 0;
};
class LAUNCH_API UNoTest : public UObject
{
public:
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UNoTest);
	static UClass* StaticClass() { return UNoTestRegisterEngineClass; }
	static inline UClass* UNoTestRegisterEngineClass = GetPrivateStaticClassBody<UNoTest>(TEXT("UNoTest"),
		(UClass::ClassConstructorType)InternalConstructor<UNoTest>, &UObject::StaticClass, nullptr);

	UNoTest() {}
	int a = 0;
};
class LAUNCH_API UTest2 : public UTest
{
public:
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UTest2);
	static UClass* StaticClass() { return UTest2RegisterEngineClass; }
	static inline UClass* UTest2RegisterEngineClass = GetPrivateStaticClassBody<UTest2>(TEXT("UTest2"),
		(UClass::ClassConstructorType)InternalConstructor<UTest2>, &UTest::StaticClass, nullptr);

	UTest2() {}
	~UTest2() {}
	int b = 0;
};

extern CORE_API map<FString, UClass*> MapClass;

int32 FEngineLoop::PreInit(const TCHAR* /*CmdLine*/)
{
	for (auto& It : MapClass)
	{
		It.second->GetDefaultObject(false);
	}

	UClass* UTest2Class = MapClass[TEXT("UTest2")];
	UClass* UNoTestClass = MapClass[TEXT("UNoTest")];
	TSubclassOf<UTest> TestClass = UTest2Class;
	TSubclassOf<UTest> TestClass2 = UNoTestClass;
	UClass* T = *TestClass;
	UClass* T2 = *TestClass2;
	bool bChild = UTest2Class->IsChildOf<UTest>();
	bool bChild2 = UTest2Class->IsChildOf<UNoTest>();

	UObject* Test2 = UTest2Class->GetDefaultObject();
	UObject* Test3 = UNoTestClass->GetDefaultObject();

	bool b = Test2->IsA<UTest>();
	return 0;
}

int32 FEngineLoop::Init()
{
	return 0;
}

void FEngineLoop::Tick()
{
}

void FEngineLoop::Exit()
{
	for (auto& It : MapClass)
	{
		It.second->~UClass();
		GUObjectArray.Free(typeid(UClass), It.second);
	}
	MapClass.clear();
	GUObjectArray.Destroy();
}
