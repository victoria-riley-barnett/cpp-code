#include "NumberGuesser.h"
#include <iostream>
using namespace std;


NumberGuesser::NumberGuesser ()
{
    high = 100;
    low = 1;
    currentGuess = (high + low) / 2;
    guessWins = 0;
}
NumberGuesser::NumberGuesser (int lowerBound, int upperBound)
{
    high = upperBound;
    low = lowerBound;
    currentGuess = (high + low) / 2;
    guessWins = 0;
}
void NumberGuesser::higher ()
{
    low = currentGuess + 1;
    currentGuess = (high + low) / 2;
}
void NumberGuesser::lower ()
{
    high = currentGuess - 1;
    currentGuess = (high + low) / 2;
}
int NumberGuesser::getCurrentGuess ()
{
    return currentGuess;
}
void NumberGuesser::reset ()
{
    high = 100;
    low = 1;
    currentGuess = (high + low) / 2;
}
void NumberGuesser::guessWinsPlus ()
{
    guessWins++;
}
int NumberGuesser::getGuessWins ()
{
    return guessWins;
}
