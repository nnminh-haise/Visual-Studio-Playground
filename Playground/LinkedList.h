#pragma once

#include <iostream>

template <typename T>
class DynamicArray
{
public:
	DynamicArray();

	bool Empty();

	int Size();

	void PushFront(T value);

	void PushBack(T value);

	T PopFront();

	T PopBack();

	T& operator[] (const int& index);

	T At(const int& index);

private:
	struct Node 
	{
		Node(T value, Node* next);

		T info_;
		Node* next_;
	};

	typedef Node* Pointer;

private:
	Pointer first_;
	Pointer last_;
};

template<typename T>
inline DynamicArray<T>::DynamicArray()
{
	this->first_ = nullptr;
	this->last_ = nullptr;
}

template<typename T>
inline bool DynamicArray<T>::Empty()
{
	return this->first_ == nullptr;
}

template<typename T>
inline int DynamicArray<T>::Size()
{
	int counter = 0;

	for (Pointer p = this->first_; p != nullptr; p = p->next_)
	{
		++counter;
	}
	return counter;
}

template<typename T>
inline void DynamicArray<T>::PushFront(T value)
{
	Pointer newNode = new Node(value, this->first_);
	this->first_ = newNode;
	if (this->first_->next_ == nullptr)
	{
		this->last_ = this->first_;
	}
}

template<typename T>
inline void DynamicArray<T>::PushBack(T value)
{
	if (this->Empty())
	{
		this->PushFront(value);
		return;
	}

	Pointer newNode = new Node(value, nullptr);
	this->last_->next_ = newNode;
	this->last_ = newNode;
}

template<typename T>
inline T DynamicArray<T>::PopFront()
{
	Pointer deleteNode = this->first_;
	this->first_ = this->first_->next_;
	T returnValue = deleteNode->info_;
	delete deleteNode;
	return returnValue;
}

template<typename T>
inline T DynamicArray<T>::PopBack()
{
	Pointer deleteNode = this->last_;
	Pointer newLast = this->first_;
	for (; newLast != nullptr && newLast->next_ != nullptr && newLast != deleteNode; newLast = newLast->next_);
	this->last_ = newLast;
	this->last_->next_ = nullptr;
	T returnValue = deleteNode->info_;
	delete deleteNode;
	return returnValue;
}

template<typename T>
inline T& DynamicArray<T>::operator[](const int& index)
{
	if (this->Empty())
	{
		throw std::logic_error("[ERROR] EMPTY LIST!\n");
	}

	if (index >= this->Size())
	{
		throw std::logic_error("[ERROR] INDEX OUT OF RANGE!\n");
	}

	int counter = 0;
	for (Pointer p = this->first_; p != nullptr; p = p->next_)
	{
		if (counter++ == index)
		{
			return p->info_;
		}
	}
}

template<typename T>
inline T DynamicArray<T>::At(const int& index)
{
	if (this->Empty())
	{
		throw std::logic_error("[ERROR] EMPTY LIST!\n");
	}

	if (index >= this->Size())
	{
		throw std::logic_error("[ERROR] INDEX OUT OF RANGE!\n");
	}

	int counter = 0;
	for (Pointer p = this->first_; p != nullptr; p = p->next_)
	{
		if (counter++ == index)
		{
			return p->info_;
		}
	}
}

template<typename T>
inline DynamicArray<T>::Node::Node(T value, Node* next)
{
	this->info_ = value;
	this->next_ = next;
}
