#pragma once

#include <iostream>

namespace BINARY_SEARCH_TREE {

	namespace AVL_TREE {
		struct Node {
			int key;
			int info;
			int balanceFactor;
			Node* left;
			Node* right;

			Node();

			Node(int key, int info, int balanceFactor, Node* left, Node* right);
		};

		typedef Node* Pointer;

        void Initialize(Pointer& root);

        bool IsEmpty(const Pointer& root);

        void InsertNode(Pointer& root, int key, int info);

        void CreateTree(Pointer& root);

        void CountNode(const Pointer& root, int& counter);

        void InterchangeLeftMostNode(Pointer& root, Pointer& removeNode);

        void RemoveNode(Pointer& root, int key);

        Pointer Search(const Pointer& root, int key);

        void PreOrderTraversal(const Pointer& root);

        void InOrderTraversal(const Pointer& root);

        void PostOrderTraversal(const Pointer& root);

        void NonrecursiveInOrderTraversal(const Pointer& root);

        void AssignToArr(const Pointer& root, int* arr);

        Pointer RotateLeft(Pointer root);

        Pointer RotateRight(Pointer root);

        bool Insert(Pointer& root, int key, int info);
	}
}
