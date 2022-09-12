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
