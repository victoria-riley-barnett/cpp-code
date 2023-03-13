#include <iostream>
#include <string>

using namespace std;

int main(){
    //Declare vars
    string names[] = {"Carnitas", "Pollo", "Veggie"};
    float prices[] = {6.95, 6.25, 5.95};
    int size = sizeof(names)/sizeof(names[0]);

    //Declare empty pointers
    string *stringPtr = nullptr;
    float *floatPtr = nullptr;

    //Assign my pointers to the arrays
    stringPtr = names;
    floatPtr = prices;

    //Update stringPtr & floatPtr values by dereferencing, and then print each value.
    for (int i = 0; i < size; i++){
        *(stringPtr+i) = *(stringPtr+i) + " Especial";
        *(floatPtr+i) = *(floatPtr+i) + 2.00;
        cout << *(stringPtr+i) << "    " << "$" << *(floatPtr+i) << endl;
    }
}