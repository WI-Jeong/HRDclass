#include <iostream>
#include <format>



int main()
{
	for (int i = 0; i < 4; ++i)
	{
		if (i % 3 == 1)
		{
			continue;
		}

		printf("출력테스트\n");
	}

}