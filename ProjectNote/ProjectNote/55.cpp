#include <iostream>
#include "func.h"
#include "general.h"

int g_i = 0;
static int gstatic = 0;

int Test()
{
	static int i = 0;
	//++g_i;
	++i;
	
	return i;
}

int main()
{
	int i = Mul(10, 20);
	g_iExtern = 500;
	Add(0, 0);

	Test();
	Test();
	Test();
	Test();
	int icallcount=Test();

	//g_i = 0;

	//printf("Test함수 호출 횟수: %d\n", icallcount);

	ABC = 100;
	
}