#pragma once
#include "CoreMinimal.h"

class ENGINE_API UEngine : public UObject
{
public:
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UEngine);
	static UClass* StaticClass() { return UEngineRegisterEngineClass; }
	static inline UClass* UEngineRegisterEngineClass = GetPrivateStaticClassBody<UEngine>(TEXT("UEngine"),
		(UClass::ClassConstructorType)InternalConstructor<UEngine>, &UObject::StaticClass, nullptr);

	UEngine();

public:
	void Init();
	void Start();
	void Tick(float DeltaSeconds);
	void PreExit();

protected:
	// World
};