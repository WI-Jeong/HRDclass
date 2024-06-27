// Fill out your copyright notice in the Description page of Project Settings.


#include "RESSACGameModeBase.h"
#include "Player/PhaseCharacter.h"

ARESSACGameModeBase::ARESSACGameModeBase()
{
	DefaultPawnClass = APhaseCharacter::StaticClass();
}