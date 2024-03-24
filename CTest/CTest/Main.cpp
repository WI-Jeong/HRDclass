#include<iostream>
#define PLUS(Value0, Value1) Value0 + Value1
#define MUL (Value0, Value1) Value0 * Value1

int main()
{
	int Value = MUL(PLUS(10, 10), PLUS(10, 10));
}