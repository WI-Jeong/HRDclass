#include <iostream>
#define HUNGRY 0x01
#define THIRSTY 0x02
#define TIRED 0x04
#define FIRE 0x08

#define COLD 0x10
#define POISON 0x20
//#define POISON 0x40
//#define POISON 0x80
//
//#define POISON 0x100
//#define POISON 0x200
//#define POISON 0x400
//#define POISON 0x800

int main()
{
	unsigned int iStatus = 0;
	iStatus |= HUNGRY;
	iStatus |= THIRSTY;

	if (iStatus & THIRSTY)
	{

	}

	iStatus &= ~THIRSTY;


}