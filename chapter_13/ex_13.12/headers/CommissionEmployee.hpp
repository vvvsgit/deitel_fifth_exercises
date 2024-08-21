#ifndef COMMISSIONEMPLOYEE_HPP
#define COMMISSIONEMPLOYEE_HPP

#include "Employee.hpp"

class CommissionEmployee : public Employee
{
public:
    CommissionEmployee(const std::string &, const std::string &, const std::string &, 
                       const int, const int, const int, 
                       const double, const double);

    void setCommissionRate(const double);
    void setGrossSales(const double);
    double getCommissionRate() const;
    double getGrossSales() const;

    virtual double earnings() const;
    virtual void print() const;
private:
    double commissionRate_;
    double grossSales_;
};

#endif

