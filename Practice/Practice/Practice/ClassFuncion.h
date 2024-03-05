// #pragma once: 한번만 이 파일이 포함되게 해주세요
#pragma once
#include <iostream>

void /*__cdecl*/ FunctionName();
// 이름이 같고, 파라미터가 다른 함수를
// 함수를 오버로딩 했다고 표현합니다.
void FunctionName(int a);

[[nodiscard("할말")]] int AddFunction(int a, int b);
[[nodiscard("할말")]] double AddFunction(double a, double b);

inline bool First()
{
	std::cout << "[First]\n";
	return true;
}

inline bool Second()
{
	std::cout << "[Second]\n";
	return false;
}

// 재귀함수: 그 함수가 자기 자신을 호출하는 함수
[[nodiscard("")]] unsigned long long Factorial(unsigned char f);

// Bit Flag
// 클로킹
// 쉴드가 있는가?
enum EPropertyFlags : unsigned char // 1Byte
{
	// 16진수		2진수		왼쪽 쉬프트 연산	10진수
	ENone = 0x00,		// 0000 0000	0						0
	EProperty1 = 0x01,		// 0000 0001	1 << 0					1
	EProperty2 = 0x02,		// 0000 0010	1 << 1					2
	EProperty3 = 0x04,		// 0000 0100	1 << 2					4
	EProperty4 = 0x08,		// 0000 1000	1 << 3					8
	EProperty5 = 0x10,		// 0001 0000	1 << 4				   16
	EProperty6 = 0x20,		// 0010 0000	1 << 5				   32
	EProperty7 = 0x40,		// 0100 0000	1 << 6				   64
	EProperty8 = 0x80,		// 1000 0000	1 << 7				  128
};

void HasFlag(unsigned char InProperty);













//클로킹
//쉴드가 있는가?
enum EPropertyFlags :unsigned char
{
				//  16진수				2진수				왼쪽쉬피트연산					10진수
	ENone		=   0x00,		   //0b 0000 0000					0							0
	EProperty1  =   0x01,		   //0b 0000 0001					1<<0						1 
	EProperty2  =	0x02,		   //0b 0000 0010					1<<1						2
	EProperty3  =	0x04,		   //0b 0000 0100					1<<2						4
	EProperty4  =	0x08,		   //0b 0000 1000					1<<3						8
	EProperty5  =	0x10,		   //0b 0001 0000					1<<4						16
	EProperty6  =	0x20,		   //0b 0010 0000					1<<5						32
	EProperty7  =	0x40,		   //0b 0100 0000					1<<6						64
	EProperty8  =	0x80,		   //0b 1000 0000					1<<7						128

};


void HasFlag(unsigned char inProperty)

{
	//1번 속성이 활성화 되어 있나요?
	//0000 0001
	//0000 0001
	//-----------AND
	//0000 0001 
	// -->참
	//if문은 0이면 False, 0이 아니면 true

	if (inProperty & EPropertyFlags::EProperty1)
	{
		std::cout << "EPropertyFlags::EProperty1\n";

	}

	if (inProperty & EPropertyFlags::EProperty2)
	{
		std::cout << "EPropertyFlags::EProperty2\n";

	}

	if (inProperty & EPropertyFlags::EProperty3)
	{
		std::cout << "EPropertyFlags::EProperty3\n";

	}

	if (inProperty & EPropertyFlags::EProperty4)
	{
		std::cout << "EPropertyFlags::EProperty4\n";

	}

	if (inProperty & EPropertyFlags::EProperty5)
	{
		std::cout << "EPropertyFlags::EProperty5\n";

	}

	if (inProperty & EPropertyFlags::EProperty6)
	{
		std::cout << "EPropertyFlags::EProperty6\n";

	}

	if (inProperty & EPropertyFlags::EProperty7)
	{
		std::cout << "EPropertyFlags::EProperty7\n";

	}


	if (inProperty & EPropertyFlags::EProperty8)
	{
		std::cout << "EPropertyFlags::EProperty8\n";

	}
};


struct FParam
{
	FParam()
	{
		std::cout << "FPram\n";
	}

	FParam(int a)
	{
		std::cout << "FPram int a\n";
		Value[0] = a;
	}

	// 복사 생성자: 선언하지 않으면 자동으로 만들어 줍니다.
	// InParam 데이터를 기반으로 나(인스턴스)를 만드는데 그 데이터를
	// 가지고 와서 채울 목적으로 보통 사용하기 위해 복사생성자를 
	// 만듭니다.

	// 원본을 수정하지 않을 목적으로 const를 붙힘
	// 선언하지 않으면 자동으로 만들어주는 복사 생성자 같은 경우
	// 자동으로 InParam에 있는 모든 데이터를 복사해온다

	// 생성자류는 새로운 인스턴스가 만들어질때만 호출됩니다. (초기화 되는 시점)
	FParam(const FParam& InParam)
	{
		std::cout << "FPram 복사 생성자\n";
		for (int i = 0; i < 1000; ++i)
		{
			this->Value[i] = InParam.Value[i];
		}
	}

	// 대입 연산자
	// 예도 자동으로 만들어줌: 복사생성자랑 비슷하게 값을 복제
	// 연산자 오버로딩
	FParam& operator = (const FParam& InParam)
	{
		std::cout << "FPram 대입 연산자\n";
		for (int i = 0; i < 1000; ++i)
		{
			this->Value[i] = InParam.Value[i];
		}
		return *this;
	}

	~FParam()
	{
		std::cout << "~FPram\n";
	}

	int Value[1000]{};
};

// CallByValue
int Function(int a);
FParam Function(FParam InParam);
// CallByPointer
void Function(FParam* InParam);

void FunctionCallByPointer(int* InParam);
// CallByReference
void FunctionCallByReference(int& InParam);
void FunctionCallByReference(FParam& InParam);