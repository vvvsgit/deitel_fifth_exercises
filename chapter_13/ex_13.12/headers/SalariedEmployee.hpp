#ifndef SALARIEDEMPLOYEE_HPP
#define SALARIEDEMPLOYEE_HPP

#include "Employee.hpp"

class SalariedEmployee : public Employee
{
public:
    SalariedEmployee(const std::string &, const std::string &, const std::string &, 
                     const int, const int, const int, 
                     const double);

    void setWeeklySalary(const double);
    double getWeeklySalary() const;

    virtual double earnings() const;
    virtual void print() const;
private:
    double weeklySalary_;
};

#endif

