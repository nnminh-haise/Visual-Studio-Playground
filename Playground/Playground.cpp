#include "BinarySearchTree.h"
#include "Student.h"
#include "IndexGenerator.h"
#include "Date.h"
#include "HashMap.h"
#include <fstream>
#include <ctime>
#include <random>
#include <format>

//void WriteStudentToFile(const std::string& filename, Student* students, int& studentCount) {
//	std::ofstream fileOut(filename, std::ostream::binary);
//
//	if (!fileOut) {
//		std::cerr << "[ERROR] Cannot open file to write!\n";
//		exit(1);
//	}
//
//	fileOut.write(std::to_string(studentCount).c_str(), sizeof(int));
//
//	for (int i = 0; i < studentCount; ++i) {
//		fileOut.write(std::to_string(students[i].GetID()).c_str(), sizeof(int));
//		fileOut.write(students[i].GetFirstName().c_str(), sizeof(std::string));
//		fileOut.write(students[i].GetLastName().c_str(), sizeof(std::string));
//		fileOut.write(students[i].GetClassID().c_str(), sizeof(std::string));
//	}
//
//	fileOut.close();
//}
//
//void LoadStudentIDFromFile(const std::string& filename, int* IDs, int& IdCount) {
//	std::ifstream fileIn(filename, std::istream::binary);
//
//	if (!fileIn) {
//		std::cerr << "[ERROR] Cannot open file to read!\n";
//		exit(1);
//	}
//
//	std::string buffer{};
//	fileIn.read((char*)buffer.c_str(), sizeof(int));
//	IdCount = std::stoi(buffer);
//
//	IDs = new int[IdCount];
//	int pos = sizeof(std::string);
//	for (int i = 0; i < IdCount; ++i) {
//		fileIn.seekg(pos + i * sizeof(std::string));
//		fileIn.read((char*)buffer.c_str(), sizeof(std::string));
//		std::cerr << buffer << "\n";
//		IDs[i] = std::stoi(buffer);
//	}
//
//	fileIn.close();
//}



int main() {
	srand(time(NULL));

	HashMap < int > intMap (456976, 0);

	try {
		intMap.Insert("ZZZZ", 100);
	}
	catch (const std::exception& ex) {
		std::cout << ex.what();
	}

	std::cout << intMap["ZZZZ"] << "\n";


	//-----------------------------------------------------------

	//int studentCount = 5;
	//Student* students = new Student[studentCount];
	//
	//for (int i = 0; i < studentCount; ++i) {
	//	students[i].SetID(rand() % 30 + 1);
	//	students[i].SetFirstName(std::to_string('A' + i));
	//	students[i].SetLastName(std::to_string('a' + i));
	//	students[i].SetClassID("D21");
	//}

	//WriteStudentToFile("students.bin", students, studentCount);

	//int* IDs{};
	//int IdCount = 0;
	//LoadStudentIDFromFile("students.bin", IDs, IdCount);

	//std::cerr << IdCount << "\n";

	//for (int i = 0; i < IdCount; ++i) {
	//	std::cout << IDs[i] << " ";
	//}
	//std::cout << std::endl;

	//delete[studentCount] students;

	//-----------------------------------------------------------

	//std::cout << std::format("hello");

	//IndexGenerator generator(20);

	//generator.Randomize();

	//std::cout << "Original: ";

	//generator.Print();

	//generator.Generate();

	//std::cout << "AVL_Tree(NLR): ";

	//generator.Print();
	//
	//generator.LogToFile("Indicies.bin");

	//generator.LoadIndiciesFromFile("Indicies.bin");

	//std::cout << "READ from file: ";

	//generator.Print();

	//std::cout << generator.FromFileGetIndexAt("Indicies.bin", 0) << "\n";

	return 0;
}