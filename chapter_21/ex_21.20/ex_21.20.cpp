#include <iostream>
#include <list>

void printListBackward(std::list<int>);

int
main ()
{
    std::cout << std::endl;

    std::list<int> intList;
    for (int i = 0; i < 10; ++i) {
        intList.push_front(i);
    }
    printListBackward(intList);
    std::cout << std::endl;

    std::cout << std::endl;
    return 0;
}

void
printListBackward(std::list<int> list)
{
    int next = list.back();
    if (list.empty()) {
        return;
    }
    list.pop_back();
    printListBackward(list);
    std::cout << next << ' ';
}

