#include<iostream>

int Value = 20;

class Test
{
public:
	void Function()
	{
		printf_s("%d",Value);
	}
};

int main()
{
	Test* Ptr = nullptr;
	Ptr->Function();
}

