#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP

#include <string>

#include "Date.hpp"

class Employee
{
public:
    Employee(const std::string &, const std::string &, const std::string &, 
             const int, const int, const int);

    void setFirstName(const std::string &);
    void setLastName(const std::string &);
    void setSocialSecurityNumber(const std::string &);
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getSocialSecurityNumber() const;

    const Date * const getBirthDate() const;

    virtual double earnings() const = 0;
    virtual void print() const;
private:
    std::string firstName_;
    std::string lastName_;
    std::string socialSecurityNumber_;
    Date birthDate_;
};

#endif

