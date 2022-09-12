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
            cout << endl << "Your cards are: " << randomnum << randomnum2 << endl;
            cout << "The dealer's cards are: " << randomnum3 << randomnum4 << endl;
        }
        else {
            cards.push_back(randomnum);
            dealercards.push_back(randomnum3);
            cout << endl << "Your cards are: " << randomnum << endl;
            cout << "The dealer's cards are: " << randomnum3 << endl;
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