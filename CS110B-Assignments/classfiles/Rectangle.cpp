#include <iostream>
#include "Rectangle.h"

using namespace std;

void Rectangle::setLength(double l)
{
    length = l;
}
void Rectangle::setWidth(double w)
{
    width = w;
}
double Rectangle::getPerimeter() const
{
    return 2 * (length + width);
}
bool Rectangle::isSquare() const
{
    return length == width;
}