// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"

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

	static ConstructorHelpers::FObjectFinder<UInputMappingContext>DEFAULTCONTEXT(TEXT("/Script/EnhancedInput.InputMappingContext'/Game/Input/IMC_Move.IMC_Move'"));
	if (DEFAULTCONTEXT.Succeeded())
	{
		DefaultContext = DEFAULTCONTEXT.Object;
	}


	static ConstructorHelpers::FObjectFinder<UInputAction>IA_Move(TEXT("/Script/EnhancedInput.InputAction'/Game/Input/IA_Move.IA_Move'"));
	if (IA_Move.Succeeded())
	{
		MoveAction = IA_Move.Object;
	}

	static ConstructorHelpers::FClassFinder<UAnimInstance> AnimClass(TEXT("/Script/Engine.AnimBlueprint'/Game/Player/AB_Phase.AB_Phase_C'"));
	if (AnimClass.Succeeded())
	{
		GetMesh()->SetAnimInstanceClass(AnimClass.Class);
	}
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	if (APlayerController* PlayerController = Cast<APlayerController>(GetController()))
	{
		if (UEnhancedInputLocalPlayerSubsystem* SubSystem =
			ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
			SubSystem->AddMappingContext(DefaultContext, 0);
	}
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

	//PlayerInputComponent->BindAxis(TEXT("MoveFront"), this, &APlayerCharacter::MoveFront);
	//PlayerInputComponent->BindAxis(TEXT("MoveSide"), this, &APlayerCharacter::MoveSide);
	//PlayerInputComponent->BindAxis(TEXT("RotationCharacter"), this, &APlayerCharacter::RotationCharacterYaw);
	//PlayerInputComponent->BindAxis(TEXT("RotationCamera"), this, &APlayerCharacter::RotationCharacterPitch);
	//PlayerInputComponent->BindAxis(TEXT("CameraZoom"), this, &APlayerCharacter::CameraZoom);

	//PlayerInputComponent->BindAction(TEXT("RotationCamera"), EInputEvent::IE_Pressed, this, &APlayerCharacter::RotationCamera);
	//PlayerInputComponent->BindAction(TEXT("RotationCamera"), EInputEvent::IE_Released, this, &APlayerCharacter::RotationCameraReleased);
	//PlayerInputComponent->BindAction(TEXT("Jump"), EInputEvent::IE_Pressed, this, &APlayerCharacter::JumpKey);
	//PlayerInputComponent->BindAction(TEXT("Attack"), EInputEvent::IE_Pressed, this, &APlayerCharacter::AttackKey);

	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &APlayerCharacter::Move);
	}
}

void APlayerCharacter::MoveFront(float Scale)
{
	//AddMovementInput(GetActorForwardVector(), Scale);
}

void APlayerCharacter::MoveSide(float Scale)
{
	//AddMovementInput(GetActorRightVector(), Scale);
}

void APlayerCharacter::RotationCharacterYaw(float Scale)
{
	if (mCameraRotationEnable)
	{
		float	Rot = 180.f * GetWorld()->GetDeltaSeconds() * Scale; //deltatime 가져오기 

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
	//float	Length = Scale * 10.f;

	//mSpringArm->TargetArmLength -= Length;

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

void APlayerCharacter::Move(const FInputActionValue& Value)
{
	FVector2D MovementVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);

		// get right vector 
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		// add movement 
		AddMovementInput(ForwardDirection, MovementVector.Y);
		AddMovementInput(RightDirection, MovementVector.X);
	}
}
