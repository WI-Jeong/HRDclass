/*
솔루션 탐색기 -> 모든 파일 표시로 변경
프로젝트 우클릭 -> 속성 -> 중간 디렉터리를 변경
프로젝트 우클릭 -> 속성 -> C++20


 빌드(Build)
 실행 파일을 만드는 과정
 - 전처리(Preprocess): 소스코드에 담긴 메타정보를 처리한다
 - 컴파일(Compile): 소스코드를 머신이 읽을 수 있는 파일로 변환한다
					(기계어: 0,1; 0,1을 사람이 읽기 편한 어셈블리어로 변환할 수 도 있다)
 - 링크(Link): 컴파일 단계에서 변환한 여러 Object파일을 Application으로 합친다
			   (우리가 작성한 소스코드들 + 가져다 쓴 코드(라이브러리) 등을 합친다)


	시작을 위한 팁:
   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
   4. [오류 목록] 창을 사용하여 오류를 봅니다.
   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.


	프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
	프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

*/


#include <iostream>

int main()
{


#pragma region 01.변수

	//short s = 0;
	//s = 32767;
	//s += 1;
	//std::cout << "Short변수 s의 값은: " << s << std::endl;

	//unsigned s1 = 0;
	//s1 = 32767;
	//s1 += 1;
	//std::cout << "unsigned short타입 변수 s1의 값은: " << s1 << std::endl;

	//char c = 0;
	//c = 127;
	//c += 1;
	//std::cout << "char변수 c의 값은: " << (int) c << std::endl;

	//unsigned char c1 = 0;
	//c1 = 127;
	//c += 1;
	//std::cout << "unsigned char변수 c1의 값은: " <<(int) c1 << std::endl;



	//float I(3);
	//std::cout << I;

#pragma endregion


#pragma region 02.형변환

	//double d = 0.123456789;
	//float f = d;



#pragma endregion

#pragma region 포인터

	/*
	포인터

	int i = 100;
	int* Pointer = &i;

	std::cout << "i= " << i << std::endl;
	std::cout << "i address= " << &i << std::endl;
	std::cout << "Pointer= " << Pointer << std::endl;
	std::cout << "Pointer address= " << &Pointer << std::endl;

	*Pointer = 777;
	std::cout << "i= " << i << std::endl;
	std::cout << "i address= " << &i << std::endl;
	std::cout << "Pointer= " << Pointer << std::endl;
	std::cout << "Pointer address= " << &Pointer << std::endl;

	*/

	/*
	포인터와 배열
	int Array[100] = {};
	int* ArrayPointer = Array;
	int* ArrayPointer2 = (int*) & Array;

	std::cout << "Array= " << Array << std::endl;
	std::cout << "ArrayPointer= " << ArrayPointer << std::endl;
	std::cout << "ArrayPointer2= " << ArrayPointer2 << std::endl;
	std::cout << "Array[0]의 주소= " << &Array[0] << std::endl;
	std::cout << "&Array= " << &Array << std::endl;	
	
	*/

	/*
	포인터의 연산
	
	int Array[3] = {1,2,3};
	int* IArrayPointer = Array;

	std::cout << "Array[0]= " << Array[0] << std::endl;
	std::cout << "Array[1]= " << Array[1] << std::endl;
	std::cout << "Array[2]= " << Array[2] << std::endl;

	std::cout << "Array[0]Address= " << &Array[0] << std::endl;
	std::cout << "Array[1]Address= " << &Array[1] << std::endl;
	std::cout << "Array[2]Address= " << &Array[2] << std::endl;


	std::cout << "IArrayPointer+0= " << IArrayPointer + 0 << std::endl;
	std::cout << "IArrayPointer + 1 = " << IArrayPointer + 1 << std::endl;
	std::cout << "IArrayPointer+2= " << IArrayPointer + 2 << std::endl;
	
	*/

	/*
	동적할당

	struct Player
{
	char Name[32];
	char Test1;
	char Test2;
	int Option1;
	char Test3;
	int Option21;
	int Option3;

};

Player* player = new Player;

std::cout << " sizeof(Player): " << sizeof(Player) << std::endl;

(*player).Option1 = 1020;

delete player;

int* DynamicArray = new int[100];

delete[] DynamicArray;

	*/

/*
포인터
int i = 100;
float f = 3.f;

int* Point = &i;
int* Point2 = (int*) &f;

i = *Point2;

std::cout << i;

int* Point = nullptr;
int i = 0;

Point = &i;

Point += 1;





int iArr[10] = {};
iArr + 1; //4를 더한 주소(int배열이니까)

//배열의 이름이 배열 시작 주소가 됨.
//포인터 변수 앞에 * 붙이면 주소값으로 접근하는거.

*(iArr + 1) = 10;
//2번째 원소에 10을 넣어라.

*/

/*
포인터 문제

문제1
short sArr[10] = { 1,2,3,4,5,6,7,8,9,10 };
int* pI = (int*)sArr;
int iData = *((short*)(pI + 2));

printf("1번 문제 정답: %d\n", iData);



문제2
char cArr[2] = { 1,1 };
short* pS = (short*)cArr;
iData = *pS;

printf("2번 문제 정답: %d\n", iData);

*/

/*
int* PInt = nullptr;
char* PChar = nullptr;
short* PShort = nullptr;

std::cout << "Size of Pint= " << sizeof(PInt) << std::endl;
std::cout << "Size of PChar= " << sizeof(PChar) << std::endl;
std::cout << "Size of PShort= " << sizeof(PShort) << std::endl;

short sArr[10] = { 1,2,3,4,5,6,7,8,9,10 };
int* pI = (int*)sArr;
int iData = *((short*)(pI + 2));

printf("1번 문제 정답: %d\n", iData);

char cArr[2] = { 1,1 };
short* pS = (short*)cArr;
int iData = 0;
iData = *pS;

printf("2번 문제 정답: %d\n", iData);

*/





#pragma endregion

#pragma region xxxxx

#pragma endregion


#pragma region xxxxx

#pragma endregion


#pragma region xxxxx

#pragma endregion


#pragma region xxxxx

#pragma endregion


#pragma region xxxxx

#pragma endregion

#pragma region xxxxx

#pragma endregion



	
}