#include <iostream>
#include <assert.h>
#include "func.h"
#include "general.h"



void Test(int a)
{

}

void Test(int a, int b)
{

}

void Test(float a)
{

}

void StrCat(wchar_t* _pDest, unsigned int _iSize, const wchar_t* _pSrc)
{
	assert(nullptr);
}


int main()
{
	wchar_t szString[100] = L"abc";


	wcscat_s(szString, 100, L"def");



	

}
