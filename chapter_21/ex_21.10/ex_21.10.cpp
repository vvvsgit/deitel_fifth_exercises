#include <iostream>
#include <stack>

int
main()
{
    std::cout << std::endl;

    std::stack<char> myStack;
    char text[] = "a man a plan a canal panama";
    std::cout << text << std::endl;
    for (int i = 0; text[i] != '\0'; ++i) {
        myStack.push(text[i]);
    }
    while (!myStack.empty()) {
        std::cout << myStack.top();
        myStack.pop();
    }
    std::cout << std::endl;

    std::cout << std::endl;
    return 0;
}

