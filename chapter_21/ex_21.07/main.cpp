#include <iostream>

#include "List.hpp"

int
main()
{
    std::cout << std::endl;
    List<int> a;
    a.insertAtFront(1);
    a.insertAtFront(2);
    a.print();

    std::cout << std::endl;
    return 0;
}

