// Двухсторонняя очередь

#include <iostream>
using namespace std;


template<typename T>

class MyInt
{
private:
	T value;
public:
	explicit MyInt(T value)
	{
		this->value = value;
	}
	void SetData(T value)
	{
		this->value = value;
	}
	T& GetData()
	{
		return value;
	}
};


template<typename T>

class Node
{
private:
	MyInt<T> myInt;
	Node<T>* next;
	Node<T>* prev; // new
public:
	explicit Node(MyInt<T> myInt) : myInt(myInt), next(nullptr), prev(nullptr) /*new*/ {}
	
	MyInt<T>& GetMyInt()
	{
		return myInt;
	}
	void SetMyInt(MyInt<T> myInt)
	{
		this->myInt = myInt;
	}
	Node<T>* GetNext() const
	{
		return next;
	}
	void SetNext(Node<T>* next)
	{
		this->next = next;
	}
	// new
	Node<T>* GetPrev() const
	{
		return prev;
	}
	void SetPrev(Node<T>* prev)
	{
		this->prev = prev;
	}
};


template<typename T>

class Queue
{
private:
	Node<T>* first;
	Node<T>* last;
	size_t size;
public:
	Queue() : first(nullptr), last(nullptr), size(0) {}

	size_t Size() const
	{
		return size;
	}

	void EnqueueLast(MyInt<T> myInt) // додаванн¤ елемент≥в в к≥нець черги 
	{
		Node<T>* newNode = new Node<T>(myInt);

		if (last == nullptr)
		{
			first = newNode;
			last = newNode;
		}
		else
		{
			last->SetNext(newNode);
			newNode->SetPrev(last);
			last = newNode;
		}

		size++;
	}

	void EnqueueFirst(MyInt<T> myInt) // додавання елементів у початок черги 
	{
		Node<T>* newNode = new Node<T>(myInt);

		if (first == nullptr)
		{
			first = newNode;
			last = newNode;
		}
		else
		{
			newNode->SetNext(first);
			first->SetPrev(newNode);
			first = newNode;
		}

		size++;
	}



	MyInt<T>& First()
	{
		if (first == nullptr)
		{
			throw runtime_error("Error");
		}

		return first->GetMyInt();
	}

	const MyInt<T> First() const
	{
		return First();
	}

	MyInt<T>& Last()
	{
		if (last == nullptr)
		{
			throw runtime_error("Error");
		}
		return last->GetMyInt();
	}

	const MyInt<T> Last() const
	{
		return Last();
	}

	void DequeueFirst()// видалення першого елементу з черги 
	{
		if (first == nullptr)
		{
			return;
		}

		Node<T>* temp = first;
		first = first->GetNext();

		if (first != nullptr)
		{
			first->SetPrev(nullptr);
		}

		if (first == nullptr)
		{
			last = nullptr;
		}

		delete temp;
		size--;
	}

	void DequeueLast() // видалення останього елементу з черги 
	{
		if (last == nullptr)
		{
			return;
		}

		Node<T>* temp = last;
		last = last->GetPrev();

		if (last != nullptr)
		{
			last->SetNext(nullptr);
		}

		if (last == nullptr)
		{
			first = nullptr;
		}

		delete temp;
		size--;
	}

	~Queue()
	{
		while (first != nullptr)
		{
			Node<T>* temp = first;
			first = first->GetNext();
			delete temp;
		}
	}
};

int main()
{
	Queue<double> queue;
	queue.EnqueueLast(MyInt<double>(9.9));

	for (int i = queue.Size(); i > 0; i--)
	{
		cout << queue.First().GetData() << endl;
		queue.DequeueFirst();
	}
}