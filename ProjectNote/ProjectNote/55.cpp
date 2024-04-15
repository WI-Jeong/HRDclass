#include <iostream>
#include <format>

struct temp {
    double e; // 8byte
    int a; // 4byte
    int b; // 4byte
    char c; // 1byte
    char d; // 1byte
    short f; // 2byte
};

void main()
{
    std::cout << std::format("구조체 temp의 크기 : {}\n", sizeof(temp));

}