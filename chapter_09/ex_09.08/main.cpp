#include "Date.hpp"

#include <iostream>

int
main()
{
    std::cout << std::endl;

    std::cout << "Live." << std::endl;
    Date liveDate;
    liveDate.print();
    liveDate.nextDay();
    liveDate.print();
    std::cout << std::endl;

    std::cout << "Month." << std::endl;
    Date monthDate(31, 1, 1111);
    monthDate.print();
    monthDate.nextDay();
    monthDate.print();
    std::cout << std::endl;

    std::cout << "Year." << std::endl;
    Date yearDate(31, 12, 999);
    yearDate.print();
    yearDate.nextDay();
    yearDate.print();

    std::cout << std::endl;
    return 0;
}

