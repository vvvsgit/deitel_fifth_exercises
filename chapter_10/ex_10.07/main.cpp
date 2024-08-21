#include "Date.hpp"

#include <iostream>

int
main()
{
    std::cout << std::endl;

    std::cout << "Live." << std::endl;
    Date liveDate;
    liveDate.printDDMMYY();
    liveDate.printDDDYYYY();
    liveDate.printMonthDDYYYY();
    std::cout << std::endl;

    std::cout << "DDMMYY." << std::endl;
    Date ddmmyyDate(10, 11, 12);
    ddmmyyDate.printDDMMYY();
    ddmmyyDate.printDDDYYYY();
    ddmmyyDate.printMonthDDYYYY();
    std::cout << std::endl;

    std::cout << "DDDYYYY." << std::endl;
    Date dddyyyyDate(365, 365);
    dddyyyyDate.printDDMMYY();
    dddyyyyDate.printDDDYYYY();
    dddyyyyDate.printMonthDDYYYY();
    std::cout << std::endl;

    std::cout << "MonthDDYYYY." << std::endl;
    char month[] = "March";
    Date monthddyyyyDate(month, 5, 1987);
    monthddyyyyDate.printDDMMYY();
    monthddyyyyDate.printDDDYYYY();
    monthddyyyyDate.printMonthDDYYYY();

    std::cout << std::endl;
    return 0;
}

