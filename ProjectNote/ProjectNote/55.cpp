#include <iostream>
#include <format>
#define NAME_SIZE 32


int main()
{
	int value = 0;
	std::cin >> value;
	std::cout << std::format("Value값은: {}\n", value);
}