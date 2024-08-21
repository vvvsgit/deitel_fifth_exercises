#include "DateAndTime.hpp"

#include <iostream>
#include <iomanip>

DateAndTime::DateAndTime()
{
    int second = time(0);
    int minute = second % (60 * 60) / 60;
    int hour = second % (60 * 60 * 24) / (60 * 60) + 4;
    int day = second / (24 * 60 * 60);
    second %= 60;
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
    setTime(second, minute, hour);
    setDate(day, month, year);
}

DateAndTime::DateAndTime(int second, int minute, int hour, int day, int month, int year)
{
    setTime(second, minute, hour);
    setDate(day, month, year);
}

void
DateAndTime::setTime(int second, int minute, int hour)
{
    setHour(hour);
    setMinute(minute);
    setSecond(second);
}

void
DateAndTime::setDate(int day, int month, int year) 
{
    setYear(year);
    setMonth(month);
    setDay(day);
}

void
DateAndTime::setSecond(int second)
{
    second_ = (second >= 0 && second < 60) ? second : 0;
}

void
DateAndTime::setMinute(int minute)
{
    minute_ = (minute >= 0 && minute < 60) ? minute : 0;
}

void
DateAndTime::setHour(int hour)
{
    hour_ = (hour >= 0 && hour < 24) ? hour : 0;
}

void
DateAndTime::setDay(int day)
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

void
DateAndTime::setMonth(int month)
{
    month_ = (month >= 1 && month <= 12 ? month : 1);
}

void
DateAndTime::setYear(int year)
{
    year_ = (year > 0 ? year : 1000);
}

int
DateAndTime::getSecond()
{
    return second_;
}

int
DateAndTime::getMinute()
{
    return minute_;
}

int
DateAndTime::getHour()
{
    return hour_;
}

int
DateAndTime::getDay()
{
    return day_;
}

int
DateAndTime::getMonth()
{
    return month_;
}

int
DateAndTime::getYear()
{
    return year_;
}

void
DateAndTime::printUniversal()
{
    std::cout << std::setfill('0') << std::setw(2) << getHour()
              << ":" << std::setw(2) << getMinute()
              << ":" << std::setw(2) << getSecond() << ' ';

    std::cout << std::setfill('0') << std::setw(2) 
              << getDay() << '/' << std::setw(2) 
              << getMonth() << '/' 
              << getYear() << std::endl;
}

void
DateAndTime::printStandart()
{
    std::cout << ((getHour() == 0 || getHour() == 12) ? 12 : getHour() % 12)
              << ":" << std::setfill('0') << std::setw(2) << getMinute()
              << ":" << std::setw(2) << getSecond()
              << (getHour() < 12 ? " AM" : " PM") << ' ';

    std::cout << std::setfill('0') << std::setw(2) 
              << getDay() << '/' << std::setw(2) 
              << getMonth() << '/' 
              << getYear() << std::endl;
}

void
DateAndTime::tick()
{
    setSecond(getSecond() + 1);
    if (getSecond() == 0) {
        setMinute(getMinute() + 1);
        if (getMinute() == 0) {
            setHour(getHour() + 1);
            if (getHour() == 0) {
                nextDay();
            }
        }
    }
}

void
DateAndTime::nextDay()
{
    setDay(getDay() + 1);
    if (getDay() == 1) {
        setMonth(getMonth() + 1);
        if (getMonth() == 1) {
            setYear(getYear() + 1);
        }
    }
}

