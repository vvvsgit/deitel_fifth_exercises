#include "IntegerSet.hpp"

#include <iostream>

int
main()
{
    std::cout << std::endl;

    IntegerSet setOne;
    std::cout << "setOne." << std::endl;
    setOne.printSet();

    int arraySet[15] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 44, 33, 77};
    IntegerSet setTwo(arraySet, 15);
    std::cout << "setTwo." << std::endl;
    setTwo.printSet();

    std::cout << "setOne.isEqualTo(setTwo) = " << std::boolalpha << setOne.isEqualTo(setTwo) << std::endl;

    IntegerSet setThree;
    setThree.unionOfSets(setOne, setTwo);
    std::cout << "setThree." << std::endl;
    setThree.printSet();

    std::cout << "setThree.isEqualTo(setTwo) = " << std::boolalpha << setThree.isEqualTo(setTwo) << std::endl;

    setOne.insertElement(100);
    std::cout << "setOne." << std::endl;
    setOne.printSet();

    setTwo.deleteElement(0);
    std::cout << "setTwo." << std::endl;
    setTwo.printSet();

    IntegerSet setFour;
    setFour.intersectionOfSets(setTwo, setThree);
    std::cout << "setFour." << std::endl;
    setFour.printSet();

    std::cout << std::endl;
    return 0;
}

