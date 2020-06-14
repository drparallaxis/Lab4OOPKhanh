#include <iostream>
#include <conio.h>
#include <random>
#include <ctime>
using namespace std;

class Coordinates
{
	double x, y;
public:
	Coordinates() { x = 0, y = 0; }
	void init(double k, double j)
	{
		x = k; y = j;
	}
	void show_coordinates() { cout << "x = " << x << ", y = " << y << endl; }
	double returnX()
	{
		return x;
	}
	double returnY()
	{
		return y;
	}
};
template<typename T>
class List
{
public:
	List();
	~List();
	void pop_front();
	void push_back(T data1, T data2);
	void clear();
	int GetSize() { return Size; }
	void show(int index);
	void check(Coordinates *c1, Coordinates *c2, int siz, List<T> l1, List<T> l2);
	void push_front(T data1, T data2);
	void insert(T data1, T data2, int index);
	void removeAt(int index);
	void pop_back();
	T res(const int index, T data, int status);
private:
	template<typename T>
	class Node
	{
	public:
		Node* pNext;
		T data1, data2;

		Node(T data1 = T(), T data2 = T(),  Node* pNext = nullptr)
		{
			this->data1 = data1;
			this->data2 = data2;
			this->pNext = pNext;
		}
	};
	int Size;
	Node<T>* head;
};
template<typename T>
List<T>::List()
{
	Size = 0;
	head = nullptr;
}
template<typename T>
List<T>::~List() { clear(); }
template<typename T>
void List<T>::pop_front()
{
	Node<T>* temp = head;
	head = head->pNext;
	delete temp;
	Size--;
}
template<typename T>
void List<T>::push_back(T data1, T data2)
{
	if (head == nullptr)
	{
		head = new Node<T>(data1, data2);
	}
	else
	{
		Node<T>* current = this->head;

		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new Node<T>(data1, data2);

	}
	Size++;
}
template<typename T>
void List<T>::clear()
{
	while (Size) { pop_front(); }
}
template<typename T>
void List<T>::push_front(T data1, T data2)
{
	head = new Node<T>(data1, data2, head);
	Size++;
}
template<typename T>
void List<T>::show(int index)
{
	int counter = 0;

	Node<T>* current = this->head;

	while (current != nullptr)
	{
		if (counter == index)
		{
			cout << "x = " << current->data1 << ", y = " << current->data2 << endl;
		}
			current = current->pNext;
			counter++;
	}
}
template<typename T>
T List<T>::res(const int index, T data, int status)
{
	int counter = 0;
	Node<T>* current = this->head;
	while (current != nullptr)
	{
		if (counter == index)
		{
			if(status == 1)
				return current->data1;
			if (status == 2)
				return current->data2;
		}
		current = current->pNext;
		counter++;
	}
}
template<typename T>
void List<T>::check(Coordinates *c1, Coordinates *c2, int siz, List<T> l1, List<T> l2)
{
	for (int i = 0; i < siz; i++)
	{
		l1.push_front(c1[i].returnX(), c1[i].returnY());
		l2.push_front(c2[i].returnX(), c2[i].returnY());
	}
	for (int i = 0; i < siz; i++)
	{
		if (c1[i].returnX() == c2[i].returnX() && c1[i].returnY() == c2[i].returnY())
		{
			cout << "x = " << c1[i].returnX() << ", y = " << c1[i].returnY() << " is in second list: " << \
				"x = " << c2[i].returnX() << ", y = " <<  c2[i].returnY() << endl;
		}
		/*cout << "x = " << res(i, c1[i].returnX(), 1) << ", y = " << res(i, c1[i].returnY(), 2) << " is in second list: " << \
			"x = " << res(i, c2[i].returnX(), 1) << ", y = " << res(i, c2[i].returnY(), 2) << endl;*/
	}
}
template<typename T>
void List<T>::insert(T data1, T data2, int index)
{

	if (index == 0)
	{
		push_front(data1, data2);
	}
	else
	{
		Node<T>* previous = this->head;

		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}

		Node<T>* newNode = new Node<T>(data1, data2, previous->pNext);

		previous->pNext = newNode;

		Size++;
	}
}
template<typename T>
void List<T>::removeAt(int index)
{
	if (index == 0)
	{
		pop_front();
	}
	else
	{
		Node<T>* previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}


		Node<T>* toDelete = previous->pNext;

		previous->pNext = toDelete->pNext;

		delete toDelete;

		Size--;
	}
}
template<typename T>
void List<T>::pop_back() { removeAt(Size - 1); }

int main()
{
	srand(time(NULL));
	Coordinates* c1 = new Coordinates[10];
	Coordinates* c2 = new Coordinates[10];
	double one = 0, two = 0, three = 0, four = 0;

	for (int i = 0; i < 7; i++)
	{
		one = rand() % 10;
		two = rand() % 10;
		three = rand() % 10;
		four = rand() % 10;
		c1[i].init(one, two);
		c2[i].init(three, four);
	}
	c1[7].init(1, 2);
	c2[7].init(1, 2);
	c1[8].init(4, 2);
	c2[8].init(4, 2);
	c1[9].init(4, 6);
	c2[9].init(4, 6);

	List<double> l1;
	List<double> l2;

	l1.check(c1, c2, 10, l1, l2);
	_getch();
}