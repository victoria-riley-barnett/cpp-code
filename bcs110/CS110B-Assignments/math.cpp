#include <iostream>
#include <cmath>

using namespace std;
//prototyping

int main(int argc, char * argv[]){
    long arg = strtol(argv[1], NULL, 10);
    long argDeg = arg * (180/M_PI);
    int size = strlen(reinterpret_cast<const char*>(argv[1]));

    cout << "Radian values\n____________________________" << endl;
    cout << "Cosine of " << arg << " is " << cos(arg) << endl;
    cout << "Sine of " << arg << " is " << sin(arg) << endl;
    cout << "Tangent of " << arg << " is " << tan(arg) << endl;
    cout << "Secant of " << arg << " is " << acos(arg) << endl;
    cout << "Cosecant of " << arg << " is " << asin(arg) << endl;
    cout << "Cotangent of " << arg << " is " << atan(arg) << endl << endl;
 
    cout << "Degree values\n____________________________" << endl;
    cout << "Cosine of " << argDeg << " is " << cos(argDeg) << endl;
    cout << "Sine of " << argDeg << " is " << sin(argDeg) << endl;
    cout << "Tangent of " << argDeg << " is " << tan(argDeg) << endl;
    cout << "Secant of " << argDeg << " is " << acos(argDeg) << endl;
    cout << "Cosecant of " << argDeg << " is " << asin(argDeg) << endl;
    cout << "Cotangent of " << argDeg << " is " << atan(argDeg) << endl;
}
