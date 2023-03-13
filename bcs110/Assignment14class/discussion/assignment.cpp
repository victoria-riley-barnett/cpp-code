#include "assignment.h"
#include <iostream>

using namespace std;

void Assignment::set(int f, int e, int s){
    if (f < 0 || f > 50 || e < 0 || e > 25 || s < 0 || s > 25){
        cout << "Invalid input. Score set to 0." << endl;
        score = 0;
    }
    else{
        functionality = f;
        efficiency = e;
        style = s;
        score = (f + e + s);
    }
}