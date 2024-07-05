#include "NetConnection.h"

void UNetConnection::InitRemoteConnection(boost::asio::io_context& InContext,
	function<void(UNetConnection*)> InAcceptFunction,
	function<void(UNetConnection*)> InConnectionClosedFunction,
	function<void(UNetConnection*, FPacketHeader*)> InRecvFunction)
{
	AcceptFunction = InAcceptFunction;
	ConnectionClosedFunction = InConnectionClosedFunction;
	RecvFunction = InRecvFunction;

	InitBase(InContext);
}

void UNetConnection::OnAccept()
{
	SetConnectionState(EConnectionState::USOCK_Pending);

	// Packet 읽어라..
	AcceptFunction(this);
}

void UNetConnection::CleanUp()
{
	if (Socket->is_open())
	{
		Socket->close();
		ConnectionClosedFunction(this);

		SetConnectionState(EConnectionState::USOCK_Closed);
	}
}

void UNetConnection::InitBase(boost::asio::io_context& InContext)
{
	SetConnectionState(EConnectionState::USOCK_Invalid);
	Socket = make_unique<FSocket>(InContext);
}

void UNetConnection::ReadPacketHeader()
{
	const EConnectionState State = GetConnectionState();
	if (State != EConnectionState::USOCK_Open && State != EConnectionState::USOCK_Pending)
	{
		E_Log(error, "not connected");
		return;
	}

	boost::asio::async_read(*Socket, 
		boost::asio::buffer(&RecvPacketHeaderBuffer, sizeof(RecvPacketHeaderBuffer)),
		[this](boost::system::error_code ErrorCode, uint64 InRecvSize)
		{
			if (ErrorCode)
			{
				CleanUp();
				return;
			}

			ReadPacketBody(RecvPacketHeaderBuffer);
		}
	);
}

void UNetConnection::ReadPacketBody(const FPacketHeader& InPacketHeader)
{
}

UNetConnection::UNetConnection()
{

}

UNetConnection::~UNetConnection()
{
	
}