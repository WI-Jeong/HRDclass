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
}


