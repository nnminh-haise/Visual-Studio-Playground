#ifndef DATE_H
#define DATE_H

#include <string>

class Date {
public:
    Date();
    Date(int day, int month, int year);
    static Date Random();
    std::string Stringify() const;
    int DaysBetween(const Date& other) const;

    Date operator+(int days) const;
    Date operator-(int days) const;

    friend bool operator>(const Date& lhs, const Date& rhs);

private:
    int day_;
    int month_;
    int year_;

    static bool IsLeapYear(int year);
    static int DaysInMonth(int month, int year);
};

#endif  // DATE_H
