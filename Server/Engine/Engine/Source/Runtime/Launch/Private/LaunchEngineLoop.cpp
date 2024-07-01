#include "LaunchEngineLoop.h"

extern CORE_API map<FString, UClass*> MapClass;

int32 FEngineLoop::PreInit(const TCHAR* /*CmdLine*/)
{
	// 설정 파일 로드
	FConfigCacheIni::InitializeConfigSystem();

	// User DLL을 load

	// Create CDO
	for (auto& It : MapClass)
	{
		It.second->GetDefaultObject(false);
	}

	return 0;
}

int32 FEngineLoop::Init()
{
	Engine = NewObject<UEngine>(nullptr);
	GEngine = Engine.get();

	// GameInstance를 생성, World 생성
	Engine->Init();

	// World에 GameMode를 지정
	//////// [SERVER] World->Listen()
	Engine->Start();

	return 0;
}

void FEngineLoop::Tick()
{
	// RequestEngineExit("Test");
	Engine->Tick(0.);
}

void FEngineLoop::Exit()
{
	Engine->PreExit();
	Engine = nullptr;
	GEngine = nullptr;

	for (auto& It : MapClass)
	{
		It.second->~UClass();
		GUObjectArray.Free(typeid(UClass), It.second);
	}
	MapClass.clear();
	GUObjectArray.Destroy();

	FConfigCacheIni::DestroyConfigSystem();
}
