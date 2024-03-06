#include <iostream>
#include <format>
#include "Function.h"

int main()
{	
	//문제 1 
	int A = 10;
	int B = 100;

	int* AP = &A;
	int* BP = &B;

	Swap(AP, BP);

	std::cout << std::format("A: {}, B: {}\n", A, B);


	//문제2
	std::array Numbers{ 1,2,3,4,5,6,7,8,9,10 };
	std::vector<int> Odds, Evens;
	SeperateOddsAndEvens(Numbers, Odds, Evens);



}