#ifndef POLYNOMIAL_HPP
#define POLYNOMIAL_HPP

#include <iostream>

class Polynomial
{
    friend std::ostream& operator<<(std::ostream &, Polynomial &);
public:
    explicit Polynomial(const int = 3);
    Polynomial(const int *, const int *, const int);
    Polynomial(const Polynomial &);
    ~Polynomial();

    void setPolynomial(const int *, const int *, const int);

    Polynomial & operator=(const Polynomial &);
    Polynomial operator+(const Polynomial &) const;
    Polynomial operator-(const Polynomial &) const;
    Polynomial & operator+=(const Polynomial &);
    Polynomial & operator-=(const Polynomial &);

    const int getSize() const;
    const int * const getCoefficients() const;
    const int * const getExponents() const;
private:
    int size_;
    int *cfPtr_;
    int *exPtr_;
};

#endif

