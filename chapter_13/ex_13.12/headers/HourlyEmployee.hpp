#ifndef HOURLYEMPLOYEE_HPP
#define HOURLYEMPLOYEE_HPP

#include "Employee.hpp"

class HourlyEmployee : public Employee
{
public:
    HourlyEmployee(const std::string &, const std::string &, const std::string &, 
                   const int, const int, const int, 
                   const double, const double);

    void setWage(const double);
    void setHours(const double);
    double getWage() const;
    double getHours() const;

    virtual double earnings() const;
    virtual void print() const;
private:
    double wage_;
    double hours_;
};

#endif

