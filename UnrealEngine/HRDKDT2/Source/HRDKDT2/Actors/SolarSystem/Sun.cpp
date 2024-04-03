// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/SolarSystem/Sun.h"

// Sets default values
ASun::ASun()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	bool bCDO=HasAnyFlags(EObjectFlags::RF_ClassDefaultObject);

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	SetRootComponent(StaticMeshComponent);

	{
		static ConstructorHelpers::FObjectFinder<UStaticMesh> ObjectFinder(TEXT("/Script/Engine.StaticMesh'/Engine/BasicShapes/Sphere.Sphere'"));
		ensure(ObjectFinder.Object);
		StaticMeshComponent->SetStaticMesh(ObjectFinder.Object);
	}
	{
		static ConstructorHelpers::FObjectFinder<UMaterial> ObjectFinder(TEXT("/Script/Engine.Material'/Game/KDT2/SolarSystem/MT_Sun.MT_Sun'"));
		ensure(ObjectFinder.Object);
		StaticMeshComponent->SetMaterial(0,ObjectFinder.Object);
	}

}



void ASun::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);

	UMaterialInterface* Material=StaticMeshComponent->GetMaterial(0);

	MID = StaticMeshComponent->CreateDynamicMaterialInstance(0, Material);
}

// Called when the game starts or when spawned
void ASun::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

