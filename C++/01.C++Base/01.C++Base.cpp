////솔루션 탐색기->모든 파일 표시로 변경
////프로젝트 우클릭->속성->중간 디렉터리 변경
////프로젝트 우클릭->속성->C++20
//
////솔루션(sln) 파일, 프로젝트(vcxproj) 파일 직접 notepad로 열어서 분석.
//// - 프로젝트: xml이라는 문법으로 만들어져 있었다.
////솔루션 빌드: 솔루션 안의 모든 파일 빌드.
//
///*
//빌드(Build)
//실행 파일을 만드는 과정
//1. 전처리(Preprocess): 소스코드에 담긴 메타 정보를 처리한다.
//#include <iostream> -> include 전처리 지시자. 
//이건 우리가 컴파일러에게 알려주는 기능
//무엇을 알려주는냐? include뒤에 나오는 파일을 포함하겠다 라고 알려주는것.
//포함이란 무엇인가? include 위치에 해당 파일을 복사 붙여넣기 한다.
//#include <iostream> 이거 줄 마우스 오른쪽 클릭해서 문서로 이동 클릭해보셈.
//
//2. 컴파일(Compile): 소스코드를 머신이 읽을 수 있는 파일로 변환한다. 
//                    (기계어 0과 1 그리고 이 0,1을 사람이 읽기 편한 어셈블리어로 변환할 수 도 있다.)
//3. 링크(Link): 컴파일 단계에서 변환한 여러 Object파일을 Application으로 합친다.
//               (우리가 작성한 소스코드들 + 가져다 쓴 코드(라이브러리) 등을 합친다.)
//*/
//
////* .pdb : 디버깅을 위한 정보가 들어있다.
////이건 실제 유저에게 배포할 때는 절대로 포함되면 안된다.
//
///*
//컴파일러
//컴파일러 제조사가 컴파일러를 표준 C++문법을 따라서 컴파일 되게 구현한 프로그램이다.
//MSVC(MicroSoft Visual C, C++) 컴파일러
//GCC
//*/
//
//// 전체 저장 ctrl shift s
//
////iostream: input output stream
////cout: cosole out. 콘솔창에 출력하겠다.
////std: 마우스올려보면 namespace std 라고 나올꺼임. 함수의 이름이 같더라도 std가 만든 cout을 쓰겠다. 이런뜻. 
////이름이 중복될 가능성이 크기 때문에 추가적인 구분을 위해 namespace통해 추가로 구분해줌
////std는 표준. 표준안에 구현되어 있는 cout을 사용한다! 
//
////프로그램은 한줄 한줄 한줄 실행. 어디서 시작할것인가. 콘솔_는 main함수를 시작으로.
//
///*
//구획을 나누기 위해 pragma사용해줄꺼임. 주석과 다르게 특정 구간 접었다 폈다 구획 나눌 수 있음.
//
//#pragma region 01.cout,cin
//    std::cout << "Hello World!\n";
//#pragma endregion
//*/
//
////위에 로컬 windows디버거 버튼을 클릭해서 디버깅가능. (F5)
////이거 옆에 디버그하지않고 시작 (ctrl F5)
//
////디버그하기위해서 브레이크 포인트(Break Point)활용
////이건 F5로 실행(디버거를 붙혀서 실행)하는 경우 해당 위치에 도달하면 자동으로 멈춘다.
////원하는 라인에 캐럿(클릭하면 생기는 깜빡이는 수직선)을 두고 F9을 누르면 된다. 
////또는 원하는 라인 가장 왼쪽에 마우스 올리면 회색 원이 생기는데 이걸 클릭하면 된다.
////이후 F10눌러서 한 줄 씩 실행 가능.
//
//
//
//
//#include <iostream>
//
//int main()
//{
//#pragma region 01.cout,cin
//    {
//        //namespace:여러 단체, 기업에 코드를 작성.
//        //이름이 중복될 가능성이 크기 때문에 추가적인 구분을 위해 namespace통해 추가로 구분해줌.
//        //std라는 namespace를 사용했고, std안에 구현되어 있는 cout을 사용했다.
//
//
//
//        //변수
//        //타입 변수의 이름
//        //int A = 5;
//        //int B{100};
//        //int B8{ 0144 };
//        //int B16{ 0x64 };
//        //int B2{ 0b01100100 };
//
//        //int C{ 77 };
//        //
//        //float F{ 3.14f };
//
//        //double D{ 3.14 };
//
//        //char C{ 'a' };
//
//
//
//
//
//        ////std::cin >> A;
//        ////std::cin >> B;
//
//        ////std::cout << "Hello World!\n";
//        //std::cout << "당신이 지정한 숫자 B는:" << B<<" A는:"<<A;
//    }
//    
//#pragma endregion
//
//
//#pragma region 03.변수(Variable)**
//    {
//        /*
//        자료형(byte)
//
//1byte=8bit
//1바이트는 2진수로 0000 0000 ~ 1111 1111까지
//즉, 10진수로 0~255까지 값을 표현할 수 있다.
//1024byte == 1KB
//1024KB == 1MB
//1024NB == 1GB
//1024GB == 1TB
//왜 1000단위가 아니라 1024인가? → 기본단위가 8bit라 계산하다보니.. 1000으로 자른것도 있긴함.
//1000KiB == 1MiB
//1000MiB ==1GiB
//비트: 2진수 (0,1)로
//
//정수형
//**char(1byte)**
//short(2바이트)
//**int(4바이트)**
//long(4바이트)
//long long(8바이트)
//int64 (8바이트)
//여기서 꼭 외워야할 것→char, int
//
//실수형
//float(4바이트)
//double(8바이트)
//
//
//        */
//
//        //{
//        //    int Var{ 0 }; //초기화 연산자로 변수를 선언과 동시에 초기화 할 수 있다.
//        //    Var = 10; //대입연산자를 사용해서 값 변경 가능.
//        //}
//        //{
//
//        //    signed int Var{ -1 }; //signed는 생략해도 자동으로 signed
//        //    Var = Var + 1;
//
//        //    unsigned int Var2{ (unsigned int) - 1};
//
//        //    Var2 = Var2 + 1;
//
//
//        //}
//
//        //{
//        //    //2바이트 정수형
//        //    //-32,768 ~ 32,767까지 표현 가능
//        //    //가장 큰 값인 32768에 1을 더해주면 -32,768로 값이 바뀜.
//        //    short S1{ 32767 };
//        //    S1 = S1 + 1;
//        //    S1 = S1 - 1;
//
//
//        //}
//
//        //{
//        //    long L1{ 14L };
//
//
//        //}
//
//        //{
//
//        //    int I{ (int)3.14f };
//        //    std::cout << I;
//        //}
//
//        {
//
//            char C = 255;
//            char C0 = 'A';
//            //A마우스 가져다대면 65가 나옴. 
//            //각 문자마다 숫자랑 1:1 대응이 되도록 약속이 되어있는데 그걸 ASCII 코드를 통해 볼 수 있다.
//            //즉, ASCII 코드 표에 대응되는 수치로 변환해서 저장.
//
//            int I = 'a';
//            //소문자 a 마우스 가져다대면 97로 나옴. 이것도 아스키코드에 볼 수 있음.
//
//            std::cout << C;
//            std::cout << std::endl;
//            std::cout << C0;
//            std::cout << std::endl;
//            std::cout << I;
//
//
//        }
//
//
//    }
//#pragma endregion
//
//}
//
//// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
//// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴
//
//// 시작을 위한 팁: 
////   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
////   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
////   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
////   4. [오류 목록] 창을 사용하여 오류를 봅니다.
////   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
////   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
//
//
////F5: 처음에 프로그램을 디버거를 붙혀서 켤 때
////    켜고난 다음에 F5를 누르면 다음 Greak Point를 만날때 까지 실행
////F10: 처음에 프로그램을 디버거를 붙혀서 켜고 첫 시작지점부터 멈춰있는다. 이후 F10으로 한줄씩 실행이 가능하다.

//복습
#include<iostream>

int main()
{
	//int A = 0;
	//int B{ 0 };

	//std::cout << A + B;

	//int C = 3;
	//int D{ 50 };

	//std::cout << D - C;


	//유니코드


	//2바이트
	//wchar_t W{ L'가' };

	//wchar_t W2{ L'A' };

	//wchar_t W3{ L'典' };

	//bool b0 = true; //1
	//bool b1 = false; //0
	//bool b2 = 0;  //false
	//bool b3 = 1; //true
	//bool b5 = 100; //true



	//부동 소수점 오차
	//{
	//	double Value = 0;

	//	if (Value==0)
	//	{
	//		std::cout << "Value가 0입니다.\n";
	//	}
	//	
	//	Value = Value + 0.1; //0.1
	//	Value = Value + 0.1; //0.2
	//	Value = Value + 0.1; //0.3

	//	if (Value == 0.3)
	//	{
	//		std::cout << "Value가 0.3입니다.\n";
	//	}

	//	std::cout << Value << std::endl;



	//}

	////0초기화(Zero initailizaion)
	//{
	//	//초기화란 변수를 선언함과 동시에 값을 지정하는 것을 의미

	//	int AA;
	//	AA = 10; //초기화가 아님. 값을 대입

	//	int BB = 0; //선언과 동시에 값을 지정(초기화)

	//	//초기화 방식 3개

	//}

	////형변환(Cast): 서로 다른 타입으로 변환
	////C++에는 int, float 등 다양한 타입들이 있기 때문에 타입간 변환이 필요한 상황이 발생한다.
	//{
	//	float F{ 3.14f };
	//	int Int = F;  
	//	//묵시적 casting (특별히 언급하지 않았는데 자동으로 casting) "경고"

	//	int Int2 = (int)F; 
	//	//명시적 casting. C스타일 cast.

	//	int Int3 = int(F); 
	//	//명시적 casting. C스타일 cast.

	//	int Int4 = static_cast<int>(F); 
	//	//C++ 버전의 명시적 cast



	//	//2바이트 정수 타입
	//	short Short{ 10 };

	//	//4바이트 정수
	//	int Int5 = Short; 
	//	//->묵시적 casting
	//	//int(4)가 short(2)보다 더 크고, 둘 다 정수 타입이기 때문에 경고가 발생하지 않는다.

	//	std::cout << F;


	//	signed int Var{ -1 };
	//	unsigned int Var2{ (unsigned int)-2 };


	//	
	//	signed short Sar{ -1 };

	//		
	//	unsigned short Sar1{ (unsigned short)-1 };
	//	Sar1 = Sar1 + 1;

	//	int I = 'A';


	//	long long LL1{ 14LL };
	//	unsigned int I1{ 4294967295 };
	//	unsigned int I2{ (unsigned int)4294967297 };
	//	long long LL2{ 4294967296 };
	//		
	//}


	////대입 연산자
	//{
	//	int i;
	//	i = 0;  // i = 0

	//	int k;
	//	k = i;  // k = 0

	//}

	////[단항] 표현식의 참/거짓 ->bool
	//{
	//	bool B1{ true };	// 참
	//	bool B2{ 1 };		//참
	//	bool B3{ false };	//거짓
	//	bool B4{ 0 };		//거짓

	//	bool B5{ !true };	//true의 not: 거짓
	//	bool B6{ !false };	//false의 not: 참

	//	bool B7{ true };	//참
	//	bool B8{ !B7 };		//거짓
	//}

	////[이항] 사칙연산
	//{
	//	int a{ 1 + 2 };		// 3
	//	int b{ a + 3 };		// 6

	//	int c{ 1 - 2 };		//-1
	//	unsigned int C2{ unsigned int(1-2) };		//4294967295

	//	int d{ c * 3 };		// -3

	//	int e{ 10 / 3 };	// 3

	//	float f{ 10 / 3 };	// 3
	//	//이건 int(10) / int(3)을 계산하고 나온 3을 float f에 대입하겠다 라는 뜻.

	//	float f2{ 10.f / 3.f };	// 3.333...


	//}

	//{

	//	int m{ 10 % 3 };	// 1
	//	int m2{ 5 % 2 };	// 1
	//	int m3{ 6 % 2 };	// 0

	//}

	//
	//{
	//	//
	//	int i{ 0 };

	//	
	//	int k{ i++ };
	//	// k = 0
	//	//k가 0이되고 나서 i가 ++되어 1이된다.
	//	//k = 0, i = 1
	//	
	//	//식 내부에 후행 연산자 사용하면 실수 여지가 많기 때문에 식 내부에 후행 연산자 사용 하지 않을 것을 추천



	//}
	//
	//{
	//	int i{ 0 };
	//	int k{ --i };
	//	//k=-1, i=-1


	//}

	////사칙연산 축약표현
	//{
	//	int i{ 1 };
	//	int k{ 2 };

	//	i += k;	//i=3
	//	i += 2;	//i=5

	//	i -= 3;	//i=2


	//	i *= 2;	//i=2*2=4
	//	i /= 2;	//i=2
	//	i %= 2;	//i=0

	//	int n = 4;
	//	n /= 3; // n=1

	//	int m = 5;
	//	m %= 2;	//m=


	//}

	//{
	//	char g = 2;
	//	char g2 = 15;
	//	char g3 = g & g2;	//g3=2

	//	char r = 2;
	//	char r2 = 15;
	//	char r3 = r | r2;	//r3=15

	//	char rg = 2;
	//	char rg2 = 15;
	//	char rg3 = rg ^rg2;	//rg3=13

	//}

	//Practice
	{



		const int iattack = 0x0000001;
		const int iarmor = 0x0000002;
		const int ihp = 0x0000004;
		const int imp = 0x0000008;
		const int icritical = 0x00000010;

		int ibuf = iattack | ihp | icritical; //10101

	


		std::cout << "Attack=" << (ibuf & iattack) << std::endl;
		std::cout << "Armor=" << (ibuf & iarmor) << std::endl;
		std::cout << "Hp=" << (ibuf & ihp) << std::endl;
		std::cout << "Mp=" << (ibuf & imp) << std::endl;
		std::cout << "Critical=" << (ibuf & icritical) << std::endl;

		ibuf ^= ihp;


	}

	{

		unsigned char c = 1;		// 0000 0001 ->10진수로 1 (2의 0승)
		unsigned char c2 = c << 1;	// 0000 0010 ->10진수로 2 (2의 1승)
		unsigned char c3 = c << 2;	// 0000 0100 ->10진수로 4 (2의 2승)
		unsigned char c4 = c << 3;	// 0000 1000 ->10진수로 8 (2의 3승)

		unsigned char c = 8;		
		// 0000 1000 ->10진수로 8

		unsigned char c2 = c >> 1;	
		// 0000 0100 ->10진수로 4

		unsigned char c3 = c >> 2;	
		// 0000 0010 ->10진수로 2

		unsigned char c4 = c >> 3;	
		// 0000 0001 ->10진수로 1

		unsigned char c5 = c >> 4;	
		// 0000 0000 ->10진수로 0

		unsigned char c6 = c >> 5;
		// 0000 0000 ->10진수로 0

		unsigned char c_ = 5;			// 0000 0101 -> 10진수로 5
		unsigned char c2_ = c_ << 1;	// 0000 1010 -> 10진수로 10





		char Minus = -1;
		// 1111 1111 ->10진수로 -1

		char C2 = Minus >> 1;
		// 1111 1111 ->10진수로 -1
		//-1을 오른쪽으로 shift해도 계속 -1

		char C3 = Minus >> 2;
		// 1111 1111 ->10진수로 -1
		//-1을 오른쪽으로 shift해도 계속 -1

		char C4 = Minus << 1;
		// 1111 1110 ->10진수로 -2

		char C4 = Minus << 2;
		// 1111 1100 ->10진수로 -4






	}

	{
		int i = 0;

		int k = i == 0;
		//k는 true니까 값이 1일 될꺼임.

		//조건이 만족하면 : 기준으로 왼쪽 결과
		//조건이 만족하지 않으면 : 기준으로 오른쪽 결과
		int k = i == 0 ? 10 : -10;
		//k=10

		int i = 2;
		int k = i == 0 ? 10 : -10;
		//k=-10

		int k2 = i != 2 ? 10 : -10;
		//i가 2가 아니면 10, 2이면 -10
		//k2는 -10


	}

	{
		int i = (10 - 5) * 5;
		//괄호 안부터 계산하고 *5해줌. 따라서 25가 나온다.

		int i2 = 10 - 5 * 5;
		//10-25가 되어 -15가 나온다.

	}





}


//프로젝트 속성->C/C++->코드생성->기본 런타임 검사->기본값으로 변경하기.

