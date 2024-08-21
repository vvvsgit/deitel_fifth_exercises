#include <iostream>

#include "../headers/BasePlusCommissionEmployee.hpp"

BasePlusCommissionEmployee::BasePlusCommissionEmployee(const std::string &first, const std::string &last, const std::string &ssn, 
                                                       const int day, const int month, const int year, 
                                                       const double sales, const double rate, const double salary)
    : CommissionEmployee(first, last, ssn, day, month, year, sales, rate)
{
    setBaseSalary(salary);
}


void
BasePlusCommissionEmployee::setBaseSalary(const double salary)
{
    baseSalary_ = (salary >= 0.0 ? salary : 0.0);
}

double
BasePlusCommissionEmployee::getBaseSalary() const
{
    return baseSalary_;
}


double
BasePlusCommissionEmployee::earnings() const
{
    return getBaseSalary() + CommissionEmployee::earnings();
}

void
BasePlusCommissionEmployee::print() const
{
    std::cout << "base-salaried ";
    CommissionEmployee::print();
    std::cout << "; base salary: " << getBaseSalary();
}

