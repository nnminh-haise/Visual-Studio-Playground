#pragma once
#ifndef LINEAR_LIST_H
#define LINEAR_LIST_H

#include "string"

namespace BOOK {
	const int MAX_SIZE = 100000;

	class LinearList {
	public:
		LinearList();

		int Size();

		int*& operator[] (int index);

		void Initialize(int size);

		bool IsEmpty();

		bool IsFull();

		bool Insert(int* newObject, int index = 0);

		int* Remove(int index);

		void Print(const std::string& message = "List");

	private:
		int size;
		int* nodes[MAX_SIZE]{};
	};
}



#endif //LINEAR_LIST_H
