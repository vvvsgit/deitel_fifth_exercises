#include "Rectangle.hpp"

#include <iostream>
#include <cmath>

Rectangle::Rectangle()
{
    int cornersSet[2][CORNERS] = {{1, 1, 1, 1}, {1, 1, 1, 1}};
    setCorners(cornersSet);
}

Rectangle::Rectangle(int corners[][CORNERS])
{
    if (!isRectangle(corners)) {
        int cornersSet[2][CORNERS] = {{0, 0, 0, 0}, {0, 0, 0, 0}};
        setCorners(cornersSet);
        return;
    }
    for (int i = 0; i < CORNERS; ++i) {
        if (corners[0][i] < 0 || corners[0][i] > 20 || corners[1][i] < 0 || corners[1][i] > 20) {
            int cornersSet[2][CORNERS] = {{2, 2, 2, 2}, {2, 2, 2, 2}};
            setCorners(cornersSet);
            return;
        }
    }
    setCorners(corners);
}

void
Rectangle::setCorners(int corners[][CORNERS])
{
    double ab = distance(corners[0][0], corners[1][0], corners[0][1], corners[1][1]);
    double ac = distance(corners[0][0], corners[1][0], corners[0][2], corners[1][2]);
    double ad = distance(corners[0][0], corners[1][0], corners[0][3], corners[1][3]);
    if (ab > ac && ab > ad) {
        if (ac < ad) {
            xy_[0][0] = corners[0][0];
            xy_[1][0] = corners[1][0];
            xy_[0][1] = corners[0][2];
            xy_[1][1] = corners[1][2];
            xy_[0][2] = corners[0][1];
            xy_[1][2] = corners[1][1];
            xy_[0][3] = corners[0][3];
            xy_[1][3] = corners[1][3];
        } else {
            xy_[0][0] = corners[0][0];
            xy_[1][0] = corners[1][0];
            xy_[0][1] = corners[0][3];
            xy_[1][1] = corners[1][3];
            xy_[0][2] = corners[0][1];
            xy_[1][2] = corners[1][1];
            xy_[0][3] = corners[0][2];
            xy_[1][3] = corners[1][2];
        }
    } else if (ac > ab && ac > ad) {
        if (ad < ab) {
            xy_[0][0] = corners[0][0];
            xy_[1][0] = corners[1][0];
            xy_[0][1] = corners[0][3];
            xy_[1][1] = corners[1][3];
            xy_[0][2] = corners[0][2];
            xy_[1][2] = corners[1][2];
            xy_[0][3] = corners[0][1];
            xy_[1][3] = corners[1][1];
        } else {
            xy_[0][0] = corners[0][0];
            xy_[1][0] = corners[1][0];
            xy_[0][1] = corners[0][1];
            xy_[1][1] = corners[1][1];
            xy_[0][2] = corners[0][2];
            xy_[1][2] = corners[1][2];
            xy_[0][3] = corners[0][3];
            xy_[1][3] = corners[1][3];
        }
    } else  {
        if (ab < ac) {
            xy_[0][0] = corners[0][0];
            xy_[1][0] = corners[1][0];
            xy_[0][1] = corners[0][1];
            xy_[1][1] = corners[1][1];
            xy_[0][2] = corners[0][3];
            xy_[1][2] = corners[1][3];
            xy_[0][3] = corners[0][2];
            xy_[1][3] = corners[1][2];
        } else {
            xy_[0][0] = corners[0][0];
            xy_[1][0] = corners[1][0];
            xy_[0][1] = corners[0][2];
            xy_[1][1] = corners[1][2];
            xy_[0][2] = corners[0][3];
            xy_[1][2] = corners[1][3];
            xy_[0][3] = corners[0][1];
            xy_[1][3] = corners[1][1];
        }
    }
}

bool
Rectangle::isRectangle(int corners[][CORNERS])
{
    return distance(corners[0][0], corners[1][0], corners[0][1], corners[1][1]) == 
           distance(corners[0][2], corners[1][2], corners[0][3], corners[1][3]) && 
           distance(corners[0][0], corners[1][0], corners[0][3], corners[1][3]) == 
           distance(corners[0][2], corners[1][2], corners[0][1], corners[1][1]); 
}

double
Rectangle::distance(int x1, int y1, int x2, int y2)
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

double
Rectangle::width()
{
    return distance(xy_[0][0], xy_[1][0], xy_[0][1], xy_[1][1]);
}

double
Rectangle::length()
{
    return distance(xy_[0][0], xy_[1][0], xy_[0][3], xy_[1][3]);
}

double
Rectangle::perimeter()
{
    return 2 * length() + 2 * width();
}

double
Rectangle::area()
{
    return length() * width();
}

bool
Rectangle::isSquare()
{
    return length() == width();
}

void
Rectangle::printCoordinates()
{
    for (int i = 0; i < CORNERS; ++i) {
        std::cout << 'x' << i << " = " << xy_[0][i] << ", " << 'y' << i << " = " << xy_[1][i] << std::endl;
    }
}

