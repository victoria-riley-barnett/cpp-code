#include <iostream>
#include "Rectangle.h"

using namespace std;

int main(){
    //Demonstrate your class works with a main() function that instantiates an array of three Rectangle objects, one for each room of a house, using the initializer list below.  
    Rectangle house[] = { Rectangle(10, 12, (char *)"Living Room"), Rectangle(20, 20, (char *)"Bedroom"), Rectangle(8, 12, (char *)"Offce") };
    //Then, use your setName() function to fix the name of “Offce” to “Office”. 
    house[2].setName((char *)"Office");
    //Finally, tell the user the name and area of each room, and the name of the room with the largest area.
    int largest = 0;
    for (int i = 0; i < 3; i++){
        cout << "Room " << i + 1 << " is the ";
        house[i].printName();
        cout << " and has an area of " << house[i].getArea() << endl;
        if (house[i].getArea() > house[largest].getArea())
            largest = i;
    }
    cout << "The largest room is: ";
    house[largest].printName();
    cout << " with an area of " << house[largest].getArea() << endl;
    return 0;
}