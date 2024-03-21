#include "LoginTask.h"
#include "Utils.h"
#include "LoginSession.h"

FLoginTask::FLoginTask()
{
	cout << "[------    Login      ------]" << endl;
	const FAccount Account = FUtils::MakeAccountFromUserInput();
	pair Result = GLoginSession.Login(Account);
	cout << Result.second << endl;
}
