#include <iostream>

#include "Package.hpp"
#include "TwoDayPackage.hpp"
#include "OverNightPackage.hpp"

int
main()
{
    std::cout << std::endl;

    Package package("anun1", "azganun1", "qaxaq1", "nahang1", "zip1", "anun2", "azganun2", "qaxaq2", "nahang2", "zip2", 5, 20);
    package.print();
    std::cout << "The cost is " << package.calculateCost() << std::endl;

    std::cout << std::endl;
    TwoDayPackage day("anun2", "azganun2", "qaxaq2", "nahang2", "zip2", "anun3", "azganun3", "qaxaq3", "nahang3", "zip3", 5, 20, 130);
    day.print();
    std::cout << "The cost is " << day.calculateCost() << std::endl;

    std::cout << std::endl;
    OverNightPackage night("anun3", "azganun3", "qaxaq3", "nahang3", "zip3", "anun4", "azganun4", "qaxaq4", "nahang4", "zip4", 5, 20, 5);
    night.print();
    std::cout << "The cost is " << night.calculateCost() << std::endl;

    std::cout << std::endl;
    return 0;
}

