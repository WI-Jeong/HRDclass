#include<iostream>
#define PLUS(Value0, Value1) Value0 + Value1
#define MUL (Value0, Value1) Value0 * Value1

class A
{
public:
	A()
	{
		std::cout << "A";
		Function();
	}
	virtual void Function()
	{
		std::cout << "AF";
	}
};

class B :public A
{
public:
	B()
	{
		std::cout << "B";
		Function();
	}
	 void Function() override
	{
		std::cout << "BF";
	}
};

int main()
{
	B newB = B();
}