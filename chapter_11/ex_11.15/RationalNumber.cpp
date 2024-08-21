#include "RationalNumber.hpp"

#include <iostream>

RationalNumber::RationalNumber(int numerator, int denominator)
{
    setRational(numerator, denominator);
}

void
RationalNumber::setRational(int numerator, int denominator)
{
    if (denominator == 0) {
        denominator = 1;
        std::cout << "Invalid denominator, set to 1." << std::endl;
    }
    int numeratorDublicat = (numerator > 0 ? numerator : -numerator);
    int denominatorDublicat = (denominator > 0 ? denominator : -denominator);
    while (numeratorDublicat != denominatorDublicat) {
        numeratorDublicat > denominatorDublicat ? numeratorDublicat -= denominatorDublicat : denominatorDublicat -= numeratorDublicat;
    }
    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }
    setNumerator(numerator / numeratorDublicat);
    setDenominator(denominator / denominatorDublicat);
}

void
RationalNumber::setNumerator(int numerator)
{
    numerator_ = numerator;
}

void
RationalNumber::setDenominator(int denominator)
{
    denominator_ = denominator;
}

int
RationalNumber::getNumerator() const
{
    return numerator_;
}

int
RationalNumber::getDenominator() const
{
    return denominator_;
}

RationalNumber
RationalNumber::operator+(const RationalNumber &number)
{
    RationalNumber result;
    if (getDenominator() == number.getDenominator()) {
        result.setRational(getNumerator() + number.getNumerator(), getDenominator());
    } else {
        result.setRational((getNumerator() * number.getDenominator()) 
                           + (number.getNumerator() * getDenominator()), 
                           getDenominator() * number.getDenominator());
    }
    return result;
}

RationalNumber
RationalNumber::operator-(const RationalNumber &number)
{
    RationalNumber result;
    if (getDenominator() == number.getDenominator()) {
        result.setRational(getNumerator() - number.getNumerator(), getDenominator());
    } else {
        result.setRational((getNumerator() * number.getDenominator()) 
                           - (number.getNumerator() * getDenominator()), 
                           getDenominator() * number.getDenominator());
    }
    return result;
}

RationalNumber
RationalNumber::operator*(const RationalNumber &number)
{
    RationalNumber result(getNumerator() * number.getNumerator(),
                          getDenominator() * number.getDenominator());
    return result;
}

RationalNumber
RationalNumber::operator/(const RationalNumber &number)
{
    RationalNumber result(getNumerator() * number.getDenominator(),
                          getDenominator() * number.getNumerator());
    return result;
}

const bool
RationalNumber::operator==(const RationalNumber &number) const
{
    return getNumerator() == number.getNumerator() &&
           getDenominator() == number.getDenominator(); 
}

const bool
RationalNumber::operator!=(const RationalNumber &number) const
{
    return !(*this == number);
}

const bool
RationalNumber::operator>(const RationalNumber &number) const
{
    return getNumerator() * number.getDenominator() > number.getNumerator() * getDenominator();
}

const bool
RationalNumber::operator<(const RationalNumber &number) const
{
    return getNumerator() * number.getDenominator() < number.getNumerator() * getDenominator();
}

const bool
RationalNumber::operator>=(const RationalNumber &number) const
{
    return !(*this < number);
}

const bool
RationalNumber::operator<=(const RationalNumber &number) const
{
    return !(*this > number);
}

void
RationalNumber::printFraction()
{
    std::cout << getNumerator() << "/" << getDenominator() << std::endl;
}

void
RationalNumber::printFloating()
{
    std::cout << static_cast<double>(getNumerator()) / getDenominator() << std::endl;
}

