#ifndef BASEPLUSCOMMISSIONEMPLOYEE_HPP
#define BASEPLUSCOMMISSIONEMPLOYEE_HPP

#include "CommissionEmployee.hpp"

class BasePlusCommissionEmployee : public CommissionEmployee
{
public:
    BasePlusCommissionEmployee(const std::string &, const std::string &, const std::string &, 
                               const int, const int, const int, 
                               const double, const double, const double);

    void setBaseSalary(const double);
    double getBaseSalary() const;

    virtual double earnings() const;
    virtual void print() const;
private:
    double baseSalary_;
};

#endif

