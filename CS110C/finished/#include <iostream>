#include <iostream>
#include <string>
using namespace std;

class song
{
    private:
        string name;
        string artist;
    public:
        void setName(string n);
        void setArtist(string a);
        string getName();
        string getArtist();
};
void song::setName(string n) {
    name = n;
}
void song::setArtist(string a) {
    artist = a;
}
string song::getName() {
    return name;
}
string song::getArtist() {
    return artist;
}
int main() {
    song song1;
    cout << "This program creates and implements some member functions of a song class, which you can name." << endl;
    string name;
    string artist;
    cout << "Enter song name: ";
    getline(cin, name);
    song1.setName(name);
    cout << "Enter artist name: ";
    getline(cin, artist);
    song1.setArtist(artist);
    cout << "Your song is: " << song1.getName() << " by " << song1.getArtist() << endl;
    return 0;
}