#pragma once

#include <iostream>

template<typename T>
class Stack
{
public:
	struct Node
	{
		Node(T info, Node* next);

		friend std::ostream& operator<<(std::ostream& os, const Node& node) {
			os << node.info_;
			return os;
		}

		T info_;
		Node* next_;
	};

public:
	Stack();

	~Stack();

	bool Empty() const;

	int Size() const;

	Node& operator[] (int index);

	Node* Begin();

	Node* End();

	void Push(T value);

	T Pop();

private:
	Node* first_;
	int size_;
};

template<typename T>
inline Stack<T>::Node::Node(T value, Node* next)
{
	this->info_ = value;
	this->next_ = next;
}

template<typename T>
Stack<T>::Stack()
{
	this->first_ = nullptr;
	this->size_ = 0;
}

template<typename T>
inline Stack<T>::~Stack()
{
	Node* currentNode = this->first_;
	for (; currentNode != nullptr;)
	{
		Node* deleteNode = currentNode;
		currentNode = currentNode->next_;
		delete deleteNode;
	}
}

template<typename T>
inline bool Stack<T>::Empty() const
{
	return this->first_ == nullptr;
}

template<typename T>
inline int Stack<T>::Size() const
{
	return this->size_;
}

template<typename T>
inline Stack<T>::Node& Stack<T>::operator[](int index)
{
	if (index < 0 || index >= this->Size())
	{
		throw std::logic_error("[ERROR] INDEX OUT OF RANGE!\n");
	}

	Stack<T>::Node* target = this->first_;
	for (int i = 0; i != index && target != nullptr; target = target->next_, i++);
	return *target;
}

template<typename T>
inline Stack<T>::Node* Stack<T>::Begin()
{
	if (this->Empty())
	{
		return nullptr;
	}

	return this->first_;
}

template<typename T>
inline Stack<T>::Node* Stack<T>::End()
{
	if (this->Empty())
	{
		return nullptr;
	}

	Node* lastNode = this->first_;
	for (; lastNode->next_ != nullptr; lastNode = lastNode->next_);
	return lastNode;
}

template<typename T>
inline void Stack<T>::Push(T value)
{
	this->size_ += 1;
	Node* newNode = new Node(value, this->first_);
	this->first_ = newNode;
}

template<typename T>
inline T Stack<T>::Pop()
{
	if (this->Empty())
	{
		throw std::logic_error("[ERROR] LIST IS EMPTY! CANNOT REMOVE ITEM!\n");
	}

	this->size_ -= 1;
	T returnValue = this->first_->info_;
	Node* deleteNode = this->first_;
	this->first_ = this->first_->next_;
	delete deleteNode;
	return returnValue;
}
