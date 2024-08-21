#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "Shape2D.hpp"

class Circle : public Shape2D
{
public:
    Circle(const double = 1.0);
    virtual double getArea() const;
    void setRadius(const double);
    double getRadius() const;
private:
    double radius_;
};

#endif

