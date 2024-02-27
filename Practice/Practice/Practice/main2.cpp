#include<iostream>

int main()
{
	const int iattack = 0x0000001;		
	const int iarmor = 0x0000002;
	const int ihp = 0x0000004;
	const int imp = 0x0000008;
	const int icritical = 0x00000010;

	int ibuf = iattack | ihp | icritical;

	std::cout << "attack=" << (ibuf & iattack) << std::endl;
	std::cout << "armor=" << (ibuf & iarmor) << std::endl;
	std::cout << "hp=" << (ibuf & ihp) << std::endl;
	std::cout << "mp=" << (ibuf & imp) << std::endl;
	std::cout << "critical=" << (ibuf & icritical) << std::endl;

}