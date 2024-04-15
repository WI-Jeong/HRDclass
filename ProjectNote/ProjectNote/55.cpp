#include <iostream>

void addPadding(int dataSize, int blockSize)
{
    int padding = blockSize - (dataSize % blockSize);
    std::cout << "Add " << padding << " bytes of padding" << std::endl;
}

int main()
{
    int dataSize = 12; // 데이터 크기
    int blockSize = 8; // 블록 크기
    addPadding(dataSize, blockSize);
    return 0;
}




