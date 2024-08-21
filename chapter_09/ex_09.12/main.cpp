#include "Rectangle.hpp"

#include <iostream>

int
main()
{
    std::cout << std::endl;

    std::cout << "Enter four pair of coordinates:" << std::endl;
    int coordinates[2][CORNERS];
    for (int i = 0; i < CORNERS; ++i) {
        std::cout << 'x' << i << " = ";
        std::cin >> coordinates[0][i];
        std::cout << 'y' << i << " = ";
        std::cin >> coordinates[1][i];
    }

    Rectangle myRectangle(coordinates);
    std::cout << "The width is " << myRectangle.width() << std::endl;
    std::cout << "The length is " << myRectangle.length() << std::endl;
    std::cout << "The perimeter is " << myRectangle.perimeter() << std::endl;
    std::cout << "The area is " << myRectangle.area() << std::endl;
    std::cout << "The rectangle is" << (myRectangle.isSquare() ? " " : " not ") << "a square." << std::endl;
    myRectangle.printCoordinates();

    std::cout << std::endl;
    return 0;
}

