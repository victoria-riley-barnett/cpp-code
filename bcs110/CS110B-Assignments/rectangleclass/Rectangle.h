#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle
{
  private:
    double width;
    double length;
    char *name;
    void initName(const char *);
  public:
    //constructors
    Rectangle();
    Rectangle(double w, double l, const char *n);
    //destructor
    ~Rectangle();
    //setters
    void setWidth(double);
    void setLength(double);
    void setWidth(char *);
    void setLength(char *);
    void setName(char *);
    //getters
    double getWidth() const;
    double getLength() const;
    void printName() const
    { std::cout << name; }
    int getArea() const
    { return width * length; }
    Rectangle& operator=(const Rectangle &right){
        if (this != &right){
            delete [] name;
            width = right.width;
            length = right.length;
            initName(right.name);
        }
        return *this;
    }
    bool operator>(const Rectangle &right) const{
        return getArea() > right.getArea();
    }
    bool operator<(const Rectangle &right) const{
        return getArea() < right.getArea();
    }
};
#endif