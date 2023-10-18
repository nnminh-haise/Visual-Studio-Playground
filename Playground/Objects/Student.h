#pragma once

#include <iostream>
#include <string>
#include <format>

class Student
{
public:
	Student();

	Student(int ID, std::string firstName, std::string lastName, std::string classID);

	void SetID(int ID);

	int GetID();

	void SetFirstName(const std::string& firstName);

	std::string GetFirstName();

	void SetLastName(const std::string& lastName);

	std::string GetLastName();

	void SetClassID(const std::string& classID);

	std::string GetClassID();

	void Print();

private:
	int ID;
	std::string firstName;
	std::string lastName;
	std::string classID;
};

