// Fill out your copyright notice in the Description page of Project Settings.


#include "PhaseCharacter.h"

APhaseCharacter::APhaseCharacter()
{
	// 에셋 로드
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> MeshAsset(TEXT("/Script/Engine.SkeletalMesh'/Game/ParagonPhase/Characters/Heroes/Phase/Meshes/Phase_GDC.Phase_GDC'"));

	if (MeshAsset.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(MeshAsset.Object);
	}

	//위치 조정
	GetCapsuleComponent()->SetCapsuleHalfHeight(90.f);

	GetMesh()->SetRelativeLocation(FVector(0.0, 0.0, -90.0)); 
	//double type
	//XYZ 순서

	GetMesh()->SetRelativeRotation(FRotator(0.0, -90.0, 0.0));
	//YZX 순서
	//Pitch Y
	//Yaw   Z
	//Roll  X
}
