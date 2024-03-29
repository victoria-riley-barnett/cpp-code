// Array-based List Class for Playlists
// Victoria Barnett
// CS110C 02/20/2023
// Assignment 2

#include <string>
#include <iostream>
#include <stdexcept>
using namespace std;

template<class ItemType>
class List {
private:
    static const int CHUNK_SIZE=100;
    ItemType *list;
    int numItems;
    int maxItems;
public:
    // default constructor and destructor
    List() { numItems = 0; maxItems = CHUNK_SIZE;
        list = new ItemType[CHUNK_SIZE]; }
    ~List() { delete [] list; }
    
    // list member functions
    bool isEmpty()  const { return numItems==0; }
    int getLength() const { return numItems; }
    bool insert(int pos, const ItemType& item);
    bool remove(int pos);
    
    // clear the list
    // clear can simply set numItems to zero.  The array list may still contain
    // items already inserted into the list, but since numItems is zero, there
    // isn't any way to get at them using getEntry() or setEntry()
    void clear() { numItems = 0; }
    
    // return entry at postion pos
    // throw invalid_argument if pos<1 or pos>getLength()
    ItemType getEntry(int pos) const;
    
    // set entry at postion pos to item
    // throw invalid_argument if pos<1 or pos>getLength()
    void setEntry(int pos, const ItemType& item);
};

template<class ItemType>
bool List<ItemType>::insert(int pos, const ItemType& item)
{
    bool canAdd;
    ItemType *listtmp;
    
    canAdd = ((pos > 0) && (pos <= numItems + 1) && (numItems < maxItems));
    if (!canAdd){
        throw invalid_argument("ERROR: insert() using invalid position");
    }
    if (canAdd)
    {
        //First we need to allocate more memory and copy the old list into the new list
        listtmp = new ItemType[CHUNK_SIZE];
        maxItems = abs(maxItems + CHUNK_SIZE);

        //Copy the old list into the new list
        for(int i=0; i<maxItems; i++)
            listtmp[i] = list[i];

        //Delete the old list
        delete [] list; 

        //Rename tmp list to list
        list = listtmp;

        // second, we have to move everything after our insertion point over one
        // position to make room for our new item.  start at the back of the list.
        // don't forget arrays start at postion zero and our list ADT starts at
        // position 1.
        for(int i=numItems; i>=pos; i--)
            list[i] = list[i-1];
        
        // now put our item at position pos-1
        list[pos-1] = item;
        
        numItems++;
    }
    return canAdd;
}

template<class ItemType>
ItemType List<ItemType>::getEntry(int pos) const
{
    if(pos<1 || pos>getLength()) {
        throw invalid_argument("ERROR: getEntry() using invalid position");
    }
    return list[pos-1];
}

// TODO: add implementations for setEntry() and remove() functions
template<class ItemType>
void List<ItemType>::setEntry(int pos, const ItemType& item){
    //If the position is invalid, throw an exception
    if(pos<1 || pos>getLength()) {
        throw invalid_argument("ERROR: setEntry() using invalid position");
    }
    //Replace item at position with new item
    list[pos-1] = item;
}
template<class ItemType>
bool List<ItemType>::remove(int pos) {
    bool canRemove;
    
    canRemove = ((pos > 0) && (pos <= numItems + 1) && (numItems < maxItems));
    if (canRemove){
        //Move everything after the position to be removed over one position
        for(int i=pos-1; i<numItems; i++)
            list[i] = list[i+1];
        numItems--;
    }
    return canRemove;
}

// Utility function to input a track number with some input checking
// to make sure it's a number
int getTrack()
{
    bool inputCheck;
    int trackNumber;
    
    do
    {
        inputCheck = true;
        cout << "Please enter the track number you'd like to view: ";
        if (!(cin >> trackNumber))
        {
            cout << "Please enter numbers only.\n";
            cin.clear();
            cin.ignore(10000,'\n');
            inputCheck = false;
        }
    } while (!inputCheck);
    return trackNumber;
}

int main(){
    List<string> songs;
    char goAgain = 'y';
    char menuControl;
    int trackNumber;
    string trackName;
    
    // Insert some songs into our list
    songs.insert(1, "One More Saturday Night");
    songs.insert(2, "Friday I'm in Love");
    songs.insert(3, "Sunday Morning Coming Down");
    songs.insert(4, "California Love");

    cout << "Welcome!  There are " << songs.getLength() << " tracks.\n";
    cout << "Here are the tracks:\n";
    for (int i=1; i<=songs.getLength(); i++)
        cout << i << ": " << songs.getEntry(i) << endl;
    
    // Demonstrate functions
    // Demo insert
    cout << "Inserting a new track at position 5.\n";
    songs.insert(5, "Heaven Ain't Even a Place");

    // Demo set
    cout << "Setting track 3 to 'Chaise Lounge'.\n";
    songs.setEntry(3, "Chaise Lounge");

    //Demo remove
    cout << "Removing track 2.\n";
    songs.remove(2);

    // Show changes
    cout << "Here are the tracks:\n";
    for (int i=1; i<=songs.getLength(); i++)
        cout << i << ": " << songs.getEntry(i) << endl;

    // Demo exception handling
    // First, we'll try to get a track that doesn't exist.
    cout << "Now that our functions are known to work, we can test our exception handling.\n";
    cout << "We'll try to get a track that doesn't exist.\n";
    try
    {
        trackName = songs.getEntry(100);
    }
    catch (invalid_argument arg)
    {
        cout << arg.what() << endl;
        trackName = "No Track";
    }

    // Next we'll test our improved insert function
    cout << "Now we'll test our improved insert function.\n";
    cout << "We'll try to insert a track at position 101, just out of our static CHUNK_SIZE range.\n";
    try{
        songs.insert(8, "Heaven Ain't Even a Place");
    }
    catch (invalid_argument arg){
        cout << arg.what() << endl;
    }


    while (goAgain!='n')
    {
        trackNumber = getTrack();
        try
        {
            trackName = songs.getEntry(trackNumber);
        }
        catch (invalid_argument arg)
        {
            cout << arg.what() << endl;
            trackName = "No Track";
        }
        cout << "Your track name is " << trackName << endl;
        cout << "Go again? (y/n) ";
        cin >> goAgain;
    }
    
    cout << "Rock on!\n";
    return 0;
}

