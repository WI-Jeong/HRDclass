#include <iostream>
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

}


int main()
{
	wchar_t szString[100] = L"abc";


	wcscat_s(szString, 100, L"def");

	wcscat_s(wchar_t *Destination, rsize_t _SizeInWords, const wchar_t *_Source);
	wcscat_s<_Size>(wchar_t(&Destination)[_Size], const wchar_t *_Source);
}
