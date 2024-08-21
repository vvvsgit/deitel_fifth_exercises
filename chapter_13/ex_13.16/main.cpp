#include <iostream>
#include <vector>
#include <typeinfo>
#include <string>

#include "headers/Account.hpp"
#include "headers/SavingsAccount.hpp"
#include "headers/CheckingAccount.hpp"

int
main()
{
    std::cout << std::endl;

    Account balance(1000.0);

    SavingsAccount save(1000.0, 0.09);

    CheckingAccount check(1000.0, 0.01);

    const int size = 3;
    std::vector<Account *> accounts(size);
    accounts[0] = &balance;
    accounts[1] = &save;
    accounts[2] = &check;

    for (int i = 0; i < size; ++i) {
        std::string name = typeid(*accounts[i]).name();
        for (int i = 0; i < name.size(); ++i) {
            if (name[i] >= '0' && name[i] <= '9') {
                continue;
            }
            std::cout << name[i];
        }
        std::cout << std::endl;
        std::cout << "The initial balance is " << accounts[i]->getBalance() << std::endl;
        if (nullptr != dynamic_cast<SavingsAccount *>(accounts[i])) {
            accounts[i]->credit(dynamic_cast<SavingsAccount *>(accounts[i])->calculateInterest());
            std::cout << "The balance after calculating interest is " << accounts[i]->getBalance() << std::endl;
        }
        double money;
        std::cout << "Enter amount to withdraw: " << std::endl;
        std::cin >> money;
        accounts[i]->debit(money);
        std::cout << "The balance after withdraw is " << accounts[i]->getBalance() << std::endl;
        std::cout << "Enter amount to deposit: " << std::endl;
        std::cin >> money;
        accounts[i]->credit(money);
        std::cout << "The balance after deposit is " << accounts[i]->getBalance() << std::endl;
        std::cout << std::endl;
    }

    std::cout << std::endl;
    return 0;
}

