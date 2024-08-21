#ifndef SAVINGSACCOUNT_HPP
#define SAVINGSACCOUNT_HPP

#include "Account.hpp"

class SavingsAccount : public Account
{
public:
    SavingsAccount(const double = 0.0, const double = 0.0);
    double calculateInterest() const;
    void setInterestRate(const double);
    double getInterestRate() const;
private:
    double interestRate_;
};

#endif

