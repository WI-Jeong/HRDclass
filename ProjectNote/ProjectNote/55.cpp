#include <iostream>
#include <assert.h>
#include "func.h"
#include "general.h"

enum EPropertyFlags :unsigned char
{
	//  16진수				2진수				왼쪽쉬피트연산					10진수
	ENone = 0x00,		   //0b 0000 0000					0							0
	EProperty1 = 0x01,		   //0b 0000 0001					1<<0						1 
	EProperty2 = 0x02,		   //0b 0000 0010					1<<1						2
	EProperty3 = 0x04,		   //0b 0000 0100					1<<2						4
	EProperty4 = 0x08,		   //0b 0000 1000					1<<3						8
	EProperty5 = 0x10,		   //0b 0001 0000					1<<4						16
	EProperty6 = 0x20,		   //0b 0010 0000					1<<5						32
	EProperty7 = 0x40,		   //0b 0100 0000					1<<6						64
	EProperty8 = 0x80,		   //0b 1000 0000					1<<7						128

};

void FlagFunction(unsigned char inProperty)
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
		std::cout << "EPropertyFlags::EProperty6\n";

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



int main()
{
	unsigned char TEST = EPropertyFlags::EProperty1;

	unsigned char TEST2 = EPropertyFlags::EProperty3;

	unsigned char TEST3 = TEST|TEST2;


}
