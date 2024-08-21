#include <cmath>

#include "../headers/Triangle.hpp"

Triangle::Triangle(const double side1, const double side2, const double side3)
{
    setSide1(side1);
    setSide2(side2);
    setSide3(side3);
}

double
Triangle::getArea() const
{
    const double semiParameter = (getSide1() + getSide2() + getSide3()) / 2;
    return sqrt(semiParameter * (semiParameter - getSide1()) 
                              * (semiParameter - getSide2()) 
                              * (semiParameter - getSide3()));
}

void
Triangle::setSide1(const double side)
{
    side1_ = (side > 0.0 ? side : 1.0);
}

void
Triangle::setSide2(const double side)
{
    side2_ = (side > 0.0 ? side : 1.0);
}

void
Triangle::setSide3(const double side)
{
    side3_ = (side > 0.0 ? side : 1.0);
}

double
Triangle::getSide1() const
{
    return side1_;
}

double
Triangle::getSide2() const
{
    return side2_;
}

double
Triangle::getSide3() const
{
    return side3_;
}

