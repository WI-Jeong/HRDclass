#pragma once
// AssortRock Inc.

#include "EngineMinimal.h"
#include "NetworkMinimal.h"
#include "ServerGameMode.generated.h"

UCLASS()
class SERVERPROJECT_API AServerGameMode : public AGameModeBase
{
	GENERATED_BODY();

public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds);

	void OnRecv(UNetDriver* InNetDriver, UNetConnection* InNetConnection, FPacketHeader* InPacketHeader);

	AServerGameMode();
	~AServerGameMode();

	shared_ptr<UNetDriver> NetDriver;
};