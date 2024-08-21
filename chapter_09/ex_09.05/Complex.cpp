#include "Complex.hpp"

#include <iostream>

Complex::Complex(double real, double imagine)
{
    setComplex(real, imagine);
}

void
Complex::setComplex(double real, double imagine)
{
    setReal(real);
    setImagine(imagine);
}

void
Complex::setReal(double real)
{
    realPart_ = real;
}

void
Complex::setImagine(double imagine)
{
    imaginePart_ = imagine;
}

double
Complex::getReal()
{
    return realPart_;
}

double
Complex::getImagine()
{
    return imaginePart_;
}

void
Complex::add(Complex number)
{
    setComplex(getReal() + number.getReal(), getImagine() + number.getImagine());
}

void
Complex::subtract(Complex number)
{
    setComplex(getReal() - number.getReal(), getImagine() - number.getImagine());
}

void
Complex::print()
{
    std::cout << getReal() << " + " << getImagine() << 'i' << std::endl;
}

