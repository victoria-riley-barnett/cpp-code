#include <iostream>
#include <string>
using namespace std;

class Player{
private:
    string ID;
    string name;
public:
    Player(string n, string s)
    { name = n; setID(s); }
    string getName() const
    { return name; }
    string getID() const
    { return ID; }
    void setID(string s)
    { ID = s; }

};

class BasketballPlayer : public Player{
    private:
        int fieldgoals;
        int attempts;
    public:
        BasketballPlayer(string n, string i, int fg, int a) : Player(n, i)
        { fieldgoals = fg; attempts = a;  } // line 1
        void printStats() const 
        { cout << " Pct: " << (double) fieldgoals / attempts << endl; }
};

int main(){
    Player golfer("Tiger Woods", "123456789");
    BasketballPlayer pointGuard("Stephen Curry", "567890123", 2585, 5523); // line 2

    cout << golfer.getName() << endl;
    cout << pointGuard.getName() << endl;
    pointGuard.printStats();
    golfer.printStats();
    return 0;
}
