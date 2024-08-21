#include <iostream>

#include "Account.hpp"

Account::Account(const double balance)
{
    if (balance < 0) {
        std::cout << "Warning 1: invalid balance, set to o." << std::endl;
    }
    setBalance(balance);
}

bool
Account::credit(const double add)
{
    if (add > 0) {
        setBalance(getBalance() + add);
        return true;
    }
    return false;
}

bool
Account::debit(const double withdraw)
{
    if (withdraw > 0) {
        if (withdraw <= getBalance()) {
            setBalance(getBalance() - withdraw);
            return true;
        } else {
            std::cout << "Debit amount exceeded account balance." << std::endl;
        }
    }
    return false;
}

void
Account::setBalance(const double balance)
{
    balance_ = (balance >= 0.0 ? balance : 0.0);
}

double
Account::getBalance() const
{
    return balance_;
}

