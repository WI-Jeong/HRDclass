#include<iostream>


int main()
{

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
		}
	}
#pragma endregion


}
