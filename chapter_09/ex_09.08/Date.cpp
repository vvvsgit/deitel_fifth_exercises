#include "Date.hpp"

#include <iostream>
#include <iomanip>

Date::Date()
{
    int day = time(0) / (24 * 60 * 60);
    int year = 1970;
    while (day > 366) {
        day -= (year % 4 == 0 && year % 100 != 0 ? 366 : 365);
        ++year;
    }
    if (day == 366 && !(year % 4 == 0 && year % 100 != 0)) {
        day -= 365;
        ++year;
    }
    int month = 1;
    while (day > 31) {
        switch (month) {
        case 4: case 6: case 9: case 11: day -= 30; break;
        case 2: day -= (year % 4 == 0 && year % 100 != 0 ? 29 : 28); break;
        default: day -= 31; break;
        }
        ++month;
    }
    if (day > 28) {
        switch (month) {
        case 4: case 6: case 9: case 11: if (day == 31) { day -= 30; ++month; } break;
        case 2: 
            if (day == 30) {
                day -= (year % 4 == 0 && year % 100 != 0 ? 29 : 28);
                ++month;
            } else if (day == 29 && !(year % 4 == 0 && year % 100 != 0)) {
                day -= 28;
                ++month;
            }
            break;
        default: break;
        }
    }
    setDate(day, month, year);
}

Date::Date(int day, int month, int year)
{
    setDate(day, month, year);
}

void
Date::setDate(int day, int month, int year)
{
    setYear(year);
    setMonth(month);
    setDay(day);
}

void
Date::setYear(int year)
{
    year_ = (year > 0 ? year : 1000);
}

void
Date::setMonth(int month)
{
    month_ = (month >= 1 && month <= 12 ? month : 1);
}

void
Date::setDay(int day)
{
    if (day < 1 || day > 31) {
        day_ = 1;
        return;
    }
    switch (getMonth()) {
    case 4: case 6: case 9: case 11: day_ = (day <= 30 ? day : 1); break;
    case 2:
        if (getYear() % 4 == 0 && getYear() % 100 != 0) {
            day_ = (day <= 29 ? day : 1);
        } else {
            day_ = (day <= 28 ? day : 1);
        }
        break;
    default: day_ = day; break;
    }
}

int
Date::getMonth()
{
    return month_;
}

int
Date::getDay()
{
    return day_;
}
int
Date::getYear()
{
    return year_;
}

void
Date::print()
{
    std::cout << std::setfill('0') << std::setw(2) 
              << getDay() << '/' << std::setw(2) 
              << getMonth() << '/' 
              << getYear() << std::endl;
}

void
Date::nextDay()
{
    setDay(getDay() + 1);
    if (getDay() == 1) {
        setMonth(getMonth() + 1);
        if (getMonth() == 1) {
            setYear(getYear() + 1);
        }
    }
}

