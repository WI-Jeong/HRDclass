#include <stdio.h>
#include <iostream>
using namespace std;

void function(int count)
{
	for (int i = 0; i < count; i++)
	{
		cout << " i / count  = " << i << " / " << count << endl;
	}

}

int main()
{
	function(10);
	function(10);
	return 0;
}