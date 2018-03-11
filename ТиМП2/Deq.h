template <typename T>
class Deq
{
	int size, maxSize;
	struct deqElem
	{
		T value;
		deqElem* prev;
		deqElem* next;
	} *head, *tail;
public:
	bool setToHead(T x);
	bool setToTail(T x);
	T getFromHead();
	T getFromTail();
	void clear();
	bool isEmpty();
	Deq(int size);
	~Deq();
};

template <typename T>
bool Deq<T>::setToHead(T x)
{
	if (!head)
	{
		head = new deqElem;
		head->prev = NULL;
		head->next = NULL;
		head->value = x;
		tail = head;
		size++;
		return true;
	}
	if (++size > maxSize)
	{
		cout << "Превышен максимальный размер дека!\n";
		return false;
	}
	deqElem* temp = new deqElem;
	temp->prev = head;
	head->next = temp;
	temp->next = NULL;
	temp->value = x;
	head = temp;
	return true;
}

template <typename T>
bool Deq<T>::setToTail(T x)
{
	if (!head)
	{
		head = new deqElem;
		head->prev = NULL;
		head->next = NULL;
		head->value = x;
		tail = head;
		size++;
		return true;
	}
	if (++size > maxSize)
	{
		cout << "Превышен максимальный размер дека!\n";
		return false;
	}
	deqElem* temp = new deqElem;
	temp->next = tail;
	tail->prev = temp;
	temp->prev = NULL;
	temp->value = x;
	tail = temp;
	return true;
}

template <typename T>
T Deq<T>::getFromTail()
{
	if (!size)
	{
		cout << "Стек пуст!\n";
		return NULL;
	}
	T x = tail->value;
	deqElem* temp = tail;
	if(tail->next)
		(tail->next)->prev = NULL;
	tail = tail->next;
	delete temp;
	size--;
	return x;
}

template <typename T>
T Deq<T>::getFromHead()
{
	if (!size)
	{
		cout << "Стек пуст!\n";
		return NULL;
	}
	T x = head->value;
	deqElem* temp = head;
	if(head->prev)
		(head->prev)->next = NULL;
	head = head->next;
	delete temp;
	size--;
	return x;
}

template <typename T>
void Deq<T>::clear()
{
	deqElem* temp;
	while (head)
	{
		temp = head;
		head = head->prev;
		delete temp;
	}
	size = 0;
}

template <typename T>
bool Deq<T>::isEmpty()
{
	if (size)
		return false;
	return true;
}

template <typename T>
Deq<T>::Deq(int size)
{
	maxSize = size;
	Deq::size = 0;
	head = NULL;
	tail = NULL;
}

template <typename T>
Deq<T>::~Deq()
{
	clear();
}
