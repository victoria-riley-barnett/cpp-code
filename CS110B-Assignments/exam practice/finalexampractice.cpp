1. Fill in the blank.  Assume you have a valid class declared named AddClass, which includes the member function:

 AddClass operator +(AddClass arg);

and you also have the following inside main():

 AddClass obj1, obj2, obj3;
 ...
 obj3 = obj1 + obj2;

1.) The return value for operator + is assigned to ______, the argument (arg) is associated with , and the current object (the calling object) is associated with 
1.) The return value for operator + is assigned to obj3, the argument (arg) is associated with obj2, and the current object (the calling object) is associated with obj2

2.  Consider the following class, which represents a price in dollars and cents:

class Price
{
private:
  int dollars;
  int cents;
public:
  Price() { dollars = cents = 0; }
  Price(int d, int c) { dollars = d; cents = c; }
  Price operator+(Price&);
};

Implement the overloaded + operator to compute the sum of two Price objects, and return the result as a Price object containing the sum.  You may assume that all price objects contain valid data, i.e. dollars>=0 and 0<=cents<=99.  
2.) 
Price Price::operator+(Price& p){
  Price temp;
  temp.dollars = dollars + p.dollars;
  temp.cents = cents + p.cents;
  if(temp.cents > 99){
    temp.dollars++;
    temp.cents -= 100;
  }
  return temp;
}

 

For questions 3 and 4, consider the following two classes, Shape and Circle:

class Shape
{
private:
  double area;
public:
  void setArea(double a)
    { area = a; }
  double getArea()
    { return area; }
};

class Circle : public Shape
{
private:
  double radius;
public:
  void setRadius(double r)
    { radius = r;
      setArea(3.14*r*r); }
  double getRadius()
    { return radius; }
};

3.  Can an object of the Circle class call the setArea() member function of the Shape class?
3.) Yes, because Cirlce is a derived class of Shape, and has access to Shape's public member functions, and setArea is public.

4. What member(s) of the Shape class are not directly accessible to member functions of the Circle class?  Name a way to make them accessible.

4.) The private member variable area is not accessible to member functions of Circle, however, it can be made accessible if it is swapped to a protected member instead.

For questions 5-9, consider the following two classes, Player and BasketballPlayer:

class Player
{
  protected:
   string name;
   double weight;
   double height;
  public:
   Player(string n, double w, double h)
     { name = n; weight = w; height = h; }
   string getName() const
     { return name; }
   virtual void printStats() const = 0;
};

class BasketballPlayer : public Player
{
  private:
   int fieldgoals;
   int attempts;
  public:
   BasketballPlayer(string n, double w,
    double h, int fg, int a) : Player(n, w, h)
     { fieldgoals = fg; attempts = a; }
   void printStats() const
     { cout << name << endl; 
       cout << "Weight: " << weight; 
       cout << " Height: " << height << endl;
       cout << "FG: " << fieldgoals;
       cout << " attempts: " << attempts;
       cout << " Pct: " << (double) fieldgoals / attempts << endl; }
};

5. What does = 0 after function printStats() do?
5.) Setting a virtual function to const = 0 makes printStats a pure virtual function, which means that it must be overridden in the derived class.

6. Would the following line in main() compile: Player p; -- why or why not?
6.) No, as Player is an abstract class and should be used as a base class only.

7. Could I remove the printStats() member function from BasketballPlayer?  Why or why not?
7.) No, as printStats is a pure virtual function in Player, and must be overridden in the derived class.

8. Would the following line in main() compile: Player *ptr; -- why or why not?
8.) Yes, this compliles as pointers and references to abstract classes are allowed.

9. Write code which creates a Player pointer (e.g. Player *p), creates an object of class BasketballPlayer, and assigns the address of the object to the pointer.  Why does this work?

9a.) 
Player *p;
BasketballPlayer b("Bob", 200, 6.5, 100, 200);
p = &b;
ptr -> printStats();
return 0;

9b.) This works because the pointer is of type Player, which is the base class of BasketballPlayer, and the pointer can point to any object of a derived class of Player, which is does once we instansiate the BasketballPlayer object and assign it to the pointer.

10. True/False: if you use new, you later should use delete.  Why or why not?
10.) True, as new allocates memory on the heap, and delete frees that memory. Allocating memory on the heap without later freeing it will cause a memory leak.

11. Consider the following code statements.  Write a statement which will assign the address of i to iPtr.

int i = 3;
int *iPtr = NULL;

11.) iPtr = &i;

For questions 12 and 13, consider the following code:

int i[4] = {3, 10, 6, 1};
int *iPtr = i;

12.  What would cout << *iPtr print out?
12.) 3

13.  True/False: *(iPtr+1) is equivalent to iPtr[1]
13.) True, dereferencing iPtr points to array[0], and adding 1 is the same as accessing the second element of the array.

For questions 14 and 15, consider the following class, MuniVehicle: 

class MuniVehicle
{
private:
  int totalFares;
public:
  MuniVehicle()
    { totalFares = 0; }
  int getTotalFares()
    { return totalFares; }
  virtual void paidFare()
    { totalFares += 2; }
};

14.  Derive a class CableCar from MuniVehicle.  It should override paidFare() so that each 
fare increases totalFares by 8 instead of 2.  
You will need to make a change to class MuniVehicle.  What is it?
14a.) 
class CableCar : public MuniVehicle{
public:
  void paidFare(){
    totalFares += 8;
  }
}
14b.) The requisite change is to make totalfares a protected member variable instead of private, as it is now accessible to the derived class, as we have overloaded the virtual function paidFare within the derived class.

15.  Create a main(), which demonstrates creating a CableCar object, 
call paidFare two times, and printing out the resulting totalFares for this CableCar object.

15.) 
int main(){
  CableCar c;
  c.paidFare();
  c.paidFare();
  cout << c.getTotalFares() << endl;
  return 0;
}

16.  Assume that there is a valid file named "cards.txt" in the current directory which contains ten valid ints.  
There is one int on every line.  Write a code snippet which reads in the first 3 ints and prints them to the screen.
16.) 
#include <fstream>
int main(){
  ifstream in;
  in.open("cards.txt");
  int i;
  for(int j = 0; j < 3; j++){
    in >> i;
    cout << i << endl;
  }
  return 0;
}

17.  What will the following code print out?

    char name[100] = "CS110B";
    name[2] = '\0';
    cout << name << endl;
17.) CS
18. True/False.  Once a STL vector is full, it is impossible to add more elements to it.
18.) False, unlike arrays, STL vectors are dynamic, and can be resized to accomodate more elements.