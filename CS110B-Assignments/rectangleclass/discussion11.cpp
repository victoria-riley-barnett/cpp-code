#include <iostream>
#include "Rectangle.h"

using namespace std;

int main(){
    Rectangle r1(10, 20, "r1");
    Rectangle r2(30, 40, "r2");
    Rectangle r3;
    Rectangle r4;
    r3 = r1;
    r3.printName();
    cout << " has an area of " << r3.getArea() << endl;
    //Demonstrate correct return type to chain assignment in one line
    r3 = r1 = r2;
    r3.printName();
    cout << " has an area of " << r3.getArea() << endl;
    return 0;


    r3 = r1 > r2;
    cout << "The rectangle with the greater area is " << endl;
    r3.printName();

    r4 = r1 < r2;
    cout << "The rectangle with the lesser area is " << endl;
    r4.printName();
}