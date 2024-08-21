#include "Polynomial.hpp"

#include <iostream>
#include <cassert>

Polynomial::Polynomial(const int size)
{
    assert(size > 0);
    int defaultValues[size] = {0};
    setPolynomial(defaultValues, defaultValues, size);
}

Polynomial::Polynomial(const int *coefficients, const int *exponents, const int size)
{
    assert(size > 0);
    setPolynomial(coefficients, exponents, size);
}

Polynomial::Polynomial(const Polynomial &polynomial)
{
    setPolynomial(polynomial.cfPtr_, polynomial.exPtr_, polynomial.size_);
}

Polynomial::~Polynomial()
{
    delete [] cfPtr_;
    delete [] exPtr_;
}

void
Polynomial::setPolynomial(const int *cfs, const int *exs, const int size)
{
    size_ = size;
    cfPtr_ = new int [size_];
    exPtr_ = new int [size_];
    for (int i = 0; i < size_; ++i) {
        cfPtr_[i] = cfs[i];
        exPtr_[i] = exs[i];
    }
}

Polynomial &
Polynomial::operator=(const Polynomial &right)
{
    if (this == &right) {
        std::cout << "Selfasiggnment" << std::endl;
        return *this;
    }
    if (size_ != right.size_) {
        delete [] cfPtr_;
        delete [] exPtr_;
        size_ = right.size_;
        cfPtr_ = new int [size_];
        exPtr_ = new int [size_];
    }
    for (int i = 0; i < size_; ++i) {
        cfPtr_[i] = right.cfPtr_[i];
        exPtr_[i] = right.exPtr_[i];
    }
    return *this;
}

Polynomial
Polynomial::operator+(const Polynomial &right) const
{
    int tempCf[size_ + right.size_];
    int tempEx[size_ + right.size_];
    int terms = 0;
    for (int i = 0; i < size_; ++i) {
        tempCf[i] = cfPtr_[i];
        tempEx[i] = exPtr_[i];
        ++terms;
    }
    for (int i = 0; i < right.size_; ++i) {
        for (int j = 0; j < size_; ++j) {
            if (right.exPtr_[i] == tempEx[j]) {
                tempCf[j] += right.cfPtr_[i];
                break;
            }
            if (j + 1 == size_) {
                tempCf[terms] = right.cfPtr_[i];
                tempEx[terms] = right.exPtr_[i];
                ++terms;
            }
        }
    }
    int resultCf[terms];
    int resultEx[terms];
    for (int i = 0; i < terms; ++i) {
        resultCf[i] = tempCf[i];
        resultEx[i] = tempEx[i];
    }
    Polynomial result(resultCf, resultEx, terms);
    return result;
}

Polynomial
Polynomial::operator-(const Polynomial &right) const
{
    int tempCf[size_ + right.size_];
    int tempEx[size_ + right.size_];
    int terms = 0;
    for (int i = 0; i < size_; ++i) {
        tempCf[i] = cfPtr_[i];
        tempEx[i] = exPtr_[i];
        ++terms;
    }
    for (int i = 0; i < right.size_; ++i) {
        for (int j = 0; j < size_; ++j) {
            if (right.exPtr_[i] == tempEx[j]) {
                tempCf[j] -= right.cfPtr_[i];
                break;
            }
            if (j + 1 == size_) {
                tempCf[terms] = -right.cfPtr_[i];
                tempEx[terms] = right.exPtr_[i];
                ++terms;
            }
        }
    }
    int resultCf[terms];
    int resultEx[terms];
    for (int i = 0; i < terms; ++i) {
        resultCf[i] = tempCf[i];
        resultEx[i] = tempEx[i];
    }
    Polynomial result(resultCf, resultEx, terms);
    return result;
}

Polynomial &
Polynomial::operator+=(const Polynomial &right)
{
    int tempCf[size_ + right.size_];
    int tempEx[size_ + right.size_];
    int terms = 0;
    for (int i = 0; i < size_; ++i) {
        tempCf[i] = cfPtr_[i];
        tempEx[i] = exPtr_[i];
        ++terms;
    }
    for (int i = 0; i < right.size_; ++i) {
        for (int j = 0; j < size_; ++j) {
            if (right.exPtr_[i] == tempEx[j]) {
                tempCf[j] += right.cfPtr_[i];
                break;
            }
            if (j + 1 == size_) {
                tempCf[terms] = right.cfPtr_[i];
                tempEx[terms] = right.exPtr_[i];
                ++terms;
            }
        }
    }
    int resultCf[terms];
    int resultEx[terms];
    for (int i = 0; i < terms; ++i) {
        resultCf[i] = tempCf[i];
        resultEx[i] = tempEx[i];
    }
    setPolynomial(resultCf, resultEx, terms);
    return *this;
}

Polynomial &
Polynomial::operator-=(const Polynomial &right)
{
    int tempCf[size_ + right.size_];
    int tempEx[size_ + right.size_];
    int terms = 0;
    for (int i = 0; i < size_; ++i) {
        tempCf[i] = cfPtr_[i];
        tempEx[i] = exPtr_[i];
        ++terms;
    }
    for (int i = 0; i < right.size_; ++i) {
        for (int j = 0; j < size_; ++j) {
            if (right.exPtr_[i] == tempEx[j]) {
                tempCf[j] -= right.cfPtr_[i];
                break;
            }
            if (j + 1 == size_) {
                tempCf[terms] = -right.cfPtr_[i];
                tempEx[terms] = right.exPtr_[i];
                ++terms;
            }
        }
    }
    int resultCf[terms];
    int resultEx[terms];
    for (int i = 0; i < terms; ++i) {
        resultCf[i] = tempCf[i];
        resultEx[i] = tempEx[i];
    }
    setPolynomial(resultCf, resultEx, terms);
    return *this;
}

const int
Polynomial::getSize() const
{
    return size_;
}

const int * const
Polynomial::getCoefficients() const
{
    return cfPtr_;
}

const int * const
Polynomial::getExponents() const
{
    return exPtr_;
}

//friend
std::ostream&
operator<<(std::ostream &output, Polynomial &value)
{
    if (value.cfPtr_[0] < 0) {
        std::cout << "- " << -value.cfPtr_[0] << "x^" << value.exPtr_[0] << ' ';
    } else {
        std::cout << value.cfPtr_[0] << "x^" << value.exPtr_[0] << ' ';
    }
    for (int i = 1; i < value.size_; ++i) {
        if (value.cfPtr_[i] < 0) {
            std::cout << "- " << -value.cfPtr_[i] << "x^" << value.exPtr_[i] << ' ';
        } else {
            std::cout << "+ " << value.cfPtr_[i] << "x^" << value.exPtr_[i] << ' ';
        }
    }
    return output;
}

