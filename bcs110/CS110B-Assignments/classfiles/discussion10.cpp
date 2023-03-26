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
    delete boxPtr;
    boxPtr = nullptr;
    return 0;
}