#include "Account.h"

void FAccountSaveLoader::Save(rapidjson::Document::AllocatorType& InAllocator)
{
	AccountValue.AddMember("ID", rapidjson::StringRef(Account.ID.data()), InAllocator);
	AccountValue.AddMember("Password", rapidjson::StringRef(Account.Password.data()), InAllocator);
}

void FAccountSaveLoader::Load()
{
	const bool bID = AccountValue.HasMember("ID");
	const bool bPassword = AccountValue.HasMember("Password");

	if (!(bID && bPassword))
	{
		return;
	}

	Account.ID = AccountValue["ID"].GetString();
	Account.Password = AccountValue["Password"].GetString();
}
