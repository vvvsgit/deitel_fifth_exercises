#include "SavingsAccount.hpp"

#include <iostream>

int
main()
{
    std::cout << std::endl;

    SavingsAccount saver1(2000.0);
    SavingsAccount saver2(3000.0);
    saver1.printBalance();
    saver2.printBalance();

    SavingsAccount::modifyInterestRate(3);
    saver1.calculateMonthlyInterest();
    saver2.calculateMonthlyInterest();
    saver1.printBalance();
    saver2.printBalance();

    SavingsAccount::modifyInterestRate(4);
    saver1.calculateMonthlyInterest();
    saver2.calculateMonthlyInterest();
    saver1.printBalance();
    saver2.printBalance();

    std::cout << std::endl;
    return 0;
}

