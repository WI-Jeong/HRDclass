#include "PrintLoginPlayerTask.h"
#include "Utils.h"
#include "LoginSession.h"

FPrintLoginPlayerTask::FPrintLoginPlayerTask()
{
	const auto& PlayerMap = GLoginSession.GetPlayerMap();
	cout << "[------    Player     ------]" << endl;
	for (auto& It : PlayerMap)
	{
		cout << format("-> Name: {}\n", It.second.GetName());
	}
	cout << "[---------------------------]" << endl;
}
