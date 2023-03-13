#include <iostream>

using namespace std;

//prototyping
void swapPtr(int *a, int *b);
void swap(int a, int b);

void swap(int *a, int *b) {
        int temp = *a;
        *a = *b;
        *b = temp;
}
void swap(int *x, int*y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}