// Assignment 4: Victoria Barnett
// This program determines simplified Poker hand values and implements functions for each typical hand.

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//Prototyping
bool  containsPair(int hand[]);
bool  containsTwoPair(int hand[]);
bool  containsThreeOfaKind(int hand[]);
bool  containsStraight(int hand[]);
bool  containsFullHouse(int hand[]);
bool  containsFourOfaKind(int hand[]);
void selectionSort(int hand[], int handsSize); //selectionSort and swap reduce search complexity
void swap(int &a, int&b);

//Vars
const int handSize = 5;
int hand[handSize];
int temp, high, pairNum, maxElement, threeOfNum, fourOfNum, fullHouseNum;
vector<int> twoPairOut;
vector<int> fullHousePair;

void selectionSort(int hand[], int handSize) {
        int minIndex, minValue;

        for (int start = 0; start < (handSize - 1); start++) {
                minIndex = start;
                minValue = hand[start];
                for(int i = start + 1; i < handSize; i++) {
                        if(hand[i] < minValue) {
                                minValue = hand[i];
                                minIndex = i;
                        }
                }
                swap(hand[minIndex], hand[start]);
        }
}
void swap(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
}
bool containsPair(int hand[]) {
        for(int i = 0; i < handSize; i++) {
                if (hand[i] == hand[i+1]) {
                        pairNum = hand[i];
                        return true;
                }
        }
        return false;
}
bool containsTwoPair(int hand[]) {
        for(int i = 0; i < handSize; i++) {
                if(hand[i] == hand[i+1]) {
                        twoPairOut.push_back(hand[i]);
                        if(twoPairOut[0] > 0 && twoPairOut[1] > 0) {
                                return true;
                        }
                }
        }
        return false;
}
bool  containsThreeOfaKind(int hand[]) {
        for(int i = 0; i < handSize; i++) {
                if (hand[i] == hand[i+1] && hand[i] == hand[i+2]) {
                        threeOfNum = hand[i];
                        return true;
                }
        }
        return false;
}
bool  containsStraight(int hand[]) {
        if(hand[0] + 1 == hand[1] && hand[1] + 1 == hand[2] && hand[2] + 1 == hand[3] && hand[3] + 1 == hand[4]){
                return true;
        }
        return false;
}
bool  containsFullHouse(int hand[]) {
        int iteratorFull;
        if(containsThreeOfaKind(hand) == true && containsPair(hand) == true && threeOfNum != pairNum){
                return true;
        }
        return false;
}
bool  containsFourOfaKind(int hand[]) {
        for(int i = 0; i < handSize; i++) {
                if (hand[i] == hand[i+1] && hand[i] == hand[i+2] && hand[i] == hand[i+3]) {
                        fourOfNum = hand[i];
                        return true;
                }
        }
        return false;
}
int main() {
        cout << "Enter five numeric cards, no face cards. Use 2 - 9: " << endl;
        int userIn;
        for(int i = 0; i < handSize; i++) {
                cout << "Enter card number " << (i + 1) << " ";
                cin >> userIn;
                while(userIn < 2 || userIn > 9) {
                        cout << "Please use a number from 2-9: ";
                        cin >> userIn;
                }
                hand[i] = userIn;
        }
        selectionSort(hand, handSize);

        if(containsFourOfaKind(hand)){
                cout << "Four of a Kind! Your quad value is: " << fourOfNum << endl;
        }
        else if(containsFullHouse(hand)) {
                cout << "A Full House!" << endl;
        }
        else if (containsStraight(hand)) {
                cout << "A Straight!" << endl;
        }
        else if (containsThreeOfaKind(hand)) {
                cout << "Three of a kind! " << threeOfNum << "'s" << endl;
        }
        else if (containsTwoPair(hand)) {
                cout << "Two pair!" << endl;
        }
        else if (containsPair(hand)) {
                cout << "Pair of " << pairNum << "'s!" << endl;
        }
        else {
                for(int i = 0; i < handSize; i++) {
                        if(hand[i] > high){
                                high = hand[i];
                        }
                }
                cout << "High card: " << high << endl;
        }
        return 0;
}
/* OUTPUT
[rbarne34@hills CS110B]$ ./a.out 
Enter five numeric cards, no face cards. Use 2 - 9: 
Enter card number 1 2
Enter card number 2 2
Enter card number 3 3
Enter card number 4 3
Enter card number 5 6
Two pair!
[rbarne34@hills CS110B]$ ./a.out 
Enter five numeric cards, no face cards. Use 2 - 9: 
Enter card number 1 2
Enter card number 2 2
Enter card number 3 5
Enter card number 4 6
Enter card number 5 7
Pair of 2's!
[rbarne34@hills CS110B]$ ./a.out 
Enter five numeric cards, no face cards. Use 2 - 9: 
Enter card number 1 2
Enter card number 2 3
Enter card number 3 4
Enter card number 4 5
Enter card number 5 6
A Straight!
[rbarne34@hills CS110B]$ ./a.out 
Enter five numeric cards, no face cards. Use 2 - 9: 
Enter card number 1 9
Enter card number 2 7
Enter card number 3 6
Enter card number 4 5
Enter card number 5 3
High card: 9
[rbarne34@hills CS110B]$ ./a.out 
Enter five numeric cards, no face cards. Use 2 - 9: 
Enter card number 1 0
Please use a number from 2-9: 10
Please use a number from 2-9: 1
Please use a number from 2-9: 2
Enter card number 2 2
Enter card number 3 5
Enter card number 4 5
Enter card number 5 5
A Full House!
[rbarne34@hills CS110B]$ ./a.out 
Enter five numeric cards, no face cards. Use 2 - 9: 
Enter card number 1 5
Enter card number 2 5
Enter card number 3 5
Enter card number 4 4
Enter card number 5 7
Three of a kind! 5's
[rbarne34@hills CS110B]$ ./a.out 
Enter five numeric cards, no face cards. Use 2 - 9: 
Enter card number 1 8
Enter card number 2 8
Enter card number 3 8
Enter card number 4 8
Enter card number 5 6
Four of a Kind! Your quad value is: 8
[rbarne34@hills CS110B]$ */