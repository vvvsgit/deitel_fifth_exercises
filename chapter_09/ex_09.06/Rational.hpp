#ifndef RATIONAL_HPP
#define RATIONAL_HPP

class Rational
{
public:
    Rational(int = 1, int = 1);

    void setRational(int, int);
    void setNumerator(int);
    void setDenominator(int);
    int getNumerator();
    int getDenominator();

    void add(Rational);
    void subtract(Rational);
    void multiply(Rational);
    void divide(Rational);
    void printFraction();
    void printFloating();
private:
    int numerator_;
    int denominator_;
};

#endif

