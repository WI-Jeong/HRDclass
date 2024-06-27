// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	mSpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	mCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));

	mSpringArm->SetRelativeLocation(FVector(0.0, 0.0, 160.0));
	mSpringArm->SetRelativeRotation(FRotator(-10.0, 90.0, 0.0));
	mSpringArm->TargetArmLength = 500.f;

	//부모 컴포넌트로 Mesh를 지정한다. 
	mSpringArm->SetupAttachment(GetMesh());

	//카메라는 부모만 지정
	mCamera->SetupAttachment(mSpringArm);

	mCameraRotationEnable = false;
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveFront"), this, &APlayerCharacter::MoveFront);
	PlayerInputComponent->BindAxis(TEXT("MoveSide"), this, &APlayerCharacter::MoveSide);
	PlayerInputComponent->BindAxis(TEXT("RotationCharacter"), this, &APlayerCharacter::RotationCharacterYaw);
	PlayerInputComponent->BindAxis(TEXT("RotationCamera"), this, &APlayerCharacter::RotationCharacterPitch);
	PlayerInputComponent->BindAxis(TEXT("CameraZoom"), this, &APlayerCharacter::CameraZoom);

	PlayerInputComponent->BindAction(TEXT("RotationCamera"), EInputEvent::IE_Pressed, this, &APlayerCharacter::RotationCamera);
	PlayerInputComponent->BindAction(TEXT("RotationCamera"), EInputEvent::IE_Released, this, &APlayerCharacter::RotationCameraReleased);
	PlayerInputComponent->BindAction(TEXT("Jump"), EInputEvent::IE_Pressed, this, &APlayerCharacter::JumpKey);
	PlayerInputComponent->BindAction(TEXT("Attack"), EInputEvent::IE_Pressed, this, &APlayerCharacter::AttackKey);

}

void APlayerCharacter::MoveFront(float Scale)
{
	AddMovementInput(GetActorForwardVector(), Scale);
}

void APlayerCharacter::MoveSide(float Scale)
{
	AddMovementInput(GetActorRightVector(), Scale);
}

void APlayerCharacter::RotationCharacterYaw(float Scale)
{
	if (mCameraRotationEnable)
	{
		float	Rot = 180.f * GetWorld()->GetDeltaSeconds() * Scale; 

		mSpringArm->AddRelativeRotation(FRotator(0.0, (double)Rot, 0.0));

	}
	else
	{
		AddControllerYawInput(Scale);
	}
}

void APlayerCharacter::RotationCharacterPitch(float Scale)
{
	if (mCameraRotationEnable)
	{
		float	Rot = 180.f * GetWorld()->GetDeltaSeconds() * Scale; //deltatime 가져오기 

		mSpringArm->AddRelativeRotation(FRotator((double)Rot, 0.0, 0.0));
	}
}

void APlayerCharacter::CameraZoom(float Scale)
{
	float	Length = Scale * 10.f;

	mSpringArm->TargetArmLength -= Length;

}

void APlayerCharacter::RotationCamera()
{
	mCameraRotationEnable = true;
}

void APlayerCharacter::RotationCameraReleased()
{
	mCameraRotationEnable = false;
}

void APlayerCharacter::JumpKey()
{
}

void APlayerCharacter::AttackKey()
{
}

