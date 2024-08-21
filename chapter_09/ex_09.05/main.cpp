#include "Complex.hpp"

#include <iostream>

int
main()
{
    std::cout << std::endl;

    Complex number1;
    Complex number2(2.3, 1.2);

    std::cout << "number1 = ";
    number1.print();
    std::cout << "number2 = ";
    number2.print();

    number1.add(number2);
    number2.subtract(number1);

    std::cout << "number1 + number2 = ";
    number1.print();
    std::cout << "number2 - number1 = ";
    number2.print();

    std::cout << std::endl;
    return 0;
}

