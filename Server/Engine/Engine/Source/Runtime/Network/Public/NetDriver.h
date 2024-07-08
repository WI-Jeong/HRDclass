#pragma once
// AssortRock Inc.

#include "NetworkTypes.h"
#include "NetConnection.h"
#include "NetDriver.generated.h"

class UNetDriver;
struct FNetworkNotify
{
	friend class UNetDriver;
public:
	FNetworkNotify(
		function<void(UNetDriver*, UNetConnection*)> InOnConnect,
		function<void(UNetDriver*, UNetConnection*)> InOnConnectionClosed,
		function<void(UNetDriver*, UNetConnection*, FPacketHeader*)> InOnRecv) :
		OnConnect(InOnConnect), OnConnectionClosed(InOnConnectionClosed), OnRecv(InOnRecv) {}

private:
	FNetworkNotify() {}

	function<void(UNetDriver*, UNetConnection*)> OnConnect;
	function<void(UNetDriver*, UNetConnection*)> OnConnectionClosed;
	function<void(UNetDriver*, UNetConnection*, FPacketHeader*)> OnRecv;
};

UCLASS()
class NETWORK_API UNetDriver : public UObject
{
	GENERATED_BODY();

//-------------- Server 
public:
	/**
	 * Initialize the network driver in server mode (listener)
	 */
	virtual bool InitListen(FNetworkNotify InNotify, FURL& ListenURL, const bool bReuseAddressAndPort, 
		const uint8 BacklogCount, TSubclassOf<UNetConnection> InNetConnectionClass = UNetConnection::StaticClass());

protected:
	void StartAccept(shared_ptr<UNetConnection> InReuseConnection = nullptr);

protected:
	unordered_map<UNetConnection*, shared_ptr<UNetConnection>> MapBacklog;
	unordered_map<UNetConnection*, shared_ptr<UNetConnection>> MapPendingConnection;
	shared_ptr<boost::asio::ip::tcp::acceptor> Acceptor;

// -------------- Client
public:
	virtual bool InitConnect(FNetworkNotify InNotify, FURL& ConnectURL, TSubclassOf<UNetConnection> InNetConnectionClass = UNetConnection::StaticClass());
	engine_weak_ptr<UNetConnection> GetClientConnection() { return ClientConnection; }

protected:
	shared_ptr<UNetConnection> ClientConnection;

// -------------- 공통
public:
	void Send(UNetConnection* TargetConnection, const uint32 PacketID, void* PacketBody, const uint32 BodySize);
	virtual bool InitBase(FNetworkNotify& InNotify, FURL& InURL, TSubclassOf<UNetConnection> InNetConnectionClass);

	virtual void Tick(float DeltaSeconds);

	// Server
	virtual void OnClientAccepted(UNetConnection* NetConnection);

	// Client: connect 성공 시
	virtual void OnPendingConnected(UNetConnection* NetConnection);

	// Client: connect이후, HelloPacket을 수신
	// Server: accept이후, HelloPacket을 수신
	virtual void OnConnected(UNetConnection* NetConnection);

	// Common
	virtual void OnConectionClosed(UNetConnection* NetConnection);
	virtual void OnReceived(UNetConnection* NetConnection, FPacketHeader* PacketHeader);

protected:
	bool bInit = false;
	bool bServer = false;
	TSubclassOf<UNetConnection> NetConnectionClass;
	FURL URL;
	FNetworkNotify NetworkNotify;

	boost::asio::io_context Context;
};