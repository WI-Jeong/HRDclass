#pragma once
#include<iostream>
#include <format>
#include<array>
#include<vector>



void Swap(int* InOutFirst, int* InOutSecond);

//포인터로 만든 스왑함수 레퍼런스로 만들어보기
void Swap(int& InOutFirst, int& InOutSecond);



void SeperateOddsAndEvens
(const std::array<int, 10>& InNumbers,
	std::vector<int>& OutOdds,
	std::vector<int>& OutEvens);

//레퍼런스로 만든 SeperateOddsAndEvens함수 포인터로 만들어보기.
void SeperateOddsAndEvens
(const std::array<int, 10>* InNumbers,
	std::vector<int>* OutOdds,
	std::vector<int>* OutEvens);


