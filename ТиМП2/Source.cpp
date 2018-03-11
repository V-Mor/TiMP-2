#include<iostream>
#include"Stack.h"
#include"Queue.h"
using namespace std;
int main()
{
	setlocale(0, "");
	Queue<int> myQueue(5);
	for (int i = 0; i <= 4; ++i)
	{
		myQueue.set(i);
	}
	cout << myQueue.get() << endl;
	cout << myQueue.isEmpty() << endl;
	cout << myQueue.get() << endl;
	myQueue.clear();
	cout << myQueue.isEmpty() << endl;
	myQueue.set(156);
	myQueue.~Queue();
	
	return 0;
}
