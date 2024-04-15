#include <iostream>
#include <assert.h>
#include <format>
#include "func.h"
#include "general.h"
#define NAME_SIZE 32


struct player
{
	char name[NAME_SIZE];
	charactertype type;
	int i;
	int j;
	struct startest;
};

int main()
{
	player TESTPLAYER;

	std::cout << TESTPLAYER.i << std::endl;
	std::cout << TESTPLAYER.name << std::endl;
}







