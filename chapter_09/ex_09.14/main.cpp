#include "HugeInteger.hpp"

#include <iostream>
#include <cstring>

int
main()
{
    std::cout << std::endl;

    HugeInteger one;
    std::cout << "one = ";
    one.input();

    HugeInteger two;
    std::cout << "two = ";
    two.input();

    std::cout << (one.isEqualTo(two) ? "one == two" : "one != two") <<std::endl;
    std::cout << (one.isGreaterThan(two) ? "one > two" : "one !> two") <<std::endl;
    std::cout << (one.isLessThan(two) ? "one < two" : "one !< two") <<std::endl;
    
    one.add(two);
    std::cout << "one = one + two = ";
    one.output();

    one.substract(two);
    std::cout << "one = one - two = ";
    one.output();

    std::cout << std::endl;
    return 0;
}

