// Fill out your copyright notice in the Description page of Project Settings.


#include "BlastGameModeBase.h"
#include "BlastCharacter.h"

ABlastGameModeBase::ABlastGameModeBase()
{
	//DefaultPawnClass = ABlastCharacter::StaticClass();

	//클래스 래퍼런스 애셋 불러오기 (_C붙여야 한다. )
	static ConstructorHelpers::FClassFinder<ACharacter> BluePrintPawn(TEXT("/Script/Engine.Blueprint'/Game/KDT2/BluePrint/RPG/BPC_RPG.BPC_RPG_C'"));

	if (BluePrintPawn.Succeeded())
	{
		DefaultPawnClass = BluePrintPawn.Class;
	}
}
