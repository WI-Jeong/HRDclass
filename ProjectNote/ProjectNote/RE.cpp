#include <stdio.h>
#include <iostream>
#include <thread>
using namespace std;

void thread_function(int count)
{
	for (int i = 0; i < count; i++)
	{
		cout << " i - " << i << endl;
		this_thread::sleep_for(chrono::milliseconds(10));
	}
}

int main()
{
	thread _t1(thread_function, 10);

	thread _t2(thread_function, 10);
	cout << "main process" << endl;

	_t1.join();
	_t2.join();
	return 0;
}