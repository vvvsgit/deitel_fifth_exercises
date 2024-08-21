#include "CheckingAccount.hpp"

CheckingAccount::CheckingAccount(const double balance, const double fee)
    : Account(balance)
{
    setTransactionFee(fee);
}

void
CheckingAccount::credit(const double add)
{
    if (Account::credit(add)) {
        setBalance(getBalance() - getTransactionFee());
    }
}

void
CheckingAccount::debit(const double withdraw)
{
    if (Account::debit(withdraw)) {
        setBalance(getBalance() - getTransactionFee());
    }
}

void
CheckingAccount::setTransactionFee(const double fee)
{
    transactionFee_ = (fee >= 0.0 ? fee : 0.0);
}

double
CheckingAccount::getTransactionFee() const
{
    return transactionFee_;
}

