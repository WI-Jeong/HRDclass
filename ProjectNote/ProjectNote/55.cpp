#include <iostream>
#include <assert.h>
#include <format>
#include "func.h"
#include "general.h"


enum EENUM
{
	num = 10,
	num1,
	num2 = 77,
	num3
};


int main()
{
	switch (EENUM)
	{
	case num:
		std::cout << "입력한 숫자는 10입니다." << std::endl;
		break;
	case num1:
		std::cout << "입력한 숫자는 11입니다." << std::endl;
		break;
	case num2:
		std::cout << "입력한 숫자는 77입니다." << std::endl;
		break;
	case num3:
		std::cout << "입력한 숫자는 78입니다." << std::endl;
		break;
	default:
		break;
	}
}
