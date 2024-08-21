#include <iostream>

#include "../headers/CommissionEmployee.hpp"

CommissionEmployee::CommissionEmployee(const std::string &first, const std::string &last, const std::string &ssn, 
                                       const int day, const int month, const int year, 
                                       const double sales, const double rate)
    : Employee(first, last, ssn, day, month, year)
{
    setGrossSales(sales);
    setCommissionRate(rate);
}

void
CommissionEmployee::setCommissionRate(const double rate)
{
    commissionRate_ = ((rate >= 0.0 && rate <= 1.0) ? rate : 0.0);
}

void
CommissionEmployee::setGrossSales(const double sales)
{
    grossSales_ = (sales >= 0.0 ? sales : 0.0);
}

double
CommissionEmployee::getCommissionRate() const
{
    return commissionRate_;
}

double
CommissionEmployee::getGrossSales() const
{
    return grossSales_;
}

double
CommissionEmployee::earnings() const
{
    return getCommissionRate() * getGrossSales();
}

void
CommissionEmployee::print() const
{
    std::cout << "commission employee: ";
    Employee::print();
    std::cout << "\ngross sales: " << getGrossSales()
              << "; commission rate: " << getCommissionRate();
}

