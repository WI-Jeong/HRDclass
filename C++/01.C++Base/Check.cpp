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


	std::array<int, Size> StArray{};
	for (size_t i = 0; i < Size; ++i)
	{
		StArray[i] = i;
	}

	for (int i : StArray)
	{
		std::cout << std::format("i값은: {}\n", i);
	}

	for (std::array Array2{ 1,2,3 }; int i : Array2)
	{
		std::cout << std::format("i값은: {}\n", i);
	}




}
