#include <iostream>
#include <assert.h>
#include "func.h"
#include "general.h"



int main()
{
	int i{ 1 };
	int k{ 2 };

	i += k;	//i=i+k=1+2= 3
	i += 2;	//i=5
	i -= 3;	//i=2
	i *= 2;	//i=2*2=4
	i /= 2;	//i=2
	i %= 2;	//i=0

	int n = 4;
	n /= 3; // n=1
}
