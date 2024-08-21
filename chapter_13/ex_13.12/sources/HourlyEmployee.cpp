#include <iostream>

#include "../headers/HourlyEmployee.hpp"

HourlyEmployee::HourlyEmployee(const std::string &first, const std::string &last, const std::string &ssn, 
                               const int day, const int month, const int year, 
                               const double wage, const double hours)
    : Employee(first, last, ssn, day, month, year)
{
    setWage(wage);
    setHours(hours);
}

void
HourlyEmployee::setWage(const double wage)
{
    wage_ = (wage >= 0.0 ? wage : 0.0);
}

void
HourlyEmployee::setHours(const double hours)
{
    hours_ = ((hours >= 0.0 && hours <= 168.0) ? hours : 0.0);
}

double
HourlyEmployee::getWage() const
{
    return wage_;
}

double
HourlyEmployee::getHours() const
{
    return hours_;
}

double
HourlyEmployee::earnings() const
{
    if (getHours() <= 40) {
        return getWage() * getHours();
    }
    return 40 * getWage() + (getHours() - 40) * (getWage() * 1.5);
}

void
HourlyEmployee::print() const
{
    std::cout << "hourly employee: ";
    Employee::print();
    std::cout << "\nhourly wage: " << getWage()
              << "; hours worked: " << getHours();
}

