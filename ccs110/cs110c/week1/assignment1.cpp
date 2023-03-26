/*Instructions:
1.  Chapter 2, exercise 9: Write a recursive C++ function that writes the digits of a positive decimal integer in reverse order.  
Hint: 2015 % 10 == 5, 2015 / 10 == 201.  Example: if given the integer 2015, your function should output 5102. 
2.  Rewrite both of the functions writeBackward and writeBackward2 in section 2.3.1 of the text (page 61 in both the 6th and 7th edition) as C++ functions.  
You may use either C-strings (char *)  or C++ string objects for the string.  Make sure you include all of the cout statements in these functions which indicate function entry, 
function exit, and about to write a character.  Make sure you carefully trace the functions and understand why the cout statements appear where they do when you run the program.
3.  Chapter 2, exercise 4: Given two integers, start and end, where end is greater than start, write a recursive C++ function that returns the 
sum of the integers from start through end, inclusive.  For example, if start is 3 and end is 6, the function should return 18, because 3+4+5+6 = 18.
*/
#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;

//prototype
int reverseDigits(int n);
void writeBackward(string s);
void writeBackward2(string s);
int sumRange(int start, int end);

int reverseDigits(int n) {
    if (n < 10) //base case
        return n;
    else
        return (n % 10) * pow(10, (int)log10(n)) + reverseDigits(n / 10);
}

void writeBackward(string s) {
    int length = s.size();
    cout << "Enter writeBackward with s: " << s << endl;
    if (length > 0) { //base case
        cout << "About to write last character of string: " << s << endl;
        cout << s.substr(length - 1, 1) << endl;
        writeBackward(s.substr(0, length - 1));
    }
    cout << "Exiting writeBackward with string: " << s << endl;
}

void writeBackward2(string s) {
    int length = s.size();
    int n = 0;
    cout << "Enter writeBackward2 with s: " << s << endl;
    if (length > 0) { //base case
        writeBackward2(s.substr(1, length - 1));
        cout << "About to write first character of string: " << s << endl;
        cout << s.substr(0, 1) << endl;
    }
    cout << "Exiting writeBackward2 with string: " << s << endl;
}

int sumRange(int start, int end) {
    if (start == end) //base case
        return start;
    else
        return start + sumRange(start + 1, end);
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Reverse digits of " << n << " is: " << reverseDigits(n) << endl << endl;
    string s;
    cout << "Enter a string: ";
    cin >> s;
    cout << endl;
    writeBackward(s);
    cout << endl;
    writeBackward2(s);
    cout << endl;
    int start, end;
    cout << "Enter a start number: ";
    cin >> start;
    cout << "Enter a end number: ";
    cin >> end;
    cout << "Sum of range from " << start << " to " << end << " is: " << sumRange(start, end) << endl;
    return 0;
}