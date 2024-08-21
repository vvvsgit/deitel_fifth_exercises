#include "Time.hpp"

#include <iostream>

int
main()
{
    std::cout << std::endl;

    std::cout << "Live time." << std::endl;
    Time liveTime;
    liveTime.printUniversal();
    liveTime.printStandart();
    std::cout << std::endl;

    std::cout << "Minute. " << std::endl;
    Time timeMinute(0, 0, 59);
    timeMinute.printUniversal();
    timeMinute.printStandart();
    std::cout << std::endl;

    std::cout << "Hour." << std::endl;
    Time timeHour(0, 59, 59);
    timeHour.printUniversal();
    timeHour.printStandart();
    std::cout << std::endl;

    std::cout << "Day." << std::endl;
    Time timeDay(23,59,59);
    timeDay.printUniversal();
    timeDay.printStandart();

    std::cout << std::endl;
    return 0;
}

