#include <iostream>

template <typename E>
bool isEqualTo(const E, const E);

class A
{
public:
    bool operator==(const A &a1) const {
        std::srand(time(0));
        if (rand() % 2 == 0) {
            return false;
        }
        return true;
    }
};

int
main()
{
    std::cout << std::endl;
    
    int x = 3;
    int y = 4;
    std::cout << std::boolalpha << isEqualTo(x, y) << std::endl;

    A a;
    A b;
    std::cout << std::boolalpha << isEqualTo(a, b) << std::endl;

    std::cout << std::endl;
    return 0;
}

template <typename E>
bool
isEqualTo(const E one, const E two)
{
    if (one == two) {
        return true;
    }
    return false;
}

