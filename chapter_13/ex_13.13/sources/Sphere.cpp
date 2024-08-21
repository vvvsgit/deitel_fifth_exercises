#include "../headers/Sphere.hpp"

Sphere::Sphere(const double radius)
{
    setRadius(radius);
}

double 
Sphere::getVolume() const
{
    return getArea() * getRadius() * 4.0/3.0;
}

double
Sphere::getArea() const
{
    return getRadius() * getRadius() * 3.14;
}

void
Sphere::setRadius(const double radius)
{
    radius_ = (radius > 0.0 ? radius : 1.0);
}

double
Sphere::getRadius() const
{
    return radius_;
}

