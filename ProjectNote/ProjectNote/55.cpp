#include <iostream>
#include <format>
#include<time.h>


/*
업그레이드가 0~3일 경우 강화 100% 성공
업그레이드가 4~6일 경우 강화 40% 성공
업그레이드가 7~9일 경우 강화 10% 성공
업그레이드가 10~13일 경우 강화 1% 성공
업그레이드가 14~15일 경우 강화 0.01% 성공
업그레이드 수치는 직접 입력하게 한다.
*/


int main()
{
	srand((unsigned int)time(0));
	rand();

	std::cout << "업그레이드 수치를 입력하세요: \n";

	int Upgrade = 0;
	float Percent = rand() % 10000 / 100;

	std::cin >> Upgrade;


	std::cout << std::format("업그레이드 수치: {}, 강화확률: {}%",Upgrade,Percent);


;
}



