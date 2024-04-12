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
	std::cout << sizeof(EENUM) << std::endl;
	std::cout << typeid(EENUM).name() << std::endl;

	EENUM::num1;
}
