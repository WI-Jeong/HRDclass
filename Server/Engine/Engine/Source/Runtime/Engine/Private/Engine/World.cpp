#include "Engine/World.h"
#include "Engine/GameInstance.h"

UWorld::UWorld()
{

}

UWorld::~UWorld()
{
	
}

void UWorld::SetGameInstance(engine_weak_ptr<UGameInstance> NewGI)
{
	OwningGameInstance = NewGI;
}

void UWorld::SetGameMode(TSubclassOf<AGameModeBase> NewGameModeClass)
{
}
