#include "Complex.hpp"

#include <iostream>

Complex::Complex(double realPart, double imaginaryPart)
    : real_(realPart)
    , imaginary_(imaginaryPart)
{
}

Complex
Complex::operator+(const Complex &operand2) const
{
    return Complex(real_ + operand2.real_, imaginary_ + operand2.imaginary_);
}

Complex
Complex::operator-(const Complex &operand2) const
{
    return Complex(real_ - operand2.real_, imaginary_ - operand2.imaginary_);
}

Complex
Complex::operator*(const Complex &operand2) const
{
    return Complex(real_ * operand2.real_ - imaginary_ * operand2.imaginary_, 
                   real_ * operand2.imaginary_ + imaginary_ * operand2.real_);
}

const bool
Complex::operator==(const Complex & operand2) const
{
    return real_ == operand2.real_ && imaginary_ == operand2.imaginary_;
}

const bool
Complex::operator!=(const Complex & operand2) const
{
    return !(*this == operand2);
}

//friend
std::istream &
operator>>(std::istream &input, Complex &number)
{
    input >> number.real_ >> number.imaginary_;
    return input;
}

//friend
std::ostream &
operator<<(std::ostream &output, const Complex &number)
{
    output << '(' << number.real_ << ", " << number.imaginary_ << ')';
    return output;
}

