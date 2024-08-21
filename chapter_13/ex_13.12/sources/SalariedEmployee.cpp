#include <iostream>

#include "../headers/SalariedEmployee.hpp"

SalariedEmployee::SalariedEmployee(const std::string &first, const std::string &last, const std::string &ssn, 
                                   const int day, const int month, const int year, 
                                   const double salary)
    : Employee(first, last, ssn, day, month, year)
{
    setWeeklySalary(salary);
}

void
SalariedEmployee::setWeeklySalary(const double salary)
{
    weeklySalary_ = (salary >= 0.0 ? salary : 0.0);
}

double
SalariedEmployee::getWeeklySalary() const
{
    return weeklySalary_;
}

double
SalariedEmployee::earnings() const
{
    return getWeeklySalary();
}

void
SalariedEmployee::print() const
{
    std::cout << "salaried employee: ";
    Employee::print();
    std::cout << "\nweekly salary: " << getWeeklySalary();
}

