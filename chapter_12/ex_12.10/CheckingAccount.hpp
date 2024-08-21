#ifndef CHECKINGACCOUNT_HPP
#define CHECKINGACCOUNT_HPP

#include "Account.hpp"

class CheckingAccount : public Account
{
public:
    CheckingAccount(const double = 0.0, const double = 0.0);

    void credit(const double);
    void debit(const double);

    void setTransactionFee(const double);
    double getTransactionFee() const;
private:
    double transactionFee_;
};

#endif

