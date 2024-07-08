#include "ClientGameMode.h"

void AClientGameMode::BeginPlay()
{
	Super::BeginPlay();

	NetDriver = NewObject<UNetDriver>(this);
	FNetworkNotify NetworkNotify(
		[this](UNetDriver*, UNetConnection*)
		{
		},
		[this](UNetDriver*, UNetConnection*)
		{
		},
		[this](UNetDriver*, UNetConnection*, FPacketHeader*)
		{
		});
	FURL URL;
	if (!NetDriver->InitConnect(NetworkNotify, URL))
	{
		RequestEngineExit("Connect failed");
		return;
	}

	ClientConnection = NetDriver->GetClientConnection();
}

void AClientGameMode::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	NetDriver->Tick(DeltaSeconds);
	//RequestEngineExit("");
}

AClientGameMode::AClientGameMode()
{

}

AClientGameMode::~AClientGameMode()
{
	
}