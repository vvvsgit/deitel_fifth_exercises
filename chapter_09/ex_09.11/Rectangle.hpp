#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP


class Rectangle
{
public:
    Rectangle(double = 0.0, double = 0.0);

    void setLength(double);
    void setWidth(double);
    double getLength();
    double getWidth();

    double perimeter();
    double area();
private:
    double length_;
    double width_;
};

#endif

