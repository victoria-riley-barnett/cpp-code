#include <iostream>
#include <string>
using namespace std;

class Time
{
private:
  int hour;
  int min;
  int sec;
public:
  Time() { hour = min = sec = 0; }
  Time(int h, int m, int s) { hour = h; min = m; sec = s; }
  bool operator==(Time&);
  Time operator++();
  void displayTime();
};
/*
1. Implement the two overloaded operators for the class Time above:

    the is equal operator == should return true if the Time objects are equivalent and false if not. 
    the prefix increment operator ++ should increment the Time object by one second.  Note that this is quite simple for most times, but you do have to account for the cases where sec and/or min are 59.  If the time is 23:59:59, it should increment to 0:0:0.  At the end of the function, return *this.

2. Implement displayTime() for the class Time above.  It should output the object's time in format hour:minute:second.  You don't need to make the formatting pretty.

3. Write a simple main() function which demonstrates that your class works properly by doing the following:

    Create two valid Time objects. They should be the same time.  The names of the objects and the time to use are up to you. 
    Call displayTime() for each of the objects to output their time.
    Demonstrate that the == operator works by comparing the two time objects and printing out what it returns (it should be 1 for true).
    Demonstrate that the ++ operator works by calling it on one of the Time objects.  Note you have implemented the prefix increment, so if your Time object is t, you can do ++t but not t++.
    Once again, call displayTime() for each of the objects to output their time.
    Once again, demonstrate that the == operator works by comparing the two times and printing out what it returns (it should be 0 for false now).

*/
//1.)
bool Time::operator==(Time& t){
  if(hour == t.hour && min == t.min && sec == t.sec){
    return true;
  }
  return false;
}
Time Time::operator++(){
    sec++;
    if(sec == 60){
      sec = 0;
      min++;
    }
    if(min == 60){
      min = 0;
      hour++;
    }
    if(hour == 24){
      hour = 0;
    }
    return *this;
}
//2.)
void Time::displayTime(){
  cout << hour << ":" << min << ":" << sec << endl;
}
//3.)
int main(){
  Time t1(12, 30, 45);
  Time t2(12, 30, 45);
  cout << "t1 time: " << endl;
  t1.displayTime();
  cout << "t2 time: " << endl;
  t2.displayTime();
  cout << "t1 == t2? ";
  cout << t1.operator==(t2) << endl;
  ++t1;
  cout << "Called ++t1" << endl;
  cout << "t1 time: " << endl;
  t1.displayTime();
  cout << "t2 time: " << endl;
  t2.displayTime();
  cout << "t1 == t2? ";
  cout << t1.operator==(t2) << endl;
  return 0;
}