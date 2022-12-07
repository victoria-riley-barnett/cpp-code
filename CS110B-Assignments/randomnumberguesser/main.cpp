#include "numberguesser.h"
#include "randomnumberguesser.h"
#include <iostream>

using namespace std;

int main() {
    //Create random and nonrandom object
    NumberGuesser *ng = new NumberGuesser(1, 10);
    NumberGuesser *ng2 = new RandomNumberGuesser(1, 10);

    //Call the getCurrentGuess() function on both objects
    cout << "First guess: " << endl;
    cout << ng->getCurrentGuess() << endl;
    cout << ng2->getCurrentGuess() << endl;

    //Call again on both objects
    cout << "Second call" << endl;
    cout << ng->getCurrentGuess() << endl;
    cout << ng2->getCurrentGuess() << endl;

    //Call the higher() function on both objects
    ng->higher();
    ng2->higher();

    //Get the current guess for both objects
    cout << "After higher" << endl;
    cout << ng->getCurrentGuess() << endl;
    cout << ng2->getCurrentGuess() << endl;

    //Call the lower() function on both objects
    ng->lower();
    ng2->lower();

    //Get the current guess for both objects
    cout << "After lower" << endl;
    cout << ng->getCurrentGuess() << endl;
    cout << ng2->getCurrentGuess() << endl;

    //Call the reset() function on both objects
    ng->reset();
    ng2->reset();

    //Get the current guess for both objects
    cout << "After reset" << endl;
    cout << ng->getCurrentGuess() << endl;
    cout << ng2->getCurrentGuess() << endl;

    //Delete the objects
    delete ng;
    delete ng2;

    return 0;
}