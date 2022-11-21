#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle
{
  private:
    double width;
    double length;
    char *name;
    void initName(char *n);
  public:
    //constructors
    Rectangle();
    Rectangle(double, double, char*);
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
    Rectangle& Rectangle::operator=(const Rectangle& right){
        if (this != &right){
            delete [] name;
            width = right.width;
            length = right.length;
            initName(right.name);
        }
        return *this;
    }
    Rectangle Rectangle::operator>(const Rectangle& right){
        if (this != &right){
            if (getArea() > right.getArea())
                return *this;
            else
                return right;
        }
    }
    Rectangle Rectangle::operator<(const Rectangle& right){
        if (this != &right){
            if (getArea() < right.getArea())
                return *this;
            else
                return right;
        }
    }
};
#endif