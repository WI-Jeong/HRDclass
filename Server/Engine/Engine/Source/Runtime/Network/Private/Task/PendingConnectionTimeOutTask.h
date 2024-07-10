#pragma once
#include "CoreMinimal.h"

class UNetDriver;
class UNetConnection;

struct FPendingConnectionTimeOutTask : public FTask
{
	FPendingConnectionTimeOutTask(UNetDriver* InNetDriver)
		: NetDriver(InNetDriver) {}

	virtual void ExecuteTask() override;

private:
	UNetDriver* NetDriver = nullptr;
};