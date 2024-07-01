#pragma once
// AssortRock Inc.

#include "CoreMinimal.h"
#include "GameInstance.generated.h"

UCLASS()
class ENGINE_API UGameInstance : public UObject
{
	GENERATED_BODY();

public:
	virtual void Initailize();
	virtual void StartGameInstance();

public:
	UGameInstance();
	~UGameInstance();

	// weak_ptr World
};