#include <iostream>
using namespace std;

//prototype
int fib(int n);
int fibIter(int n);

int fib(int n) {
    if (n < 0) //base case
        return 0;
    if (n == 1)//base case
        return 1;
    else
        return fib(n - 1) + fib(n - 2);
}

int fibIter(int n) {
    int a = 0;
    int b = 1;
    int c = 0;
    for (int i = 0; i < n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return a;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    //cout << "Fibonacci number by recursion is: " << fib(n) << endl;
    cout << "Fibonacci number by iteration is: " << fibIter(n) << endl;
    return 0;
}