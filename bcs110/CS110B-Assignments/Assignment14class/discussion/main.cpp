#include "gradedactivity.h"
#include "assignment.h"
#include <iostream>

using namespace std;

int main(){
    Assignment a1;
    int f, e, s;
    cout << "Enter functionality score out of 50: ";
    cin >> f;
    cout << "Enter efficiency score out of 25: ";
    cin >> e;
    cout << "Enter style score out of 25: ";
    cin >> s;
    a1.set(f, e, s);

    cout << "Score: " << a1.getScore() << endl;
    cout << "Grade: " << a1.getLetterGrade() << endl;

    return 0;
}