#ifndef PHONENUMBER_HPP
#define PHONENUMBER_HPP

#include <iostream>
#include <string>

class PhoneNumber
{
public:
    std::ostream& operator<<(std::ostream &) const;
    std::istream& operator>>(std::istream &);
private:
    std::string areaCode_;
    std::string exchange_;
    std::string line_;
};

#endif

