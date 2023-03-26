//Assignment 7: Victoria Barnett
//This program models a 5-team baseball league using DMA.

#include <iostream>
#include <string>

using namespace std;

//prototyping
void initializeArrays(string namesPtr[], int winsPtr[], int size);
void sortData(string namesPtr[], int winsPtr[], int size);
void displayData(string namesPtr[], int winsPtr[], int size);
void swap(int *a, int *b);

void swap(int *a, int *b) {
        int temp = *a;
        *a = *b;
        *b = temp;
}
void initializeArrays(string namesPtr[], int winsPtr[], int size){
    cout << "Please enter your team names and wins: " << endl;
    for(int i = 0; i < size; i++){
        cout << "Team name #" << i + 1 << endl;
        //Getline so we can use names with spaces
        getline(cin, namesPtr[i]);
    }
    for(int j = 0; j < size; j++){
        cout << "How many wins for the " << namesPtr[j] << "?: ";
        cin >> winsPtr[j];
    }
}
void sortData(string namesPtr[], int winsPtr[], int size){
    int minIndex, maxValue;

    for (int start = 0; start < size; start++) {
            minIndex = start;
            maxValue = winsPtr[start];
            for(int i = start + 1; i < size; i++) {
                    if(winsPtr[i] > maxValue) {
                            maxValue = winsPtr[i];
                            minIndex = i;
                    }
            }
            swap(winsPtr[minIndex], winsPtr[start]);
            swap(namesPtr[minIndex], namesPtr[start]);
    }
}
void displayData(string namesPtr[], int winsPtr[], int size){
    cout << endl << "League Standings" << endl << "----------------------------" << endl << endl;
    for(int i = 0; i < size; i++){
        cout << namesPtr[i] << ": " << winsPtr[i] << endl;
    }
}
int main(){
    //Get size in way that doesn't mess up istream for later
    string usrIn;
    int size;

    cout << "How many teams do you have?" << endl;
    getline(cin, usrIn);

    //Vars
    size = stoi(usrIn);
    string *namesPtr = nullptr;
    int *winsPtr = nullptr;
    namesPtr = new string[size];
    winsPtr = new int[size];

    //Function calls
    initializeArrays(namesPtr, winsPtr, size);
    sortData(namesPtr, winsPtr, size);
    displayData(namesPtr, winsPtr, size);

    delete [] namesPtr;
    delete [] winsPtr;

    namesPtr = nullptr;
    winsPtr = nullptr;

    return 0;
}