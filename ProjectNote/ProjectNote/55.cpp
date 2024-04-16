#include <iostream>
#include <format>
#define NAME_SIZE 32

struct player
{
	char name[NAME_SIZE];
	int i;
	int j;
	struct startest;
};

struct FPadding
{
	char C;

};

struct FPadding2
{
	char C;
	int I;
};

struct FPadding3
{
	int I;
	char C;
	char C2; 
	
};



int main()
{
	std::cout << sizeof(FPadding3);

	```
		if (true)
		{
			std::cout << "If문 조건이 true입니다." << std::endl;
		}
	-> 출력됨.

		if (false)
		{
			std::cout << "If문 조건이 false입니다." << std::endl;
		}
	->if문의 조건식이 false이므로 출력되지 않는다.
		```
}