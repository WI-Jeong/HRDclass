// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../GameInfo.h"
#include "GameFramework/Character.h"
#include "PlayerAnimInstance.h" 
#include "InputActionValue.h"
#include "PlayerCharacter.generated.h"

UCLASS()
class RESSAC_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerCharacter();

protected:
	UPROPERTY(Category = Camera, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USpringArmComponent> mSpringArm;

	UPROPERTY(Category = Camera, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UCameraComponent> mCamera;

	bool	mCameraRotationEnable;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

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
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UInputMappingContext* DefaultContext;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UInputAction* MoveAction;

	TObjectPtr<class UPlayerAnimInstance> mPlayerAnim;

protected:
	void Move(const FInputActionValue& Value);

};
