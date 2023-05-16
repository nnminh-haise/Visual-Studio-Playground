#include <fstream>
#include "Student.h"
#include "Date.h"
#include "DataStructures/HashMap.h"
#include "DataStructures/DynamicArray.h"
#include "DataStructures/LinearList.h"
#include "DataStructures/LinkedList.h"
#include "DataStructures/Stack.h"
#include "DataStructures/AVL_Tree.h"
#include "DataStructures/DoubleLinkedList.h"
#include <ctime>
#include <random>
#include <format>

struct Data {
	int a_;
	int b_;

	Data() : a_(0), b_(0) {}

	Data(int a, int b) : a_(a), b_(b) {}

	friend std::ostream& operator<< (std::ostream& os, const Data& data)
	{
		os << std::format("({}, {})", data.a_, data.b_);
		return os;
	}
};

struct Object {
	DoubleLinkedList<Data> lst_;
};

int main()
{
	srand(time(NULL));

	Object obj;

	{
		DoubleLinkedList<Data> list;
		for (int i = 0; i < 10; ++i)
		{
			list.PushBack(Data(i + 1, rand() % 100 + 1));
		}
		obj.lst_ = list;
	}

	for (auto p = obj.lst_.Begin(); p != nullptr; p = p->right_)
	{
		std::cout << p->info_ << "; ";
	}
	std::cout << "\b\b\n";

	return 0;
}