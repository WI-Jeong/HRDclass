#include "ProjectGameInstance.h"

void UProjectGameInstance::Initailize()
{
	Super::Initailize();
}

void UProjectGameInstance::StartGameInstance()
{
	Super::StartGameInstance();

	UClass::LogReflectionData(this);
}

UProjectGameInstance::UProjectGameInstance()
{

}

UProjectGameInstance::~UProjectGameInstance()
{
	
}