#include "NetDriver.h"

bool UNetDriver::InitListen(FNetworkNotify InNotify, 
	FURL& ListenURL, const bool bReuseAddressAndPort, const uint8 BacklogCount, 
	TSubclassOf<UNetConnection> InNetConnectionClass)
{
	NetworkNotify = InNotify;
	URL = ListenURL;
	NetConnectionClass = InNetConnectionClass;
	if (!NetConnectionClass)
	{
		E_Log(error, "NetConnectionClass is nullptr");
	}

	Acceptor = make_shared<boost::asio::ip::tcp::acceptor>(Context,
		tcp::endpoint(tcp::v4(), (boost::asio::ip::port_type)ListenURL.Port), bReuseAddressAndPort);

	for (uint8 i = 0; i < BacklogCount; ++i)
	{
		StartAccept();
	}

	return true;
}

void UNetDriver::StartAccept(shared_ptr<UNetConnection> InReuseConnection)
{
	shared_ptr<UNetConnection> NewConnection = InReuseConnection ? 
		InReuseConnection : NewObject<UNetConnection>(this, NetConnectionClass);
	if (!InReuseConnection)
	{
		NewConnection->InitRemoteConnection(Context,
			bind(&ThisClass::OnClientConectionClosed, this, placeholders::_1),
			bind(&ThisClass::OnClientReceived, this, placeholders::_1, placeholders::_2));
		MapBacklog.insert(make_pair(NewConnection.get(), NewConnection));
	}

	Acceptor->async_accept(*NewConnection->GetSocket(), 
		[](const boost::system::error_code& Error)
		{
			int a;
			// 
		}
	);
}

void UNetDriver::OnClientConectionClosed(UNetConnection* NetConnection)
{
}

void UNetDriver::OnClientReceived(UNetConnection* NetConnection, FPacketHeader* PacketHeader)
{
}

void UNetDriver::Tick(float DeltaSeconds)
{
}

UNetDriver::UNetDriver()
{

}

UNetDriver::~UNetDriver()
{
	
}