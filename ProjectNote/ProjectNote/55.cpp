#include <iostream>
#include <assert.h>
#include <format>
#include "func.h"
#include "general.h"


enum ESeason
{
	Spring = 1,
	Summer,
	Fall,
	Winter
};


int main()
{

	ESeason Birthday = ESeason::Fall;

	switch (Birthday)
	{
	case Spring:
		std::cout << "생일이 속한 계절은 봄 입니다." << std::endl;
		break;

	case Summer:
		std::cout << "생일이 속한 계절은 여름 입니다." << std::endl;
		break;

	case Fall:
		std::cout << "생일이 속한 계절은 가을 입니다." << std::endl;
		break;

	default:
		std::cout << "생일이 속한 계절은 봄 입니다." << std::endl;
		break;
	}
}
