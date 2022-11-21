#include <iostream>
#include "Rectangle.h"
#include <cstring>

using namespace std;

void Rectangle::initName(char *n)
{
    name = new char[strlen(n) + 1];
    strcpy(name, n);
}
Rectangle::Rectangle(){
    width = 0;
    length = 0;
    name = (char *)"Default";
}
Rectangle::Rectangle(double w, double l, char *n){
    width = w;
    length = l;
    initName(n);
}
Rectangle::~Rectangle(){
    delete [] name;
}
void Rectangle::setWidth(double w){
    width = w;
}
void Rectangle::setLength(double l){
    length = l;
}
void Rectangle::setWidth(char *w){
    width = atof(w);
}
void Rectangle::setLength(char *l){
    length = atof(l);
}
void Rectangle::setName(char *n){
    delete [] name;
    initName(n);
}
double Rectangle::getWidth() const{
    return width;
}
double Rectangle::getLength() const{
    return length;
}
