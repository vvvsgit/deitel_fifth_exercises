#include "../headers/Cube.hpp"

Cube::Cube(const double side)
{
    setSide(side);
}

double
Cube::getArea() const
{
    return getSide() * getSide();
}

double
Cube::getVolume() const
{
    return getArea() * getSide();
}

void
Cube::setSide(const double side)
{
    side_ = (side > 0.0 ? side : 1.0);
}

double
Cube::getSide() const
{
    return side_;
}

