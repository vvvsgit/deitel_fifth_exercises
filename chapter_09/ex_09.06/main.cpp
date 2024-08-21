#include "Rational.hpp"

#include <iostream>

int
main()
{
    std::cout << std::endl;

    Rational number1;
    Rational number2(3, 9);
    std::cout << "number1 = ";
    number1.printFraction();
    std::cout << "number1 = ";
    number1.printFloating();
    std::cout << "number2 = ";
    number2.printFraction();
    std::cout << "number2 = ";
    number2.printFloating();

    std::cout << std::endl;
    number1.add(number2);
    number2.add(number1);
    std::cout << "number1 = number1 + number2 = ";
    number1.printFraction();
    std::cout << "number1 = number1 + number2 = ";
    number1.printFloating();
    std::cout << "number2 = number2 + number1 = ";
    number2.printFraction();
    std::cout << "number2 = number2 + number1 = ";
    number2.printFloating();

    std::cout << std::endl;
    number1.subtract(number2);
    number2.subtract(number1);
    std::cout << "number1 = number1 - number2 = ";
    number1.printFraction();
    std::cout << "number1 = number1 - number2 = ";
    number1.printFloating();
    std::cout << "number2 = number2 - number1 = ";
    number2.printFraction();
    std::cout << "number2 = number2 - number1 = ";
    number2.printFloating();

    std::cout << std::endl;
    number1.multiply(number2);
    number2.multiply(number1);
    std::cout << "number1 = number1 * number2 = ";
    number1.printFraction();
    std::cout << "number1 = number1 * number2 = ";
    number1.printFloating();
    std::cout << "number2 = number2 * number1 = ";
    number2.printFraction();
    std::cout << "number2 = number2 * number1 = ";
    number2.printFloating();

    std::cout << std::endl;
    number1.divide(number2);
    number2.divide(number1);
    std::cout << "number1 = number1 / number2 = ";
    number1.printFraction();
    std::cout << "number1 = number1 / number2 = ";
    number1.printFloating();
    std::cout << "number2 = number2 / number1 = ";
    number2.printFraction();
    std::cout << "number2 = number2 / number1 = ";
    number2.printFloating();

    std::cout << std::endl;
    return 0;
}

