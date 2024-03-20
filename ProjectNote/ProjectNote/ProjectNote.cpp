
#include <iostream>
#include <random>
#include <format>
#include <iomanip>



enum RSP
{
	Exit,
	SCISSOR,
	ROCK,
	PAPER
};

enum class ECostumeType 
{
    Armor, 
    Weapon,
    Face
};

enum class EShopItemType
{
    Potion,
    Armor,
    Weapon,
    Diamond
};

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
    /*
        std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 3); // Generate random numbers between 1 and 3

    int playerwin = 0;
    int aiwin = 0;
    int nobodywin = 0;

    while (true)
    {
        system("cls");

        std::cout << "1.가위\n2.바위\n3.보\n0. 종료" << std::endl;
        std::cout << "가위, 바위, 보 중 하나를 입력하세요: " << std::endl;
        int player = 0;
        std::cin >> player;

        if (player == SCISSOR)
            std::cout << "Player: 가위 " << std::endl;
        else if (player == ROCK)
            std::cout << "Player: 바위 " << std::endl;
        else if (player == PAPER)
            std::cout << "Player: 보 " << std::endl;
        else if (player == Exit)
        {
            int yn = 0;
            std::cout << "종료하시겠습니까?\n1.Y\n2.N." << std::endl;
            std::cin >> yn;
            if (yn == 1)
            {
                std::cout << "종료합니다." << std::endl;
                break;
            }
            if (yn == 2)
            {
                std::cout << "다시 시작합니다." << std::endl;
                system("pause");
                continue;
            }
        }
        else if (player > 3 || player < 1)
        {
            std::cout << "다시 입력하세요" << std::endl;
            system("pause");
            continue;
        }

        int ai = dis(gen);

        switch (ai)
        {
        case SCISSOR:
            std::cout << "AI: 가위" << std::endl;
            break;
        case ROCK:
            std::cout << "AI: 바위" << std::endl;
            break;
        default:
            std::cout << "AI: 보" << std::endl;
            break;
        }

        int result = player - ai;

        std::cout << std::endl;

        if (result == -2 || result == 1)
        {
            std::cout << "플레이어 승리" << std::endl;
            ++playerwin;
        }
        else if (result == 0)
        {
            std::cout << "무승부" << std::endl;
            ++nobodywin;
        }
        else
        {
            std::cout << "AI 승리" << std::endl;
            ++aiwin;
        }

        std::cout << std::endl;

        std::cout << "플레이어 승리 횟수: " << playerwin << std::endl;
        std::cout << "AI 승리 횟수: " << aiwin << std::endl;
        std::cout << "무승부 횟수: " << nobodywin << std::endl;

        if (playerwin >= 5)
        {
            std::cout << std::endl;
            std::cout << "플레이어가 5회 이상 이겼습니다.\n자동으로 종료합니다." << std::endl;
            break;
        }

        system("pause");

    }

    FPlayer Player;
Player.HP = 300;
Player.MP = 100;

int Value = 0;

std::cin >> Value;

if (Value == 100)
{
    std::cout << "Value가 100입니다.\n";
}

else
{
    std::cout << std::format("Value: {}입니다.\n", Value);
}

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
    std::cout << "5\n";
}

    FPlayer Player;
    Player.Tier = ETier::Gold;
    std::cout << "[Player Info]\n";
    //std::cout << std::format("HP: {}, MP: {}\n", Player.HP, Player.MP);
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

    std::random_device RD;
std::mt19937 Gen(RD());
std::uniform_int_distribution<int> Dist(0, 100);
int RandomValue = Dist(Gen);

int Upgrade = 0;
float fpercent = Dist(Gen);

std::cout << "Upgrade 기본 수치를 입력하세요: " << std::endl;
std::cin >> Upgrade;
std::cout << "Upgrade 기본수치: " << Upgrade << std::endl;
std::cout << "Percent: " << fpercent << std::endl;

if (Upgrade <= 3)
std::cout << "강화 성공" << std::endl;


else if (Upgrade >= 4 && Upgrade <= 6)
{
    if (fpercent < 40.f)
        std::cout << "강화 성공" << std::endl;

    else
        std::cout << "강화 실패" << std::endl;

}

else if (Upgrade >= 7 && Upgrade <= 9)
{
    if (fpercent < 10.f)
        std::cout << "강화 성공" << std::endl;

    else
        std::cout << "강화 실패" << std::endl;
}

else if (Upgrade >= 10 && Upgrade <= 13)
{
    if (fpercent < 1.f)
        std::cout << "강화 성공" << std::endl;

    else
        std::cout << "강화 실패" << std::endl;
}

else if (Upgrade >= 14 && Upgrade <= 15)
{
    if (fpercent < 0.01f)
        std::cout << "강화 성공" << std::endl;

    else
        std::cout << "강화 실패" << std::endl;
}
    */

/*
강화 확률 :
업그레이드가 0~3일 경우 강화 100 % 성공
업그레이드가 4~6일 경우 강화 40 % 성공
업그레이드가 7~9일 경우 강화 10 % 성공
업그레이드가 10~13일 경우 강화 1 % 성공
업그레이드가 14~15일 경우 강화 0.01 % 성공

업그레이드 수치는 직접 입력하게 한다.
*/

/*
std::random_device RD;
std::mt19937 Gen(RD());
std::uniform_int_distribution<> Dist(0.0f, 100.f);
float FPercent = Dist(Gen);
std::cout << FPercent;

//std::cout << "업그레이드 수치를 입력하세요(0~15)" << std::endl;

int Upgrade = 0;


std::cin >> Upgrade;
std::cout << std::format("업그레이드 수치: {}\n",Upgrade);

std::random_device rd;
std::mt19937 gen(rd());
std::uniform_real_distribution<> dis(0.0, 1.0); // Generate random real numbers between 0 and 1

int Upgrade = 0;
std::cout << "Upgrade 기본 수치를 입력하세요: " << std::endl;
std::cin >> Upgrade;
std::cout << "Upgrade 기본수치: " << Upgrade << std::endl;

double fpercent = dis(gen) * 100; // Generating random percent between 0 and 100

std::cout << std::fixed << std::setprecision(2); // Set precision for floating point numbers
std::cout << "Percent: " << fpercent << std::endl;

if (Upgrade <= 3)
std::cout << "강화 성공" << std::endl;
else if (Upgrade >= 4 && Upgrade <= 6)
{
    if (fpercent < 40.0)
        std::cout << "강화 성공" << std::endl;
    else
        std::cout << "강화 실패" << std::endl;
}
else if (Upgrade >= 7 && Upgrade <= 9)
{
    if (fpercent < 10.0)
        std::cout << "강화 성공" << std::endl;
    else
        std::cout << "강화 실패" << std::endl;
}
else if (Upgrade >= 10 && Upgrade <= 13)
{
    if (fpercent < 1.0)
        std::cout << "강화 성공" << std::endl;
    else
        std::cout << "강화 실패" << std::endl;
}
else if (Upgrade >= 14 && Upgrade <= 15)
{
    if (fpercent < 0.01)
        std::cout << "강화 성공" << std::endl;
    else
        std::cout << "강화 실패" << std::endl;
}

*/

/*
플레이어는 가위, 바위, 보 셋중 하나를 선택한다.
AI는 가위, 바위, 보 셋중 하나를 랜덤하게 얻어온다.
플레이어와 AI 중 누가 이겼는지를 판단한다.

+
가위바위보를 반복해서 하되 종료버튼을 추가하고, 그 외의 숫자들을 입력하면 다시 숫자를 선택하게 출력해라.
플레이어와 AI가 각각 몇 번 이겼는지 통계도 함께 출력되게 해라. 만약 플레이어의 누적 승리가 5회가 되면 자동으로 종료되게 만들어라.
*/

/*


*/

while (true)
{
    system("cls");

    std::cout << "다음 중 하나의 숫자를 고르시요\n1. 가위\n2. 바위\n3. 보\n0. 종료" << std::endl;

    int Player;
    std::cin >> Player;

    std::random_device RD;
    std::mt19937 Gen(RD());
    std::uniform_int_distribution<> Dis(1, 3);

    int AI = Dis(Gen);

    if (Player == SCISSOR)
    {
        std::cout << std::format("플레이어: 가위", Player);
    }
    else if (Player == ROCK)
    {
        std::cout << std::format("플레이어: 바위", Player);
    }
    else if (Player == PAPER)
    {
        std::cout << std::format("플레이어: 보", Player);
    }
    else if (Player == Exit)
    {
        std::cout << "종료하시겠습니까?\n1. Yes\n2. No" << std::endl;
        int Yes = 0;
        std::cin >> Yes;
        if (Yes == 1)
        {
            std::cout << "종료합니다." << std::endl;
            break;
        }
        if (Yes == 2)
        {
            std::cout << "다시 시작합니다." << std::endl;
            system("pause");
            continue;
        }
    }

    else
    {
        std::cout << "잘못입력했습니다. 다시 입력하세요." << std::endl;
        system("Pause");
        continue;
    }

}

//std::cout << std::format("플레이어: {}, AI: {}", Player, AI);

/*
#define HUNGRY 0x01
#define THIRSTY 0x02
#define TIRED 0x04
#define FIRE 0x08

#define COLD 0x10
#define POISON 0x20
#define POISON 0x40
#define POISON 0x80

#define POISON 0x100
#define POISON 0x200
#define POISON 0x400
#define POISON 0x800

    unsigned int iStatus = 0;
    iStatus |= HUNGRY;
    iStatus |= THIRSTY;

    if (iStatus & THIRSTY)
    {

    }

    iStatus &= ~THIRSTY;


*/;

/*
    int a = 0;
    {
        int a = 10;
        a = 30;
        std::cout << std::format("내부a의 값은: {}\n", a);
    }

    std::cout << std::format("외부a의 값은: {}", a);
*/

}
