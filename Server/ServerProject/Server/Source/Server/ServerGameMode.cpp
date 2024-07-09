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
	EMyPacketType PacketType = (EMyPacketType)InPacketHeader->GetPacketID();
	switch (PacketType)
	{
	case EMyPacketType::EMessage:
	{
		FMessagePacket* MessagePacket = (FMessagePacket*)InPacketHeader;
		string Message = string(MessagePacket->Buffer.begin(), MessagePacket->Buffer.end());
		E_Log(trace, "{}", Message);

		MessagePacket->Buffer[11] = '2';

		InNetConnection->Send(InPacketHeader);
		break;
	}
	default:
		E_Log(error, "Unsupport packet type.");
		break;
	}
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