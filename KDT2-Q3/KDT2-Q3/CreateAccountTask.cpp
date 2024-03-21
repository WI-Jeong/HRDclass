#include "CreateAccountTask.h"
#include "Utils.h"
#include "DataBase.h"

FCreateAccountTask::FCreateAccountTask()
{
	cout << "[------ Create Account -----]" << endl;
	const FAccount Account = FUtils::MakeAccountFromUserInput();
	FAccount* Result = GDataBase.CreateAccount(Account);
	FUtils::PrintSystemSuccessOrFailed(Result, __func__);
}