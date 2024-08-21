#ifndef COMPLEX_HPP
#define COMPLEX_HPP

class Complex
{
public:
    Complex(double = 0.0, double = 0.0);
    
    void setComplex(double, double);
    void setReal(double);
    void setImagine(double);
    double getReal();
    double getImagine();

    void add(Complex);
    void subtract(Complex);
    void print();
private:
    double realPart_;
    double imaginePart_;
};

#endif

