#include "Time.hpp"

#include <iostream>

int
main()
{
    std::cout << std::endl;

    Time liveTime;
    liveTime.printUniversal();
    liveTime.printStandart();

    std::cout << std::endl;
    return 0;
}

