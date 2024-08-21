#include "../headers/CheckingAccount.hpp"

CheckingAccount::CheckingAccount(const double balance, const double fee)
    : Account(balance)
{
    setTransactionFee(fee);
}

bool
CheckingAccount::credit(const double add)
{
    if (Account::credit(add)) {
        setBalance(getBalance() - getTransactionFee());
        return true;
    }
    return false;
}

bool
CheckingAccount::debit(const double withdraw)
{
    if (Account::debit(withdraw)) {
        setBalance(getBalance() - getTransactionFee());
        return true;
    }
    return false;
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

