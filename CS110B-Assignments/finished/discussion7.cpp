#include <iostream>
#include <string>

using namespace std;

int main(){
    //Declare vars
    string names[] = {"Carnitas", "Pollo", "Veggie"};
    float prices[] = {6.95, 6.25, 5.95};
    int size = sizeof(names)/sizeof(names[0]);

    //Declare empty pointers
    string *stringptr = nullptr;
    float *floatptr = nullptr;

    //Assign my pointers to the arrays
    stringptr = names;
    floatptr = prices;

    //Update stringPtr & floatPtr values by dereferencing, and then print each value.
    for (int i = 0; i < size; i++){
        *(stringptr+i) = *(stringptr+i) + " Especial";
        *(floatptr+i) = *(floatptr+i) + 2.00;
        cout << *(stringptr+i) << "    " << *(floatptr+i) << endl;
    }
}