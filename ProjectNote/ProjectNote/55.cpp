#include <iostream>
#include <format>
#define NAME_SIZE 32


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

int main()
{
	FPlayer Player;
	Player.Tier = ETier::Gold;

}



