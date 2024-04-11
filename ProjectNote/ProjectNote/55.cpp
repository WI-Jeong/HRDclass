#include <iostream>
#include <assert.h>
#include <format>
#include "func.h"
#include "general.h"
#define HUNGRY 1
#define THIRSTY 2
#define TIRED 4


int main()
{
	unsigned int iStatus = 0;
	iStatus |= HUNGRY;
	iStatus |= THIRSTY;

	iStatus &= ~THIRSTY;

	if (iStatus & THIRSTY)
	{
		std::cout << "THIRSTY 상태입니다.\n";
	}

	else
		std::cout << "THIRSTY 상태가 아닙니다.\n";
}
