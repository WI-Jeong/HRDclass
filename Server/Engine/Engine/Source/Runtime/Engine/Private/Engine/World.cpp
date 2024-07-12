﻿#include "Engine/World.h"
#include "Engine/GameInstance.h"

UWorld::UWorld()
{

}

UWorld::~UWorld()
{
	
}

void UWorld::Tick(float DeltaSeconds)
{
	for (auto It : MapActors)
	{
		It.second->Tick(DeltaSeconds);
	}
}

void UWorld::SetGameInstance(engine_weak_ptr<UGameInstance> NewGI)
{
	OwningGameInstance = NewGI;
}

void UWorld::SetGameMode(TSubclassOf<AGameModeBase> NewGameModeClass)
{
	if (GameMode.IsValid())
	{
		E_LOG(fatal, "GameMode is valid.");
		return;
	}

	GameMode = SpawnActor<AGameModeBase>(NewGameModeClass);
}

engine_weak_ptr<AActor> UWorld::SpawnActor(UClass* InClass, const FActorSpawnParameters& SpawnParameters)
{
	if (!InClass)
	{
		E_LOG(error, "Class is nullptr");
	}

	shared_ptr<AActor> NewActor = NewObject<AActor>(this, InClass, SpawnParameters.Name, SpawnParameters.ObjectFlags);
	FString ActorName = NewActor->GetName();
	MapActors.insert(make_pair(ActorName, NewActor));

	NewActor->BeginPlay();

	return NewActor;
}
