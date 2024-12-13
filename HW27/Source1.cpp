// Стек

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
	Node<T>* next /*= nullptr*/;
public:
	explicit Node(MyInt<T> myInt) : myInt(myInt), next(nullptr) {}

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
};


template<typename T>

class Stack
{
private:
	Node<T>* top;
	size_t size;
public:
	Stack() : top(nullptr), size(0) {}

	size_t GetSize() const
	{
		return size;
	}

	void Push(MyInt<T> myInt) // додавання елементів на вершину 
	{
		Node<T>* newNode = new Node<T>(myInt);

		newNode->SetNext(top);
		top = newNode;

		size++;
	}

	MyInt<T>& Peek() // отримаємо верхній елемент
	{
		if (top == nullptr)
		{
			throw runtime_error("Error");
		}

		return top->GetMyInt();
	}

	const MyInt<T> Peek() const // отримаємо верхній елемент
	{
		return Peek();
	}

	void Pop() // видалення верхнього елементу
	{
		if (top == nullptr)
		{
			throw runtime_error("Error");
		}

		Node<T>* temp = top;
		top = top->GetNext();

		delete temp;
		size--;
	}

	~Stack()
	{
		while (top != nullptr)
		{
			Node<T>* temp = top;
			top = top->GetNext();
			delete temp;
		}
	}
};


int main()
{
	Stack<double> stack;
	stack.Push(MyInt<double>(9.9));

	while (stack.GetSize() != 0)
	{
		cout << stack.Peek().GetData() << endl;
		stack.Pop();
	}
}

