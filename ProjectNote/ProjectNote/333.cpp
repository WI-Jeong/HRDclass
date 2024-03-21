#include <iostream>

int FFactorial(int num)
{
	int Factorial = 1;

	for (int j = 0; j < num - 1; ++j)
	{
		Factorial *= (j + 2);
	}

	return Factorial;
}

int Factorial_Re(int number)
{
	return number * Factorial_Re(number - 1);

}


int main()
{
	int Value = FFactorial(7);

	Value = FFactorial(10);

}


/*

*/