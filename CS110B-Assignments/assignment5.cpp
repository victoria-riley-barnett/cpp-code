//[rbarne34@hills CS110B]$ cat assignment5.cpp 
//Assignment 5: Victoria Barnett
//This program models a 5-team baseball league.

#include <iostream>
#include <string>

using namespace std;

//prototyping
void initializeArrays(string *namesPtr[], int *winsPtr[], int size);
void sortData(string *namesPtr[], int *winsPtr[], int size);
void displayData(string *namesPtr[], int *winsPtr[], int size);
void swap(int *a, int *b);

void swap(int *a, int *b) {
        int temp = *a;
        *a = *b;
        *b = temp;
}

void initializeArrays(string *namesPtr[], int *winsPtr[], int size){
    cout << "Please enter your team names and wins: " << endl;
    for(int i = 0; i < size; i++){
        cout << "Team name #" << i + 1 << endl;
        cin >> *namesPtr[i];
    }
    for(int j = 0; j < size; j++){
        cout << "How many wins for " << namesPtr[j] << "?: ";
        cin >> *winsPtr[j];
    }

}
void sortData(string *namesPtr[], int *winsPtr[], int size){
    int minIndex, maxValue;

    for (int start = 0; start < size; start++) {
            minIndex = start;
            maxValue = *winsPtr[start];
            for(int i = start + 1; i < size; i++) {
                    if(*winsPtr[i] > maxValue) {
                            maxValue = *winsPtr[i];
                            minIndex = i;
                    }
            }
            swap(winsPtr[minIndex], winsPtr[start]);
            swap(namesPtr[minIndex], namesPtr[start]);
    }

}
void displayData(string *namesPtr[], int *winsPtr[], int size){
    cout << endl << "League Standings" << endl << "----------------------" << endl;
    for(int i = 0; i < size; i++){
        cout << namesPtr[i] << ": " << winsPtr[i] << endl;
    }

}
int main(){
    int size;
    cout << "How many teams do you have?" << endl;
    cin >> size;
    string *namesPtr = nullptr;
    int *winsPtr = nullptr;
    namesPtr = new string[size];
    winsPtr = new int[size];

    initializeArrays(&namesPtr, &winsPtr, size);
    sortData(&namesPtr, &winsPtr, size);
    displayData(&namesPtr, &winsPtr, size);

    return 0;
}