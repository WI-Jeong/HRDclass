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
	if (1 == number)
	{
		return 1;
	}

	return number * Factorial_Re(number - 1);
}


int Fibonacci(int number)
{
	if (1 == number || 2 == number)
	{
		return 1;
	}

	int Prev1 = 1;
	int Prev2 = 1;
	int Value = 0;

	for (int i = 0; i < number-2; ++i)
	{
		Value = Prev1 + Prev2;
		Prev1 = Prev2;
		Prev2 = Value;	
	}
}


int Fibonnacci_Re(int number)
{
	if (1 == number || 2 == number)
	{
		return 1;
	}

	return Fibonnacci_Re(number - 1) + Fibonnacci_Re(number - 2);
}

int main()
{

	int Value = FFactorial(7);

	Value = FFactorial(10);

	Value = Factorial_Re(5);

	Value = Fibonacci(7);

	Value = Fibonacci_Re(7);

}


/*

*/