#include "ClientGameMode.h"

void AClientGameMode::BeginPlay()
{
	Super::BeginPlay();

	NetDriver = NewObject<UNetDriver>(this);
	FNetworkNotify NetworkNotify;
	FURL URL;
	if (!NetDriver->InitConnect(NetworkNotify, URL))
	{
		RequestEngineExit("Connect failed");
		return;
	}

	auto& Vector = ObjectMap[UNetDriver::StaticClass()];
	for (engine_weak_ptr<UObject> It : Vector)
	{
		engine_weak_ptr<UNetDriver> ItNet = Cast<UNetDriver>(It);
	}
}

void AClientGameMode::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	NetDriver->Tick(DeltaSeconds);
}

AClientGameMode::AClientGameMode()
{

}

AClientGameMode::~AClientGameMode()
{
	
}