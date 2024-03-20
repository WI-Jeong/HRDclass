#include <iostream>
#include <format>
#include <stdio.h>

int FFactorial(int num)
{
	int Factorial = 1;

	for (int j = 0; j < num - 1; ++j)
	{
		Factorial *= (j + 2);
	}

	return Factorial;
}



int main()
{
	int Value = FFactorial(7);

	Value = FFactorial(10);

}