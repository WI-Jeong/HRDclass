#include "NetConnection.h"

void UNetConnection::InitRemoteConnection(boost::asio::io_context& InContext,
	function<void(UNetConnection*)> InOnConnectionClosed,
	function<void(UNetConnection*, FPacketHeader*)> InOnRecv)
{
	OnConnectionClosed = InOnConnectionClosed;
	OnRecv = InOnRecv;

	InitBase(InContext);
}

void UNetConnection::InitBase(boost::asio::io_context& InContext)
{
	Socket = make_unique<FSocket>(InContext);
}

UNetConnection::UNetConnection()
{

}

UNetConnection::~UNetConnection()
{
	
}