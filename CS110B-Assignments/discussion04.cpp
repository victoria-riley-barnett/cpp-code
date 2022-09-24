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
        cout << "How many " << burritoType[i] << "sold Today?" << endl;
        cin >> numSold[i]; 
        totalSale += numSold[i];
        if (numSold[i] > mostSoldNum) {
            mostSoldNum = numSold[i];
            mostSold = burritoType[i];
        }
    }
    
    cout << "You sold " << totalSale << "Burritos today. \nThe most popular was: " << mostSold << endl;
}
