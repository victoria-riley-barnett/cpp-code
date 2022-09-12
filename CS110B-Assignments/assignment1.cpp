// Assignment1: Riley Barnett
// This program calculates a Pitcher's ERA rating given runs, innings

#include <iostream>
using namespace std;

int main() {
    int usrage;
    
    cout << "How old are you?: ";
    cin >> usrage;

    if (usrage <= 12)
        if (usrage >= 0) {
        cout << "You are a Child" << endl;
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