﻿#include "NetConnection.h"
#include "NetDriver.h"

bool UNetConnection::InitRemoteConnection(
	const bool bServer,
	const FURL& InURL, 
	boost::asio::io_context& InContext,
	function<void(UNetConnection*)> InPendingConnectFunction,
	function<void(UNetConnection*)> InConnectFunction,
	function<void(UNetConnection*)> InConnectionClosedFunction,
	function<void(UNetConnection*, FPacketHeader*)> InRecvFunction)
{
	E_Log(info, "{}", to_string(GetName()));
	bNetDriverIsServer = bServer;
	PendingConnectFunction = InPendingConnectFunction;
	ConnectFunction = InConnectFunction;
	ConnectionClosedFunction = InConnectionClosedFunction;
	RecvFunction = InRecvFunction;

	InitBase(InURL, InContext);
	if (!bServer)
	{
		boost::asio::ip::tcp::endpoint EndPoint(boost::asio::ip::address::from_string(URL.Host), URL.Port);

		tcp::resolver Resolver(InContext);
		boost::system::error_code ErrorCode;
		boost::asio::connect(*GetSocket(), Resolver.resolve(EndPoint), ErrorCode);

		if (ErrorCode)
		{
			E_Log(error, "connect failed: {}", ErrorCode.message());
			return false;
		}

		OnPendingConnect();
	}

	return true;
}

void UNetConnection::Send(FPacketHeader* Packet)
{
	Send(Packet->GetPacketID(), Packet + 1, Packet->GetPayload());
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
	new(Header)FPacketHeader(PacketID, BodySize);

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
			// 명시적으로 소멸할 필요가 없는 기본 자료형만 있음
			// 또한, 이부분에는 PacketHeader가 오는 것을 보장 할 수 없음
			//PacketHeader(Data)->~FPacketHeader();
			BufferPool.free(Data);
			if (ErrorCode)
			{
				E_Log(info, "async_write error: {}", ErrorCode.message());
				CleanUp();
				return;
			}
		}
	);
}

void UNetConnection::OnPendingConnect()
{
	E_Log(info, "{}", to_string(GetName()));
	SetConnectionState(EConnectionState::USOCK_Pending);

	// Packet 읽어라..
	ReadPacketHeader();

	PendingConnectFunction(this);
}

void UNetConnection::OnConnect()
{
	E_Log(info, "{}", to_string(GetName()));
	SetConnectionState(EConnectionState::USOCK_Open);
	ConnectFunction(this);
}

void UNetConnection::CleanUp()
{
	if (Socket->is_open())
	{
		Socket->close();
		E_Log(info, "{}", to_string(GetName()));
		SetConnectionState(EConnectionState::USOCK_Closed);
		ConnectionClosedFunction(this);
	}
}

void UNetConnection::InitBase(const FURL& InURL, boost::asio::io_context& InContext)
{
	URL = InURL;
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
				E_Log(trace, "{}", ErrorCode.message());
				CleanUp();
				return;
			}

			ReadPacketBody(RecvPacketHeaderBuffer);
		}
	);
}

void UNetConnection::ReadPacketBody(const FPacketHeader& InPacketHeader)
{
	const EConnectionState State = GetConnectionState();
	if (State != EConnectionState::USOCK_Open && State != EConnectionState::USOCK_Pending)
	{
		E_Log(error, "not connected");
		return;
	}

	const uint32 PayloadSize = InPacketHeader.GetPayload();
	const uint32 PacketID = InPacketHeader.GetPacketID();

	const uint32 PacketSize = sizeof(FPacketHeader) + PayloadSize;
	const uint32 BufferSize = BufferPool.get_requested_size();
	if (PacketSize > BufferSize)
	{
		E_Log(fatal, "Packet size({})가 Buffer size({}) 보다 크다", PacketSize, BufferSize);
		CleanUp();
		return;
	}

	FPacketHeader* PacketHeader = (FPacketHeader*)BufferPool.malloc();
	new(PacketHeader)FPacketHeader(InPacketHeader);

	if (PayloadSize == 0)
	{
		RecvFunction(this, PacketHeader);

		// 명시적으로 소멸할 필요가 없는 기본 자료형만 있음
		//PacketHeader->~FPacketHeader();
		BufferPool.free(PacketHeader);
	}
	else
	{
		boost::asio::async_read(*GetSocket(),
			boost::asio::buffer(PacketHeader + 1, PayloadSize),
			[this, PacketHeader](boost::system::error_code ErrorCode, uint64 /*InRecvSize*/)
			{
				if (ErrorCode)
				{
					E_Log(trace, "{}", ErrorCode.message());
					CleanUp();
					return;
				}
				RecvFunction(this, PacketHeader);

				// 명시적으로 소멸할 필요가 없는 기본 자료형만 있음
				//PacketHeader->~FPacketHeader();
				BufferPool.free(PacketHeader);
			}
		);
	}
}

UNetConnection::UNetConnection()
{

}

UNetConnection::~UNetConnection()
{
	
}