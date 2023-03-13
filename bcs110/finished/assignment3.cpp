//[rbarne34@hills CS110B]$ cat assignment3.cpp 
//Assignment 3: Riley Barnett
//This program plays a number guessing game with the user

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

//Prototyping
bool shouldPlayAgain();
void playOneGame();
void playRandom();
char getUserResponseToGuess(int guess);
int getMidpoint(int low, int high);
int getRandomMidpoint(int low, int high);

//global var
int low = 0;
int high = 100;
int guess, randGuess;
char response, randResponse, playFlag;;
unsigned int seed = time(0);

int main() {
    //seed RNG
    srand(seed);

    do {
        playOneGame();
    }
    while (shouldPlayAgain());

    return 0;
}
bool shouldPlayAgain() {
    

    cout << "Would you like to play the number guesser? (y/n): " << endl;
    
    cin >> playFlag;

    if (playFlag == 'y') {
        return true;
    }
    else {
        return false;
    }
    return false;
}   
void playOneGame() {
    guess = getMidpoint (low, high);
    response = getUserResponseToGuess(guess);

    if (response == 'h') {
        low = guess;
        playOneGame();
    }
    else if (response == 'l') {
        high = guess;
        playOneGame();

    }
    else if (response == 'r') {
        playRandom();
    }
    else if (response == 'x') {
        return;
    }
    else if (response == 'c') {
        //reset game
        low = 0;
        high = 100;

        cout << "Your number was " << guess << "!" << endl;
    }
    else {
    cout << endl << "_____Input_Error_____" << endl << "Please use one of the listed commands." << endl << endl;
    playOneGame();
    }
}
void playRandom() {
    randGuess = getRandomMidpoint(low, high);
    randResponse = getUserResponseToGuess(randGuess);

    if (randResponse == 'h') {
        low = guess;
        playOneGame();
    }
    else if (randResponse == 'l') {
        high = guess;
        playOneGame();

    }
    else if (randResponse == 'r') {
        playRandom();
    }
    else if (randResponse == 'c') {
        //reset game
        low = 0;
        high = 100;

        cout << endl << "Your number was " << randGuess << "!" << endl;
    }
    else if (response == 'x') {
        return;
    }
    else {
    cout << endl << "_____Input_Error_____" << endl << "Please use one of the listed commands." << endl << endl;
    playOneGame();
    }
}
int getMidpoint(int low, int high) {
    int guess = (low + high) / 2;
    return guess;
}
int getRandomMidpoint(int low, int high) {
    int randomNum = (rand() % (high - low +1)) + low;
    return randomNum;
}
char getUserResponseToGuess(int guess) {
    char userResponse;
    cout << "Is your number " << guess << "?" << "\nCommands:  (h)igher \t (l)ower \t (c)orrect \t (r)andom \t e(x)it" << endl;
    cin >> userResponse;
    return userResponse;
}
/* 
[rbarne34@hills CS110B]$ ./a.out //Normal game
Is your number 50?
Commands:  (h)igher      (l)ower     (c)orrect   (r)andom    e(x)it
h
Is your number 75?
Commands:  (h)igher      (l)ower     (c)orrect   (r)andom    e(x)it
h
Is your number 87?
Commands:  (h)igher      (l)ower     (c)orrect   (r)andom    e(x)it
h
Is your number 93?
Commands:  (h)igher      (l)ower     (c)orrect   (r)andom    e(x)it
l
Is your number 90?
Commands:  (h)igher      (l)ower     (c)orrect   (r)andom    e(x)it
h
Is your number 91?
Commands:  (h)igher      (l)ower     (c)orrect   (r)andom    e(x)it
h
Is your number 92?
Commands:  (h)igher      (l)ower     (c)orrect   (r)andom    e(x)it
c
Your number was 92!
Would you like to play the number guesser? (y/n): 
y //Random game
Is your number 50?
Commands:  (h)igher      (l)ower     (c)orrect   (r)andom    e(x)it
l
Is your number 25?
Commands:  (h)igher      (l)ower     (c)orrect   (r)andom    e(x)it
r
Is your number 21?
Commands:  (h)igher      (l)ower     (c)orrect   (r)andom    e(x)it
r
Is your number 38?
Commands:  (h)igher      (l)ower     (c)orrect   (r)andom    e(x)it
l
Is your number 12?
Commands:  (h)igher      (l)ower     (c)orrect   (r)andom    e(x)it
r
Is your number 9?
Commands:  (h)igher      (l)ower     (c)orrect   (r)andom    e(x)it
r
Is your number 8?
Commands:  (h)igher      (l)ower     (c)orrect   (r)andom    e(x)it
r
Is your number 5?
Commands:  (h)igher      (l)ower     (c)orrect   (r)andom    e(x)it
r
Is your number 19?
Commands:  (h)igher      (l)ower     (c)orrect   (r)andom    e(x)it
c

Your number was 19!
Would you like to play the number guesser? (y/n): 
n

//Input Validation Showcase - bad input validated in game, but exits in play boolean
[rbarne34@hills CS110B]$ ./a.out 
Is your number 50?
Commands:  (h)igher      (l)ower     (c)orrect   (r)andom    e(x)it
;

_____Input_Error_____
Please use one of the listed commands.

Is your number 50?
Commands:  (h)igher      (l)ower     (c)orrect   (r)andom    e(x)it
x
Would you like to play the number guesser? (y/n): 
;
[rbarne34@hills CS110B]$ 

*/