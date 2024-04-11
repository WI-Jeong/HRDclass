#include <iostream>
#include <assert.h>
#include "func.h"
#include "general.h"



int main()
{
	int a = 123;
	std::cout << typeid(a).name() << std::endl;
}
