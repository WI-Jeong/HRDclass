#include "LaunchEngineLoop.h"

extern CORE_API map<FString, UClass*> MapClass;

int32 FEngineLoop::PreInit(const TCHAR* /*CmdLine*/)
{
	// Create CDO
	for (auto& It : MapClass)
	{
		It.second->GetDefaultObject(false);
	}

	return 0;
}

int32 FEngineLoop::Init()
{
	UClass* Test = UEngine::StaticClass();

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
