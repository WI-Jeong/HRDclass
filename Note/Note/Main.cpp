#include <iostream>
#include <format>
#include<array>
#include "Main.h"

int main()
{

	/*
	unsigned char Buff = EBuff::Attack | EBuff::HP;

	if ((Buff & EBuff::Armor) == 0)
	{
		std::cout << "Armor 버프는 포함되어 있지 않습니다.\n";
	}
	else
	{
		std::cout << "Armor 버프는 포함되어있습니다.\n";
	}


	if ((Buff & EBuff::Attack) == 0)
	{
		std::cout << "Attack 버프는 포함되어 있지 않습니다.\n";
	}
	else
	{
		std::cout << "Attack 버프는 포함되어있습니다.\n";
	}

	if ((Buff & EBuff::HP) == 0)
	{
		std::cout << "HP 버프는 포함되어 있지 않습니다.\n";
	}
	else
	{
		std::cout << "HP 버프는 포함되어있습니다.\n";
	}

	if ((Buff & EBuff::MP) == 0)
	{
		std::cout << "MP 버프는 포함되어 있지 않습니다.\n";
	}
	else
	{
		std::cout << "MP 버프는 포함되어있습니다.\n";
	}

	if ((Buff & EBuff::Critical) == 0)
	{
		std::cout << "Critical 버프는 포함되어 있지 않습니다.\n";
	}
	else
	{
		std::cout << "Critical 버프는 포함되어있습니다.\n";
	}


	unsigned char Buff1 = Buff | EBuff::Critical;

	*/

	/*
	bit flag
	

	unsigned char Property1 = EPropertyFlags::EProperty1;
	unsigned char Property3 = EPropertyFlags::EProperty3;

	unsigned char Property = Property1 | Property3;
	HasProperty(Property);

	unsigned char Property10 = Property | EPropertyFlags::EProperty7;
	HasProperty(Property10);

	unsigned char Property20 = Property10 & ~EPropertyFlags::EProperty1;
	HasProperty(Property20);



	
	*/	


	enum EBuff
	{
		None,
		Attack,
		Armor,
		HP,
		MP,
		Critical
	};

	int buff = EBuff::Attack | EBuff::HP | EBuff::Critical;



















	
}