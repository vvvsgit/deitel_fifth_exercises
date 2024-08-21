#ifndef SQUARE_HPP
#define SQUARE_HPP

#include "Shape2D.hpp"

class Square : public Shape2D
{
public:
    Square(const double = 1.0);
    virtual double getArea() const;
    void setSide(const double);
    double getSide() const;
private:
    double side_;
};

#endif

