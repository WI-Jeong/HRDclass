#include "NetDriver.h"

bool UNetDriver::InitListen(FNetworkNotify InNotify, 
	FURL& ListenURL, const bool bReuseAddressAndPort, const uint8 BacklogCount, 
	TSubclassOf<UNetConnection> InNetConnectionClass)
{
	if (!InitBase(InNotify, ListenURL, InNetConnectionClass))
	{
		return false;
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
	if (InReuseConnection)
	{
		InReuseConnection->CleanUp();
	}

	shared_ptr<UNetConnection> NewConnection = InReuseConnection ? 
		InReuseConnection : NewObject<UNetConnection>(this, NetConnectionClass);
	if (!InReuseConnection)
	{
		NewConnection->InitRemoteConnection(Context,
			bind(&ThisClass::OnClientAccept, this, placeholders::_1),
			bind(&ThisClass::OnClientConectionClosed, this, placeholders::_1),
			bind(&ThisClass::OnClientReceived, this, placeholders::_1, placeholders::_2));
		MapBacklog.insert(make_pair(NewConnection.get(), NewConnection));
	}

	Acceptor->async_accept(*NewConnection->GetSocket(), 
		[this, NewConnection](const boost::system::error_code& Error)
		{
			E_Log(trace, "New Client Accept: {}", to_string(NewConnection->GetName()));
			if (Error)
			{
				E_Log(error, "AsyncAccept error");

				StartAccept(NewConnection);
				return;
			}

			// Move NewConnection Backlog to PendingConnection.
			MapBacklog.erase(NewConnection.get());
			MapPendingConnection.insert(make_pair(NewConnection.get(), NewConnection));

			StartAccept();

			NewConnection->OnAccept();
		}
	);
}

void UNetDriver::OnClientAccept(UNetConnection* NetConnection)
{
}

void UNetDriver::OnClientConectionClosed(UNetConnection* NetConnection)
{
}

void UNetDriver::OnClientReceived(UNetConnection* NetConnection, FPacketHeader* PacketHeader)
{
}

bool UNetDriver::InitConnect(FNetworkNotify InNotify, FURL& ConnectURL, TSubclassOf<UNetConnection> InNetConnectionClass)
{
	if (!InitBase(InNotify, ConnectURL, InNetConnectionClass))
	{
		return false;
	}

	shared_ptr<UNetConnection> NewConnection = NewObject<UNetConnection>(this, NetConnectionClass);
	NewConnection->InitRemoteConnection(Context,
		bind(&ThisClass::OnClientAccept, this, placeholders::_1),
		bind(&ThisClass::OnClientConectionClosed, this, placeholders::_1),
		bind(&ThisClass::OnClientReceived, this, placeholders::_1, placeholders::_2));

	boost::asio::ip::tcp::endpoint EndPoint(boost::asio::ip::address::from_string(ConnectURL.Host), ConnectURL.Port);

	tcp::resolver Resolver(Context);
	boost::system::error_code ErrorCode;
	boost::asio::connect(*NewConnection->GetSocket(), Resolver.resolve(EndPoint), ErrorCode);
	
	if (ErrorCode)
	{
		E_Log(error, "connect failed: {}", ErrorCode.message());
		return false;
	}

	return true;
}

bool UNetDriver::InitBase(FNetworkNotify& InNotify, FURL& InURL, TSubclassOf<UNetConnection> InNetConnectionClass)
{
	NetworkNotify = InNotify;
	URL = InURL;
	NetConnectionClass = InNetConnectionClass;
	if (!NetConnectionClass)
	{
		E_Log(error, "NetConnectionClass is nullptr");
		return false;
	}

	return true;
}

void UNetDriver::Tick(float DeltaSeconds)
{
	boost::system::error_code ErrorCode;

	uint32 PollCountPerTick = 0;
	while (uint32 n = Context.poll_one(ErrorCode))
	{
		if (ErrorCode)
		{
			E_Log(error, "Context poll one: {}", ErrorCode.message());
		}

		PollCountPerTick += n;
		if (PollCountPerTick >= 1000)
		{
			break;
		}
	}
}

UNetDriver::UNetDriver()
{

}

UNetDriver::~UNetDriver()
{
	
}