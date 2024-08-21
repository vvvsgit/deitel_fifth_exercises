#include <iostream>
#include <stack>

int
main()
{
    std::cout << std::endl;

    std::stack<char> myStack;
    char text[] = "a man a plan a canal panama";
    for (int i = 0; text[i] != '\0'; ++i) {
        if (text[i] >= 'a' && text[i] <= 'z' || text[i] >= 'A' && text[i] <= 'Z') {
            myStack.push(text[i]);
        }
    }
    
    for (int i = 0; !myStack.empty(); ++i) {
        if (text[i] >= 'a' && text[i] <= 'z' || text[i] >= 'A' && text[i] <= 'Z') {
            if (text[i] != myStack.top()) {
                std::cout << "Not a palindrom." << std::endl;
                break;
            }
            myStack.pop();
        }
    }

    std::cout << std::endl;
    return 0;
}

