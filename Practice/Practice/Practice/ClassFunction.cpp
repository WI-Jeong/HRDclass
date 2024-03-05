#include "ClassFuncion.h"
#include <format>

void FunctionName()
{
}

void FunctionName(int a)
{
	//std::cout << "a: " << a << std::endl;
	std::cout << std::format("a: {}\n", a);
}

int AddFunction(int a, int b)
{
	const int Sum = a + b;
	std::cout << std::format("[{}:{}:{}] {} + {} = {}\n", __func__, __FILE__, __LINE__, a, b, Sum);
	return Sum;
}

double AddFunction(double a, double b)
{
	const double Sum = a + b;
	std::cout << std::format("[{}:{}:{}] {} + {} = {}\n", __func__, __FILE__, __LINE__, a, b, Sum);
	return Sum;
}

unsigned long long Factorial(unsigned char f)
{
	if (f == 0)
	{
		return 1;
	}
	else
	{
		return f * Factorial(f - 1);
	}
}

void HasFlag(unsigned char InProperty)
{
	// 1번 속성이 활성화 되어 있나요?
	// 0000 0101
	// 0000 0001
	// --------- AND (둘다 1이면 1, 하나라도 0이면 0)
	// 0000 0001
	// 참
	// if는 0이면 false, 0이 아니면 true
	if (InProperty & EPropertyFlags::EProperty1)
	{
		std::cout << "EPropertyFlags::EProperty1\n";
	}
	if (InProperty & EPropertyFlags::EProperty2)
	{
		std::cout << "EPropertyFlags::EProperty2\n";
	}
	if (InProperty & EPropertyFlags::EProperty3)
	{
		std::cout << "EPropertyFlags::EProperty3\n";
	}
	if (InProperty & EPropertyFlags::EProperty4)
	{
		std::cout << "EPropertyFlags::EProperty4\n";
	}
	if (InProperty & EPropertyFlags::EProperty5)
	{
		std::cout << "EPropertyFlags::EProperty5\n";
	}
	if (InProperty & EPropertyFlags::EProperty6)
	{
		std::cout << "EPropertyFlags::EProperty6\n";
	}
	if (InProperty & EPropertyFlags::EProperty7)
	{
		std::cout << "EPropertyFlags::EProperty7\n";
	}
	if (InProperty & EPropertyFlags::EProperty8)
	{
		std::cout << "EPropertyFlags::EProperty8\n";
	}
}

// int a = Value;
int Function(int a)
{
	a = 10;
	return a;
}

// 1. FParam InParam = FParam(Param); // 복사!
// 2. return -> Param = InParam; // 복사!
FParam Function(FParam InParam)
{
	for (int i = 0; i < 1000; ++i)
	{
		InParam.Value[i] = i;
	}
	return InParam;
}

void Function(FParam* InParam)
{
	for (int i = 0; i < 1000; ++i)
	{
		InParam->Value[i] = i;
	}
}

void FunctionCallByPointer(int* InParam)
{
	*InParam += 1;
}

void FunctionCallByReference(int& InParam)
{
	InParam += 1;
}

void FunctionCallByReference(FParam& InParam)
{
	for (int i = 0; i < 1000; ++i)
	{
		InParam.Value[i] = i;
	}
}