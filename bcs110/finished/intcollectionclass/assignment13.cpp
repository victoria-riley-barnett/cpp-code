//Assignment 13
//Riley Barnett
#include "IntCollection.h"
#include <iostream>
using namespace std;

int main()
{
    IntCollection c;
    c.add(45);
    c.add(12);
    c.add(3);
    
    // test copy constructor
    IntCollection c2(c);
    cout << "C2 should have same values as C (45, 12, 3)" << endl;
    for (int i = 0; i < c2.getSize(); i++){
        cout << c2.get(i) << endl;
    }

    //test assignment operator
    IntCollection c3;
    IntCollection c4;
    c4 = c3 = c;
    cout << "C3 should have same values as C (45, 12, 3)" << endl;
    
    for (int i = 0; i < c3.getSize(); i++){
        cout << c3.get(i) << endl;
    }
    cout << "C4 should have same values as C (45, 12, 3)" << endl;
    for (int i = 0; i < c4.getSize(); i++){
        cout << c4.get(i) << endl;
    }

    //test equality operator
    IntCollection c5;
    IntCollection c6;
    c5.add(1);
    c5.add(2);
    c5.add(3);
    c6.add(1);
    c6.add(2);
    c6.add(3);
    cout << "C5 and C6 should be equal: " << endl;
    if (c5 == c6){
        cout << "C5 and C6 are equal" << endl << endl;
    }
    else{
        cout << "C5 and C6 are not equal" << endl;
    }

    //test insertion operator
    IntCollection c7(c);
    c7 << 1 << 2 << 3;
    cout << "C7 should have same values as C (45, 12, 3) and 1, 2, 3" << endl;
    for (int i = 0; i < c7.getSize(); i++){
        cout << c7.get(i) << endl;
    }
    
    //test insertion operator with chaining
    IntCollection c8;
    c8 << 1 << 2 << 3 << 4 << 5 << 6 << 7 << 8 << 9 << 10 << 11;
    cout << "C8 should have 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11" << endl;
    for (int i = 0; i < c8.getSize(); i++){
        cout << c8.get(i) << endl;
    }

    //test destructor
    cout << "Testing destructor: " << endl;
    IntCollection *c9 = new IntCollection();
    delete c9;
    c9 = NULL;
    if (c9 == NULL){
        cout << "C9 is NULL" << endl << endl;
    }
    else{
        cout << "C9 is not NULL" << endl;
    }

    //test addCapacity
    IntCollection c10(c);
    cout << "C10 should have same values as C (45, 12, 3)" << endl;
    cout << "C10 has capacity of " << c10.getCapacity() << endl;
    cout << "Adding 100 more values to C10" << endl;
    for (int i = 0; i < 100; i++){
        c10.add(i);
    }
    cout << "C10 now has capacity of " << c10.getCapacity() << endl;

    //Question 6:
    //Calling the function addCapacity() from main() will not work because it is a private member function. 
    //Rather, we use the add() function to add elements to the collection. 
    //The add() function will call the addCapacity() function if the collection is full.
    
}