#include <cstdlib>
#include <iostream>
#include <ctime>
#include <string>
#include <vector>

using namespace std;

//ASCII char #s
const int maxVal = 125; //cut last two
const int minVal = 33;
int len;
char letter;
string pass;

int main (){
    //Seed RNG
    srand(time(0));
    
    cout << endl << "Password Length: ";
    cin >> len;
    for (int i = 0; i < len; ++i) {
        letter = static_cast<char> (minVal + (rand() % 125));
        if (letter != '\\') {
            pass.push_back(letter);
            }   
        }
    cout << "Your password is:" << endl << pass << endl << endl;
}