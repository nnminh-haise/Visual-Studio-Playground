#pragma once

#include <iostream>
#include <string>
#include <format>

template <typename T>
class LinearList
{
public:
	LinearList();

	~LinearList();

	int Size() const;

	bool Empty() const;

	bool Full() const;

	void Clear() noexcept;

	void PushFront(T value);

	void PushBack(T value);

	void PushAt(T value, int position = 0);

	T PopFront();

	T PopBack();

	T PopAt(int position = 0);

public:
	int MAX_SIZE = 100000;

private:
	T* nodes_;
	int nodeCount_;
};

template<typename T>
inline LinearList<T>::LinearList()
{
	this->nodes_ = new T [this->MAX_SIZE];
}

template<typename T>
inline LinearList<T>::~LinearList()
{
	delete[] this->nodes_;
}

template<typename T>
inline int LinearList<T>::Size() const
{
	return this->nodeCount_;
}

template<typename T>
inline bool LinearList<T>::Empty() const
{
	return this->nodeCount_ == 0;
}

template<typename T>
inline bool LinearList<T>::Full() const
{
	return this->nodeCount_ == this->MAX_SIZE;
}

template<typename T>
inline void LinearList<T>::Clear() noexcept
{
	std::destroy(this->nodes_, this->nodes_ + this->nodesCount_);
	this->nodeCount_ = 0;
}

template<typename T>
inline void LinearList<T>::PushFront(T value)
{
	if (this->Full())
	{
		throw std::logic_error(std::format("[ERROR] LIST IS FULL! CANNOT INSERT NEW ELEMENT!\n"));
		exit(1);
	}

	for (int i = this->nodeCount_; i > 0; --i)
	{
		this->nodes_[i] = this->nodes_[i - 1];
	}
	this->nodes_[0] = value;
	this->nodeCount_ += 1;
}

template<typename T>
inline void LinearList<T>::PushBack(T value)
{
	if (this->Full())
	{
		throw std::logic_error(std::format("[ERROR] LIST IS FULL! CANNOT INSERT NEW ELEMENT!\n"));
		exit(1);
	}

	this->nodes_[this->nodeCount_] = value;
	this->nodeCount_ += 1;
}

template<typename T>
inline void LinearList<T>::PushAt(T value, int position)
{
	if (this->Full())
	{
		throw std::logic_error(std::format("[ERROR] LIST IS FULL! CANNOT INSERT NEW ELEMENT!\n"));
		exit(1);
	}

	if (position < 0)
	{
		throw std::logic_error("[ERROR] INDEX OUT OF RANGE!\n");
		exit(1);
	}

	if (position > this->nodeCount_)
	{
		throw std::logic_error("[ERROR] INDEX OUT OF RANGE!\n");
		exit(1);
	}

	for (int i = this->nodeCount_; i > position; --i)
	{
		this->nodes_[i] = this->nodes_[i - 1];
	}
	this->nodes_[position] = value;
	this->nodeCount_ += 1;
}

template<typename T>
inline T LinearList<T>::PopFront()
{
	if (this->Empty())
	{
		throw std::logic_error(std::format("[ERROR] LIST IS EMPTY! CANNOT POP NEW ELEMENT!\n"));
		exit(1);
	}

	T returnValue = this->nodes_[0];
	for (int i = 0; i < this->nodeCount_ - 1; ++i)
	{
		this->nodes_[i] = this->nodes_[i + 1];
	}
	this->nodeCount_ -= 1;
	return returnValue;
}

template<typename T>
inline T LinearList<T>::PopBack()
{
	if (this->Empty())
	{
		throw std::logic_error(std::format("[ERROR] LIST IS EMPTY! CANNOT POP NEW ELEMENT!\n"));
		exit(1);
	}

	T returnValue = this->nodes_[this->nodeCount_ - 1];
	this->nodeCount_ -= 1;
	return returnValue;
}

template<typename T>
inline T LinearList<T>::PopAt(int position)
{
	if (this->Empty())
	{
		throw std::logic_error(std::format("[ERROR] LIST IS EMPTY! CANNOT POP NEW ELEMENT!\n"));
		exit(1);
	}

	if (position < 0)
	{
		throw std::logic_error("[ERROR] INDEX OUT OF RANGE!\n");
		exit(1);
	}

	if (position > this->nodeCount_)
	{
		throw std::logic_error("[ERROR] INDEX OUT OF RANGE!\n");
		exit(1);
	}

	T returnValue = this->nodes_[position];
	for (int i = position; i < this->nodeCount_ - 1; ++i)
	{
		this->nodes_[i] = this->nodes_[i + 1];
	}
	return returnValue;
}