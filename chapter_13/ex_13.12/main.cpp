#include <iostream>
#include <iomanip>
#include <vector>

#include "headers/Employee.hpp"
#include "headers/SalariedEmployee.hpp"
#include "headers/HourlyEmployee.hpp"
#include "headers/CommissionEmployee.hpp"
#include "headers/BasePlusCommissionEmployee.hpp"

int
main()
{
    std::cout << std::endl;

    std::cout << std::fixed << std::setprecision(2);

    const Date now;
    SalariedEmployee employee0("John", "Smith", "111-11-1111", 23, 11, 1987, 800);
    HourlyEmployee employee1("Neo", "Anderson", "666-66-6666", 6, 8, 1957, 16.75, 40);
    CommissionEmployee employee2("James", "Bond", "007-00-7007", 7, 7, 1977, 10000, 0.06);
    BasePlusCommissionEmployee employee3("Bruce", "Wayne", "888-88-8888", 15, 9, 1982, 5000, 0.04, 300);

    const int size = 4;
    std::vector<Employee *> employees(size);
    employees[0] = &employee0;
    employees[1] = &employee1;
    employees[2] = &employee2;
    employees[3] = &employee3;
    
    for (int i = 0; i < size; ++i) {
        std::cout << employees[i]->getBirthDate()->getDay() << '/' 
                  << employees[i]->getBirthDate()->getMonth() << '/' 
                  << employees[i]->getBirthDate()->getYear() << std::endl;
        employees[i]->print();
        double payroll = employees[i]->earnings();
        if (now.getMonth() == employees[i]->getBirthDate()->getMonth()) {
            payroll += 100.0;
        }
        std::cout << "\nearned $" << payroll << std::endl << std::endl;
    }

    std::cout << std::endl;
    return 0;
}

