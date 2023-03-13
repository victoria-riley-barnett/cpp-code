[rbarne34@hills CS110B]$ cat discussion04.cpp 
#include <iostream>
#include <string>

using namespace std;

const int NUM_TYPES = 4;
string burritoType[NUM_TYPES] = {"carnitas", "beef", "shrimp", "veggie"};
int numSold[NUM_TYPES];
int totalSale;
int mostSoldNum;
string mostSold;

int main() {
    for (int i = 0; i < NUM_TYPES; ++i) {
        cout << "How many " << burritoType[i] << " sold Today?" << endl;
        cin >> numSold[i]; 
        totalSale += numSold[i];
        if (numSold[i] > mostSoldNum) {
            mostSoldNum = numSold[i];
            mostSold = burritoType[i];
        }
    }
    
    cout << "You sold " << totalSale << " burritos today. \nThe most popular was: " << mostSold << endl;
}

[rbarne34@hills CS110B]$ ./a.out 
How many carnitas sold Today?
4
How many beef sold Today?
4
How many shrimp sold Today?
4
How many veggie sold Today?
5
You sold 17 burritos today. 
The most popular was: veggie
[rbarne34@hills CS110B]$ 