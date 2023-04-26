#include "IndexGenerator.h"
#include "BinarySearchTree.h"
#include <iostream>
#include <fstream>
#include <ctime>

IndexGenerator::IndexGenerator(int amount) {
	this->amount = amount;
	this->indicies = new int[amount + 1];
	for (int i = 0; i <= this->amount; ++i) {
		this->indicies[i] = 0;
	}
	this->indicies[0] = -1;
}

IndexGenerator::~IndexGenerator()
{
	delete[this->amount + 1] this->indicies;
}

void IndexGenerator::Randomize()
{
	for (int i = 1; i <= this->amount; ++i) {
		this->indicies[i] = i;
	}

	for (int i = 1; i <= this->amount; ++i) {
		std::swap(this->indicies[i], this->indicies[rand() % (this->amount - i + 1) + i]);
	}
}

void IndexGenerator::Generate()
{
	BINARY_SEARCH_TREE::AVL_TREE::Pointer tree;
	BINARY_SEARCH_TREE::AVL_TREE::Initialize(tree);

	for (int i = 1; i <= this->amount; ++i) {
		if (BINARY_SEARCH_TREE::AVL_TREE::IsEmpty(tree)) {
			tree = new BINARY_SEARCH_TREE::AVL_TREE::Node(this->indicies[i], this->indicies[i], 0, nullptr, nullptr);
		}
		else {
			BINARY_SEARCH_TREE::AVL_TREE::Insert(tree, this->indicies[i], this->indicies[i]);
		}

	}

	int* arr = new int[this->amount];
	BINARY_SEARCH_TREE::AVL_TREE::AssignToArr(tree, arr);

	for (int i = 0; i < this->amount; ++i) {
		this->indicies[i + 1] = arr[i];
	}

	delete[] arr;
	delete tree;
}

void IndexGenerator::Print()
{
	for (int i = 1; i <= this->amount; ++i) {
		std::cout << this->indicies[i] << " ";
	}
	std::cout << std::endl;
}

int IndexGenerator::operator[](int index)
{
	if (index < 0 || index >= this->amount) {
		std::cerr << "[ERROR] Index access out of scope!\n";
	}
	return this->indicies[index + 1];
}

void IndexGenerator::GetIndicies(int* arr, int indexCount)
{
	for (int i = 0; i < this->amount; ++i) {
		arr[i] = this->indicies[i + 1];
	}
	indexCount = this->amount;
}

void IndexGenerator::LogToFile(const std::string& filename)
{
	std::ofstream fileOut(filename, std::ofstream::binary);

	if (!fileOut) {
		std::cerr << "[ERROR] Cannot open " << filename << "!\n";
		exit(1);
	}

	for (int i = 0; i <= this->amount; ++i) {
		fileOut.write((char*)&this->indicies[i], sizeof(this->indicies[i]));
	}

	fileOut.close();
}

void IndexGenerator::LoadIndiciesFromFile(const std::string& filename)
{
	std::ifstream fileIn(filename, std::ifstream::binary);

	if (!fileIn) {
		std::cerr << "[ERROR] Cannot open " << filename << "!\n";
		exit(1);
	}

	for (int i = 0; i < this->amount; ++i) {
		fileIn.read((char*)&this->indicies[i], sizeof(this->indicies[i]));
	}
	fileIn.close();
}

int IndexGenerator::FromFileGetIndexAt(const std::string& filename, int index)
{
	std::ifstream fileIn(filename, std::ifstream::binary);

	if (!fileIn.is_open()) {
		std::cerr << "[ERROR] Cannot open " << filename << "!\n";
		exit(1);
	}

	if (index < 0 || index >= this->amount) {
		std::cerr << "[ERROR] Index out of scope!\n";
		exit(1);
	}

	int result = 0;

	fileIn.seekg(0, fileIn.end);
	long long fileSize = fileIn.tellg();
	fileIn.seekg(0, fileIn.beg);

	std::cout << "File size  : " << fileSize << "\n";

	std::cout << "Size of arr: " << sizeof(this->indicies) << "\n";

	fileIn.seekg(index * sizeof(int));
	
	fileIn.read((char*)&result, sizeof(int));

	fileIn.close();

	return result;
}
