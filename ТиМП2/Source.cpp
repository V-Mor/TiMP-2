#include<iostream>
#include"Stack.h"
using namespace std;
int main()
{
	setlocale(0, "");
	Stack<int> myStack(5);
	for (int i = 0; i <= 5; ++i)
	{
		myStack.set(i);
	}
	
	return 0;
}
