#include "../headers/Square.hpp"

Square::Square(const double side)
{
    setSide(side);
}

double
Square::getArea() const
{
    return getSide() * getSide();
}

void
Square::setSide(const double side)
{
    side_ = (side > 0.0 ? side : 1.0);
}

double
Square::getSide() const
{
    return side_;
}

