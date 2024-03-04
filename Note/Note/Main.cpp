#include <iostream>
#include <format>
#include "Main.h"

int main()
{
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

	//testtest










	
}