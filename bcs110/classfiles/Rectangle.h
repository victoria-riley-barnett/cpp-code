#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle
{
private:
    double length;
    double width;
public:
    void setLength(double);
    void setWidth(double);
    double getLength() const
    { return length; }
    double getWidth() const
    { return width; }
    double getArea() const
    { return length * width; }
    double getPerimeter() const;
    bool isSquare() const;
};

#endif