// Assignment1: Riley Barnett
// This program calculates grades

#include <iostream>
using namespace std;

int main() {
    int assignments, assigni = 0, grade, grades;
    double avggrade;
    char lettergrade;

    cout << "How many assignments did you complete?" << endl;
    cin >> assignments;

    while (assigni <= assignments) {
        cout << "Enter your grade: ";
        cin >> grade;
            while (grade < 0 || grade > 100) {
                cout << "Your grades must be entered numerically from 0-100" << endl;
                cout << "Enter your grade: ";
                cin >> grade;
            }
        grades += grade;
        ++assigni;
    }
    avggrade = grades/assignments;

    if (avggrade >= 90) {
        lettergrade = 'A';
    }
    else if (avggrade >= 80 and avggrade < 90) {
        lettergrade = 'B';
    }
    else if (avggrade >= 70 and avggrade < 80) {
        lettergrade = 'C';
    }
    else if (avggrade >= 60 and avggrade < 70) {
        lettergrade = 'D';
    }
    else {
        lettergrade = 'F';
    }

    cout << "Your total points scored: " << grades << endl
         << "Your letter grade is: " << lettergrade << endl
         << "Your average(mean) grade is: " << avggrade << endl;

    return 0;
}