#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "Shape2D.hpp"

class Triangle : public Shape2D
{
public:
    Triangle(const double = 1.0, const double = 1.0, const double = 1.0);
    virtual double getArea() const;
    void setSide1(const double);
    void setSide2(const double);
    void setSide3(const double);
    double getSide1() const;
    double getSide2() const;
    double getSide3() const;
private:
    double side1_;
    double side2_;
    double side3_;
};

#endif

