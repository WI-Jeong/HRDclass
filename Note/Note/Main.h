#pragma once

enum EBuff :unsigned char
{
	 None,
	 Attack,
	 Armor,
	 HP=4,
	 MP=8,
	 Critical=16

};

enum EPropertyFlags :unsigned char
{
	ENone,
	EProperty1,
	EProperty2,
	EProperty3 = 4,
	EProperty4 = 8,
	EProperty5 = 16,
	EProperty6 = 32,
	EProperty7 = 64,
	EProperty8 = 128,

};

void HasProperty(unsigned char inProperty)
{
	if (inProperty & EPropertyFlags::EProperty1)
	{
		std::cout << "EPropertyFlags::EProperty1\n";
	}

	if (inProperty & EPropertyFlags::EProperty2)
	{
		std::cout << "EPropertyFlags::EProperty2\n";
	}

	if (inProperty & EPropertyFlags::EProperty3)
	{
		std::cout << "EPropertyFlags::EProperty3\n";
	}

	if (inProperty & EPropertyFlags::EProperty4)
	{
		std::cout << "EPropertyFlags::EProperty4\n";
	}

	if (inProperty & EPropertyFlags::EProperty5)
	{
		std::cout << "EPropertyFlags::EProperty5\n";
	}

	if (inProperty & EPropertyFlags::EProperty6)
	{
		std::cout << "EPropertyFlags::EProperty1\n";
	}

	if (inProperty & EPropertyFlags::EProperty6)
	{
		std::cout << "EPropertyFlags::EProperty1\n";
	}

	if (inProperty & EPropertyFlags::EProperty7)
	{
		std::cout << "EPropertyFlags::EProperty7\n";
	}

	if (inProperty & EPropertyFlags::EProperty8)
	{
		std::cout << "EPropertyFlags::EProperty8\n";
	}
};

