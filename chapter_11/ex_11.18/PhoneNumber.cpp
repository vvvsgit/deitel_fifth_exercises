#include "PhoneNumber.hpp"

#include <iomanip>

std::ostream &
PhoneNumber::operator<<(std::ostream &output) const
{
    output << "(" << areaCode_ << ") " << exchange_ << "-" << line_ << std::endl;
    return output;
}

std::istream &
PhoneNumber::operator>>(std::istream &input)
{
    input.ignore();
    input >> std::setw(3) >> areaCode_;
    input.ignore(2);
    input >> std::setw(3) >> exchange_;
    input.ignore();
    input >> std::setw(4) >> line_;
    return input;
}

