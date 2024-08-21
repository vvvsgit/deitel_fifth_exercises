#ifndef RATIONALNUMBER_HPP
#define RATIONALNUMBER_HPP

class RationalNumber
{
public:
    RationalNumber(int = 1, int = 1);

    void setRational(int, int);
    void setNumerator(int);
    void setDenominator(int);
    int getNumerator() const;
    int getDenominator() const;

    RationalNumber operator+(const RationalNumber &);
    RationalNumber operator-(const RationalNumber &);
    RationalNumber operator*(const RationalNumber &);
    RationalNumber operator/(const RationalNumber &);

    const bool operator==(const RationalNumber &) const;
    const bool operator!=(const RationalNumber &) const;
    const bool operator>(const RationalNumber &) const;
    const bool operator<(const RationalNumber &) const;
    const bool operator>=(const RationalNumber &) const;
    const bool operator<=(const RationalNumber &) const;

    void printFraction();
    void printFloating();
private:
    int numerator_;
    int denominator_;
};

#endif

