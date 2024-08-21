#ifndef BASEPLUSCOMMISSIONEMPLOYEE_HPP
#define BASEPLUSCOMMISSIONEMPLOYEE_HPP

#include <string>

#include "CommissionEmployee.hpp"

class BasePlusCommissionEmployee
{
public:
    BasePlusCommissionEmployee(const std::string &, const std::string &, const std::string &, double = 0.0, double = 0.0, double = 0.0);

    void setBaseSalary(const double);
    double getBaseSalary() const;

    double earnings() const;
    void print();
private:
    CommissionEmployee employee_;
    double baseSalary_;
};

#endif

