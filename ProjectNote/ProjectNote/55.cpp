#include <iostream>
#include "func.h"
#include "general.h"

void Output(const int* pi)
{
	int A = *pi;
	int* pint = (int*)pi;
	*pint = 100;
}


int main()
{
	void* pvoid = nullptr;
	int abc = 0;
	pvoid = &abc;
	//*pvoid;
	pvoid+1;
}