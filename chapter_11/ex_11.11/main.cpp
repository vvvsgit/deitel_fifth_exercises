#include "DoubleSubscriptedArray.hpp"

#include <iostream>

int
main()
{
    std::cout << std::endl;

    DoubleSubscriptedArray array1(3, 3);
    DoubleSubscriptedArray array2;

    std::cout << "array1\n" << array1 << std::endl;
    std::cout << "array2\n" << array2 << std::endl;

    
    std::cin >> array1 >> array2;

    std::cout << "array1\n" << array1 << std::endl;
    std::cout << "array2\n" << array2 << std::endl;

    std::cout << "array1 == array2 = " << std::boolalpha << (array1 == array2) << std::endl;
    std::cout << "array1 != array2 = " << std::boolalpha << (array1 != array2) << std::endl;

    std::cout << "array2 = array1;" << std::endl;
    array2 = array1;

    std::cout << "array1\n" << array1 << std::endl;
    std::cout << "array2\n" << array2 << std::endl;

    std::cout << "array1 == array2 = " << std::boolalpha << (array1 == array2) << std::endl;
    std::cout << "array1 != array2 = " << std::boolalpha << (array1 != array2) << std::endl;

    std::cout << "array1(0, 0) == " << array1(0, 0) << std::endl;

    std::cout << "array1(0, 0) = 555" << std::endl;
    array1(0, 0) = 555;
    std::cout << "array1(0, 0) == " << array1(0, 0) << std::endl;

    std::cout << "array1\n" << array1 << std::endl;
    std::cout << "array1 == array2 = " << std::boolalpha << (array1 == array2) << std::endl;

    DoubleSubscriptedArray array3(array1);

    std::cout << "array3\n" << array1 << std::endl;
    
    std::cout << std::endl;
    return 0;
}

