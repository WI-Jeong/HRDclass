#pragma once
// AssortRock Inc.

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "World.generated.h"

class UGameInstance;

UCLASS()
class ENGINE_API UWorld : public UObject
{
	GENERATED_BODY();

public:
	UWorld();
	~UWorld();

	void SetGameInstance(engine_weak_ptr<UGameInstance> NewGI);
	void SetGameMode(TSubclassOf<AGameModeBase> NewGameModeClass);

private:
	engine_weak_ptr<UGameInstance> OwningGameInstance;
};