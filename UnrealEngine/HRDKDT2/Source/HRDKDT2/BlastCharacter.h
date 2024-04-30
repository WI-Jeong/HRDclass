// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlayerCharacter.h"
#include "HRDKDT2.h"
#include "BlastCharacter.generated.h"

/**
 * 
 */
UCLASS()
class HRDKDT2_API ABlastCharacter : public APlayerCharacter
{
	GENERATED_BODY()

public:
	ABlastCharacter();

protected:
	UCapsuleComponent* CapsuleComponent;	
};
