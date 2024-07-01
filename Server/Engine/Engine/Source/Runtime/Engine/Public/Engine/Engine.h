#pragma once
#include "CoreMinimal.h"
#include "Engine.generated.h"

UCLASS()
class ENGINE_API UEngine : public UObject
{
	GENERATED_BODY()
public:
	UEngine();

public:
	void Init();
	void Start();
	void Tick(float DeltaSeconds);
	void PreExit();

protected:
	// World
};

extern ENGINE_API UEngine* GEngine;