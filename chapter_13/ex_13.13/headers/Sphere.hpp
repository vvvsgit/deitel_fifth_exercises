#ifndef SPHERE_HPP
#define SPHERE_HPP

#include "Shape3D.hpp"

class Sphere : public Shape3D
{
public:
    Sphere(const double = 1.0);
    virtual double getArea() const;
    virtual double getVolume() const;
    void setRadius(const double);
    double getRadius() const;
private:
    double radius_;
};

#endif

