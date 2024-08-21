#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <iostream>

class Complex
{
    friend std::istream & operator>>(std::istream &, Complex &);
    friend std::ostream & operator<<(std::ostream &, const Complex &);
public:
    Complex(double = 0.0, double = 0.0);

    Complex operator+(const Complex &) const;
    Complex operator-(const Complex &) const;
    Complex operator*(const Complex &) const;
    const bool operator==(const Complex &) const;
    const bool operator!=(const Complex &) const;
private:
    double real_;
    double imaginary_;
};

#endif

