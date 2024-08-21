#ifndef SHAPE3D_HPP
#define SHAPE3D_HPP

#include "Shape.hpp"

class Shape3D : public Shape
{
public:
    virtual double getArea() const = 0;
    virtual double getVolume() const = 0;
};

#endif

