#include "Polynomial.hpp"

#include <iostream>

int
main()
{
    std::cout << std::endl;

    const int oneSize = 3;
    int oneCf[oneSize] = {1, 2, 3};
    int oneEx[oneSize] = {2, 3, 4};
    Polynomial one(oneCf, oneEx, oneSize);

    const int twoSize = 4;
    int twoCf[twoSize] = {2, 3, 4, 6};
    int twoEx[twoSize] = {2, 4, 5, 1};
    Polynomial two(twoCf, twoEx, twoSize);

    std::cout << "one = " << one << std::endl;
    std::cout << "two = " << two << std::endl;
    std::cout << std::endl;

    two = one + two;
    std::cout << "two = one + two" << std::endl;
    std::cout << "one = " << one << std::endl;
    std::cout << "two = " << two << std::endl;
    std::cout << std::endl;

    one = one - two;
    std::cout << "one = one - two" << std::endl;
    std::cout << "one = " << one << std::endl;
    std::cout << "two = " << two << std::endl;
    std::cout << std::endl;

    one += two;
    std::cout << "one += two" << std::endl;
    std::cout << "one = " << one << std::endl;
    std::cout << "two = " << two << std::endl;
    std::cout << std::endl;

    two -= one;
    std::cout << "two -= one" << std::endl;
    std::cout << "one = " << one << std::endl;
    std::cout << "two = " << two << std::endl;
    std::cout << std::endl;

    one = two;
    std::cout << "one = two" << std::endl;
    std::cout << "one = " << one << std::endl;
    std::cout << "two = " << two << std::endl;
    std::cout << std::endl;

    Polynomial three(one);
    std::cout << "three = " << three << std::endl;


    std::cout << std::endl;
    return 0;
}

