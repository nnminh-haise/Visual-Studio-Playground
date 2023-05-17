#include <iostream>
#include "DataStructures/LinearList.h"
#include "DataStructures/AVL_Tree.h"
#include "DataStructures/DoubleLinkedList.h"
#include "DataStructures/LinkedList.h"
#include "DataStructures/Stack.h"

#define TESTING_TYPE IntLinearList<int>

template<typename T>
class IntLinearList : public LinearList<T>
{
public:
	IntLinearList();

	IntLinearList(int capacity);

	IntLinearList(const IntLinearList<T>& other);

	~IntLinearList();

	IntLinearList<T>& operator=(const IntLinearList<T>& other);

	void PushOrder(const T& value);
};

template<typename T>
IntLinearList<T>::IntLinearList() : LinearList<T>() {}

template<typename T>
IntLinearList<T>::IntLinearList(int capacity) : LinearList<T>(capacity) {}

template<typename T>
IntLinearList<T>::IntLinearList(const IntLinearList<T>& other) : LinearList<T>(other) {}

template<typename T>
IntLinearList<T>::~IntLinearList() {}

template<typename T>
IntLinearList<T>& IntLinearList<T>::operator=(const IntLinearList<T>& other)
{
	if (this == &other)
	{
		return *this;
	}

	LinearList<T>::operator=(other);
	return *this;
}

template<typename T>
void IntLinearList<T>::PushOrder(const T& value)
{
	int index = 0;
	for (; index < this->Size(); ++index)
	{
		if (this->operator[](index) > value)
		{
			break;
		}
	}
	this->PushAt(value, index);
}


struct Object {
	IntLinearList<int> list_;
};

int main()
{
	Object obj;

	{
		TESTING_TYPE list;
		for (int i = 0; i < 10; ++i)
		{
			list.PushBack(i + 1);
		}
		obj.list_ = list;
	}

	for (int i = 0; i < obj.list_.Size(); ++i) std::cout << obj.list_[i] << " "; std::cout << "\b\n";

	TESTING_TYPE ls1;
	for (int i = 20; i <= 40; ++i)
	{
		ls1.PushBack(i);
	}

	for (int i = 0; i < ls1.Size(); ++i) std::cout << ls1[i] << " "; std::cout << "\b\n";

	TESTING_TYPE ls2 = ls1;

	for (int i = 0; i < ls2.Size(); ++i) std::cout << ls2[i] << " "; std::cout << "\b\n";

	//IntLinearList<int> ls;
	//ls.PushBack(2);
	//ls.PushBack(4);
	//ls.PushBack(6);
	//ls.PushBack(8);
	//ls.PushBack(10);
	//ls.PushBack(12);
	//ls.PushBack(14);
	//ls.PushBack(16);
	//ls.PushBack(18);
	//ls.PushBack(20);

	//std::cout << ls.Size() << "\n";

	//for (int i = 0; i < ls.Size(); ++i)
	//{
	//	std::cout << ls[i] << " ";
	//}
	//std::cout << "\n";

	//ls.PushOrder(13);

	//for (int i = 0; i < ls.Size(); ++i)
	//{
	//	std::cout << ls[i] << " ";
	//}
	//std::cout << "\n";

	return 0;
}