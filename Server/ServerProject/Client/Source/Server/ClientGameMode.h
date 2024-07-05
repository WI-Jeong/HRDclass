#pragma once
// AssortRock Inc.

#include "EngineMinimal.h"
#include "NetworkMinimal.h"
#include "ClientGameMode.generated.h"

UCLASS()
class CLIENTPROJECT_API AClientGameMode : public AGameModeBase
{
	GENERATED_BODY();

public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds);

	AClientGameMode();
	~AClientGameMode();

	shared_ptr<UNetDriver> NetDriver;
	engine_weak_ptr<UNetConnection> ClientConnection;
};