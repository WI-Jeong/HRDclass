#include "Engine/GameInstanceTest.h"

void UGameInstanceTest::Initailize()
{
    Super::Initailize();
    E_Log(trace, "Hello");
}

void UGameInstanceTest::StartGameInstance()
{
    Super::StartGameInstance();
}

UGameInstanceTest::UGameInstanceTest()
{

}

UGameInstanceTest::~UGameInstanceTest()
{

}