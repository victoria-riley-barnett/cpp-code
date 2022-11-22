#include <IntCollection.h>
#include <iostream>
using namespace std;

int main()
{
    IntCollection c;
    c.add(45);
    c.add(-210);
    c.add(77);
    c.add(2);
    c.add(-21);
    c.add(42);
    c.add(7);
    for (int i = 0; i < c.getSize(); i++)
    {
        cout << c.get(i) << endl;
    }
    
    // test copy constructor
    IntCollection c2(c);
    for (int i = 0; i < c2.getSize(); i++)
    {
        cout << c2.get(i) << endl;
    }

    //test assignment operator
    IntCollection c3;
    IntCollection c4;
    c4 = c3 = c;
    for (int i = 0; i < c3.getSize(); i++)
    {
        cout << c3.get(i) << endl;
    }
    for (int i = 0; i < c4.getSize(); i++)
    {
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
    if (c5 == c6)
    {
        cout << "c5 and c6 are equal" << endl;
    }
    else
    {
        cout << "c5 and c6 are not equal" << endl;
    }

    //test insertion operator
    IntCollection c7;
    c7 << 1 << 2 << 3;
    for (int i = 0; i < c7.getSize(); i++)
    {
        cout << c7.get(i) << endl;
    }
    
    //test insertion operator with chaining
    IntCollection c8;
    c8 << 1 << 2 << 3 << 4 << 5 << 6 << 7 << 8 << 9 << 10 << 11;
    for (int i = 0; i < c8.getSize(); i++)
    {
        cout << c8.get(i) << endl;
    }

    //test destructor
    IntCollection *c9 = new IntCollection;
    c9->add(1);
    c9->add(2);
    c9->add(3);
    delete c9;
    c9 = NULL;

    //test addCapacity
    IntCollection c10;
    for (int i = 0; i < 100; i++)
    {
        c10.add(i);
    }
    for (int i = 0; i < c10.getSize(); i++)
    {
        cout << c10.get(i) << endl;
    }
}