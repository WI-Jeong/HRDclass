// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "HRDKDT2.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraActor.h"
#include "Camera/CameraComponent.h"
#include "PlayerCharacter.generated.h"


UCLASS()
class HRDKDT2_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	UPROPERTY(Category=Camera, VisibleAnywhere, Blueprintreadonly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USpringArmComponent> mSpringArm;

	UPROPERTY(Category = Camera, VisibleAnywhere, Blueprintreadonly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UCameraComponent> mCamera;

private:
	void MoveFront(float Scale);
	void MoveSide(float Scale);
	void RotationCharacterYaw(float Scale);
	void RotationCharacterPitch(float Scale);
	void CameraZoom(float Scale);

	void RotationCamera();
	void RotationCameraReleased();
	void JumpKey();
	void AttackKey();

protected:
	bool mCameraRotationEnable;


};
