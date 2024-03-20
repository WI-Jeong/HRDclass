#include <iostream>
#include <format>


int main()
{
	int a = 0;
	{
		int a = 10;
		a = 30;
		std::cout << std::format("내부a의 값은: {}\n", a);
	}

	std::cout << std::format("외부a의 값은: {}", a);

}