#include "Rational.hpp"

#include <iostream>

Rational::Rational(int numerator, int denominator)
{
    setRational(numerator, denominator);
}

void
Rational::setRational(int numerator, int denominator)
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
    if (numerator < 0 && denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }
    setNumerator(numerator / numeratorDublicat);
    setDenominator(denominator / denominatorDublicat);
}

void
Rational::setNumerator(int numerator)
{
    numerator_ = numerator;
}

void
Rational::setDenominator(int denominator)
{
    denominator_ = denominator;
}

int
Rational::getNumerator()
{
    return numerator_;
}

int
Rational::getDenominator()
{
    return denominator_;
}

void
Rational::add(Rational number)
{
    if (getDenominator() == number.getDenominator()) {
        setRational(getNumerator() + number.getNumerator(), getDenominator());
    } else {
        setRational((getNumerator() * number.getDenominator()) 
                    + (number.getNumerator() * getDenominator()), 
                    getDenominator() * number.getDenominator());
    }
}

void
Rational::subtract(Rational number)
{
    if (getDenominator() == number.getDenominator()) {
        setRational(getNumerator() - number.getNumerator(), getDenominator());
    } else {
        setRational((getNumerator() * number.getDenominator()) 
                    - (number.getNumerator() * getDenominator()), 
                    getDenominator() * number.getDenominator());
    }
}

void
Rational::multiply(Rational number)
{
    setRational(getNumerator() * number.getNumerator(),
                getDenominator() * number.getDenominator());
}

void
Rational::divide(Rational number)
{
    setRational(getNumerator() * number.getDenominator(),
                getDenominator() * number.getNumerator());
}

void
Rational::printFraction()
{
    std::cout << getNumerator() << "/" << getDenominator() << std::endl;
}

void
Rational::printFloating()
{
    std::cout << static_cast<double>(getNumerator()) / getDenominator() << std::endl;
}

