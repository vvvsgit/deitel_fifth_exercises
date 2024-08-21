#include <iostream>

#include "CommissionEmployee.hpp"

CommissionEmployee::CommissionEmployee(const std::string &first, const std::string &last, const std::string &ssn, double sales, double rate)
    : firstName_(first)
    , lastName_(last)
    , socialSecurityNumber_(ssn)
{
    setGrossSales(sales);
    setCommissionRate(rate);
}

void
CommissionEmployee::setFirstName(const std::string &first)
{
    firstName_ = first;
}

void
CommissionEmployee::setLastName(const std::string &last)
{
    lastName_ = last;
}

void
CommissionEmployee::setSocialSecurityNumber(const std::string &ssn)
{
    socialSecurityNumber_ = ssn;
}

void
CommissionEmployee::setGrossSales(const double sales)
{
    grossSales_ = (sales >= 0.0 ? sales : 0.0);
}

void
CommissionEmployee::setCommissionRate(const double rate)
{
    commissionRate_ = (rate >= 0.0 ? rate : 0.0);
}

std::string
CommissionEmployee::getFirstName() const
{
    return firstName_;
}

std::string
CommissionEmployee::getLastName() const
{
    return lastName_;
}

std::string
CommissionEmployee::getSocialSecurityNumber() const
{
    return socialSecurityNumber_;
}

double
CommissionEmployee::getGrossSales() const
{
    return grossSales_;
}

double
CommissionEmployee::getCommissionRate() const
{
    return commissionRate_;
}

double
CommissionEmployee::earnings() const
{
    return getGrossSales() * getCommissionRate();
}

void
CommissionEmployee::print() const
{
    std::cout << "commission employee: " << getFirstName() << ' '
              << getLastName() << "\nsocial security number: "
              << getSocialSecurityNumber() << "\ngross sales: "
              << getGrossSales() << "\ncommission rate: " 
              << getCommissionRate() << std::endl;
}

