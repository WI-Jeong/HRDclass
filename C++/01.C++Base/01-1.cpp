#include<iostream>


int main()
{

#pragma region 01. buf
	//const int iattack = 0x0000001;
	//const int iarmor = 0x0000002;
	//const int ihp = 0x0000004;
	//const int imp = 0x0000008;
	//const int icritical = 0x00000010;

	//int ibuf = iattack | ihp | imp | icritical;

	//std::cout << "ibuf: " << ibuf << std::endl;

	//std::cout << "attack: " << (ibuf & iattack) << std::endl;
	//std::cout << "armor: " << (ibuf & iarmor) << std::endl;
	//std::cout << "hp: " << (ibuf & ihp) << std::endl;
	//std::cout << "mp: " << (ibuf & imp) << std::endl;
	//std::cout << "critical: " << (ibuf & icritical) << std::endl;

#pragma endregion


#pragma region 02. 삼항연산

	//int i = 0;
	//int k = i == 0 ? 10 : -10;
	////std::cout << k;

	//int i2 = 7;
	//int k2 = i == 2 ? 8 : 6;
	////std::cout << k2;

	//int i3 = 57;
	//int k3 = i3 == i2 ? 1 : 0;
	//std::cout << k3;

#pragma endregion




#pragma region 03. 열거체

	//enum ETier : unsigned char
	//{
	//	None,
	//	Iron,
	//	Bronze,
	//	Silver,
	//	Gold
	//};


	//ETier MyTier=ETier::Gold;

	//if (MyTier == ETier::Gold)
	//{
	//	std::cout << "Gold\n";
	//}


	//ETier MyTier2=ETier::Bronze;

	//if (MyTier2 == ETier::Bronze)
	//{
	//	std::cout << "Bronze\n";
	//}

	//ETier MyTier3 = (ETier)2;
	//std::cout << "MyTier3= " << (int) MyTier3;





	//enum NUM
	//{
	//	num0 = 10,
	//	num1,
	//	num2,
	//	num3
	//};

	////NUM number;

	////std::cout << typeid(number).name() << std::endl;


	//Enum과 Enum class
	//enum Color
	//{
	//	RED = 1,
	//	GREEN = 2,
	//	BLUE = 3

	//};








#pragma region 04. 열거체 연습

	//enum Week
	//{
	//	Mon=1,
	//	Tue,
	//	Wed,
	//	Thu,
	//	Fri,
	//	Sat,
	//	Sun
	//};

	//enum Season : unsigned char
	//{
	//	Spring=1,
	//	Summer,
	//	Fall,
	//	Winter
	//};

	////Season Birthday = Season::Fall;
	////std::cout << "생일이 속한 계절= " << (int) Birthday << std::endl;


	//Season Birthday = Season::Fall;

	//switch (Birthday)
	//{
	//case Spring:
	//	std::cout << "생일이 속한 계절은 봄 입니다." << std::endl;
	//	break;

	//case Summer:
	//	std::cout << "생일이 속한 계절은 여름 입니다." << std::endl;
	//	break;

	//case Fall:
	//	std::cout << "생일이 속한 계절은 가을 입니다." << std::endl;
	//	break;

	//default:
	//	std::cout << "생일이 속한 계절은 봄 입니다." << std::endl;
	//	break;

	//}



#pragma endregion


	



}