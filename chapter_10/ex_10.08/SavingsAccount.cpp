#include "SavingsAccount.hpp"

#include <iostream>

double SavingsAccount::annualInterestRate_ = 0.0;

SavingsAccount::SavingsAccount(double balance)
{
    setBalance(balance);
    setSavingsBalance(0.0);
}

void
SavingsAccount::setBalance(double balance)
{
    if (balance < 0) {
        balance_ = 0;
        return;
    }
    balance_ = balance;
}

double
SavingsAccount::getBalance()
{
    return balance_;
}

void
SavingsAccount::calculateMonthlyInterest()
{
    setSavingsBalance(getSavingsBalance() + getBalance() * getAnnualInterestRate() / 12);
}

void
SavingsAccount::setSavingsBalance(double savingsBalance)
{
    if (savingsBalance < 0) {
        savingsBalance_ = 0;
        return;
    }
    savingsBalance_ = savingsBalance;
}

double
SavingsAccount::getSavingsBalance()
{
    return savingsBalance_;
}

void
SavingsAccount::modifyInterestRate(double rate)
{
    if (rate < 0) {
        annualInterestRate_ = 0;
        return;
    }
    annualInterestRate_ = rate;
}

double
SavingsAccount::getAnnualInterestRate()
{
    return annualInterestRate_;
}

void
SavingsAccount::printBalance()
{
    std::cout << "The balance is " << getBalance()
              << "\nThe savings Balance is " << getSavingsBalance() 
              << std::endl << std::endl;
}

