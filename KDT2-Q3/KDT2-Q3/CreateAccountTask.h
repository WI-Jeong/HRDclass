#pragma once
#include "Headers.h"

struct FCreateAccountTask
{
	FCreateAccountTask();

	FCreateAccountTask(const FCreateAccountTask&) = delete;
	FCreateAccountTask(const FCreateAccountTask&&) = delete;
	FCreateAccountTask& operator=(const FCreateAccountTask&) = delete;
};

