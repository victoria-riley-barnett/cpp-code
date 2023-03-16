// Victoria Barnett - CS110C - Midterm Practice questions

#include <iostream>
#include <string>

using namespace std;

// Prototyping
void first(int theArray[], int size);
int max (int array[], int size);

//Global variables
int theArray[] = {1, 2, 3, 4, 5};
int size = 5;

int main(){
    first(theArray, size);
    max(theArray, size);
    return 0;

}

//1. Testing the first function
//prints out the first element of an array recursively
//segfaults when size is not 1
void first(int theArray[], int size)
{
  if (size == 1)
    cout << theArray[0];
  else {
    first(theArray, size);
  }
}

// 2. Recursive function that returns the max value in an int array of len size
int max (int array[], int size){
  if (size == 1)
    return array[0];
  else {
    int max = max(theArray, size);
    return max;
  }
}