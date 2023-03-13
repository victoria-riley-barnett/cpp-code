//Discussion 5: Victoria Barnett
//This program reads sequential credit card numbers from a file into a vector, takes a user credit card number, and checks for a match.
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

//var
vector<int> cards;
const int size = 20;
int card;
int ccNum;

//prototyping
bool linearSearch(vector<int> cards, int size, int ccNum);

int main() {

//stream obj
ifstream inputFile;
inputFile.open("cards.txt");

if(inputFile.is_open()) {
    while (inputFile >> card){
        cards.push_back(card);
    }
}

cout << "Please enter the credit card # to check: " << endl;
cin >> ccNum;

if (linearSearch(cards, size, ccNum) == true){
    cout << "This credit card number " << ccNum << " is a stolen CC card number." << endl;
}
else {
     cout << "The credit card number " << ccNum << " has passed verification!" << endl;
}

return 0;
}

bool linearSearch(vector<int> cards, int size, int ccNum) {
    int pos = 0;
    bool badNumFlag = false;

    while (!badNumFlag && pos < size) {
        if (cards[pos] == ccNum) {
            badNumFlag = true;
        }
        pos++;
    }
    return badNumFlag;
}
