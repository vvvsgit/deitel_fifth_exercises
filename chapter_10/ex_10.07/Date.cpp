#include "Date.hpp"

#include <iostream>
#include <iomanip>
#include <cassert>

const int MONTHS = 12;
static const char *months[MONTHS] = {"January", "February", "March",
                                     "April", "May", "June",
                                     "July", "August", "September",
                                     "October", "November", "December"};

Date::Date()
{
    int day = time(0) / (24 * 60 * 60) + 1;
    int year = 1970;
    while (day > 366) {
        day -= ((year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) ? 366 : 365);
        ++year;
    }
    if (day == 366 && !(year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))) {
        day -= 365;
        ++year;
    }
    int month = 1;
    while (day > 31) {
        switch (month) {
        case 4: case 6: case 9: case 11: day -= 30; break;
        case 2: day -= ((year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) ? 29 : 28); break;
        default: day -= 31; break;
        }
        ++month;
    }
    if (day > 28) {
        switch (month) {
        case 4: case 6: case 9: case 11: if (day == 31) { day -= 30; ++month; } break;
        case 2: 
            if (day == 30) {
                day -= ((year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) ? 29 : 28);
                ++month;
            } else if (day == 29 && !(year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))) {
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

Date::Date(int day, int year)
{
    if (year < 1) {
        year = 1;
    }
    if (day > 365) {
       if (!(year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))) {
           day = 1;
       } else if (day > 366) {
           day = 1;
       }
    }

    int month = 1;
    while (day > 31) {
        switch (month) {
        case 4: case 6: case 9: case 11: day -= 30; break;
        case 2: day -= ((year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) ? 29 : 28); break;
        default: day -= 31; break;
        }
        ++month;
    }
    if (day > 28) {
        switch (month) {
        case 4: case 6: case 9: case 11: if (day == 31) { day -= 30; ++month; } break;
        case 2: 
            if (day == 30) {
                day -= ((year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) ? 29 : 28);
                ++month;
            } else if (day == 29 && !(year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))) {
                day -= 28;
                ++month;
            }
            break;
        default: break;
        }
    }
    setDate(day, month, year);
}

Date::Date(char *monthWord, int day, int year)
{
    int month = 0;
    for (int i = 0; i < MONTHS; ++i) {
        if (*monthWord == *months[i]) {
            month = i + 1;
            break;
        }
    }
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
        if (getYear() % 400 == 0 || (getYear() % 4 == 0 && getYear() % 100 != 0)) {
            day_ = (day <= 29 ? day : 1);
        } else {
            day_ = (day <= 28 ? day : 1);
        }
        break;
    default: day_ = day; break;
    }
}

int
Date::getYear()
{
    return year_;
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

void
Date::printDDMMYY()
{
    std::cout << std::setfill('0') << std::setw(2) 
              << getDay() << '/' << std::setw(2) 
              << getMonth() << '/' 
              << getYear() << std::endl;
}

void
Date::printDDDYYYY()
{
    int day = getDay();
    int month = getMonth() - 1;
    int year = getYear();
    while (month > 0) {
        switch (month) {
        case 4: case 6: case 9: case 11: day += 30; break;
        case 2: day += ((year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) ? 29 : 28); break;
        default: day += 31; break;
        }
        --month;
    }
    std::cout << std::setfill('0') << std::setw(3) 
              << day << ' ' << std::setw(4) 
              << year << std::endl;
}

void
Date::printMonthDDYYYY()
{
    std::cout << months[getMonth() - 1] << ' '
              << std::setfill('0') << std::setw(2) 
              << getDay() << ',' << ' ' 
              << getYear() << std::endl;
}

