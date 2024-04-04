// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/TimelineComponent.h"
#include "Sun.generated.h"

UCLASS()
class HRDKDT2_API ASun : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASun();

protected:
	virtual void OnConstruction(const FTransform& Transform) override;
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* StaticMeshComponent=nullptr;

	UTimelineComponent* SunPowerTimelineComponent = nullptr;

	UMaterialInstanceDynamic* MID = nullptr;

};
