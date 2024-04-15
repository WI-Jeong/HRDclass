#include <iostream>
#include <format>

struct FMystruct
{
	int a;
	float b;
	short c;
	char d;
};

struct FMystruct2
{
	char d;
	int a;
	float b;
	short c;
};

int main()
{
	std::cout << sizeof(FMystruct) << std::endl;
	std::cout << sizeof(FMystruct2) << std::endl;
	
}