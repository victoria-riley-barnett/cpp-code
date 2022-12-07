#include <iostream>
#include "Rectangle.h"

using namespace std;

int main(){
    Rectangle r1(10, 20, "r1");
    Rectangle r2(30, 40, "r2");
    Rectangle r3;
    Rectangle r4;
    r3 = r1;
    r3.printName(); //r3 is a copy of r1
    cout << " has an area of " << r3.getArea() << endl;
    //Demonstrate correct return type to chain assignment in one line
    r4 = r3 = r2;
    r4.printName(); //r4 is now r2
    cout << " has an area of " << r4.getArea() << endl << endl;

    //Overloaded comparison operators
    cout << "greater than overloaded operator: " << endl;
    if (r1 > r2)
        cout << "r1 is bigger than r2" << endl;
    else
        cout << "r1 is not bigger than r2" << endl;
    cout << "less than overloaded operator: " << endl;
    if (r1 < r2)
        cout << "r1 is smaller than r2" << endl;
    else
        cout << "r1 is not smaller than r2" << endl;


    return 0;
}