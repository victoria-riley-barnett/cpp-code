#ifndef CIRCLE_H
#define CIRCLE_H

class Circle
{
private:
    double x;
    double y;
    double radius;
public:
    void setX(double value)
    { x = value; }
    void setY(double value)
    { y = value; }
    void setRadius(double r)
    { radius = r; }
    double getX()
    { return x; }
    double getY()
    { return y; }
    double getRadius()
    { return radius; }
    double getArea();
    bool containsPoint(double xValue, double yValue);
};

#endif