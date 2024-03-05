#include <iostream>
#include <format>
#include<array>
#include "Main.h"

int main()
{

	/*
	unsigned char Buff = EBuff::Attack | EBuff::HP;

	if ((Buff & EBuff::Armor) == 0)
	{
		std::cout << "Armor 버프는 포함되어 있지 않습니다.\n";
	}
	else
	{
		std::cout << "Armor 버프는 포함되어있습니다.\n";
	}


	if ((Buff & EBuff::Attack) == 0)
	{
		std::cout << "Attack 버프는 포함되어 있지 않습니다.\n";
	}
	else
	{
		std::cout << "Attack 버프는 포함되어있습니다.\n";
	}

	if ((Buff & EBuff::HP) == 0)
	{
		std::cout << "HP 버프는 포함되어 있지 않습니다.\n";
	}
	else
	{
		std::cout << "HP 버프는 포함되어있습니다.\n";
	}

	if ((Buff & EBuff::MP) == 0)
	{
		std::cout << "MP 버프는 포함되어 있지 않습니다.\n";
	}
	else
	{
		std::cout << "MP 버프는 포함되어있습니다.\n";
	}

	if ((Buff & EBuff::Critical) == 0)
	{
		std::cout << "Critical 버프는 포함되어 있지 않습니다.\n";
	}
	else
	{
		std::cout << "Critical 버프는 포함되어있습니다.\n";
	}


	unsigned char Buff1 = Buff | EBuff::Critical;

	*/

	/*
	bit flag
	

	unsigned char Property1 = EPropertyFlags::EProperty1;
	unsigned char Property3 = EPropertyFlags::EProperty3;

	unsigned char Property = Property1 | Property3;
	HasProperty(Property);

	unsigned char Property10 = Property | EPropertyFlags::EProperty7;
	HasProperty(Property10);

	unsigned char Property20 = Property10 & ~EPropertyFlags::EProperty1;
	HasProperty(Property20);



		enum EBuff
	{
		None,
		Attack,
		Armor,
		HP,
		MP,
		Critical
	};

	int buff = EBuff::Attack | EBuff::HP | EBuff::Critical;
	
	*/	

	/*
	배열
	int Array[3]{};

	int Arraysize = sizeof(Array);
	int ArrayElement = sizeof(Array[0]);
	int ArrayEleCount = Arraysize / ArrayElement;

	std::cout << Arraysize << "&" << ArrayElement << "&" << ArrayEleCount;

		std::array<int, 3> Array;

	size_t Size = Array.size();

	std::cout << Size;

	size_t TotalSize = sizeof(Array);
	std::cout << TotalSize;
	
	*/



#pragma region 11.반복문(loop)**
	{
		//{
		//	int i = 0;
		//	while (i < 5)
		//	{
		//		std::cout << std::format("i값은: {}\n", i);
		//		++i; // i = i + 1;

		//		if (i == 3)
		//		{
		//			std::cout << std::format("i가 3일때 탈출!\n");
		//			break;
		//		}
		//	}
		//}
		//{
		//	int i{ 30 };
		//	do
		//	{
		//		std::cout << std::format("i값은: {}\n", i);
		//		++i;
		//	} while (i < 5);	// false일때 탈출
		//	// 31 < 5 => false
		//}
		//{
		//	int length = 5;
		//	for (int i = 0; i < length; ++i)//, First())
		//	{
		//		std::cout << std::format("i값은: {}\n", i);
		//	}

		//	const int Size = 6;
		//	int Array[Size]{};
		//	for (int i = 0; i < Size; ++i)
		//	{
		//		Array[i] = i;
		//	}

		//	// 범위기반 for(range based for)
		//	for (int i : Array)
		//	{
		//		//i = 10000;
		//		std::cout << std::format("i 값은: {}\n", i);
		//	}

		//	std::array<int, Size> StdArray{};
		//	for (size_t i = 0; i < Size; ++i)
		//	{
		//		StdArray[i] = i;
		//	}

		//	for (int i : StdArray)
		//	{
		//		std::cout << std::format("i 값은: {}\n", i);
		//	}

		//	// CTAD(class template argument deduction; 클래스 템플릿 인수 추론)

		//	// C++20
		//	for (std::array Array2{ 1,2,3 }; int i : Array2)
		//	{
		//		std::cout << std::format("i 값은: {}\n", i);
		//	}
		//}


		{
			//어소트락 인강 13 반복문


		}





	}
#pragma endregion
#pragma region 12.포인터와 동적 메모리(pointer***, dynamic memory) + 레퍼런스***(Reference; 참조)
	//{
	//	// 메모리 할당과 관리하는 것은 C++프로그래밍에서 문제가 발생하기 쉬운 영역입니다.
	//	// 품질이 뛰어난 C++프로그램을 작성학기 위해서는 메모리 내부 작동 방식을 이해하고 있어야 합니다
	//	// 이번 시간에는 동적 메모리를 다루는 과정에서 어떤 위험에 빠지기 쉬운지 알아보고 이런 상황을
	//	// 해결하거나 애초에 방지하는 방법을 알아보겠습니다.

	//	// low-level(저수준; 낮은수준) 메모리 연산 방법은 new, new[], delete, delete[]
	//	// 또는 C스타일의 malloc(malloc allocation), free라는 함수를 사용하는 방법이 있습니다.
	//	// 요즘 와서는 로우레벨 메모리 연산을 최대한 피하는 추세라고 생각됩니다.
	//	// 저도 최근 몇년간 저수준의 동적 할당을 해본 경험이 손에 꼽을 수준인 것 같습니다.
	//	// 예를 들면 표준 라이브러리에서 제공하는 vector라는 컨테이너(동적 배열)가 있는데
	//	// 이를 사용하면 필요할 때 메모리를 늘리거나 줄일 수 있습니다.
	//	// 또는 동적으로 할당한 메모리를 사용하지 않으면 자동으로 해제해주는 shared_ptr 등의
	//	// 스마트 포인터를 사용하기도 합니다.

	//	// 동적 메모리를 이용하면 컴파일 시간에 크기를 확정할 수 없는 데이터를 다룰 수 있습니다.
	//	{
	//		// 지역변수는 지금까지 사용한바와 같이 시작과 끝 스코프({}) 내부에서 선언되는
	//		// 변수를 의미합니다.

	//		// 유저영역 메모리 공간은 크게 4구획으로 나누어 져있다고 생각하시면 편합니다
	//		// [코드영역]	: 소스코드가 기계어로 변환되어 로직을 수행하는 코드정보
	//		// [데이터영역]	: 전역변수, static 변수 등
	//		// [Heap]		: 동적 할당
	//		// [Stack]		: 지역변수

	//		// [프로그램의 메모리 구조]
	//		// 낮은주소 0000000.......
	//		// -------------------- 소스코드 영역 --------------
	//		// .... 소스코드들...
	//		// ---------------------데이터 영역  ---------------
	//		// .... 전역변수, static(정적) 변수
	//		// --------------------- Heap 영역   ---------------
	//		// ........ (실행 중에 메모리 할당하는 경우)
	//		// .......
	//		// .....
	//		// ...
	//		// ..
	//		// .
	//		// -------------------------------------------------
	//		// ....... (지역변수, 함수 복귀주소 등)
	//		// 
	//		// A
	//		// ->
	//		// Main
	//		// --------------------- Stack 영역 ----------------

	//		// 실행시간(런타임;run time)에 동적으로 메모리 공간이 필요한 경우 OS(운영체제;Operating System)
	//		// 에 메모리를 요청해야 하는데, 이런 과정에서 커널에 요청할 필요가 있습니다.
	//		// 커널은 OS 중 항상 메모리에 올라가 있는 운영체제의 핵심 부분으로, 하드웨어와 응용 프로그램
	//		// 사이에서 인터페이스 역할을 제공합니다.
	//		// 커널에 요청하는 경우 이를 system call이라고 합니다. (메모리 할당을 할때마다 system call이 발생
	//		// 하지는 않을 수 있습니다)
	//		// 이 system call은 유저 영역과 커널 영역을 넘나드는 호출로서 상당한 비용을 지불하게 됩니다.
	//	}

	//	{
	//		// 64비트 일때는 포인터의 크기는 8byte
	//		// 32비트 일때는 포인터의 크기는 4byte
	//		// [Stack]										// [Heap]
	//		// [0xfff] Pointer(8Byte; 64bit) = nullptr
	//		// 주소를 들고 있을 것이다. 그 주소를 찾아가면 int가 있다
	//		int* Pointer{ nullptr };	// 실제 값은 0, 프로그래머를 위해 0을 쓰는 것 보다
	//		// nullptr을 넣어주면 명확한 의미를 전달할 수 있다.

	//		// 포인터의 크기는 플랫폼 bit수에 대응해서 바뀜
	//		// 32bit라면 최대 표현 가능한 주소가 FFFF FFFF(10진수로 4,294,967,295) 으로 unsigned int범위에
	//		// 해당한다. 즉 4byte이다
	//		// 64bit라면 FFFF FFFF FFFF FFFF 8byte까지 표현할 수 있기 때문에.
	//		// 
	//		// int*의 의미는 지금 내가 가지고 있는 주소(*)로 가면 그 값은 int야 라는 의미입니다.
	//		// char* 라면 내가 가지고 있는 주소는 8byte 주소이지만, 그 주소로 가면 char 타입의 변수가 있다
	//		size_t Size = sizeof(int*);
	//		size_t Size2 = sizeof(char*);
	//	}
	//	{
	//		int a = 100;
	//		// [Stack]										// [Heap]
	//		// [0xfff] Pointer(8Byte; 64bit) = nullptr		
	//		int* Pointer{ nullptr };
	//		int b = 10;

//		// [Stack]										// [Heap]
//		// [0xfff] Pointer(8Byte; 64bit) = 0x100		0x100 int[4byte] = 10
//		Pointer = new int{ 10 };

//		// [Stack]										// [Heap]
//		// [0xfff] Pointer(8Byte; 64bit) = 0x100		0x100 int[4byte] = 10000
//		*Pointer = 10000;
//		std::cout << *Pointer << std::endl;
//		//Pointer = (int*)10000;	// 잠재적인 문제가 발생할 가능성이 아주 높다
//		//*Pointer = 500;
//		// 이렇게 동작할당을 하고 Memory를 해제하기 전에 다른 주소로 바꾸는 경우
//		// 할당한 메모리는 미아가 됩니다.
//		// 이를 메모리 누수(메모리 릭, memory leak)이라고 부릅니다.

//		// memory 할당 해제
//		delete Pointer;
//	}
//	{
//		// [Stack]										// [Heap]
//		// [0xfff] Pointer(8Byte; 64bit) = 0x100		0x100 int[4byte] = 5	
//		int* Pointer{ new int{5} };
//		// 동적할당을 하고 해당 스코프({})를 벗어나면 동적 할당한 메모리는 미아가 됩니다.
//		// 메모리 누수(메모리 릭, memory leak)

//		// delete를 해줌으로서 메모리 누수를 막을 수 있다.
//		delete Pointer;
//	}
//	{
//		// C언어를 배우셨다면 malloc을 사용해서 메모리를 할당 했을텐데, C++에서도 사용할 수 있습니다.
//		// malloc과 new는 큰 차이가 있습니다.
//		// 아직 배우지 않았지만, new와 delete는 struct 또는 class에서 생성자 소멸자를 호출해주는 특징이 있습니다.
//		// 그러나 malloc은 순수하게 memory만 할당 해줍니다.
//		// int* 입장에서도 new는 초기값{}을 지정할 수 있었지만, malloc은 지정 불가!
//		int* Pointer = (int*)malloc(sizeof(int));
//		*Pointer = 1000;
//		free(Pointer);
//	}
//	{
//		// 메모리 할당이 실패할 수도 있습니다.
//		// 컴퓨터에 메모리가 부족한 경우 동적 할당은 실패할 수 있습니다.
//		// nullptr
//		/*while (true)
//		{
//			new int;
//		}*/
//	}
//	{
//		// [Stack]										// [Heap]
//		// [0xfff] Array(8Byte; 64bit) = 0x100			0x100 [int][int][int][int][int][int]
//		// 
//		// 배열 동적 할당
//		int* Array = nullptr;
//		Array = new int[6] {0, 1, 2, 3, 4, 5};
//		Array[0] = 100;
//		for (int i = 0; i < 6; ++i)
//		{
//			Array[i] = i + 1;

//			// Array + n
//			// Array(Heap에 있는 주소) + n
//			// Array + 1 = Array주소에 + 4byte(int)의 주소

//			// Array(int*)	Array + 1    Array + 2    Array + 3 ...
//			// [00 00 00 01][00 00 00 02][00 00 00 03][00 00 00 04]

//			*(Array + i) = i + 2;
//		}
//		delete[] Array;
//	}
//	{
//		// [Stack]										// [Heap]
//		// [0xfff] Array(8Byte; 64bit) = 0x100			0x100 [int][int][int][int][int][int]
//		// 
//		// 배열 동적 할당
//		char* Array = nullptr;
//		Array = new char[6] {0, 1, 2, 3, 4, 5};
//		Array[0] = 100;
//		for (int i = 0; i < 6; ++i)
//		{
//			Array[i] = i + 1;

//			// Array + n
//			// Array(Heap에 있는 주소) + n
//			// Array + 1 = Array주소에 + 4byte(int)의 주소

//			// Array(char*)	Array + 1    Array + 2    Array + 3 ...
//			// [01]         [02]         [03]         [04]
//			//int* Test = (int* )Array;
//			// i offset 만큼 떨어진 위치의 값을 바꾸기겠다
//			*(Array + i) = i + 2;
//			// 리틀엔디안 빅엔디안 (컴퓨터 내부에서 비트를 처리하는 방식)
//			//*(Test + 1) = 5;
//		}
//		delete[] Array;
//	}
//}
#pragma endregion

int 

}







	
}