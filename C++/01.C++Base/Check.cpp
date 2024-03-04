#include<iostream>
#include<format>
#include<array>


int main()
{
	int a{}, b{}, c{};
	a = 1;
	b = 2;
	c = 3;

	//1차원 배열
	{
		//3개가 있다.
		int Array[3]{};

		//0번 인덱스(원소)에 1을 넣겠다
		Array[0] = 1;
		//1번 인덱스에 2를 넣겠다.
		Array[1] = 2;
		//2번 인덱스에 3을 넣겠다.
		Array[2] = 3;

		//Array의 시작 주소에서 size+index
		//메모리에 접근하겠다.

		//Array[3] = 4;
		//인덱스 범위 0~2를 벗어나서 초록색 밑줄 생기는거 볼 수 있음.

		/*
		#Pragma warning(disable:숫자)
		이거 하면 경고 뜬거 비활성화 하겠다는 것.
		숫자는 에러메세지에 뜬 숫자 넣어주면 됨.
		맨 위에 이거 넣어주면 됨.
		*/

		int ArraySize = sizeof(Array);
		int ArrayElemSize = sizeof(Array[0]);
		int ArrayElemCount = ArraySize / ArrayElemSize;
	}

	//2차원 배열
	{
		int Array[2][3]{};
		Array[0][0] = 1;
		Array[0][1] = 2;
		Array[0][2] = 3;
		Array[1][0] = 4;
		Array[1][1] = 5;
		Array[1][2] = 6;

	}

	//컨테이너
	{
		std::array<int, 3> Array;
		Array[0] = 1;
		Array[1] = 2;
		Array[2] = 3;

		size_t Size = Array.size();

		//typedef unsigned __int64 HI;
		//HI Size = Array.size();
	}


}
