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
	//캡슐의 절반 높이는 기본 88로 되어있지만 매시의 키가 커서 90으로 설정
	GetCapsuleComponent()->SetCapsuleHalfHeight(90.f);

	//캡슐의 절반 높이가 90으로 설정되었기 때문에 기본 매시 출력은 캡술의 가운데를 발로 밟고 옆을 바라보게 하여 출력되어 있으므로
	//캡셜의 절반높이 인 90만큼 아래로 내려준다. 
	GetMesh()->SetRelativeLocation(FVector(0.0, 0.0, -90.0)); 
	//double type
	//XYZ 순서

	//전방을 바라보게 회전한다. 
	GetMesh()->SetRelativeRotation(FRotator(0.0, -90.0, 0.0));
	//YZX 순서
	//Pitch Y
	//Yaw   Z
	//Roll  X
}
