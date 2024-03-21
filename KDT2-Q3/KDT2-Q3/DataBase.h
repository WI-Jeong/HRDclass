#pragma once
#include "Headers.h"
#include "Account.h"

class FDataBase final
{
public:
	FAccount* CreateAccount(const FAccount& InAccount);

	FAccount* FindAccount(const FAccountName& InID);

	FAccount* CheckAccount(const FAccount& InAccount);

	bool DeleteAccount(const FAccount& InAccount);

	const unordered_map<FAccountName, FAccount>& GetAccountMap() const { return AccountMap; }

public:
	FDataBase();
	~FDataBase();

private:
	void Save();
	void Load();

private:
	unordered_map<FAccountName, FAccount> AccountMap;
};

extern FDataBase GDataBase;
