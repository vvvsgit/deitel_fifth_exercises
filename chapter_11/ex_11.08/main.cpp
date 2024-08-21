#include "String.hpp"

#include <iostream>

int
main()
{
    std::cout << std::endl;

    String s1("barev");
    String s2("ape");
    String s3(" ");

    s3 = s1 + (s3 + s2);

    std::cout << "s1 = " << s1 << std::endl;
    std::cout << "s2 = " << s2 << std::endl;
    std::cout << "s3 = " << s3 << std::endl;

    std::cout << std::endl;
    return 0;
}

