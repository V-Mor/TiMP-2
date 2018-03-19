template <typename T>
class Queue
{
	int size, maxSize;
	struct queueElem
	{
		T value;
		queueElem* prev;
		queueElem* next;
	} *head, *tail;
public:
	bool set(T x);
	T get();
	void clear();
	void showStatus();
	int getSize();
	bool isEmpty();
	Queue(int size);
	~Queue();
};

template <typename T>
bool Queue<T>::set(T x)
{
	if (!head)
	{
		head = new queueElem;
		head->prev = NULL;
		head->next = NULL;
		head->value = x;
		tail = head;
		size++;
		return true;
	}
	if (++size > maxSize)
	{
		cout << "Превышен максимальный размер очереди!\n";
		return false;
	}
	queueElem* temp = new queueElem;
	temp->prev = head;
	head->next = temp;
	temp->next = NULL;
	temp->value = x;
	head = temp;
	return true;
}

template <typename T>
T Queue<T>::get()
{
	if (!size)
	{
		cout << "Стек пуст!\n";
		return NULL;
	}
	T x = tail->value;
	queueElem* temp = tail;
	if(tail->next)
		(tail->next)->prev = NULL;
	tail = tail->next;
	if (size == 1)
	{
		delete temp;
		head = NULL;
	}
	else
		delete temp;
	size--;
	return x;
}

template <typename T>
void Queue<T>::clear()
{
	if (size)
	{
		queueElem* temp;
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
void Queue<T>::showStatus()
{
	queueElem *temp = head;
	while (temp)
	{
		cout << temp->value << " ";
		temp = temp->prev;
	}
	cout << endl;
}

template <typename T>
bool Queue<T>::isEmpty()
{
	if (size)
		return false;
	return true;
}

template <typename T>
int Queue<T>::getSize()
{
	return size;
}

template <typename T>
Queue<T>::Queue(int size)
{
	maxSize = size;
	Queue::size = 0;
	head = NULL;
	tail = NULL;
}

template <typename T>
Queue<T>::~Queue()
{
	clear();
}