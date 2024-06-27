#include "LaunchEngineLoop.h"

FEngineLoop EngineLoop;

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
	int b = 0;
};

extern CORE_API map<FString, UClass*> MapClass;
/**
 * PreInits the engine loop
 */
int32 EnginePreInit(const TCHAR* CmdLine)
{
	E_Log(trace, "");
	const int32 ErrorLevel = EngineLoop.PreInit(CmdLine);

	GetPrivateStaticClassBody<UTest2>(TEXT("UTest2"),
		(UClass::ClassConstructorType)InternalConstructor<UTest2>, nullptr, nullptr);

	UClass* Class = MapClass[TEXT("UTest2")];
	UObject* Object = Class->GetDefaultObject(false);

	return ErrorLevel;
}

/**
 * Inits the engine loop
 */
int32 EngineInit()
{
	E_Log(trace, "");
	const int32 ErrorLevel = EngineLoop.Init();

	return ErrorLevel;
}

/**
 * Ticks the engine loop
 */
void EngineTick()
{
	E_Log(trace, "");
	EngineLoop.Tick();
}

/**
 * Shuts down the engine
 */
void EngineExit()
{
	E_Log(trace, "");
	EngineLoop.Exit();
}

int32 LAUNCH_API GuardedMain(const TCHAR* CmdLine)
{
	int32 ErrorLevel = 0;

	// 초기화
	ErrorLevel = EnginePreInit(CmdLine);
	if (ErrorLevel != 0) { return ErrorLevel; }
	ErrorLevel = EngineInit();
	if (ErrorLevel != 0) { return ErrorLevel; }

	// 시뮬레이션
	EngineTick();

	// 종료
	EngineExit();

	return ErrorLevel;
}