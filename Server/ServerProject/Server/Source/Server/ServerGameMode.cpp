#include "ServerGameMode.h"

void AServerGameMode::BeginPlay()
{
	Super::BeginPlay();

	NetDriver = NewObject<UNetDriver>(this);
	FNetworkNotify NetworkNotify;
	FURL URL;
	NetDriver->InitListen(NetworkNotify, URL, true, 5);
}

AServerGameMode::AServerGameMode()
{

}

AServerGameMode::~AServerGameMode()
{
	
}