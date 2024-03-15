// ProjectNote.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <random>

enum RSP
{
	Exit,
	SCISSOR,
	ROCK,
	PAPER
};


int main()
{
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

    return 0;
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
