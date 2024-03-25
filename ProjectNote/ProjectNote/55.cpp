#include <iostream>
#include "func.h"
#include "general.h"



int main()
{
	int i = 0;
	int* pint = &i;

	volatile const int cint = 100;

	pint = (int*)&cint;

	*pint = 300;

	printf("cint출력: %d\n", cint);
	
}