#include "PendingConnectionTimeOutTask.h"
#include "NetDriver.h"

void FPendingConnectionTimeOutTask::ExecuteTask()
{
	auto Now = chrono::system_clock::now();

	vector<UNetConnection*> TimeOutConnections;

	for (auto& It : NetDriver->MapPendingConnection)
	{
		auto& PendingConnectTime = It.second->GetPendingConnectTime();
		auto DiffTime = std::chrono::duration_cast<std::chrono::seconds>(Now - PendingConnectTime);

		if (DiffTime.count() >= 5)
		{
			TimeOutConnections.push_back(It.first);
		}
	}

	for (UNetConnection* It : TimeOutConnections)
	{
		E_Log(trace, "{}", to_string(It->GetName()));
		It->CleanUp();
	}
}
