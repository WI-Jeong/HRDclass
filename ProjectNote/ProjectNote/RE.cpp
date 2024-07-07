#include <stdio.h>
#include <iostream>
#include <thread>
using namespace std;


int main()
{
	short s = 0;
	s = 65535;
	std::cout << "Short변수 s의 값은: " << s << std::endl;

	unsigned s1 = 0;
	s1 = 65535;
	std::cout << "unsigned short타입 변수 s1의 값은: " << s1 << std::endl;

	char c = 0;
	c = 255;
	std::cout << "char변수 c의 값은: " << (int)c << std::endl;

	unsigned char c1 = 0;
	c1 = 255;
	std::cout << "unsigned char변수 c1의 값은: " << (int)c1 << std::endl;


}