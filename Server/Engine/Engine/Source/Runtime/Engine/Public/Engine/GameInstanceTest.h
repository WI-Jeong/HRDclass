#pragma once
// AssortRock Inc.

#include "CoreMinimal.h"
#include "GameInstance.h"
#include "GameInstanceTest.generated.h"

UCLASS()
class ENGINE_API UGameInstanceTest : public UGameInstance
{
    GENERATED_BODY();
public:

    virtual void Initailize() override;
    virtual void StartGameInstance() override;

public:
    UGameInstanceTest();
    ~UGameInstanceTest();
};