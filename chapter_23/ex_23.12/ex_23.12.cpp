#include <iostream>
#include <vector>

template<typename P>
bool pallindrome(std::vector<P>);

int
main()
{
    std::cout << std::endl;

    std::vector<int> intVector1 = {4, 5, 6, 7, 6, 5, 4};
    std::vector<int> intVector2 = {4, 6, 7, 6, 5, 4};
    std::vector<double> doubleVector1 = {3.3, 2.2, 2.2, 3.3};
    std::vector<double> doubleVector2 = {2.2, 2.2, 3.3};
    std::vector<char> charVector1 = {'a', 's', 's', 'd', 's', 's', 'a'};
    std::vector<char> charVector2 = {'a', 's', 'd', 's', 's', 'a'};

    std::cout << std::boolalpha;
    std::cout << "intvector1 pallindrome - " << pallindrome(intVector1) << std::endl;
    std::cout << "intvector2 pallindrome - " << pallindrome(intVector2) << std::endl;
    std::cout << "doublevector1 pallindrome - " << pallindrome(doubleVector1) << std::endl;
    std::cout << "doublevector2 pallindrome - " << pallindrome(doubleVector2) << std::endl;
    std::cout << "charvector1 pallindrome - " << pallindrome(charVector1) << std::endl;
    std::cout << "charvector2 pallindrome - " << pallindrome(charVector2) << std::endl;


    std::cout << std::endl;
    return 0;
}

template<typename P>
bool
pallindrome(std::vector<P> toCheck)
{
    int size = toCheck.size() - 1;
    for (int i = 0; i <= size; ++i, --size) {
        if (toCheck[i] != toCheck[size]) {
            return false;
        }
    }
    return true;
}

