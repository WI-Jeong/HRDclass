#include <iostream>
#include <assert.h>
#include <format>
#include "func.h"
#include "general.h"


enum ETier : unsigned char
{
	None,
	Iron,
	Bronze,
	Silver,
	Gold
};
/*

		enum ESeason
	{
		Spring = 1,
		Summer,
		Fall,
		Winter
	};

	ESeason Birthday = ESeason::Fall;
	std::cout << "생일이 속한 계절= " << Birthday << std::endl;

	이거 값 3나옴.

		enum ESeason : unsigned char
	{
		Spring = 1,
		Summer,
		Fall,
		Winter
	};

	ESeason Birthday = ESeason::Fall;
	std::cout << "생일이 속한 계절= " << Birthday << std::endl;

	이거 값 아무것도 안나옴

		나오게 하려면
		std::cout << "생일이 속한 계절= " << (int)Birthday << std::endl;
	로 int로 형변환해서 구해줘야함.
*/


int main()
{

}
