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

	ClientConnection = NetDriver->GetClientConnection();
	NetDriver->Send(ClientConnection.Get(), FPacketHeader::EHelloPacket, nullptr, 0);
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