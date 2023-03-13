#ifndef NUMBERGUESSER_H
#define NUMBERGUESSER_H

class NumberGuesser
{
    private:
        int high;
        int low;
        int currentGuess;
        int guessWins;

    public:
        NumberGuesser(); 
        NumberGuesser(int lowerBound, int upperBound);
        void higher();
        void lower();
        int getCurrentGuess();
        void reset();
        void guessWinsPlus();
        int getGuessWins();
};

#endif