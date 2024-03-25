#include <iostream>
#include "func.h"
#include "general.h"

void Output(const int* pi)
{
	int A = *pi;
	*pi;
	//*pi = 777;
}


int main()
{
	int a = 0;
	a = 100;
	Output(&a);
}