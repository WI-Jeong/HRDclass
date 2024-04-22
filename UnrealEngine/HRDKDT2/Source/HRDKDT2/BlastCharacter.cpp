// Fill out your copyright notice in the Description page of Project Settings.


#include "BlastCharacter.h"

ABlastCharacter::ABlastCharacter()
{
	static ConstructorHelpers::FObjectFinder<USkeletalMesh>	MeshAsset(TEXT("/Script/Engine.SkeletalMesh'/Game/ParagonTwinblast/Characters/Heroes/TwinBlast/Meshes/TwinBlast.TwinBlast'"));
	//static 을 붙이며 한번만 해줘서 중복 생성할 필요 없다.  

	//애셋 로드 성공하면
	if (MeshAsset.Succeeded())
	{
		//위에서 불러온 SkeletalMesh를 Character 클래스가 가지고 있는 SetSkeletalMesh에 지정해준다. 
		GetMesh()->SetSkeletalMesh(MeshAsset.Object);
	}

}
