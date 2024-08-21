#include "SavingsAccount.hpp"

SavingsAccount::SavingsAccount(const double balance, const double rate)
    : Account(balance)
{
    setInterestRate(rate);
}

double
SavingsAccount::calculateInterest() const
{
    return getInterestRate() * getBalance();
}

void
SavingsAccount::setInterestRate(const double rate)
{
    interestRate_ = (rate >= 0.0 ? rate : 0.0);
}

double
SavingsAccount::getInterestRate() const
{
    return interestRate_;
}

