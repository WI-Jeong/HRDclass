﻿#include "ServerGameMode.h"

void AServerGameMode::BeginPlay()
{
	Super::BeginPlay();

	NetDriver = NewObject<UNetDriver>(this);
	FNetworkNotify NetworkNotify;
	FURL URL;
	NetDriver->InitListen(NetworkNotify, URL, true, 5);

	auto& Vector = ObjectMap[UNetDriver::StaticClass()];
	for (engine_weak_ptr<UObject> It : Vector)
	{
		engine_weak_ptr<UNetDriver> ItNet = Cast<UNetDriver>(It);
	}
}

void AServerGameMode::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	NetDriver->Tick(DeltaSeconds);
}

AServerGameMode::AServerGameMode()
{

}

AServerGameMode::~AServerGameMode()
{
	
}