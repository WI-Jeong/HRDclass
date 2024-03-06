#pragma once
#include<iostream>
#include <format>
#include<array>
#include<vector>



void Swap(int* InOutFirst, int* InOutSecond);



void SeperateOddsAndEvens
(const std::array<int, 10>& InNumbers,
	std::vector<int>& OutOdds,
	std::vector<int>& OutEvens);

