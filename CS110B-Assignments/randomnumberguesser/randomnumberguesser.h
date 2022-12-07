#ifndef RANDOMNUMBERGUESSER_H
#define RANDOMNUMBERGUESSER_H
#include "numberguesser.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class RandomNumberGuesser : public NumberGuesser
{
    private:
        int currentGuess;
    public:
        RandomNumberGuesser(int l, int h) : NumberGuesser(l, h) {}
        int getCurrentGuess() {
            srand(time(0));
            currentGuess = rand() % (high - low + 1) + low;
            return currentGuess;
        }
        void higher() {
            low = getCurrentGuess() + 1;
            currentGuess = rand() % (high - low + 1) + low;
        }
        void lower() { 
            high = getCurrentGuess() - 1;
            currentGuess = rand() % (high - low + 1) + low;
        }
        void reset() {
            low = originalLow; high = originalHigh;
        }
};

#endif
