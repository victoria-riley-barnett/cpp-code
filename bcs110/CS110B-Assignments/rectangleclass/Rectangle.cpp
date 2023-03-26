#include <iostream>
#include "Rectangle.h"
#include <cstring>
#include <string>

using namespace std;

void Rectangle::initName(const char *n)
{
    name = new char[strlen(n) + 1];
    strcpy(name, n);
}
Rectangle::Rectangle(){
    width = 0;
    length = 0;
    name = new char[1];
    name[0] = '\0';
}
Rectangle::Rectangle(double w, double l, const char *n){
    width = w;
    length = l;
    name = new char[strlen(n) + 1];
    strcpy(name, n);
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
    name = new char[strlen(n) + 1];
    strcpy(name, n);
}
double Rectangle::getWidth() const{
    return width;
}
double Rectangle::getLength() const{
    return length;
}
