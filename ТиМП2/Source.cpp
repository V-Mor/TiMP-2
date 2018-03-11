#include<iostream>
using namespace std;
template <typename T>
class Stack
{
	int size, maxSize;
	struct stackElem
	{
		T value;
		stackElem* prev;
	} * head;
public:
	bool set(T x);
	T get();
	void clear();
	int getSize();
	Stack(int size);
	~Stack();
};

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

template <typename T>
bool Stack<T>::set(T x)
{
	if (!head)
	{
		head = new stackElem;
		head->prev = NULL;
		head->value = x;
		size++;
		return true;
	}
	if (++size > maxSize)
	{
		cout << "Превышен максимальный размер стека!\n";
		return false;
	}
	stackElem* el = new stackElem;
	el->prev = head;
	el->value = x;
	head = el;
	return true;
}

template <typename T>
T Stack<T>::get()
{
	if (!size)
	{
		cout << "Стек пуст!\n";
		return NULL;
	}
	T x = head->value;
	stackElem* temp = head;
	head = head->prev;
	delete temp;
	size--;
	return x;
}

template <typename T>
void Stack<T>::clear()
{
	stackElem* temp;
	while (head)
	{
		temp = head;
		head = head->prev;
		delete temp;
	}
	size = 0;
}

template <typename T>
int Stack<T>::getSize()
{
	return size;
}

template <typename T>
Stack<T>::Stack(int size)
{
	maxSize = size;
	Stack::size = 0;
	head = NULL;
}

template <typename T>
Stack<T>::~Stack()
{
	clear();
}