#include "Stack.h"

STACK::Node::Node() {
	this->info = nullptr;
	this->next = nullptr;
}

STACK::Node::Node(BINARY_SEARCH_TREE::AVL_TREE::Pointer info, STACK::Node* next) {
	this->info = info;
	this->next = next;
}

void STACK::Initialize(STACK::Stack& First) {
	First = nullptr;
}

bool STACK::IsEmpty(const STACK::Stack& First) {
	return First == nullptr;
}

void STACK::Push(STACK::Stack& First, BINARY_SEARCH_TREE::AVL_TREE::Pointer info) {
	STACK::Stack newNode = new STACK::Node(info, First);
	First = newNode;
}

BINARY_SEARCH_TREE::AVL_TREE::Pointer STACK::Pop(STACK::Stack& First) {
	if (STACK::IsEmpty(First)) {
		return nullptr;
	}

	STACK::Stack removeNode = First;
	First = removeNode->next;
	BINARY_SEARCH_TREE::AVL_TREE::Pointer returnInfo = removeNode->info;
	delete removeNode;
	return returnInfo;
}

void STACK::Traversal(const STACK::Stack& First) {
	for (STACK::Stack p = First; p != nullptr; p = p->next) {
		std::cout << p->info << " ";
	}
	std::cout << "\n";
}
