// [rbarne34@hills CS110B]$ cat assignment1.cpp 
// Assignment1: Riley Barnett
// This program classifies a user based on their age input

#include <iostream>
using namespace std;

int main() {
    int usrage;
    
    cout << "How old are you?: ";
    cin >> usrage;

    if (usrage <= 12){
        if (usrage >= 0) {
        cout << "You are a Child" << endl;
	}
    }
    if (usrage >= 13) {
        if (usrage < 18) {
        cout << "You are a teenager" << endl;
        }
    }
    if (usrage >= 18) {
        if (usrage < 65) {
        cout << "You are an adult" << endl;
        }
    }
    if (usrage >= 65) {
        cout << "You are a retiree" << endl;
    }
    if (usrage < 0) {
        cout << "Error - Please enter a positive number for your age." << endl;
    }

    return 0;
}

/* OUTPUT
[rbarne34@hills CS110B]$ ./a.out
How old are you?: 12
You are a Child
[rbarne34@hills CS110B]$ ./a.out
How old are you?: 13
You are a teenager
[rbarne34@hills CS110B]$ ./a.out
How old are you?: 18
You are an adult
[rbarne34@hills CS110B]$ ./a.out
How old are you?: 64  
You are an adult
[rbarne34@hills CS110B]$ ./a.out
How old are you?: 65
You are a retiree
[rbarne34@hills CS110B]$ ./a.out
How old are you?: -6
Error - Please enter a positive number for your age.
*/