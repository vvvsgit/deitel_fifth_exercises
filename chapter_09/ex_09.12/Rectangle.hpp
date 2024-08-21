#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

const int CORNERS = 4;

class Rectangle
{
public:
    Rectangle();
    Rectangle(int [][CORNERS]);

    void setCorners(int [][CORNERS]);

    bool isRectangle(int [][CORNERS]);
    double distance(int, int, int, int);
    double width();
    double length();
    double perimeter();
    double area();
    bool isSquare();
    void printCoordinates();
private:
    int xy_[2][CORNERS];
};

#endif

