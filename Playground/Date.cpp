#include "Date.h"
#include <cmath>
#include <stdexcept>
#include <format>
#include <string>
#include <chrono>

Date::Date() {
    auto now = std::chrono::system_clock::now();
    time_t currentTime = std::chrono::system_clock::to_time_t(now);
    struct tm timeinfo;
    localtime_s(&timeinfo, &currentTime);
    day_ = timeinfo.tm_mday;
    month_ = timeinfo.tm_mon + 1;  // tm_mon is 0-based
    year_ = timeinfo.tm_year + 1900;  // tm_year is years since 1900
}

Date::Date(int day, int month, int year) : day_(day), month_(month), year_(year) {}

Date Date::Random() {
    int maxDaysInMonth[] = {
    31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
    };

    // Generate a random year between 1900 and 2100
    int year = rand() % 201 + 1900;

    // Generate a random month between 1 and 12
    int month = rand() % 12 + 1;

    // Check if it's a leap year and adjust max days in February accordingly
    if (month == 2 && (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)) {
        maxDaysInMonth[1] = 29;
    }

    // Generate a random day between 1 and the maximum number of days in the given month and year
    int maxDays = maxDaysInMonth[month - 1];
    int day = rand() % maxDays + 1;

    return Date(day, month, year);
}

std::string Date::Stringify() const {
    return std::format("{}/{}/{}", this->day_, this->month_, this->year_);
}

int Date::DaysBetween(const Date& other) const {
    int days1 = day_;
    for (int m = 1; m < month_; m++)
        days1 += DaysInMonth(m, year_);

    int days2 = other.day_;
    for (int m = 1; m < other.month_; m++)
        days2 += DaysInMonth(m, other.year_);

    for (int y = year_; y < other.year_; y++)
        days2 += IsLeapYear(y) ? 366 : 365;

    return std::abs(days2 - days1);
}

Date Date::operator+(int days) const {
    Date result(*this);
    int totalDays = day_ + days;

    while (totalDays > DaysInMonth(result.month_, result.year_)) {
        totalDays -= DaysInMonth(result.month_, result.year_);
        ++result.month_;
        if (result.month_ > 12) {
            result.month_ = 1;
            ++result.year_;
        }
    }

    result.day_ = totalDays;
    return result;
}

Date Date::operator-(int days) const {
    Date result(*this);
    int totalDays = day_ - days;

    while (totalDays < 1) {
        --result.month_;
        if (result.month_ < 1) {
            result.month_ = 12;
            --result.year_;
        }
        totalDays += DaysInMonth(result.month_, result.year_);
    }

    result.day_ = totalDays;
    return result;
}

bool operator>(const Date& lhs, const Date& rhs) {
    if (lhs.year_ > rhs.year_)
        return true;
    else if (lhs.year_ == rhs.year_) {
        if (lhs.month_ > rhs.month_)
            return true;
        else if (lhs.month_ == rhs.month_)
            return lhs.day_ > rhs.day_;
    }
    return false;
}

bool Date::IsLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int Date::DaysInMonth(int month, int year) {
    static const int daysPerMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (month < 1 || month > 12)
        throw std::out_of_range("Invalid month");
    int days = daysPerMonth[month - 1];
    if (month == 2 && IsLeapYear(year))
        days++;
    return days;
}

