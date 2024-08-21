#include "PhoneNumber.hpp"

#include <iostream>

int
main()
{
    std::cout << std::endl;

    PhoneNumber phone;
    std::cout << "Enter phone number in the form (123) 456-7890:" << std::endl;
    phone >> std::cin;
    std::cout << "The Phone number entered was: ";
    phone << std::cout;
    phone.operator<<(std::cout);

    std::cout << std::endl;
    return 0;
}

