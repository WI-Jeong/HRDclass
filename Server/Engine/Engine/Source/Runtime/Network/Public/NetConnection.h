#pragma once
// AssortRock Inc.

#include "NetworkTypes.h"
#include "NetConnection.generated.h"

#pragma pack(push, 1)
struct FPacketHeader
{
	enum EPreDefinedPacketID
	{
		EHelloPacket = 2,	// Client to Server; 클라가 처음 접속하며 서버로 보내는 Packet
		EHelloPacketAck,	// Server to Client; HelloPacket을 받으면 클라로 보내는 Packet

		EEnd
	};

public:
	FPacketHeader() = default;
	FPacketHeader(const uint32 NewPacketID) : PacketID(NewPacketID) {}
	void SetPayload(const uint32 InPayload) { Payload = InPayload; }
	void SetPacketID(const uint32 InPacketID) { PacketID = InPacketID; }
	uint32 GetPayload() const { return Payload; }
	uint32 GetPacketID() const { return PacketID; }

private:
	// Packet의 본문의 크기
	uint32 Payload = 0;
	uint32 PacketID = 0;
};

#pragma pack(pop)

enum EConnectionState
{
	USOCK_Invalid = 0, // Connection is invalid, possibly uninitialized.
	USOCK_Closed = 1, // Connection permanently closed.
	USOCK_Pending = 2, // Accept는 했으나, 아직 아무런 Packet도 받지 못한
	USOCK_Open = 3, // Connection is open.
};

UCLASS()
class NETWORK_API UNetConnection : public UObject
{
	GENERATED_BODY();

public:
	void InitRemoteConnection(boost::asio::io_context& InContext,
		function<void(UNetConnection*)> InAcceptFunction,
		function<void(UNetConnection*)> InConnectionClosedFunction,
		function<void(UNetConnection*, FPacketHeader*)> InRecvFunction);

	FSocket* GetSocket() const { return Socket.get(); }

	void OnAccept();

	// 재사용 직전에 CleanUp
	void CleanUp();

protected:
	void InitBase(boost::asio::io_context& InContext);
	
	EConnectionState GetConnectionState() const { return ConnectionState; }
	void SetConnectionState(const EConnectionState NewState) { ConnectionState = NewState; }

	void ReadPacketHeader();
	void ReadPacketBody(const FPacketHeader& InPacketHeader);

public:
	UNetConnection();
	~UNetConnection();

private:
	FPacketHeader RecvPacketHeaderBuffer;

private:
	EConnectionState ConnectionState = EConnectionState::USOCK_Invalid;
	unique_ptr<FSocket> Socket;
	function<void(UNetConnection*)> AcceptFunction;
	function<void(UNetConnection*)> ConnectionClosedFunction;
	function<void(UNetConnection*, FPacketHeader*)> RecvFunction;
};