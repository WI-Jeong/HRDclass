#include <stdio.h>
#include <iostream>
#include <thread>
using namespace std;


int main()
{
	short s = 0;
	s = 65535;
	std::cout << "Short���� s�� ����: " << s << std::endl;

	unsigned s1 = 0;
	s1 = 65535;
	std::cout << "unsigned shortŸ�� ���� s1�� ����: " << s1 << std::endl;

	char c = 0;
	c = 255;
	std::cout << "char���� c�� ����: " << (int)c << std::endl;

	unsigned char c1 = 0;
	c1 = 255;
	std::cout << "unsigned char���� c1�� ����: " << (int)c1 << std::endl;


}