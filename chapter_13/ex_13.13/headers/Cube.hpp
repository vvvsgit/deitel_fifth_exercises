#ifndef CUBE_HPP
#define CUBE_HPP

#include "Shape3D.hpp"

class Cube : public Shape3D
{
public:
    Cube(const double = 1.0);
    virtual double getArea() const;
    virtual double getVolume() const;
    void setSide(const double);
    double getSide() const;
private:
    double side_;
};

#endif

