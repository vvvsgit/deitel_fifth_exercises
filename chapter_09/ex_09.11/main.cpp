#include "Rectangle.hpp"

#include <iostream>

int
main()
{
    std::cout << std::endl;

    std::cout << "Enter rectangle's sizes:" << std::endl;
    std::cout << "   length = ";
    double length;
    std::cin >> length;
    std::cout << "   width = ";
    double width;
    std::cin >> width;

    Rectangle myRectangle(length, width);
    std::cout << "The perimeter is " << myRectangle.perimeter() << std::endl;
    std::cout << "The area is " << myRectangle.area() << std::endl;

    std::cout << std::endl;
    return 0;
}

