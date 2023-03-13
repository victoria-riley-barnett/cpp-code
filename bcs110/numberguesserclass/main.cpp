#include "NumberGuesser.h"
#include <iostream>
using namespace std;

int main(){
    NumberGuesser guesser(1, 100);
    char response;
    cout << "Think of a number between 1 and 100." << endl;
    cout << "h = higher, l = lower, c = correct, x = exit" << endl;
    do {
        cout << "Is it " << guesser.getCurrentGuess() << "? (h/l/c/x): " << endl;
        cin >> response;
        if (response == 'h') {
            guesser.higher();
        }
        else if (response == 'l') {
            guesser.lower();
        }
        else if (response == 'c') {
            cout << "Guessed it!" << endl;
            guesser.reset();
            guesser.guessWinsPlus();
            cout << guesser.getGuessWins() << " numbers have been guessed correctly " << endl;
        }
        else if (response == 'x') {
            cout << "Closing program." << endl;
        }
        else {
            cout << "Invalid response." << endl;
        }
    }
    while (response != 'x');
    return 0;
}
/* OUTPUT
[rbarne34@hills numberguesserclass]$ pwd
/students/rbarne34/CS110B/numberguesserclass
[rbarne34@hills numberguesserclass]$ ls
a.out  main.cpp  NumberGuesser.cpp  NumberGuesser.h
[rbarne34@hills numberguesserclass]$ ./a.out
Think of a number between 1 and 100.
h = higher, l = lower, c = correct, x = exit
Is it 50? (h/l/c/x):
h
Is it 75? (h/l/c/x):
l
Is it 62? (h/l/c/x):
h
Is it 68? (h/l/c/x):
h
Is it 71? (h/l/c/x):
c
Guessed it!
1 numbers have been guessed correctly
Is it 50? (h/l/c/x):
l
Is it 25? (h/l/c/x):
l
Is it 12? (h/l/c/x):
h
Is it 18? (h/l/c/x):
h
Is it 21? (h/l/c/x):
l
Is it 19? (h/l/c/x):
c
Guessed it!
2 numbers have been guessed correctly
Is it 50? (h/l/c/x):
l
Is it 25? (h/l/c/x):
l
Is it 12? (h/l/c/x):
l
Is it 6? (h/l/c/x):
h
Is it 9? (h/l/c/x):
c
Guessed it!
3 numbers have been guessed correctly
Is it 50? (h/l/c/x):
h
Is it 75? (h/l/c/x):
h
Is it 88? (h/l/c/x):
h
Is it 94? (h/l/c/x):
l
Is it 91? (h/l/c/x):
h
Is it 92? (h/l/c/x):
c
Guessed it!
4 numbers have been guessed correctly
Is it 50? (h/l/c/x):
x
Closing program.
[rbarne34@hills numberguesserclass]$
*/