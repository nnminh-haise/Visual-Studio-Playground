#include <iostream>
#include "DataStructures/LinearList.h"
#include "DataStructures/AVL_Tree.h"
#include "DataStructures/DoubleLinkedList.h"
#include "DataStructures/LinkedList.h"
#include "DataStructures/Stack.h"

#define TESTING_TYPE Stack<int>

struct Object {
	TESTING_TYPE list_;
};

int main()
{
	Object obj;

	{
		TESTING_TYPE list;
		for (int i = 0; i < 10; ++i)
		{
			list.Push(i + 1);
		}
		obj.list_ = list;
	}

	obj.list_.Print();

	TESTING_TYPE ls1;
	for (int i = 20; i <= 40; ++i)
	{
		ls1.Push(i);
	}

	ls1.Print();

	TESTING_TYPE ls2 = ls1;

	ls2.Print();

	return 0;
}