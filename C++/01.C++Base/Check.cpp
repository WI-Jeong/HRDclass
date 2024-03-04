#include<iostream>
#include<format>
#include<array>


int main()
{
	//int a{}, b{}, c{};
	//a = 1;
	//b = 2;
	//c = 3;

	////1차원 배열
	//{
	//	//3개가 있다.
	//	int Array[3]{};

	//	//0번 인덱스(원소)에 1을 넣겠다
	//	Array[0] = 1;
	//	//1번 인덱스에 2를 넣겠다.
	//	Array[1] = 2;
	//	//2번 인덱스에 3을 넣겠다.
	//	Array[2] = 3;

	//	//Array의 시작 주소에서 size+index
	//	//메모리에 접근하겠다.

	//	//Array[3] = 4;
	//	//인덱스 범위 0~2를 벗어나서 초록색 밑줄 생기는거 볼 수 있음.

	//	/*
	//	#Pragma warning(disable:숫자)
	//	이거 하면 경고 뜬거 비활성화 하겠다는 것.
	//	숫자는 에러메세지에 뜬 숫자 넣어주면 됨.
	//	맨 위에 이거 넣어주면 됨.
	//	*/

	//	int ArraySize = sizeof(Array);
	//	int ArrayElemSize = sizeof(Array[0]);
	//	int ArrayElemCount = ArraySize / ArrayElemSize;
	//}

	////2차원 배열
	//{
	//	int Array[2][3]{};
	//	Array[0][0] = 1;
	//	Array[0][1] = 2;
	//	Array[0][2] = 3;
	//	Array[1][0] = 4;
	//	Array[1][1] = 5;
	//	Array[1][2] = 6;

	//}

	////컨테이너
	//{
	//	std::array<int, 3> Array;
	//	Array[0] = 1;
	//	Array[1] = 2;
	//	Array[2] = 3;

	//	size_t Size = Array.size();

	//	//typedef unsigned __int64 HI;
	//	//HI Size = Array.size();
	//}

	{

		//int i = 0;
		//while (i < 5)
		//{
		//	std::cout << std::format("i값은: {}\n", i);
		//	++i;

		//	if (i == 3)
		//	{
		//		std::cout << std::format("i가 3일때 탈출!\n");
		//		break;
		//	}
		//}



		//int i = 30;
		//do
		//{
		//	std::cout << std::format("i값은: {}\n",i);
		//	++i;
		//} while (i < 5);//false일 때 탈출
		////31<5->false


		////for
		//size_t length = 5;

		//for(size_t i=0; i<length;++i)
		//{
		//	std::cout << std::format("i값은: {}\n", i);

		//}
	}

	//const int Size = 5;
	//int Array[Size];
	////상수const만 배열선언 가능하다. const지우면 int Array[Size];여기 빨간줄 에러남

	//for (int i = 0; i < Size; ++i) //int i도 stack에 저장됨.
	//{
	//	Array[i] = i;

	//}

	const int Size = 6;
	int Array[Size]{};

	//for (int i = 0; i < Size; ++i) //int i도 stack에 저장됨.
	//{
	//	Array[i] = i;

	//}

	//for (int i : Array)
	//{
	//	std::cout << std::format("i값은: {}\n", i);
	//}


	//std::array<int, Size> StArray{};
	//for (size_t i = 0; i < Size; ++i)
	//{
	//	StArray[i] = i;
	//}

	//for (int i : StArray)
	//{
	//	std::cout << std::format("i값은: {}\n", i);
	//}

	//for (std::array Array2{ 1,2,3 }; int i : Array2)
	//{
	//	std::cout << std::format("i값은: {}\n", i);
	//}

	//int number = 0;

	//while (number<5)
	//{
	//	std::cout << std::format("number: {}\n", number);
	//	++number;

	//	if (number == 3)
	//	{
	//		std::cout << std::format("i가 3일 때 종료\n", number);
	//		break;
	//	}
	//}

	//int i = 30;
	//do
	//{
	//	std::cout << std::format("i값은: {}\n", i);
	//	++i;
	//} while (i < 5);//false일 때 탈출
	////31<5->false
	////



	//int sum = 0;
	//int i = 1;

	////do
	////{
	////	sum += i;
	////	++i;
	////} while (i <= 10);

	//////std::cout << "1부터 10까지 합은: " << sum << std::endl;


	//while (i <= 10)
	//{
	//	sum += i;
	//	++i;	
	//}
	//std::cout << std::format("1부터 10까지 합은: {}\n", sum);

	//for (int i = 1; i < 100; ++i)
	//{
	//	if (i % 2 != 0)
	//		continue;
	//	std::cout << i << std::endl;
	//}

	//for (int i = 2; i < 100; i += 2)
	//{
	//	std::cout << i << std::endl;
	//}


	//{

	//	//64비트 환경에서 포인터의 크기는 8byte(최대 2의 8승까지)
	//	//32비트 환경에서 포인터의 크기는 4바이트.
	//	//size_t Size = sizeof(int*); 로 확인 가능

	//	//[Stack]										//[Heap]
	//	//[0x???] Pointer(8바이트;64비트)=
	//	//포인터 변수는 stack에 만들어지고 heap에 없음
	//	//int*: 주소를 들고 있을 것이다.
	//	//그 주소를 찾아가면 int가 있다.
	//	int* Pointer{ nullptr }; 
	//	//실제 값은 0이지만 프로그래머를 위해 0을 쓰는 것보다 nullptr을 넣어주면
	//	//명확한 의미를 전달할 수 있다.
	//	//nullptr이랑 NULL은 같은데 C++에서는 nullptr을 더 자주 씀

	//	size_t Size = sizeof(int*);

	//	size_t Size2 = sizeof(char*);

	//	
	//}

	//{
	//	//[Stack]											//[heap]
	//	//[0xfff] Pointer(8byte;64bit) =nullptr
	//	int* Pointer{ nullptr };	

	//}

}
