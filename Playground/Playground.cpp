#include "Student.h"
#include "Date.h"
#include "DataStructures/HashMap.h"
#include "DataStructures/DynamicArray.h"
#include "DataStructures/LinearList.h"
#include "DataStructures/LinkedList.h"
#include "DataStructures/DoubleLinkedList.h"
#include "DataStructures/Stack.h"
#include "DataStructures/AVL_Tree.h"
#include <fstream>
#include <ctime>
#include <random>
#include <format>

struct Data {
	int a;
	int b;

	Data() {
		this->a = 0;
		this->b = 0;
	}

	Data(int a, int b) {
		this->a = a;
		this->b = b;
	}

	friend std::ostream& operator<< (std::ostream& os, const Data& data) {
		os << std::format("a = {}, b = {}", data.a, data.b);
		return os;
	}
};

int main() {
	srand(time(NULL));

	DoubleLinkedList<int> list;
	
	list.PushBack(10);
	list.PushBack(11);
	list.PushBack(12);
	list.PushBack(13);
	list.PushBack(14);

	int listSize = list.Size();

	std::cout << "size = " << listSize << "\n";

	for (int i = 0; i < listSize; ++i)
	{
		std::cout << list[i] << " ";
	}
	std::cout << "\n";

	for (auto currentNode = list.NodeAt(0); currentNode != nullptr; currentNode = currentNode->right_)
	{
		std::cout << currentNode->info_ << " ";
	}
	std::cout << "\n";

	return 0;
}