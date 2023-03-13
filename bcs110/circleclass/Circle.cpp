#include "Circle.h"
#include <math.h>

using namespace std;

double Circle::getArea(){
    return M_PI * radius * radius;
}
bool Circle::containsPoint(double xValue, double yValue){
    double distance = sqrt(pow(xValue - x, 2) + pow(yValue - y, 2));
    return distance <= radius;
}