template <typename T>
class Stack
{
	int size, maxSize;
	struct stackElem
	{
		T value;
		stackElem* prev;
	} *head;
public:
	bool set(T x);
	T get();
	void clear();
	int getSize();
	Stack(int size);
	~Stack();
};
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
	stackElem* temp = new stackElem;
	temp->prev = head;
	temp->value = x;
	head = temp;
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
	if (size)
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