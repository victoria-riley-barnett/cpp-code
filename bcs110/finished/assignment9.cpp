//Assignment 9: Victoria Barnett
//This program models a 5-team baseball league, now with structs and dynamic arrays.

#include <iostream>
#include <string>
#include <cstring>

using namespace std;
struct WinRecord {
    char* name;
    int wins;
};

//prototyping
char* getline();
void initializeData(WinRecord* standings, int size);
void sortData(WinRecord* standings, int size);
void displayData(WinRecord* standings, int size);
void swap(int &a, int &b);

char* getLine(){
  // Prof. Lutrell's getline function, called in initializeData

  const int BUFFER_SIZE = 1000;
  // Allocate a buffer local to this function
  char buffer[BUFFER_SIZE];
  // Use cin.getline() to input the buffer from the user
  cin.getline(buffer, BUFFER_SIZE);
  // Find the length of the string in buffer
  int length = strlen(buffer);
  // Dynamically allocate an array, to be returned
  char *rValue = new char[length + 1];
  // Copy the string into the dynamically allocated array
  strncpy(rValue, buffer, length);
  // Return the address of the dynamically allocated array
  return rValue;
}
void swap(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
}
void initializeData(WinRecord* standings, int size){
    cout << "Please enter your team names and wins: " << endl;
    for(int i = 0; i < size; i++){
        cout << "Team name #" << i + 1 << endl;
        standings[i].name = getLine();
    }
    for(int j = 0; j < size; j++){
        cout << "How many wins for " << standings[j].name << "?: ";
        cin >> standings[j].wins;
    }
}
void sortData(WinRecord* standings, int size){
    int minIndex, maxValue;
    for (int start = 0; start < size; start++) {
            minIndex = start;
            maxValue = standings[start].wins;
            for(int i = start + 1; i < size; i++) {
                    if(standings[i].wins > maxValue) {
                        maxValue = standings[i].wins;
                        minIndex = i;
                    }
            }
            swap(standings[minIndex].wins, standings[start].wins);
            swap(standings[minIndex].name, standings[start].name);
    }
}
void displayData(WinRecord* standings, int size){
    cout << endl << "League Standings" << endl << "----------------------" << endl;
    for(int i = 0; i < size; i++){
        cout << standings[i].name << ": " << standings[i].wins << endl;
    }
}
int main(){
    string teamsIn;
    cout << "How many teams are in the league? " << endl;
    getline(cin, teamsIn);
    int size = stoi(teamsIn);
    WinRecord * standings = nullptr;
    standings = new WinRecord[size];

    //Function calls
    initializeData(standings, size);
    sortData(standings, size);
    displayData(standings, size);

    //Deallocate memory
    for(int i = 0; i < size; i++){
        delete [] standings[i].name;
    }
    delete [] standings;
    return 0;
}
/*
[rbarne34@hills CS110B]$ g++ assignment9.cpp -o assignment9.out
[rbarne34@hills CS110B]$ ./assignment9.out
How many teams are in the league?
5
Please enter your team names and wins:
Team name #1
Dodgers
Team name #2
Yankees
Team name #3
Red Sox
Team name #4
Astros
Team name #5
Cubs
How many wins for Dodgers?: 72
How many wins for Yankees?: 75
How many wins for Red Sox?: 73
How many wins for Astros?: 68
How many wins for Cubs?: 69

League Standings
----------------------
Yankees: 75
Red Sox: 73
Dodgers: 72
Cubs: 69
Astros: 68
[rbarne34@hills CS110B]$ cat assignment9.cpp
*/