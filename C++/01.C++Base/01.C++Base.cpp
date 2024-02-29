
#include<iostream>
#include<format>
#include<time.h>

int main()
{
#pragma region 조건문

	/*
	장비 강화 성공/실패 구하기

	강화 확률 :
	업그레이드가 0~3일 경우 강화 100 % 성공
	업그레이드가 4~6일 경우 강화 40 % 성공
	업그레이드가 7~9일 경우 강화 10 % 성공
	업그레이드가 10~13일 경우 강화 1 % 성공
	업그레이드가 14~15일 경우 강화 0.01 % 성공

	업그레이드 수치는 직접 입력하게 한다.

	*/

	//int Upgrade = 0;
	//srand((unsigned int)time(0));
	//float Percent = rand() % 10000 / 100.f;
	//
	//std::cout << "업그레이드 수치를 입력하세요.\n업그레이드는 0부터 15까지 입니다.";
	//
	//std::cin >> Upgrade;
	//std::cout << Percent;
	//
	//if (Upgrade < 0 || Upgrade>15)
	//{
	//	std::cout << "다시 입력하세요.";
	//
	//}
	//
	//if (Upgrade >= 0 && Upgrade <= 3)
	//{
	//	std::cout << "강화성공" << std::endl;
	//}
	//
	//else if (Upgrade >= 4 && Upgrade <= 6)
	//{
	//	if (Percent < 40.f)
	//	{
	//		std::cout << "강화성공" << std::endl;
	//	}
	//
	//	else
	//	{
	//		std::cout << "강화실패" << std::endl;
	//	}
	//}
	//
	//else if (Upgrade >= 7 && Upgrade <=9)
	//{
	//	if (Percent < 10.f)
	//	{
	//		std::cout << "강화성공" << std::endl;
	//	}
	//
	//	else
	//	{
	//		std::cout << "강화실패" << std::endl;
	//	}
	//}
	//
	//else if (Upgrade >= 10 && Upgrade <= 13)
	//{
	//	if (Percent < 1.f)
	//	{
	//		std::cout << "강화성공" << std::endl;
	//	}
	//
	//	else
	//	{
	//		std::cout << "강화실패" << std::endl;
	//	}
	//}
	//
	//
	//else 
	//{
	//	if (Percent < 0.01f)
	//	{
	//		std::cout << "강화성공" << std::endl;
	//	}
	//
	//	else
	//	{
	//		std::cout << "강화실패" << std::endl;
	//	}
	//}



	//srand((unsigned int)time(0));
	//
	//int Upgrade = 0;
	//float fpercent = rand() % 10000 / 100.f;
	//
	//std::cout << "Upgrade 기본 수치를 입력하세요: " << std::endl;
	//std::cin >> Upgrade;
	//std::cout << "Upgrade 기본수치: " << Upgrade << std::endl;
	//std::cout << "Percent: " << fpercent << std::endl;
	//
	//if (Upgrade <= 3)
	//std::cout << "강화 성공" << std::endl;
	//
	//
	//else if (Upgrade >= 4 && Upgrade <= 6)
	//{
	//	if (fpercent < 40.f)
	//		std::cout << "강화 성공" << std::endl;
	//
	//	else
	//		std::cout << "강화 실패" << std::endl;
	//
	//}
	//
	//else if (Upgrade >= 7 && Upgrade <= 9)
	//{
	//	if (fpercent < 10.f)
	//		std::cout << "강화 성공" << std::endl;
	//
	//	else
	//		std::cout << "강화 실패" << std::endl;
	//}
	//
	//else if (Upgrade >= 10 && Upgrade <= 13)
	//{
	//	if (fpercent < 1.f)
	//		std::cout << "강화 성공" << std::endl;
	//
	//	else
	//		std::cout << "강화 실패" << std::endl;
	//}
	//
	//else if (Upgrade >= 14 && Upgrade <= 15)
	//{
	//	if (fpercent < 0.01f)
	//		std::cout << "강화 성공" << std::endl;
	//
	//	else
	//		std::cout << "강화 실패" << std::endl;
	//}
	//
	//
	//return 0; }

	//
	//{
	//
	//	//0부터 100가지 숫자 입력 후 그 수가 20보다 크면 더 작은 수 말하라고 하고 그 수가 20보다 작으면 up
	//	//20이면 정답
	//
	//
	//	int a = 0;
	//	std::cout << "0부터 100까지 숫자를 입력하세요.\n";
	//
	//	std::cin >> a;
	//
	//	while (true)
	//	{
	//		if (a < 0 || a>100)
	//		{
	//			std::cout << "다시 입력하세요.\n";
	//			break;
	//		}
	//
	//	}
	//
	//
	//	if (a == 20)
	//	{
	//		std::cout << "정답입니다.";
	//	}
	//
	//	else if (a > 20)
	//	{
	//		std::cout << "입력한 숫자보다 작습니다.";
	//	}
	//
	//	else
	//	{
	//		std::cout << "입력한 숫자보다 큽니다.";
	//	}
	//
	//
	//}


			/*
			장비 강화 성공/실패 구하기

			강화 확률 :
			장비 레벨이 0~3일 경우 강화 100 % 성공
			장비 레벨이 4~6일 경우 강화 40 % 성공
			장비 레벨이 7~9일 경우 강화 10 % 성공
			장비 레벨이 10~13일 경우 강화 1 % 성공
			장비 레벨이 14~15일 경우 강화 0.01 % 성공

			장비 레벨은 직접 입력하게 한다.

			*/

			//	srand((unsigned int)time(0));
			//
			//	int Level;
			//	std::cout << "장비 레벨을 입력하세요.";
			//	std::cin >> Level;
			//
			//	if (Level < 0 || Level>15)
			//	{
			//		std::cout << "잘못된 레벨입니다.";
			//	}
			//
			//	std::cout << "장비레벨: " << Level << std::endl;
			//
			//	float FPercent = rand() % 10000 / 100.f;
			//	std::cout << "강화확률= " << FPercent << std::endl;
			//
			//	if (Level >= 0 && Level <= 3)
			//	{
			//		std::cout << "100% 확률로 강화 성공합니다.";
			//	}
			//
			//	else if (Level >= 4 && Level <= 6)
			//	{
			//		std::cout << "70% 확률로 강화 성공합니다.";
			//
			//		if (FPercent <= 70.f)
			//		{
			//			std::cout << "강화성공";
			//		}
			//
			//		else
			//		{
			//			std::cout << "강화실패";
			//		}
			//	}
			//
			//	else if (Level >= 7 && Level <= 9)
			//	{
			//		std::cout << "30% 확률로 강화 성공합니다.";
			//
			//		if (FPercent <= 30.f)
			//		{
			//			std::cout << "강화성공";
			//		}
			//
			//		else
			//		{
			//			std::cout << "강화실패";
			//		}
			//	}
			//
			//
			//	else if (Level >= 10 && Level <= 13)
			//	{
			//		std::cout << "10% 확률로 강화 성공합니다.";
			//
			//		if (FPercent <= 10.f)
			//		{
			//			std::cout << "강화성공";
			//		}
			//
			//		else
			//		{
			//			std::cout << "강화실패";
			//		}
			//	}
			//
			//
			//	else if (Level >= 14 && Level <= 15)
			//	{
			//		std::cout << "1% 확률로 강화 성공합니다.";
			//
			//		if (FPercent <= 1.f)
			//		{
			//			std::cout << "강화성공";
			//		}
			//
			//		else
			//		{
			//			std::cout << "강화실패";
			//		}
			//	}
			//
			//}

#pragma endregion

#pragma region 01. 변수

/*
초기화 방법


int a = 7;
int b{ 98 };
int c(55);

*/

/*
int B{100}
==int B8{0144}
==int B16 {0x64}
==int B2{0b01100100}

*/

/*

unsigned int Var1{ (unsigned int)-1 };
unsigned int Var2{ (unsigned int)-2 };
srand((unsigned int)time(0));

int i = 77;
int k = i == 7 ? 100 : 200;

unsigned int Var1{ (unsigned int)-1 };
unsigned int Var2{ (unsigned int)-2 };
srand((unsigned int)time(0));

int i = 77;
int k = i == 7 ? 100 : 200;

*/




#pragma endregion


#pragma region 






#pragma endregion



#pragma region 06. 


#pragma endregion

#pragma region 07. 


#pragma endregion

#pragma region 08. 


#pragma endregion

}

