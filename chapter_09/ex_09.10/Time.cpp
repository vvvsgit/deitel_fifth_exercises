#include "Time.hpp"

#include <iostream>
#include <iomanip>

Time::Time()
{
    setTime(time(0) % (60 * 60 * 24) / (60 * 60) + 4, 
            time(0) % (60 * 60) / 60,
            time(0) % 60);
}

Time::Time(int hour, int minute, int second)
{
    setTime(hour, minute, second);
}

void
Time::setTime(int hour, int minute, int second)
{
    if (hour < 0 || hour > 23) {
        std::cout << "Warning: invalid hour, set to 0." << std::endl;
        hour = 0;
    }
    setHour(hour);
    if (minute < 0 || minute > 59) {
        std::cout << "Warning: invalid minute, set to 0." << std::endl;
        minute = 0;
    }
    setMinute(minute);
    if (second < 0 || second > 59) {
        std::cout << "Warning: invalid second, set to 0." << std::endl;
        second = 0;
    }
    setSecond(second);
}

void
Time::setHour(int hour)
{
    hour_ = hour != 24 ? hour : 0;
}

void
Time::setMinute(int minute)
{
    minute_ = minute != 60 ? minute : 0;
}

void
Time::setSecond(int second)
{
    second_ = second != 60 ? second : 0;
}

int
Time::getHour()
{
    return hour_;
}

int
Time::getMinute()
{
    return minute_;
}

int
Time::getSecond()
{
    return second_;
}

void
Time::printUniversal()
{
    std::cout << std::setfill('0') << std::setw(2) << getHour()
              << ":" << std::setw(2) << getMinute()
              << ":" << std::setw(2) << getSecond() << std::endl;
}

void
Time::printStandart()
{
    std::cout << ((getHour() == 0 || getHour() == 12) ? 12 : getHour() % 12)
              << ":" << std::setfill('0') << std::setw(2) << getMinute()
              << ":" << std::setw(2) << getSecond()
              << (getHour() < 12 ? " AM" : " PM") << std::endl;
}

void
Time::tick()
{
    setSecond(getSecond() + 1);
    if (getSecond() == 0) {
        setMinute(getMinute() + 1);
        if (getMinute() == 0) {
            setHour(getHour() + 1);
        }
    }
}

