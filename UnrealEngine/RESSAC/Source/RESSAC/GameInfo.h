// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EngineMinimal.h"
#include "EngineGlobals.h"
#include "Engine.h"
#include "InputActionValue.h"   
#include "UObject/NoExportTypes.h"
#include "GameInfo.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(RESSAC, Log, All);    

#define   LOG_CALLINFO   (FString(__FUNCTION__) + TEXT("[") + FString::FromInt(__LINE__) + TEXT("]"))

#define   LOG(Format, ...)   UE_LOG(RESSAC, Warning, TEXT("%s : %s"), *LOG_CALLINFO, *FString::Printf(Format, ##__VA_ARGS__))

#define   LOGSTRING(str)      UE_LOG(RESSAC, Warning, TEXT("%s : %s"), *LOG_CALLINFO, *str)
/**
 *
 */
UCLASS()
class RESSAC_API UGameInfo : public UObject
{
	GENERATED_BODY()
};
