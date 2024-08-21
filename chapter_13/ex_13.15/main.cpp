#include <iostream>
#include <vector>

#include "headers/Package.hpp"
#include "headers/TwoDayPackage.hpp"
#include "headers/OverNightPackage.hpp"

int
main()
{
    std::cout << std::endl;

    Package common("anun1", "azganun1", "qaxaq1", "nahang1", "zip1", "anun2", "azganun2", "qaxaq2", "nahang2", "zip2", 5, 20);

    TwoDayPackage day("anun2", "azganun2", "qaxaq2", "nahang2", "zip2", "anun3", "azganun3", "qaxaq3", "nahang3", "zip3", 5, 20, 130);

    OverNightPackage night("anun3", "azganun3", "qaxaq3", "nahang3", "zip3", "anun4", "azganun4", "qaxaq4", "nahang4", "zip4", 5, 20, 5);

    const int size = 3;
    std::vector <Package *> packages(size);
    packages[0] = &common;
    packages[1] = &day;
    packages[2] = &night;

    double totalCost = 0.0;
    for (int i = 0; i < size; ++i) {
        packages[i]->print();
        totalCost += packages[i]->calculateCost();
        std::cout << "The cost is " << packages[i]->calculateCost() << std::endl;
        std::cout << std::endl;
    }
    std::cout << "The Total cost for all packages is " << totalCost << std::endl;

    std::cout << std::endl;
    return 0;
}

