#include "LaunchEngineLoop.h"

extern CORE_API map<FString, UClass*> MapClass;

int32 FEngineLoop::PreInit(const TCHAR* /*CmdLine*/)
{
#if WITH_DEBUG
	_CrtSetDbgFlag(_CrtSetDbgFlag(_CRTDBG_REPORT_FLAG) | _CRTDBG_LEAK_CHECK_DF);
	//_crtBreakAlloc = 377;

	// 메모리릭 탐지 검증
	int* Test = new int;
#endif
	FLogger::InitializeLogSystem();
	FTaskManager::Get();
	FConfigCacheIni::InitializeConfigSystem();

	// User DLL을 load
	const FString& ProejctDllDir = FPaths::ProjectDllDir();
	if (filesystem::is_directory(ProejctDllDir))
	{
		for (const auto& It : filesystem::directory_iterator(ProejctDllDir))
		{
			if (It.path().extension() == TEXT(".dll"))
			{
				LoadLibrary(It.path().c_str());
			}
		}
	}
	
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
	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
	{
		RequestEngineExit("Test");
	}
	Engine->Tick(0.);
}

void FEngineLoop::Exit()
{
	ObjectMap.clear();

	if (Engine)
	{
		Engine->PreExit();
		Engine = nullptr;
		GEngine = nullptr;
	}

	for (auto& It : MapClass)
	{
		It.second->~UClass();
		GUObjectArray.Free(typeid(UClass), It.second);
	}
	MapClass.clear();
	GUObjectArray.Destroy();

	FConfigCacheIni::DestroyConfigSystem();
	FTaskManager::Get(true);
	FLogger::DestroyLogSystem();
}
