#include"Function.h"

void Swap(int* InOutFirst, int* InOutSecond)
{
	int Temp = 0;

	Temp = *InOutFirst;

	*InOutFirst = *InOutSecond;

	*InOutSecond = Temp;

}

void SeperateOddsAndEvens(const std::array<int, 10>& InNumbers, std::vector<int>& OutOdds, std::vector<int>& OutEvens)
{
	for (int Value : InNumbers)
	{
		std::cout << Value << std::endl;

		if (Value % 2 == 1)
		{
			OutOdds.push_back(Value);
		}
		else
		{
			OutEvens.push_back(Value);
		}
	}
}
