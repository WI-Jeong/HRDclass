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

	int i = 0;
	int k = i == 0 ? 10 : -10;
	//std::cout << k;

	int i2 = 7;
	int k2 = i == 2 ? 8 : 6;
	//std::cout << k2;

	int i3 = 57;
	int k3 = i3 == i2 ? 1 : 0;
	std::cout << k3;

#pragma endregion


	



}