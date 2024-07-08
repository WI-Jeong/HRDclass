#include "ServerGameMode.h"

void AServerGameMode::BeginPlay()
{
	Super::BeginPlay();

	NetDriver = NewObject<UNetDriver>(this);
	FNetworkNotify NetworkNotify = FNetworkNotify
	(
		[this](UNetDriver*, UNetConnection*) 
		{
		},
		[this](UNetDriver*, UNetConnection*)
		{
		}, 
		bind(&ThisClass::OnRecv, this, placeholders::_1, placeholders::_2, placeholders::_3)
	);

	FURL URL;
	NetDriver->InitListen(NetworkNotify, URL, true, 1);

	auto& Vector = ObjectMap[UNetDriver::StaticClass()];
	for (engine_weak_ptr<UObject> It : Vector)
	{
		engine_weak_ptr<UNetDriver> ItNet = Cast<UNetDriver>(It);
	}
}

void AServerGameMode::OnRecv(UNetDriver* InNetDriver, UNetConnection* InNetConnection, FPacketHeader* InPacketHeader)
{

}

void AServerGameMode::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	NetDriver->Tick(DeltaSeconds);
}

AServerGameMode::AServerGameMode()
{

}

AServerGameMode::~AServerGameMode()
{
	
}