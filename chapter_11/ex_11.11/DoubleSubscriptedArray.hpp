#ifndef DOUBLESUBSCRIPTEDARRAY_HPP
#define DOUBLESUBSCRIPTEDARRAY_HPP

#include <iostream>

class DoubleSubscriptedArray
{
    friend std::ostream & operator<<(std::ostream &, const DoubleSubscriptedArray &);
    friend std::istream & operator>>(std::istream &, DoubleSubscriptedArray &);

public:
    DoubleSubscriptedArray(int = 2, int = 2);
    DoubleSubscriptedArray(const DoubleSubscriptedArray &);
    ~DoubleSubscriptedArray();

    int getRow();
    int getColumn();
    const int getLength() const;
    
    const DoubleSubscriptedArray & operator=(const DoubleSubscriptedArray &);
    const bool operator==(const DoubleSubscriptedArray &) const;
    const bool operator!=(const DoubleSubscriptedArray &) const;
    const int operator()(const int, const int) const;
    int & operator()(const int, const int);

private:
    int row_;
    int column_;
    int *intPtr_;
};

#endif

