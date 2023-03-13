//[rbarne34@hills CS110B]$ cat test2.cpp 
// Assignment2: Riley Barnett
// This program plays a simplified version of blackjack

#include <iostream> 
#include <vector> //For a dynamic array
#include <cstdlib> //For rand/seeding srand
#include <ctime> //For rand/seeding srand
#include <numeric> //For accumulate
#include <string> //For returning our cards
using namespace std;

int main() {
    //Variables
    vector<int> cards;
    vector<int> dealercards;
    char repeat = 'y';
    

    //Seed random numbers
    unsigned seed = time(0);
    srand(seed);

    
    while (repeat == 'y') {
        //Lower scope const/var
        const int MAX_VAL = 10, MIN_VAL = 1;
        int randomnum = (rand() % (MAX_VAL - MIN_VAL +1)) + MIN_VAL;
        int randomnum2 = (rand() % (MAX_VAL - MIN_VAL +1)) + MIN_VAL;
        int randomnum3 = (rand() % (MAX_VAL - MIN_VAL +1)) + MIN_VAL;
        int randomnum4 = (rand() % (MAX_VAL - MIN_VAL +1)) + MIN_VAL;

        //Append to Cards
        if (cards.size() == 0) {
            cards.push_back(randomnum);
            cards.push_back(randomnum2);
            dealercards.push_back(randomnum3);
            dealercards.push_back(randomnum4);
            cout << endl << "Your cards are: " << randomnum << " "  << randomnum2 << endl;
            cout << "The dealer's cards are: " << randomnum3 << " " << randomnum4 << endl;
        }
        else {
            cards.push_back(randomnum);
            dealercards.push_back(randomnum3);
            cout << endl << "Your card is: " << randomnum << endl;
            cout << "The dealer's card is: " << randomnum3 << endl;
        }

        //Add up cards
        int totalscore = accumulate(cards.begin(), cards.end(), 0);
        int dealerscore = accumulate(dealercards.begin(), dealercards.end(), 0);
        
        cout << "Your hand is: ";
        for (auto i: cards) {
            cout << i << ' ';
        }
        cout << "The dealers hand is: ";
        for (auto i: dealercards) {
            cout << i << ' ';
        }
        cout << endl << "Your Score: " << totalscore << "  Dealer Score: " << dealerscore << endl;
        if (totalscore < 21 && dealerscore < 21) {
            cout << "Deal again? (y/n): ";
        }
        else if (totalscore == 21 && dealerscore != 21) {
            cout << "You won!" << endl;
            cards.clear();
            dealercards.clear();
            cout << "Play again? (y/n): ";
        }
        else if (totalscore == 21 && dealerscore == 21) {
            cout << "You tied! What are the odds?" << endl;
            cards.clear();
            dealercards.clear();
            cout << "Play again? (y/n): ";
        }
        else if (dealerscore == 21) {
            cout << "You lost to the dealer!" << endl;
            cards.clear();
            dealercards.clear();
            cout << "Play again? (y/n): ";
        }
        else if (totalscore > 21 ) {
            cout << "Bust! You went over 21." << endl;
            cards.clear();
            dealercards.clear();
            cout << "Play again? (y/n): ";
        }
        else if (dealerscore > 21) {
            cout << "The dealer busted! You win." << endl;
            cards.clear();
            dealercards.clear();
            cout << "Play again? (y/n): ";
        }
        cin >> repeat;
        if (repeat == 'n') {
            while (dealerscore < 17) {
                cout << "Dealer takes another card" << endl;
                dealerscore += (rand() % (MAX_VAL - MIN_VAL +1)) + MIN_VAL;
                cout << "Their score is now: " << dealerscore << endl;
            }
            if (dealerscore > 21) {
                cout << "The dealer busted! You win." << endl;
            }
            else if (abs(dealerscore - 21) > abs(totalscore - 21)) {
                cout << "You won!" << endl;
                }
            else if (abs(dealerscore - 21) < abs(totalscore -21)) {
                cout << "The dealer won!" << endl;
            }
            else if (abs(dealerscore - 21) == abs(totalscore -21)) {
                cout << "It's a Push!" << endl;
            }
            else {
                cout << "Something went wrong";
            }
        }
    }
    return 0;
}
/*
[rbarne34@hills CS110B]$ ./a.out 

Your cards are: 7 3
The dealer's cards are: 1 2
Your hand is: 7 3 The dealers hand is: 1 2 
Your Score: 10  Dealer Score: 3
Deal again? (y/n): y

Your card is: 9
The dealer's card is: 7
Your hand is: 7 3 9 The dealers hand is: 1 2 7 
Your Score: 19  Dealer Score: 10
Deal again? (y/n): n
Dealer takes another card
Their score is now: 16
Dealer takes another card
Their score is now: 18
You won!
[rbarne34@hills CS110B]$ ./a.out 

Your cards are: 2 10
The dealer's cards are: 6 4
Your hand is: 2 10 The dealers hand is: 6 4 
Your Score: 12  Dealer Score: 10
Deal again? (y/n): y

Your card is: 2
The dealer's card is: 5
Your hand is: 2 10 2 The dealers hand is: 6 4 5 
Your Score: 14  Dealer Score: 15
Deal again? (y/n): y

Your card is: 5
The dealer's card is: 6
Your hand is: 2 10 2 5 The dealers hand is: 6 4 5 6 
Your Score: 19  Dealer Score: 21
You lost to the dealer!
Play again? (y/n): y

Your cards are: 4 9
The dealer's cards are: 8 8
Your hand is: 4 9 The dealers hand is: 8 8 
Your Score: 13  Dealer Score: 16
Deal again? (y/n): y

Your card is: 8
The dealer's card is: 9
Your hand is: 4 9 8 The dealers hand is: 8 8 9 
Your Score: 21  Dealer Score: 25
You won!
lay again? (y/n): y

Your cards are: 5 10
The dealer's cards are: 1 1
Your hand is: 5 10 The dealers hand is: 1 1 
Your Score: 15  Dealer Score: 2
Deal again? (y/n): y

Your card is: 3
The dealer's card is: 3
Your hand is: 5 10 3 The dealers hand is: 1 1 3 
Your Score: 18  Dealer Score: 5
Deal again? (y/n): n
Dealer takes another card
Their score is now: 10
Dealer takes another card
Their score is now: 19
The dealer won!
[rbarne34@hills CS110B]$ ./a.out 

Your cards are: 9 4
The dealer's cards are: 8 8
Your hand is: 9 4 The dealers hand is: 8 8 
Your Score: 13  Dealer Score: 16
Deal again? (y/n): y

Your card is: 4
The dealer's card is: 6
Your hand is: 9 4 4 The dealers hand is: 8 8 6 
Your Score: 17  Dealer Score: 22
The dealer busted! You win.
Play again? (y/n): y

Your cards are: 5 10
The dealer's cards are: 8 8
Your hand is: 5 10 The dealers hand is: 8 8 
Your Score: 15  Dealer Score: 16
Deal again? (y/n): y

Your card is: 8
The dealer's card is: 9
Your hand is: 5 10 8 The dealers hand is: 8 8 9 
Your Score: 23  Dealer Score: 25
Bust! You went over 21.
Play again? (y/n): y

Your cards are: 6 4
The dealer's cards are: 4 5
Your hand is: 6 4 The dealers hand is: 4 5 
Your Score: 10  Dealer Score: 9
Deal again? (y/n): y

Your card is: 10
The dealer's card is: 2
Your hand is: 6 4 10 The dealers hand is: 4 5 2 
Your Score: 20  Dealer Score: 11
Deal again? (y/n): n
Dealer takes another card
Their score is now: 15
Dealer takes another card
Their score is now: 20
It's a Push!
[rbarne34@hills CS110B]$ 
*/
