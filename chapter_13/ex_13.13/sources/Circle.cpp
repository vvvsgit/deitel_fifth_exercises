#include "../headers/Circle.hpp"

Circle::Circle(const double radius)
{
    setRadius(radius);
}

double
Circle::getArea() const
{
    return getRadius() * getRadius() * 3.14;
}

void
Circle::setRadius(const double radius)
{
    radius_ = (radius > 0.0 ? radius : 1.0);
}

double
Circle::getRadius() const
{
    return radius_;
}

