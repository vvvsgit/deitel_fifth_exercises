#ifndef SHAPE2D_HPP
#define SHAPE2D_HPP

#include "Shape.hpp"

class Shape2D : public Shape
{
public:
    virtual double getArea() const = 0;
};

#endif

