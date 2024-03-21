#pragma once
#include"Headers.h"

class FEngine
{
public:
	void Run();

private:
	void Init();
	void Release();

	EMenuEvent PrintMenue();

	bool bTerminated = false;
};

inline FEngine GEngine;
