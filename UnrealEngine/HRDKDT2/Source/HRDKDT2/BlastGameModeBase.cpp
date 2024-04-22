// Fill out your copyright notice in the Description page of Project Settings.


#include "BlastGameModeBase.h"
#include "BlastCharacter.h"

ABlastGameModeBase::ABlastGameModeBase()
{
	DefaultPawnClass = ABlastCharacter::StaticClass();
}
