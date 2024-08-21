#include <iostream>

#include "../headers/Employee.hpp"

Employee::Employee(const std::string &first, const std::string &last, const std::string &ssn, 
                   const int day, const int month, const int year)
    : firstName_(first)
    , lastName_(last)
    , socialSecurityNumber_(ssn)
    , birthDate_(day, month, year)
{
}

void
Employee::setFirstName(const std::string &first)
{
    firstName_ = first;
}

void
Employee::setLastName(const std::string &last)
{
    lastName_ = last;
}

void
Employee::setSocialSecurityNumber(const std::string &ssn)
{
    socialSecurityNumber_ = ssn;
}

std::string
Employee::getFirstName() const
{
    return firstName_;
}

std::string
Employee::getLastName() const
{
    return lastName_;
}

std::string
Employee::getSocialSecurityNumber() const
{
    return socialSecurityNumber_;
}

const Date * const
Employee::getBirthDate() const
{
    return &birthDate_;
}

void
Employee::print() const
{
    std::cout << getFirstName() << ' ' << getLastName()
              << "\nsocial security number: " 
              << getSocialSecurityNumber();
}

