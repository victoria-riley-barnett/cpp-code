/*
[rbarne34@hills classfiles]$ ls
a.out  discussion10.cpp  Rectangle.cpp  Rectangle.h
[rbarne34@hills classfiles]$ cat Rectangle.cpp
*/
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
[rbarne34@hills classfiles]$ cat Rectangle.h
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
[rbarne34@hills classfiles]$ cat discussion10.cpp
#include <iostream>
#include "Rectangle.h"

using namespace std;

int main(){
    Rectangle box;
    Rectangle *boxPtr = nullptr;
    boxPtr = &box;
    double boxLength;
    double boxWidth;

    cout << "This program will calculate the area, perimeter, and square status of a rectangle.\n";
    cout << "What is the length of the rectangle? ";
    cin >> boxLength;
    cout << "What is the width of the rectangle? ";
    cin >> boxWidth;

    boxPtr->setLength(boxLength);
    boxPtr->setWidth(boxWidth);

    cout << "The area of the rectangle is " << boxPtr->getArea() << endl;
    cout << "The perimeter of the rectangle is " << boxPtr->getPerimeter() << endl;
    if (boxPtr->isSquare())
        cout << "The rectangle is a square.\n";
    else
        cout << "The rectangle is not a square.\n";

    return 0;
}

[rbarne34@hills classfiles]$
[rbarne34@hills classfiles]$ g++ discussion10.cpp Rectangle.cpp
[rbarne34@hills classfiles]$ ./a.out
This program will calculate the area, perimeter, and square status of a rectangle.
What is the length of the rectangle? 12
What is the width of the rectangle? 12
The area of the rectangle is 144
The perimeter of the rectangle is 48
The rectangle is a square.
[rbarne34@hills classfiles]$ ./a.out
This program will calculate the area, perimeter, and square status of a rectangle.
What is the length of the rectangle? 14
What is the width of the rectangle? 9
The area of the rectangle is 126
The perimeter of the rectangle is 46
The rectangle is not a square.