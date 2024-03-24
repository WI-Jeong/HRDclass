#include<iostream>

class Test
{
public:
	virtual void Function()
	{

	}

private:
	bool Value0;
	int Value2;
	int Value3;
};


int main()
{
	std::cout << sizeof(Test);

	int Value = 0;
	int Value1 = 20;

	int& Ref = Value;

}