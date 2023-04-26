#pragma once

#include <string>

class IndexGenerator
{
public:
	IndexGenerator(int amount);

	~IndexGenerator();

	void Randomize();

	void Generate();

	void Print();

	int operator[] (int index);

	void GetIndicies(int* indicies, int indexCount);

	void LogToFile(const std::string& filename);

	void LoadIndiciesFromFile(const std::string& filename);

	int FromFileGetIndexAt(const std::string& filename, int index);

private:
	int amount;
	int* indicies;
};

