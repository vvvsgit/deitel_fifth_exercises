#include <cmath>

#include "../headers/Tetrahedron.hpp"

Tetrahedron::Tetrahedron(const double side1, const double side2, const double side3,
            const double vertex1, const double vertex2, const double vertex3)
{
    setSide1(side1);
    setSide2(side2);
    setSide3(side3);
    setVertex1(vertex1);
    setVertex2(vertex2);
    setVertex3(vertex3);
}

double
Tetrahedron::getArea() const
{
    const double semiParameter = (getSide1() + getSide2() + getSide3()) / 2;
    return sqrt(semiParameter * (semiParameter - getSide1()) 
                              * (semiParameter - getSide2()) 
                              * (semiParameter - getSide3()));
}

double
Tetrahedron::getVolume() const
{
    const double sqr1 = getSide1() * getSide1();
    const double sqr2 = getSide2() * getSide2();
    const double sqr3 = getSide3() * getSide3();

    const double x = sqr2 * sqr3 - getVertex1() * getVertex1();
    const double y = sqr1 * sqr3 - getVertex2() * getVertex2();
    const double z = sqr1 * sqr2 - getVertex3() * getVertex3();

    return sqrt(4 * sqr1 * sqr2 * sqr3 - sqr1 * x * x - sqr2 * y * y - sqr3 * z * z + x * y * z) / 12.0;
}

void
Tetrahedron::setSide1(const double side)
{
    side1_ = (side > 0.0 ? side : 1.0);
}

void
Tetrahedron::setSide2(const double side)
{
    side2_ = (side > 0.0 ? side : 1.0);
}

void
Tetrahedron::setSide3(const double side)
{
    side3_ = (side > 0.0 ? side : 1.0);
}

double
Tetrahedron::getSide1() const
{
    return side1_;
}

double
Tetrahedron::getSide2() const
{
    return side2_;
}

double
Tetrahedron::getSide3() const
{
    return side3_;
}

void
Tetrahedron::setVertex1(const double vertex)
{
    vertex1_ = (vertex > 0.0 ? vertex : 1.0);
}

void
Tetrahedron::setVertex2(const double vertex)
{
    vertex2_ = (vertex > 0.0 ? vertex : 1.0);
}

void
Tetrahedron::setVertex3(const double vertex)
{
    vertex3_ = (vertex > 0.0 ? vertex : 1.0);
}

double
Tetrahedron::getVertex1() const
{
    return vertex1_;
}

double
Tetrahedron::getVertex2() const
{
    return vertex2_;
}

double
Tetrahedron::getVertex3() const
{
    return vertex3_;
}

