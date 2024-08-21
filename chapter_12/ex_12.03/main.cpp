#include <iostream>
#include <iomanip>

#include "BasePlusCommissionEmployee.hpp"

int
main()
{
    std::cout << std::endl;

    BasePlusCommissionEmployee employee("Bob", "Lewis", "333-33-3333", 5000, 0.04, 300);

    std::cout << std::fixed << std::setprecision(2);
    employee.print();
    std::cout << "employee's earnings: $" << employee.earnings() << std::endl;

    std::cout << std::endl;

    employee.setBaseSalary(1000);
    employee.print();
    std::cout << "employee's earnings: $" << employee.earnings() << std::endl;
    
    std::cout << std::endl;
    return 0;
}

