#include <iostream>
#include <assert.h>
#include "func.h"
#include "general.h"



int main()
{
	const int iattack = 0x0000001;
	const int iarmor = 0x0000002;
	const int ihp = 0x0000004;
	const int imp = 0x0000008;
	const int icritical = 0x00000010;

	int ibuf = iattack | ihp | icritical;
}
