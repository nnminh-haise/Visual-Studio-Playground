#include "BinarySearchTree.h"
#include "Student.h"
#include "IndexGenerator.h"
#include "Title.h"
#include <ctime>
#include <random>
#include <format>
#include <iostream>
#include <sstream>
#include <string>

struct Date {
    int day;
    int month;
    int year;
};

Date parseDate(const std::string& dateString) {
    std::istringstream ss(dateString);
    char delimiter;
    Date result;

    ss >> result.day >> delimiter >> result.month >> delimiter >> result.year;

    return result;
}

int main() {
    srand(time(NULL));

    std::string dateString = "05/05/2023";
    Date parsedDate = parseDate(dateString);

    std::cout << "Parsed date: " << parsedDate.day << "/" << parsedDate.month << "/" << parsedDate.year << std::endl;

    return 0;
}