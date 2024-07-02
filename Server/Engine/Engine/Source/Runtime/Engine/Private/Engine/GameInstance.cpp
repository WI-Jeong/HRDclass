#include "Engine/GameInstance.h"
#include "Engine/Engine.h"
#include "Engine/GameMapsSettings.h"

void UGameInstance::Initailize()
{
	// World 생성
	UEngine* Engine = GetEngine();
	Engine->World = NewObject<UWorld>(this);
	World = Engine->World;
	World->SetGameInstance(Cast<UGameInstance>(this));
}

void UGameInstance::StartGameInstance()
{
	// World에 GameMode를 등록
	World->SetGameMode(GetDefault<UGameMapsSettings>()->GameModeClass);
}

UEngine* UGameInstance::GetEngine()
{
	return (UEngine*)GetOuter();
}

UGameInstance::UGameInstance()
{

}

UGameInstance::~UGameInstance()
{
	
}