#include <iostream>

#include "Account.hpp"
#include "SavingsAccount.hpp"
#include "CheckingAccount.hpp"

int
main()
{
    std::cout << std::endl;

    std::cout << "Account" << std::endl;
    Account balance(1000.0);
    std::cout << balance.getBalance() << std::endl;
    balance.credit(500);
    std::cout << balance.getBalance() << std::endl;
    balance.debit(150);
    std::cout << balance.getBalance() << std::endl;
    std::cout << std::endl;

    std::cout << "Savings Account" << std::endl;
    SavingsAccount save(1000.0, 0.09);
    std::cout << save.getBalance() << std::endl;
    save.credit(save.calculateInterest());
    std::cout << save.getBalance() << std::endl;
    std::cout << std::endl;

    std::cout << "Checking Account" << std::endl;
    CheckingAccount check(1000.0, 0.01);
    std::cout << check.getBalance() << std::endl;
    check.credit(500);
    std::cout << check.getBalance() << std::endl;
    check.debit(150);
    std::cout << check.getBalance() << std::endl;

    std::cout << std::endl;
    return 0;
}

