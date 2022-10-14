/*[rbarne34@hills CS110B]$ touch pointerTasks.cpp
[rbarne34@hills CS110B]$ vim pointerTasks.cpp 
[rbarne34@hills CS110B]$ cat pointerTasks.cpp
*/

#include <iostream>

using namespace std;

//Prototyping
void noNegatives(int *);
void swap(int *, int *);

int main(){

    // 1. Create two integer variables named x and y
    int x, y;

    // 2. Create an int pointer named p1
    int *p1;

    // 3. Store the address of x in p1
    p1 = &x;

    // 4. Use p1 to set the value of x to 99
    *p1 = 99;

    // 5. Using cout and x, display the value of x
    cout << "The value of X is: " << x << endl;

    // 6. Using cout and the pointer p1, display the value of x
    cout << "The value of X as referenced as *p1 is: " << *p1 << endl;

    // 7. Store the address of y into p1
    p1 = &y;

    // 8. Use p1 to set the value of y to -300
    *p1 = -300;

    // 9. Create two new variables: an int named temp, and an int pointer named p2
    int temp = 0;
    int *p2;

    // 10. Use temp, p1, and p2 to swap the values in x and y (this will take a few statements)
    p2 = &x;

    temp = *p1;
    *p1 = *p2;
    *p2 = temp;

    // 11. Write a function with the following signature: void noNegatives(int *x). The function should accept the address of an int variable. If the value of this integer is negative then it should set it to zero.  Note: you should declare the noNegatives function BEFORE main, not inside of main.
    // 12. Call the function twice: once with the address of x as the argument, and once with the address of y
    noNegatives(&x);
    noNegatives(&y);

    // 13. Use p2 to display the values in x and y (this will require both assignment statements and cout statements)
    p2 = &x;
    cout << "The value in X is: " << *p2 << endl;
    p2 = &y;
    cout << "The value in Y is: " << *p2 << endl;

    // 14. Create an int array with two elements. The array should be named ‘a’
    int a[2];

    // 15. Use p2 to initialize the first element of a with the value of x
    p2 = &x;
    a[0] = *p2;

    // 16. Use p2 to initialize the second element of a with the value of y
    p2 = &y;
    a[1] = *p2;

    // 17. Using cout, display the address of the first element in a
    cout << "The first element is: " << a[0] << endl;

    // 18. Using cout, display the address of the second element in a
    cout << "The second element is: " << a[1] << endl;

    // 19. Use p1, p2, and temp to swap the values in the two elements of array ‘a’. (first point p1 at a[0], 
    //then point p2 at a[1]. After this the swapping steps should look very similar to step 10.)
    p1 = &a[0];
    p2 = &a[1];
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;

    // 20. Display the values of the two elements. (The first element should be 99, the second 0).
    for(int i = 0; i < 2; i++){
        cout << "Element " << i << " is: " << a[i] << endl;
    }
    
    // 21. Write a function named ‘swap’ that accepts two integer pointers as arguments, and then swaps the two integers that the pointers point to. This function must be pass by pointer, i.e. int *, not pass by reference, i.e. int &.  Note: you should declare the swap function BEFORE main, not inside of main.
    // 22. Call your swap function with the addresses of x and y, then print their values. (x should be 99, y should be 0).
    swap(&x,&y);
    cout << "The value of X is: " << x << endl;
    cout << "The value of Y is: " << y << endl;
    
    // 23. Call your swap function with the address of the two elements in array ‘a’, then print their values. (a[0] should be 0, a[1] should be 99)
    swap(&a[0],&a[1]);
    cout << "The value of a[0] is: " << a[0] << endl;
    cout << "The value of a[1] is: " << a[1] << endl;
}
void noNegatives(int *x){
    if(*x < 0){
        *x = 0;
    }
}
void swap(int *x, int*y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
/*OUTPUT
[rbarne34@hills CS110B]$ g++ pointerTasks.cpp 
[rbarne34@hills CS110B]$ ./a.out 
The value of X is: 99
The value of X as referenced as *p1 is: 99
The value in X is: 0
The value in Y is: 99
The first element is: 0
The second element is: 99
Element 0 is: 99
Element 1 is: 0
The value of X is: 99
The value of Y is: 0
The value of a[0] is: 0
The value of a[1] is: 99
[rbarne34@hills CS110B]$
*/