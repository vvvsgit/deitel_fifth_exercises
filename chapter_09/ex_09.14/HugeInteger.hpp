#ifndef HUGEINTEGER_HPP
#define HUGEINTEGER_HPP

const int SIZE = 40;

class HugeInteger
{
public:
    HugeInteger();
    void setHugeInteger();
    
    void input();
    void output();
    
    void add(HugeInteger);
    void substract(HugeInteger);
    
    bool isEqualTo(HugeInteger);
    bool isNotEqualTo(HugeInteger);
    bool isGreaterThan(HugeInteger);
    bool isLessThan(HugeInteger);
    bool isGreaterThanOrEqualTo(HugeInteger);
    bool isLessThanOrEqualTo(HugeInteger);
    bool isZero();
private:
    char hugeInteger_[SIZE + 1];
};

#endif

