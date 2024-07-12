#include "DBNetDriver.h"
#include "Task/CreateAccountTask.h"

bool UDBNetDriver::InitConnect(FNetworkNotify InNotify, FURL_DB& ConnectURL, TSubclassOf<UNetConnection> InNetConnectionClass)
{
	const uint32 ThreadCount = std::thread::hardware_concurrency() - 1u;
	E_LOG(info, "Create DB thread pool {}", ThreadCount);
	DBThreadPool = make_shared<boost::asio::thread_pool>(ThreadCount);

	// DB 접속 테스트 및 초기화
	// - DB이름, Table 이름
	{
		boost::asio::ssl::context SSL_Context(boost::asio::ssl::context::tls_client);
		boost::asio::ip::tcp::resolver Resolver(Context.get_executor());
		auto EndPoint = Resolver.resolve(ConnectURL.Host, to_string(ConnectURL.Port));

		boost::mysql::tcp_ssl_connection SSL_Connection(Context, SSL_Context);
		boost::mysql::handshake_params Parms(ConnectURL.ID, ConnectURL.Password);

		boost::mysql::error_code ErrorCode;
		boost::mysql::diagnostics Diagnostics;
		SSL_Connection.connect(*EndPoint.begin(), Parms, ErrorCode, Diagnostics);
		if (ErrorCode)
		{
			E_LOG(error, "{} IP:{}:{} ID:{}, PW:{} connect failed!", 
				to_string(GetName()), ConnectURL.Host, ConnectURL.Port, ConnectURL.ID, ConnectURL.Password);
			PrintError(ErrorCode, &Diagnostics);
			return false;
		}

		boost::mysql::results Result;
		SSL_Connection.execute("CREATE DATABASE IF NOT EXISTS AccountDB", Result, ErrorCode, Diagnostics);
		if (ErrorCode) { PrintError(ErrorCode, &Diagnostics); return false; }

		SSL_Connection.execute("USE AccountDB", Result, ErrorCode, Diagnostics);
		if (ErrorCode) { PrintError(ErrorCode, &Diagnostics); return false; }

		SSL_Connection.execute(R"(
					CREATE TABLE IF NOT EXISTS Account
					(
						ID VARCHAR(15) PRIMARY KEY,
						Password VARBINARY(128) NOT NULL
					);
			)", Result, ErrorCode, Diagnostics);
		if (ErrorCode) { PrintError(ErrorCode, &Diagnostics); return false; }
		SSL_Connection.close();
	}

	E_LOG(trace, "{} IP:{}:{} ID:{}, PW:{} connect!",
		to_string(GetName()), ConnectURL.Host, ConnectURL.Port, ConnectURL.ID, ConnectURL.Password);

	boost::mysql::pool_params Params;
	Params.server_address.emplace_host_and_port(ConnectURL.Host, ConnectURL.Port);
	Params.username = ConnectURL.ID;
	Params.password = ConnectURL.Password;
	Params.initial_size = 1000;
	Params.max_size = 1000;
	Params.database = "AccountDB";
	Params.connect_timeout = std::chrono::seconds(60);
	Params.multi_queries = false;

	DBConnectionPool = make_shared<boost::mysql::connection_pool>(
		boost::mysql::pool_executor_params::thread_safe(Context.get_executor()),
		move(Params));
	DBConnectionPool->async_run(boost::asio::detached);

	engine_weak_ptr<ThisClass> DBNetDriver = this->As<ThisClass>();
	for (int i = 0; i < 2; ++i)
	{
		string ID = "DAFRBC" + to_string(i);
		string Password = "Aszxc";
		AsyncTask<FCreateAccountTask>(ENamedThreads::MainThread, ID, Password, DBNetDriver,
			[](FCreateAccountTask*, FCreateAccountTask::EResult) {});
	}
	return true;
}

bool UDBNetDriver::Send_CreateStatement(shared_ptr<boost::mysql::pooled_connection> Conenction, string_view SQL, FStatement& OutStatement)
{
	OutStatement = Conenction->get().prepare_statement(SQL);
	if (OutStatement.valid() == false)
	{
		// 너무 긴 Statement가 만들어지면 실패할 수 있음
		E_LOG(error, "Statement not valid");
		RequestEngineExit("Statement not valid");
		return false;
	}
	return true;
}

void UDBNetDriver::AsyncGetConnection(function<void(shared_ptr<boost::mysql::pooled_connection>)> Callback)
{
	if (!DBConnectionPool)
	{
		E_LOG(error, "DBConnectionPool is nullptr");
		return;
	}

	shared_ptr<boost::mysql::diagnostics> Diagnostics = make_shared<boost::mysql::diagnostics>();

	DBConnectionPool->async_get_connection(chrono::seconds(60), *Diagnostics,
		[Callback, Diagnostics](boost::mysql::error_code ErrorCode, boost::mysql::pooled_connection Connection)
		{
			if (ErrorCode)
			{
				UDBNetDriver::PrintError(ErrorCode, Diagnostics.get());
				RequestEngineExit("async_get_connection failed");
				return;
			}

			shared_ptr<boost::mysql::pooled_connection> SharedConnection = make_shared<boost::mysql::pooled_connection>(move(Connection));
			Callback(SharedConnection);
		}
	);
}

UDBNetDriver::~UDBNetDriver()
{
	if (HasAnyFlags(EObjectFlags::RF_ClassDefaultObject)) { return; }
	if (!DBConnectionPool) { return; }

	DBThreadPool->join();
	DBConnectionPool->cancel();
}

void UDBNetDriver::PrintError(boost::mysql::error_code& InErrorCode, boost::mysql::diagnostics* InDiagnostics)
{
	if (InErrorCode)
	{
		E_LOG(error, "{}", InErrorCode.to_string());
		if (InDiagnostics && !InDiagnostics->server_message().empty())
		{
			E_LOG(error, "{}", InDiagnostics->server_message().data());
		}
		if (InDiagnostics && !InDiagnostics->client_message().empty())
		{
			E_LOG(error, "{}", InDiagnostics->client_message().data());
		}
	}
}
