#include "RationalNumber.hpp"

#include <iostream>

int
main()
{
    std::cout << std::endl;

    RationalNumber number1;
    RationalNumber number2(3, 9);
    std::cout << "number1 = ";
    number1.printFraction();
    std::cout << "number1 = ";
    number1.printFloating();
    std::cout << "number2 = ";
    number2.printFraction();
    std::cout << "number2 = ";
    number2.printFloating();

    std::cout << std::endl;
    number1 = number1 + number2;
    number2 = number2 + number1;
    std::cout << "number1 = number1 + number2 = ";
    number1.printFraction();
    std::cout << "number1 = number1 + number2 = ";
    number1.printFloating();
    std::cout << "number2 = number2 + number1 = ";
    number2.printFraction();
    std::cout << "number2 = number2 + number1 = ";
    number2.printFloating();

    std::cout << std::endl;
    number1 = number1 - number2;
    number2 = number2 - number1;
    std::cout << "number1 = number1 - number2 = ";
    number1.printFraction();
    std::cout << "number1 = number1 - number2 = ";
    number1.printFloating();
    std::cout << "number2 = number2 - number1 = ";
    number2.printFraction();
    std::cout << "number2 = number2 - number1 = ";
    number2.printFloating();

    std::cout << std::endl;
    number1 = number1 * number2;
    number2 = number2 * number1;
    std::cout << "number1 = number1 * number2 = ";
    number1.printFraction();
    std::cout << "number1 = number1 * number2 = ";
    number1.printFloating();
    std::cout << "number2 = number2 * number1 = ";
    number2.printFraction();
    std::cout << "number2 = number2 * number1 = ";
    number2.printFloating();

    std::cout << std::endl;
    number1 = number1 / number2;
    number2 = number2 / number1;
    std::cout << "number1 = number1 / number2 = ";
    number1.printFraction();
    std::cout << "number1 = number1 / number2 = ";
    number1.printFloating();
    std::cout << "number2 = number2 / number1 = ";
    number2.printFraction();
    std::cout << "number2 = number2 / number1 = ";
    number2.printFloating();

    std::cout << std::endl;
    std::cout << (number1 == number2 ? "number1 == number2" : "number1 !(=) number2") << std::endl;
    std::cout << (number1 != number2 ? "number1 != number2" : "number1 !(!=) number2") << std::endl;
    std::cout << (number1 > number2 ? "number1 > number2" : "number1 !(>) number2") << std::endl;
    std::cout << (number1 < number2 ? "number1 < number2" : "number1 !(<) number2") << std::endl;
    std::cout << (number1 >= number2 ? "number1 >= number2" : "number1 !(>=) number2") << std::endl;
    std::cout << (number1 <= number2 ? "number1 <= number2" : "number1 !(<=) number2") << std::endl;

    std::cout << std::endl;
    return 0;
}

