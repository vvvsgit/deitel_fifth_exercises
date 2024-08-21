#include "DateAndTime.hpp"

#include <iostream>

int
main()
{
    std::cout << std::endl;

    std::cout << "Live." << std::endl;
    DateAndTime liveDateAndTime;
    liveDateAndTime.printUniversal();
    liveDateAndTime.printStandart();
    liveDateAndTime.tick();
    liveDateAndTime.printUniversal();
    liveDateAndTime.printStandart();
    std::cout << std::endl;

    std::cout << "Minute. " << std::endl;
    DateAndTime minuteDateAndTime(59, 15, 11, 2, 27, 1642);
    minuteDateAndTime.printUniversal();
    minuteDateAndTime.printStandart();
    minuteDateAndTime.tick();
    minuteDateAndTime.printUniversal();
    minuteDateAndTime.printStandart();
    std::cout << std::endl;

    std::cout << "Hour." << std::endl;
    DateAndTime hourDateAndTime(59, 59, 21, 4, 3, 1867);
    hourDateAndTime.printUniversal();
    hourDateAndTime.printStandart();
    hourDateAndTime.tick();
    hourDateAndTime.printUniversal();
    hourDateAndTime.printStandart();
    std::cout << std::endl;

    std::cout << "Day." << std::endl;
    DateAndTime dayDateAndTime(59, 59, 23, 6, 5, 1900);
    dayDateAndTime.printUniversal();
    dayDateAndTime.printStandart();
    dayDateAndTime.tick();
    dayDateAndTime.printUniversal();
    dayDateAndTime.printStandart();
    std::cout << std::endl;

    std::cout << "Month." << std::endl;
    DateAndTime monthDateAndTime(59, 59, 23, 31, 1, 1111);
    monthDateAndTime.printUniversal();
    monthDateAndTime.printStandart();
    monthDateAndTime.tick();
    monthDateAndTime.printUniversal();
    monthDateAndTime.printStandart();
    std::cout << std::endl;

    std::cout << "Year." << std::endl;
    DateAndTime yearDateAndTime(59, 59, 23, 31, 12, 2023);
    yearDateAndTime.printUniversal();
    yearDateAndTime.printStandart();
    yearDateAndTime.tick();
    yearDateAndTime.printUniversal();
    yearDateAndTime.printStandart();

    std::cout << std::endl;
    return 0;
}

