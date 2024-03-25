#include <iostream>
#include "func.h"
#include "general.h"



int main()
{
	int a = 0;
	int* pint = &a;

	const int* pconstint = &a;
	*pconstint;
	//*pconstint = 100;
	int b = 0;
	pconstint = &b;

	int* const pintconst = &a;
	*pintconst = 400;
	//pintconst = &b;

	const int* const pconstintconst = nullptr;

	int const* p = &a;

}