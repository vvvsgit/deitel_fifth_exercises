#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

class Account
{
public:
    explicit Account(const double = 0.0);

    bool credit(const double);
    bool debit(const double);

    void setBalance(const double);
    double getBalance() const;
private:
    double balance_;
};

#endif

