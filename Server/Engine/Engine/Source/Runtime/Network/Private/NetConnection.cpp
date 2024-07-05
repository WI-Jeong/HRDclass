#include "NetConnection.h"

void UNetConnection::InitRemoteConnection(boost::asio::io_context& InContext,
	function<void(UNetConnection*)> InConnectFunction,
	function<void(UNetConnection*)> InConnectionClosedFunction,
	function<void(UNetConnection*, FPacketHeader*)> InRecvFunction)
{
	ConnectFunction = InConnectFunction;
	ConnectionClosedFunction = InConnectionClosedFunction;
	RecvFunction = InRecvFunction;

	InitBase(InContext);
}

void UNetConnection::Send(const uint32 PacketID, void* PacketBody, const uint32 BodySize)
{
	const size_t SendBufferSize = BufferPool.get_requested_size();
	if (BodySize + sizeof(FPacketHeader) > SendBufferSize)
	{
		E_Log(error, "Send Buffer overflow! BodySize: {} / {}", BodySize, SendBufferSize);
		return;
	}
	FPacketHeader* Header = (FPacketHeader*)BufferPool.malloc();
	Header->SetPacketID(PacketID);
	Header->SetPayload(BodySize);

	if (BodySize != 0)
	{
		std::memcpy(Header + 1, PacketBody, BodySize);
	}
	const uint64 PacketSize = Header->GetPayload() + sizeof(FPacketHeader);
	LowLevelSend(Header, PacketSize);
}

void UNetConnection::LowLevelSend(void* Data, const uint64 Size)
{
	const EConnectionState State = GetConnectionState();
	if (State != EConnectionState::USOCK_Open && State != EConnectionState::USOCK_Pending)
	{
		E_Log(error, "ConnectionState error {}", (uint8)State);
		return;
	}

	boost::asio::async_write(*GetSocket(), boost::asio::buffer(Data, Size),
		[this, Data](boost::system::error_code ErrorCode, uint64 /*Length*/)
		{
			BufferPool.free(Data);
			if (ErrorCode)
			{
				E_Log(error, "async_write error: {}", ErrorCode.message());
				CleanUp();
				return;
			}
		}
	);
}

void UNetConnection::OnConnect()
{
	SetConnectionState(EConnectionState::USOCK_Pending);

	// Packet 읽어라..
	ReadPacketHeader();

	//ConnectFunction(this);
}

void UNetConnection::CleanUp()
{
	if (Socket->is_open())
	{
		Socket->close();
		ConnectionClosedFunction(this);
		E_Log(info, "{}", to_string(GetName()));
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

	boost::asio::async_read(*GetSocket(),
		boost::asio::buffer(&RecvPacketHeaderBuffer, sizeof(RecvPacketHeaderBuffer)),
		[this](boost::system::error_code ErrorCode, uint64 /*InRecvSize*/)
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