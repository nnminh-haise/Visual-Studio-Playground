#include "Student.h"

Student::Student() :
	ID(-1), firstName(std::string()), lastName(std::string()), classID(std::string())
{
}

Student::Student(int ID, std::string firstName, std::string lastName, std::string classID) :
	ID(ID), firstName(firstName), lastName(lastName), classID(classID)
{
}

void Student::SetID(int ID)
{
	this->ID = ID;
}

int Student::GetID()
{
	return this->ID;
}

void Student::SetFirstName(const std::string& firstName)
{
	this->firstName = firstName;
}

std::string Student::GetFirstName()
{
	return this->firstName;
}

void Student::SetLastName(const std::string& lastName)
{
	this->lastName = lastName;
}

std::string Student::GetLastName()
{
	return this->lastName;
}

void Student::SetClassID(const std::string& classID)
{
	this->classID = classID;
}

std::string Student::GetClassID()
{
	return this->classID;
}

void Student::Print()
{
	std::cout << std::format("Student's ID: {}\n", this->ID);
	std::cout << std::format("First name  : {}\n", this->firstName);
	std::cout << std::format("Last name   : {}\n", this->lastName);
	std::cout << std::format("Class's ID  : {}\n", this->classID);
}
