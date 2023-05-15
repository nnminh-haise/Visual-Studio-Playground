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

void InOrderTraversal(AVL_Tree<int>::Node* node)
{
	if (node != nullptr)
	{
		InOrderTraversal(node->left_);
		std::cout << node->key_ << " ";
		InOrderTraversal(node->right_);
	}
}

int main() {
	srand(time(NULL));

	AVL_Tree<int, int> tree;

	int vals[10]{};
	int keys[10]{};
	for (int i = 0; i < 10; ++i)
	{
		vals[i] = rand() % 100 + 1;
		keys[i] = rand() % 1000 + 1;
		std::cout << "Inserting node with key = " << keys[i] << ", val = " << vals[i] << "\n";
		tree.Insert(keys[i], vals[i]);
	}

	InOrderTraversal(tree.GetRoot());
	std::cout << "\n";

	tree.Remove(keys[2]);

	std::cout << "deleteing key = " << keys[2] << "\n";
	std::cout << "root key = " << tree.GetRoot()->key_ << "\n";

	InOrderTraversal(tree.GetRoot());
	std::cout << "\n";

	return 0;
}