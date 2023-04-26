#pragma once

#include "BinarySearchTree.h"

/**
* This stack data structure is built based on the linked list data structure.
* The top element of the stack is the first element of the linked list.
*/

namespace STACK {
	const int MAX_SIZE = 1000;

	struct Node {
		BINARY_SEARCH_TREE::AVL_TREE::Pointer info;
		Node* next;

		Node();

		Node(BINARY_SEARCH_TREE::AVL_TREE::Pointer info, Node* next);
	};

	typedef Node* Stack;

	void Initialize(Stack& First);

	bool IsEmpty(const Stack& First);

	void Push(Stack& First, BINARY_SEARCH_TREE::AVL_TREE::Pointer info);

	BINARY_SEARCH_TREE::AVL_TREE::Pointer Pop(Stack& First);

	void Traversal(const Stack& First);
}
