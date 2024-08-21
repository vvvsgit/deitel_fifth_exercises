#include <iostream>

#include "List.hpp"

int
main()
{
    std::cout << std::endl;

    List<int> i;
    i.insertAtFront(0);
    i.insertAtFront(2);
    i.insertAtFront(3);
    i.print();
    std::cout << i[2] << ' ' << i[1] << ' ' << i[0] << std::endl;
    i[0] = 100;
    std::cout << i[2] << ' ' << i[1] << ' ' << i[0] << std::endl;

    std::cout << std::endl;
    return 0;
}

