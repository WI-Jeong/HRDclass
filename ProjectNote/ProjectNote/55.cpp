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


unsigned int GetLength(const wchar_t* _pStr)
{
	//문자 개수 체크 용도
	int i = 0;

	while (true)
	{
		wchar_t c = _pStr[i];

		if ('\0' == c)
		{
			break;
		}

		++i;
	}

	return i;
}

void StrCat(wchar_t* _pDest, unsigned int _iSize, const wchar_t* _pSrc)
{
	int iDestLen = GetLength(_pDest);
	int iSrcLen = GetLength(_pSrc);

	if (_iSize < iDestLen + iSrcLen + 1)
	{
		//iDestLen + iSrcLen + 1=> NULL문자 공간까지 계산
		assert(nullptr);
	}

	//문자열 이어 붙이기 

}


int main()
{
	wchar_t szString[100] = L"abc";


	wcscat_s(szString, 100, L"def");



	

}
