#include <iostream>
#include <list>

int
main()
{
    std::cout << std::endl;

    std::list<char> myList;
    std::list<char> myListReverse;
    char text[] = "a man a plan a canal panama";
    for (int i = 0; text[i] != '\0'; ++i) {
        myList.push_front(text[i]);
        myListReverse.push_back(text[i]);
    }
    for (int i = 0; !myList.empty(); ++i) {
        std::cout << myList.front();
        myList.pop_front();
    }
    std::cout << std::endl;
    for (int i = 0; !myListReverse.empty(); ++i) {
        std::cout << myListReverse.front();
        myListReverse.pop_front();
    }
    std::cout << std::endl;

    std::cout << std::endl;
    return 0;
}

