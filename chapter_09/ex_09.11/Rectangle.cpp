#include "Rectangle.hpp"

#include <iostream>

Rectangle::Rectangle(double length, double width)
{
    setLength(length);
    setWidth(width);
}

void
Rectangle::setLength(double length)
{
    length_ = length > 0.0 && length < 20.0 ? length : 1.0;
}

void
Rectangle::setWidth(double width)
{
    width_ = width > 0.0 && width < 20.0 ? width : 1.0;
}

double
Rectangle::getLength()
{
    return length_;
}

double
Rectangle::getWidth()
{
    return width_;
}

double
Rectangle::perimeter()
{
    return 2 * getLength() + 2 * getWidth();
}

double
Rectangle::area()
{
    return getLength() * getWidth();
}

