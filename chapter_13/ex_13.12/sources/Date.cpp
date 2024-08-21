#include <ctime>

#include "../headers/Date.hpp"

const int Date::daysPerMonth_[] = {0, 31, 28, 31, 30, 31, 30,
                                   31, 31, 30, 31, 30, 31};

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

Date::Date(const int day, const int month, const int year)
{
    setDate(day, month, year);
}

void
Date::setDate(const int day, const int month, const int year)
{
    year_ = (year >= 1 ? year : 1);
    month_ = ((month >= 1 && month <= 12) ? month : 1);
    if (month_ == 2 && isLeapYear(year_)) {
        day_ = ((day >= 1 && day <= 29) ? day : 1);
    } else {
        day_ = ((day >= 1 && day <= daysPerMonth_[month_]) ? day : 1);
    }
}

int
Date::getDay() const
{
    return day_;
}

int
Date::getMonth() const
{
    return month_;
}

int
Date::getYear() const
{
    return year_;
}

bool
Date::isLeapYear(const int year) const
{
    if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0)) {
        return true;
    }
    return false;
}

