#include "LaunchEngineLoop.h"

class LAUNCH_API UTest : public UObject
{
public:
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UTest);
	//static void __DefaultConstructor(const FObjectInitializer& X) { new((EInternal*)X.GetObj())UTest; }
	UTest() {}
	int a = 0;
};
class LAUNCH_API UTest2 : public UTest
{
public:
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UTest2);
	//static void __DefaultConstructor(const FObjectInitializer& X) { new((EInternal*)X.GetObj())UTest; }
	UTest2() {}
	~UTest2() {}
	int b = 0;
};

extern CORE_API map<FString, UClass*> MapClass;

int32 FEngineLoop::PreInit(const TCHAR* /*CmdLine*/)
{
	GetPrivateStaticClassBody<UTest2>(TEXT("UTest2"),
		(UClass::ClassConstructorType)InternalConstructor<UTest2>, nullptr, nullptr);

	UClass* Class = MapClass[TEXT("UTest2")];
	UObject* Object = Class->GetDefaultObject(false);

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