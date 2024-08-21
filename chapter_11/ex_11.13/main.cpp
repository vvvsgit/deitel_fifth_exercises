#include "Complex.hpp"

#include <iostream>

int
main()
{
    std::cout << std::endl;

    Complex x;
    Complex y(4.3, 8.2);
    Complex z(3.3, 1.1);

    std::cout << "x = " << x << "\ny = " << y << "\nz = " << z << std::endl;

    x = y + z;
    std::cout << "\nx = y + z:" << std::endl;
    std::cout << x << " = " << y << " + " << z << std::endl;

    x = y - z;
    std::cout << "\nx = y - z:" << std::endl;
    std::cout << x << " = " << y << " - " << z << std::endl;

    x = y * z;
    std::cout << "\nx = y * z:" << std::endl;
    std::cout << x << " = " << y << " * " << z << std::endl;

    Complex w;
    w = x;
    std::cout << "\nx = " << x << "\nw = " << w << std::endl;
    std::cout << "x == w " << std::boolalpha << (x == w) << std::endl;
    std::cout << "x != w " << std::boolalpha << (x != w) << std::endl;

    std::cout << std::endl;
    return 0;
}

