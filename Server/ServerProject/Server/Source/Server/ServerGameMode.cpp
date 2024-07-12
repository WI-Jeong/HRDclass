#include "ServerGameMode.h"

void AServerGameMode::BeginPlay()
{
	Super::BeginPlay();

	// DB
	{
		FNetworkNotify NetworkNotify = FNetworkNotify
		(
			[this](UNetDriver*, UNetConnection*) {},
			[this](UNetDriver*, UNetConnection*) {},
			[this](UNetDriver*, UNetConnection*, FPacketHeader*) {}
			);

		FURL_DB URL;
		const FString ConfigKey = TEXT("LoginServerDB");
		if (GConfig->LoadIniFile(ConfigKey, TEXT("LoginServerDB.ini")))
		{
			FConfigFile& Config = GConfig->GetConfig(TEXT("LoginServerDB"));
			Config.Get("DBSettings", "Host", URL.Host);
			Config.Get("DBSettings", "Port", URL.Port);
			Config.Get("DBSettings", "ID", URL.ID);
			Config.Get("DBSettings", "Password", URL.Password);
			GConfig->UnLoadIniFile(ConfigKey);
		}

		DBNetDriver = NewObject<UDBNetDriver>(this);
		if (!DBNetDriver->InitConnect(NetworkNotify, URL))
		{
			RequestEngineExit("DBNetDriver connect failed");
		}
	}

	{
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
		NetDriver->InitListen(NetworkNotify, URL, true, 5);

		auto& Vector = ObjectMap[UNetDriver::StaticClass()];
		for (engine_weak_ptr<UObject> It : Vector)
		{
			engine_weak_ptr<UNetDriver> ItNet = Cast<UNetDriver>(It);
		}
	}
}

void AServerGameMode::OnRecv(UNetDriver* InNetDriver, UNetConnection* InNetConnection, FPacketHeader* InPacketHeader)
{
	EARPacketType PacketType = (EARPacketType)InPacketHeader->GetPacketID();
	switch (PacketType)
	{
	case EARPacketType::EMessage:
	{
		FMessagePacket* MessagePacket = (FMessagePacket*)InPacketHeader;
		string Message = string(MessagePacket->Buffer.begin(), MessagePacket->Buffer.end());
		E_LOG(trace, "{}", Message);

		MessagePacket->Buffer[12] = '2';

		NetDriver->Send(InNetConnection, InPacketHeader);
		break;
	}
	case EARPacketType::ELogin:
	{
		struct FCreateAccountPacket : public FAccountPacket
		{
			FCreateAccountPacket() {}
		};
		FCreateAccountPacket* Packet = (FCreateAccountPacket*)InPacketHeader;
		if (!CheckPacket(*Packet))
		{
			InNetDriver->KickNetConnection(InNetConnection, "Check packet failed");
			break;
		}

		E_LOG(trace, "ID: {}, Password: {}", Packet->ID.data(), Packet->Password.data());
		if (Packet->ID.empty() || Packet->Password.empty())
		{
			InNetDriver->KickNetConnection(InNetConnection, "ID or Password is empty");
			break;
		}
		// 문자열 길이 확인

		// 회원가입 처리

		break;
	}
	default:
		E_LOG(error, "Unsupport packet type.");
		break;
	}
}

void AServerGameMode::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	DBNetDriver->Tick(DeltaSeconds);
	NetDriver->Tick(DeltaSeconds);

	//if (GetAsyncKeyState(VK_SPACE) & 0x8000)
	//{
	//	RequestEngineExit("Test");
	//}
}

AServerGameMode::AServerGameMode()
{

}

AServerGameMode::~AServerGameMode()
{
	
}