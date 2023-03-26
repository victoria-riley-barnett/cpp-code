/* TERMINAL
[rbarne34@hills CS110B]$ cat assignment0.cpp
*/
// Assignment 0: Riley Barnett
// This program prints out asterisks according to input

#include <iostream>
using namespace std;

int main () {
    int userIn;
    char repeatVal = 'y';
    while (repeatVal != 'n')
    {
        cout << "How many Asterisks?: ";
        cin >> userIn;
        for (int i = 0; i < userIn; i++)
        {
            cout << "*";
        }
        cout << endl;
        cout << "Go again? y/n: ";
        cin >> repeatVal;
    }
    return 0;
}
/* OUTPUT
[rbarne34@hills CS110B]$ ./a.out 
How many Asterisks?: 2
**
Go again? y/n: y
How many Asterisks?: 15
***************
Go again? y/n: y
How many Asterisks?: 7
*******
Go again? y/n: n
*/