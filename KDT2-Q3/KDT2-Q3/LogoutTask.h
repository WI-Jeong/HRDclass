#pragma once
#include "Account.h"

struct FLogoutTask
{
	FLogoutTask();
	FLogoutTask(const FAccount& InAccount);

private:
	void ExecuteTask(const FAccount& InAccount);
};

