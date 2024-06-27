#include "LaunchEngineLoop.h"

FEngineLoop EngineLoop;

class LAUNCH_API UTest : public UObject
{
public:
	int a = 0;
};

extern CORE_API map<FString, UClass*> MapClass;
/**
 * PreInits the engine loop
 */
int32 EnginePreInit(const TCHAR* CmdLine)
{
	E_Log(trace, "");
	const int32 ErrorLevel = EngineLoop.PreInit(CmdLine);

	GetPrivateStaticClassBody<UTest>(TEXT("UTest"),
		(UClass::ClassConstructorType)InternalConstructor<UTest>, nullptr, nullptr);

	UClass* Class = MapClass[TEXT("UTest")];
	UObject* Object = Class->GetDefaultObject(false);

	/*UClass Test = UClass(TEXT("Test"), typeid(UObject), sizeof(UObject), nullptr, nullptr);
	UObject* Obj = Test.GetDefaultObject(false);*/

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