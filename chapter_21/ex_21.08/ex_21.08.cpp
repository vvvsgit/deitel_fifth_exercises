#include <iostream>
#include <list>

int
main()
{
    std::cout << std::endl;

    std::srand(time(0));
    std::list<int> myList;
    int quantity = 25;
    for (int i = 0; i < quantity; ++i) {
        myList.push_front(rand() % 100);
    }
    int sum = 0;
    while (!myList.empty()) {
        std::cout << myList.front() << ' ';
        sum += myList.front();
        myList.pop_front();
    }
    std::cout << std::endl;
    std::cout << "The sum is " << sum << "\nThe avarage is " << static_cast<double>(sum) / quantity << std::endl;

    std::cout << std::endl;
    return 0;
}

