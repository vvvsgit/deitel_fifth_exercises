#ifndef TETRAHEDON_HPP
#define TETRAHEDON_HPP

#include "Shape3D.hpp"

class Tetrahedron : public Shape3D
{
public:
    Tetrahedron(const double = 1.0, const double = 1.0, const double = 1.0, const double = 1.0, const double = 1.0, const double = 1.0);
    virtual double getArea() const;
    virtual double getVolume() const;
    void setSide1(const double);
    void setSide2(const double);
    void setSide3(const double);
    double getSide1() const;
    double getSide2() const;
    double getSide3() const;
    void setVertex1(const double);
    void setVertex2(const double);
    void setVertex3(const double);
    double getVertex1() const;
    double getVertex2() const;
    double getVertex3() const;
private:
    double side1_;
    double side2_;
    double side3_;
    double vertex1_;
    double vertex2_;
    double vertex3_;
};

#endif

