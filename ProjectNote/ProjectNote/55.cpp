#include <iostream>
#include <format>
#define NAME_SIZE 32

struct player
{
	char name[NAME_SIZE];
	int i;
	int j;
	struct startest;
};

struct FPadding
{
	char C;

};

struct FPadding2
{
	char C;
	int I;
};

struct FPadding3
{
	int I;
	char C;
	char C2; 
	
};



int main()
{
	std::cout << sizeof(FPadding3);
}