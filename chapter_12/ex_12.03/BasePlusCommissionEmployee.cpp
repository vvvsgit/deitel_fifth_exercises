#include <iostream>

#include "BasePlusCommissionEmployee.hpp"

BasePlusCommissionEmployee::BasePlusCommissionEmployee(const std::string &first, const std::string &last, const std::string &ssn, double sales, double rate, double salary)
    : employee_(first, last, ssn, sales, rate)
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
    return getBaseSalary() + employee_.earnings();
}

void
BasePlusCommissionEmployee::print()
{
    std::cout << "base-salaried ";
    employee_.print();
    std::cout << "base salary: " << getBaseSalary() << std::endl;
}

