#include "Engine/Engine.h"
#include "Engine/GameMapsSettings.h"

UEngine* GEngine = nullptr;

UEngine::UEngine()
{

}

void UEngine::Init()
{
	GameInstance = NewObject<UGameInstance>(this, GetDefault<UGameMapsSettings>()->GameInstanceClass);
	GameInstance->Initailize();
}

void UEngine::Start()
{
	GameInstance->StartGameInstance();
}

void UEngine::Tick(float DeltaSeconds)
{
	// World -> Tick
}

void UEngine::PreExit()
{
}
