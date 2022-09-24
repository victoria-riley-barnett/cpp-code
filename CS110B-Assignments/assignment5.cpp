//Assignment 5: Victoria Barnett
//This program models a 5-team baseball league.

#include <iostream>
#include <string>

using namespace std;

//prototyping
void initializeArrays(string names[], int wins[], int size);
void sortData(string names[], int wins[], int size);
void displayData(string names[], int wins[], int size);
void swap(int &a, int &b);

void swap(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
}

void initializeArrays(string names[], int wins[], int size){
    cout << "Please enter your team names and wins: " << endl;
    for(int i = 0; i < size; i++){
        cout << "Team name #" << i + 1 << endl;
        getline(cin, names[i]);
    }
    for(int j = 0; j < size; j++){
        cout << "How many wins for " << names[j] << "?: ";
        cin >> wins[j];
    }

}
void sortData(string names[], int wins[], int size){
    int minIndex, maxValue;

    for (int start = 0; start < size; start++) {
            minIndex = start;
            maxValue = wins[start];
            for(int i = start + 1; i < size; i++) {
                    if(wins[i] > maxValue) {
                            maxValue = wins[i];
                            minIndex = i;
                    }
            }
            swap(wins[minIndex], wins[start]);
            swap(names[minIndex], names[start]);
    }

}
void displayData(string names[], int wins[], int size){
    cout << endl << "League Standings" << endl << "----------------------" << endl;
    for(int i = 0; i < size; i++){
        cout << names[i] << ": " << wins[i] << endl;
    }

}
int main(){
    const int size = 5;
    string names[size];
    int wins[size];

    initializeArrays(names, wins, size);
    sortData(names, wins, size);
    displayData(names, wins, size);

    return 0;
}
f