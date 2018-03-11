#include<iostream>
#include"Stack.h"
#include"Queue.h"
#include"Deq.h"
using namespace std;
int main()
{
	setlocale(0, "");
	Deq<int> myDeq(10);
	for (int i = 1; i <= 5; i++)
	{
		myDeq.setToHead(i);
		myDeq.setToTail(100 - i);
	}
	cout << myDeq.getFromHead() << endl;
	cout << myDeq.getFromTail() << endl;
	for (int i = 1; i <= 8; i++)
		cout << myDeq.getFromTail() << endl;
	
	return 0;
}
