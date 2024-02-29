#include <iostream>
#include <format>
#include "ClassFuncion.h"

int main()
{
#pragma region 02.변수(Variable)*
	{		// 지역변수와 메모리
		{
			// 유저영역 메모리 공간은 크게 4구획으로 나누어 져있다고 생각하시면 편합니다
			// [코드영역]	: 소스코드가 기계어로 변환되어 로직을 수행하는 코드정보
			// [데이터영역]	: 전역변수, static 변수 등
			// [Heap]		: 동적 할당
			// [Stack]		: 지역변수

			// [프로그램의 메모리 구조]
			// 낮은주소 0000000.......
			// -------------------- 소스코드 영역 --------------
			// .... 소스코드들...
			// ---------------------데이터 영역  ---------------
			// .... 전역변수, static(정적) 변수
			// --------------------- Heap 영역   ---------------
			// ........ (실행 중에 메모리 할당하는 경우)
			// .......
			// .....
			// ...
			// ..
			// .
			// -------------------------------------------------
			// ....... (지역변수)
			// ........
			// ..........
			// // Return 이후 실행해야 할 주소
			// ....
			// Main함수 RBP(Stack) 주소(미리 변수를 타입과 함께 선언했기 때문에 컴파일러가 해당 함수 Stack에서 어느정도 메모리를 사용할지 알기 때문에 미리 크기를 계산할 수 있다)
			// ....
			// (RBP + 상대 주소) [a](4byte) 
			// (RBP + 상대 주소) [b](4byte) 
			// (RBP + 상대 주소) [c](4byte) 
			// (RBP + 상대 주소) [d](4byte) 
			// (RBP + 상대 주소) [e](4byte) 
			// (RBP + 상대 주소) [f](4byte) 
			// (RBP + 상대 주소) [g](4byte) 
			// 
			// --------------------- Stack 영역 ----------------
			// 높은주소 FFFFFFF.......

		}		
	}
#pragma endregion

#pragma region 03.연산자

	{
		// 단항(unary; 유너리) 연산자: 표현식(expression) 하나를 계산
		// 이항(binary; 바이너리) 연산자: 표현식 2개를 계산
		// 삼항(temary; 텀메리) 연산자: 표현식 3개를 계산

		// 대입 연산자[이항]: 오른쪽 값을 왼쪽의 표현식에 대입하는 연산자
		{
			int i;
			i = 0;	// 대입; i = 0
			int k;
			k = i;	// 대입; k = 0
		}

		// [단항]표현식의 참/거짓 (참: 보통은1, 0이아닌값, 0이면 거짓)
		{
			bool b1{ true };	// 참
			bool b2{ 1 };		// 참
			bool b3{ false };	// 거짓
			bool b4{ 0 };		// 거짓

			bool b5{ !true };	// true의 not(true가 아니다): 거짓
			bool b6{ !false };	// false의 not(false가 아니다): 참

			bool b7{ true };	// true
			bool b8{ !b7 };		// b7(true)의 not: 거짓(false)
		}

		// [이항]사칙연산
		{
			int a{ 1 + 2 };	// 1+2 = 3 = a
			int b{ a + 3 };	// a + 3 = 3 + 3 = 6

			int c{ 1 - 2 }; // 1-2 = -1 = c
			unsigned int c2{ unsigned int(1 - 2) };

			int d{ c * 3 }; // -1 * 3 = -3 = d

			int e{ 10 / 3 }; // 3
			float f{ 10 / 3 };	// int(10) / int(3) = 3 -> float f = 3;
			float f2{ int(10) / int(3) };
			float f3{ 10.0f / 3.f };
		}

		// [이항]mod, 나머지 연산자
		{
			int m{ 10 % 3 };	// 몫 3, 나머지 1
			int m2{ 5 % 2 };	// 몫 2, 나머지 1
			int m3{ 6 % 2 };	// 몫 3, 나머지 0
		}

		// [단항]후행 / 선행 연산자
		{
			// 후행 증가
			{
				int i{ 0 };
				//i++;
				int k{ i++ }; // k = 0
				// 그리고 나서 i가 ++되어 1이 됩니다
				// k = 0
				// i = 1

				// 식 내부에 후행 연산자를 쓰지 마라
				// 실수 여지가 많다
			}
			// 선행 증가
			{
				int i{ 0 };
				// ++i;
				int k{ ++i }; // k = 1
				// i = 1

				// 이런 선행 수행 연산을 식 내부에 쓰지 마라
				/*++i;
				int k{ i };*/
			}
			// 후행 감소
			{
				int i{ 0 };
				//i--;	// i = -1;
				int k{ i-- }; // k = 0, i = -1
			}
			// 선행 감소
			{
				int i{ 0 };
				//--i;	// i = -1;
				int k{ --i }; // k = -1, i = -1
			}
		}

		// 사칙연산 축약 표현
		{
			int i{ 1 };
			int k{ 2 };

			// i = i + k; // i = {1 + 2} = 3
			i += k; // i = 3
			i += 2;	// i = 5

			i -= 3; // i = i - 3 = 5 - 3 = 2

			i *= 2; // 2 * 2 = 4
			i /= 2; // 4 / 2 = 2
			i %= 2;	// 2 % 2 = 0
		}

		// 비트 단위 연산
		{
			// AND 연산
			{
				// 둘다 1이면 1이고, 하나라도 0이면 0이다
				// 0010
				// 1111
				// ------ AND
				// 0010
				//char c = 2;
				char c = 0b0010;
				//char c2 = 15;
				char c2 = 0b1111;
				char c3 = c & c2;	// 2
			}
			// OR 연산
			{
				// 둘중에 하나라도 1이면 1이고, 둘다 0이면 0
				// 0010
				// 1111
				// ------ OR
				// 1111
				char c = 2;
				char c2 = 15;
				char c3 = c | c2; // 15
			}
			// XOR 연산(exclusive or)
			{
				// 서로 다르면 1, 같으면 0
				// 0010
				// 1111
				// ------ XOR
				// 1101		-> 1(2^0) + x(2^1) + 4(2^2) + 8(2^3) = 13

				// 1101
				// 1111
				// ------ XOR
				// 0010

				char c = 2;
				char c2 = 15;
				char c3 = c ^ c2;	// 13
			}
			// 비트 이동(shift) 연산
			{
				// 0000 = 0
				// 0001 = (2의 0승) = 1
				// 0010 = (2의 1승) = 2
				// 0100 = (2의 2승) = 4
				// 1000 = (2의 3승) = 8
				// 1100 = (2의 3승 + 2의 2승) = 8 + 4 = 12

				// 왼쪽으로 비트 이동
				{
					// 0001
					// 왼쪽으로 한칸 이동
					// 0010
					unsigned char c_ = 5;		// 0000 0101 : 5
					unsigned char c2_ = c_ << 1;// 0000 1010 : 8 + 2 = 10

					unsigned char c = 1;		// 0000 0001 : 1
					unsigned char c2 = c << 1;  // 0000 0010 : 2
					unsigned char c3 = c << 2;	// 0000 0100 : 4
					unsigned char c4 = c << 3;	// 0000 1000 : 8
				}
				// 오른쪽으로 비트 이동
				{
					unsigned char c = 8;		// 0000 1000 : 8
					unsigned char c2 = c >> 1;	// 0000 0100 : 4
					unsigned char c3 = c >> 2;	// 0000 0010 : 2
					unsigned char c4 = c >> 3;	// 0000 0001 : 1
					unsigned char c5 = c >> 4;	// 0000 0000 : 0
					unsigned char c6 = c >> 5;	// 0000 0000 : 0
				}
				// 음수의 경우 조금 다르게 동작
				{
					// MSB(Most Significant Bit) '1'111 1111
					// 부호있는 타입의 경우 음수를 표현하는 방법: MSB가 1이면 음수, 0이면 양수
					char Minus = -1;		// 1111 1111 : -1
					char c2 = Minus >> 1;	// 1111 1111 : -1 오른쪽으로 shift해도 계속 -1
					char c3 = Minus >> 2;	// 1111 1111 : -1 오른쪽으로 shift해도 계속 -1

					char c4 = Minus << 1;	// 1111 1110 : -2
					char c5 = Minus << 2;	// 1111 1100 : -4
				}
			}
		}

		// 삼항 연산(temary operator) / 조건 연산자
		{
			int i = 0;

			//int k = i == 0;
			// 조건이 만족하면 : 기준으로 왼쪽 결과
			// 조건이 만족하지 않으면 : 기준으로 오른쪽 결과	
			int k = i == 0 ? 10 : -10;
			int k2 = (i != 0) ? 10 : -10;
		}

		// 연산자 우선순위
		{
			int i = (10 - 5) * 5; // 5 * 5 = 25
			int i2 = 10 - 5 * 5; // 10 - 25 = -15
		}
	}


#pragma endregion



#pragma region 04.열거형(enumerated type, enum; 이넘)*
	{
		{
			// const: 상수(constant), 초기화 이후 해당 값을 변경할 수 없다
			const int Iron = 0;
			//Iron = 10;
			const int Bronze = 1;
			const int Silver = 2;
			const int Gold = 3;

			int MyTier = Gold;
		}
		{
			enum /*class*/ ETier : unsigned char
			{
				Iron /*= 10*/
				, Bronze
				, Silver /*= 20*/
				, Gold
			};

			// class키워드를 enum에 붙혀두면 cast를 해야 다른 type에 값을 넣을 수 있다
			unsigned char MyTier = (unsigned char)ETier::Gold;
			ETier MyTier2 = ETier::Bronze;
			ETier MyTier3 = (ETier)0;	// ETier::Iron

			//if (MyTier2 == ETier::Bronze)
			if (MyTier2 == 1)
			{
				std::cout << "Bronze\n";
			}

			if (MyTier == ETier::Gold)
			{
				std::cout << "Gold\n";
			}
		}
	}
#pragma endregion
#pragma region 05.구조체(struct)***
	{
		enum class ETier : unsigned char
		{
			None,
			Iron,
			Bronze,
			Silver,
			Gold,
		};

		/*int HP = 10;
		int MP = 0;*/
		// 구조체를 사용하면 데이터를 묶어서 들고 있을수 있게 한다
		struct FPlayer
		{
			int HP;// = 10;
			int MP = 0;
			ETier Tier = ETier::None;
			// 3Byte
		};

		ETier Tier = ETier::Gold;

		// FPlayer: 구조체 타입
		// Player: 인스턴스(instance; 실체화된 사례) (메모리에 만들어진 것)
		FPlayer Player{ .HP = 100, .MP = 20 };
		Player.HP = 100;
		Player.MP = 30;
		Player.Tier = ETier::Gold;

		// 컴파일 타임에 size를 계산해서 변수에 저장한다
		int Size = sizeof(FPlayer);
		int Size2 = sizeof(Player);
		//int Size3 = sizeof(long long);
		std::cout << "[Player Info]\n";
		//std::cout << "HP: " << Player.HP << "MP: " << Player.MP << std::endl;
		std::cout << std::format("HP: {}, MP: {}\n", Player.HP, Player.MP);
		//std::cout << Player.Tier;
		std::cout << std::format("Tier: {}\n", (int)Player.Tier);

		struct FPadding
		{
			char C;
			// Padding에 의해 3Byte 가 숨겨져 있다
			// 지금 가장 큰 기본 자료형 크기가 4Byte라서 4Byte 기준으로 4Byte보다 작은 경우 
			// padding이 생긴다

			char C2;
			char C3;
			char C4;
			// 4byte ----------

			char C5;
			// padding 3Byte
			// 8Byte-----------

			// padding은 바꿀 수 있다(padding이 생기지 않도록 처리할 수 있습니다)
			int I;
			// 12Byte ---------
		};

		struct FPadding2
		{
			char c;	// 1Byte
			// 7Byte padding

			double b;	// 8Byte
		};
		// 64bit(8Byte) 환경에서 한번에 접근해서 연산할수 있는 최대 단위가 8byte
		// padding을 비활성화 해서 다음과 같이
		// char / double (9)
		// [00] / [00 00 00 00 00 00 00 00]
		// [00] / [00 00 00 00 00 00 00]    // [00]
		// [00] 00 00 00 00 00 00 00 / [00 00 00 00 00 00 00 00]
		// double에 값을 쓰거나 읽으려고 했을때 padding이 잡혀있지 않으면
		// 2번 접근해야 하는 상황이 발생할 수 있다.
		// 그렇기 때문에 읽고 쓰는 속도가 느려질 수 있다.
	}
#pragma endregion
#pragma region 06.조건문(if / switch)***
	{
		// if
		{
			//int Value = 0;
			//std::cin >> Value;

			//// if 조건이 true if내부로 실행
			//// if 조건이 false else 실행
			//// else는 없을 수 있다
			//// 조건문을 사용하면 어떤 값이 참 또는 거짓인지에 따라 원하는 코드를 실행하는 문법
			//if (Value == 100)
			//{
			//	std::cout << "Value가 100입니다\n";
			//}
			//else
			//{
			//	std::cout << std::format("Value: {} 입니다\n", Value);
			//}

			// if(<초기자>;<조건문>)
			// if 조건이 true이면 if 내부로 실행
			// if 조건이 false이고, else if 조건이 만족하면, else if가 실행이 됩니다.
			// 전부 만족하지 않는 경우 else 가 실행 됩니다.
			if (int i = 10; i < 10)
			{
				std::cout << "1\n";
			}
			else if (i == 13)
			{
				std::cout << "2\n";
			}
			else if (i == 12)
			{
				std::cout << "3\n";
			}
			else if (i == 10)
			{
				std::cout << "4\n";
			}
			else
			{
				//i = 10000;
				std::cout << "5\n";
			}
		}

		// switch
		{
			enum class ETier : unsigned char
			{
				None,
				Iron,
				Bronze,
				Silver,
				Gold,
			};

			struct FPlayer
			{
				int HP = 100;
				int MP{ 10 };
				ETier Tier = ETier::None;
			};
			FPlayer Player;
			Player.Tier = ETier::Gold;
			std::cout << "[Player Info]\n";
			std::cout << std::format("HP: {}, MP: {}\n", Player.HP, Player.MP);
			//std::cout << std::format("Tier: {}\n", (int)Player.Tier);
			switch (Player.Tier)
			{
			case ETier::None:
				std::cout << "Tier: None\n";
				break;
			case ETier::Iron:
				std::cout << "Tier: Iron\n";
				break;
			case ETier::Bronze:
				std::cout << "Tier: Bronze\n";
				break;
			case ETier::Silver:
				std::cout << "Tier: Silver\n";
				break;
			case ETier::Gold:
				std::cout << "Tier: Gold\n";
				break;
			default:
				std::cout << "default\n";
				break;
			}

			if (Player.Tier == ETier::None)
			{
				std::cout << "Tier: None\n";
			}
			else if (Player.Tier == ETier::Iron)
			{
				std::cout << "Tier: Iron\n";
			}
			else if (Player.Tier == ETier::Bronze)
			{
				std::cout << "Tier: Bronze\n";
			}
			else if (Player.Tier == ETier::Silver)
			{
				std::cout << "Tier: Silver\n";
			}
			else if (Player.Tier == ETier::Gold)
			{
				std::cout << "Tier: Gold\n";
			}
			else
			{
				std::cout << "defaultn";
			}

			Player.Tier = ETier::Iron;
			switch (Player.Tier/*(ETier)4*/)
			{
			case ETier::Iron:
				std::cout << "분발하세요\n";
				[[fallthrough]]; // 에트리뷰트
			case ETier::Bronze:
			case ETier::Silver:
				std::cout << "Iron, Brone, Silver\n";
				break;
			case ETier::Gold:
				std::cout << "[Gold]\n";
				break;
			default:
				break;
			}

			Player.Tier = ETier::Gold;
			// Player.Tier == Iron 또는 Player.Tier == Bronze 인가요?
			if (
				Player.Tier == ETier::Iron
				|| Player.Tier == ETier::Bronze
				|| Player.Tier == ETier::Silver
				)
				//(
				// // 나는 Silver
				// Player.Tier == ETier::Iron  -> 거짓 (0)
				// || Player.Tier == ETier::Bronze -> 거짓 (0)
				// || Player.Tier == ETier::Silver -> 참 (1)
				//	)
				// 0 || 0 || 1
				// 0 || 1
				// 1
			{
				if (Player.Tier == ETier::Iron)
				{
					std::cout << "분발하세요\n";
				}
				std::cout << "Iron, Brone, Silver\n";
			}
			else if (Player.Tier == ETier::Gold)
			{
				std::cout << "[Gold]";
			}
		}
	}
#pragma endregion
#pragma region 07.논리연산자*
	{
		// 논리 부정
		if (!false) // true
		{
			std::cout << "!false";
		}

		// 논리곱(AND)
		// && : AND양쪽 조건이 모두 참인경우 true / 하나라도 거짓인 경우 false
		int a = 10;
		int b = 20;
		// 1. a == 10 ? true
		// 2. b == 10 ? false
		// 3. true && false => false
		//if (a == 10 && b == 10)

		// 1. a == 10 ? true
		// 2. b == 20 ? true
		// 3. true && true => true
		if (a == 10 && b == 20)
			// if ((a == 10 || a == 15) && b == 20)
		{
			std::cout << "a && b\n";
		}
		else
		{
			std::cout << "not a && b\n";
		}

		// 논리합(OR)
		// 1. a == 10 ? true
		// 2. 내부로 진입
		// b를 판단할 필요 없어 a가 이미 참이므로 내부로 진입한다
		if (a == 10 || b == 10)
		{
			std::cout << "a || b\n";
		}

		// 1. b == 10 ? false
		// 2. a == 10 ? true
		// 3. false || true => true
		if (b == 10 || a == 10)
		{
			std::cout << "a || b\n";
		}

		// 1. b == 500 ? false
		// 2. a == 2000? false
		// 3. false || false => false
		if (b == 500 || a == 2000)
		{
			std::cout << "a || b\n";
		}
		else
		{
			std::cout << "not a || b\n";
		}

		a = 10;
		b = 20;
		int c = 100;
		// 1. a == 10 ? true
		// 2. b == 20 ? true
		// 3. c == 100? true
		// true && true && true => true
		if (a == 10 && b == 20 && c == 100)
		{
			std::cout << "a && b && c\n";
		}

		// 1. a == 10 ? true
		// 2. (b == 50 || c == 100) ? true
		//	   b == 50 ? false
		//	   c == 100? true
		//	   false || true => true
		// 3. true(a==10) && (false || true)
		//    true && true => true
		if (a == 10 && (b == 50 || c == 100))
		{
			std::cout << "a && (b || c)\n";
		}

		if (First())
		{
			std::cout << "First!\n";
		}

		if (First() || Second())
		{
			std::cout << "First || Second\n";
		}

		if (Second() || First())
		{
			std::cout << "Second || First\n";
		}

		const bool bFirst = First();
		const bool bSecond = Second();
		//bSecond = false;
		if (bFirst || bSecond)
		{
			std::cout << "First || Second !\n";
		}
	}
#pragma endregion
#pragma region 08.함수(function)***
	{
		// 규모가 큰 프로그램에서 모든 코드를 main함수 안에 담게 되면 관리가 힘들 것 같습니다.
		// 코드 가독성(읽기 쉬운 정도)을 높이려면 코드를 간결하고 명확한 함수 단위로 나누는 것이 좋겠습니다.

		// C++에서 함수를 사용하려면 먼저 선언을 해야 합니다.
		// 반환타입		함수이름	(입력 파라미터(옵션))
		// void			FunctionName(int a, int b, ...)

		// 선언만 하고 구체적인 동작을 구현(정의)하지 않은 채 함수를 호출한 문장이 담긴 코드를 컴파일하면
		// 존재하지 않는 함수를 호출하기 때문에 링크 과정에서 에러가 발생합니다.

		// 디버거가 붙어있는 상황에서 F11을 눌러서 함수 내부로 진입할 수 있다
		FunctionName();

		// 이 함수를 호출하는 위치 기준으로 이 라인보다 위에 함수가 있다는 것을 
		// 알려주지 않으면 함수를 찾을수 없습니다.

		// 함수도 주소가 있고
		// 함수를 호출한다는건
		// >>> 돌아올 다음주소를 Backup해두고
		// >>> 함수의 주소로 이동했다가
		// >>> 그 함수를 수행하고
		// >>> ret을 만나면 Backup해둔 주소로 이동한다
		FunctionName();
		int a = 10;
		// 콜링컨벤션(Calling Conventions)
		// 함수를 호출하는 방법에 대한 종류
		// __cdecl, __stdcall, __thiscall, __fastcall

		// 파라미터를 던지는 경우 특정 레지스터(메모리)에 값을 backup했다가
		// 함수 내부로 진입해서 그 레지스터(메모리)에서 다른 메모리로 값을 복원한다
		// 이런것을 함수 호출의 오버해드라고 영어로 이야기 합니다.
		FunctionName(a);

		int Result = AddFunction(10, 20);
		int Result2 = AddFunction(11, 30);
		int Result3 = AddFunction(15, 40);
		int Result4 = AddFunction(3, 2);
		int Result5 = AddFunction(1, 3);
		AddFunction(10, 20);

		double Result6 = AddFunction(3., 2.45);

		unsigned long long Ret = Factorial(4);
		std::cout << std::format("{}\n", Ret);
	}
#pragma endregion

}