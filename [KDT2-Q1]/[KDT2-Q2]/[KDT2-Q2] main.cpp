// [KDT2-Q2].cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <format>
#include <map>
#include "vector.h"

int main()
{
    KDT::vector<int> numbers;

    for (int i = 1; i <= 15; ++i) {
        numbers.push_back(i);
    }

    std::cout << "벡터의 모든 요소: ";

    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    numbers[2] = 27;
    numbers[5] = 50;
    numbers[6] = 100;

    std::cout << "수정된 벡터의 요소: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    numbers.resize(7);
    std::cout << "크기 조절 후 벡터의 크기: " << numbers.size() << std::endl;

    std::cout << "크기 조절 후 벡터의 요소: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;


    return 0;
}
