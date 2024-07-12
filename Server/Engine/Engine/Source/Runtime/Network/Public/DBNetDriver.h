#pragma once
// AssortRock Inc.

#include "NetDriver.h"
#include <boost/mysql.hpp>
#include "DBNetDriver.generated.h"

using FStatement = boost::mysql::statement;

struct FURL_DB : public FURL
{
	FURL_DB()
	{
		Port = 3306;
	}
	string ID = "root";
	string Password = "root";
};

UCLASS()
class NETWORK_API UDBNetDriver : public UNetDriver
{
	GENERATED_BODY();

public:
	~UDBNetDriver();
	virtual bool InitConnect(FNetworkNotify InNotify, FURL_DB& ConnectURL, TSubclassOf<UNetConnection> InNetConnectionClass = UNetConnection::StaticClass());

public:
	bool Send_CreateStatement(shared_ptr<boost::mysql::pooled_connection> Conenction, string_view SQL, FStatement& OutStatement);

	template <BOOST_MYSQL_EXECUTION_REQUEST ExecutionRequest, BOOST_MYSQL_RESULTS_TYPE ResultsType>
	bool SendSQL(shared_ptr<boost::mysql::pooled_connection> Conenction, const ExecutionRequest& InReq,
		ResultsType& OutResult, boost::mysql::error_code& OutErrorCode, boost::mysql::diagnostics& OutDiagnostics)
	{
		Conenction->get().execute(InReq, OutResult, OutErrorCode, OutDiagnostics);
		if (OutErrorCode)
		{
			E_LOG(error, "check!");
			PrintError(OutErrorCode, &OutDiagnostics);
			return false;
		}

		return true;
	}

public:
	void AsyncGetConnection(function<void(shared_ptr<boost::mysql::pooled_connection>)> Callback);
	boost::asio::thread_pool& GetDBThreadPool() const { return *DBThreadPool; }

protected:
	static void PrintError(boost::mysql::error_code& InErrorCode, boost::mysql::diagnostics* InDiagnostics);

protected:
	shared_ptr<boost::asio::thread_pool> DBThreadPool;
	shared_ptr<boost::mysql::connection_pool> DBConnectionPool;

private:
	// DBNetDriver FURL_DB 버전의 InitConnect를 사용하십시오.
	virtual bool InitConnect(FNetworkNotify InNotify, FURL& ConnectURL, TSubclassOf<UNetConnection> InNetConnectionClass = UNetConnection::StaticClass()) override
	{
		_ASSERT(false);
		return false;
	}
	// DBNetDriver not support InitListen
	virtual bool InitListen(FNetworkNotify InNotify, FURL& ListenURL, const bool bReuseAddressAndPort,
		const uint8 BacklogCount, TSubclassOf<UNetConnection> InNetConnectionClass = UNetConnection::StaticClass()) override
	{
		_ASSERT(false);
		return false;
	}
};