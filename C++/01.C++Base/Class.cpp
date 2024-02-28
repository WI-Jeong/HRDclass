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












}
