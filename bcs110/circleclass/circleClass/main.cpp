#include "Circle.h"
#include <iostream>

using namespace std;

int main(){
    // Create a circle object
    Circle cir1;

    //Set vars
    double x, y, radius;
    cout << "Enter the x value: ";
    cin >> x;
    cir1.setX(x);
    cout << "Enter the y value: ";
    cin >> y;
    cir1.setY(y);
    cout << "Enter the radius: ";
    cin >> radius;
    cir1.setRadius(radius);

    //Print vars
    cout << "X: " << cir1.getX() << endl;
    cout << "Y: " << cir1.getY() << endl;
    cout << "Radius: " << cir1.getRadius() << endl;
    cout << "Area: " << cir1.getArea() << endl;

    //Define pointer to circle object
    Circle *cir2 = nullptr;
    cir2 = &cir1;

    //Set vars with pointer
    double x2, y2, radius2;
    cout << "Enter new x for ptr: ";
    cin >> x2;
    cir2->setX(x2);
    cout << "Enter new y for ptr: ";
    cin >> y2;
    cir2->setY(y2);
    cout << "Enter new radius for ptr: ";
    cin >> radius2;
    cir2->setRadius(radius2);

    //Print vars with pointer
    cout << "X: " << cir2->getX() << endl;
    cout << "Y: " << cir2->getY() << endl;
    cout << "Radius: " << cir2->getRadius() << endl;
    cout << "Area: " << cir2->getArea() << endl;

    //Check if point is in circle with pointer
    cout << "Checking point 5, 5" << endl;
    if (cir2->containsPoint(5, 5))
        cout << "Point is in circle" << endl;
    else
        cout << "Point is not in circle" << endl;
    
    cout << "Checking point 10, 10" << endl;
    if (cir2->containsPoint(10, 10))
        cout << "Point is in circle" << endl;
    else
        cout << "Point is not in circle" << endl;

    return 0;
}
