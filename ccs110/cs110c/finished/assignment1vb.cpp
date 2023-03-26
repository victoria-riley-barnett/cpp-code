//[rbarne34@hills CS110C]$ cat assignment1.cpp

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
/*[rbarne34@hills CS110C]$ ./a.out
Enter a number: 321
Reverse digits of 321 is: 123

Enter a string: cat

Enter writeBackward with s: cat
About to write last character of string: cat
t
Enter writeBackward with s: ca
About to write last character of string: ca
a
Enter writeBackward with s: c
About to write last character of string: c
c
Enter writeBackward with s:
Exiting writeBackward with string:
Exiting writeBackward with string: c
Exiting writeBackward with string: ca
Exiting writeBackward with string: cat

Enter writeBackward2 with s: cat
Enter writeBackward2 with s: at
Enter writeBackward2 with s: t
Enter writeBackward2 with s:
Exiting writeBackward2 with string:
About to write first character of string: t
t
Exiting writeBackward2 with string: t
About to write first character of string: at
a
Exiting writeBackward2 with string: at
About to write first character of string: cat
c
Exiting writeBackward2 with string: cat

Enter a start number: 1
Enter a end number: 100
Sum of range from 1 to 100 is: 5050
[rbarne34@hills CS110C]$*/