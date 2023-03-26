/* victoria on hills.ccsf.edu in ~/CS110C/week2  > ls
a.out  discussion2.cpp
victoria on hills.ccsf.edu in ~/CS110C/week2  > cat discussion2.cpp
// Creates a class Box that can hold any type of data, creates a fuction that can search an array of boxes of any data type for a user defined target.
// CS110C - Discussion 2 - 02/17/2023
// Victoria Barnett */

#include <iostream>
#include <stdexcept>

using namespace std;

template <class ItemType>
class Box {
    private:
        ItemType item;
    public:
        void setItem(const ItemType &x){
            item = x;
        }
        ItemType getItem() const {
            return item;
        }
};

template <class ItemType>
Box<ItemType> findBox(Box<ItemType> B[], int size, Box<ItemType> target){
    int i = 0;
    bool found = false;
    while (!found && i < size){
        if (B[i].getItem() == target.getItem()){
            found = true;
        }
        else{
            i++;
        }
    }
    //check if the user entered a negative number or a number greater than 9 digits
    if( target.getItem() < 0 || target.getItem() > 999999999 || target.getItem() == 0){
        throw logic_error("SSN must be a positive integer and a valid 9-digit SSN");;
    }
    if(!found) {
        throw logic_error("SSN not in this array");
    }
    return B[i];
}

int main(){
    Box<int> B[5];
    Box<int> target, result;
    int targetSSN;
    B[0].setItem(123456789);
    B[1].setItem(234567890);
    B[2].setItem(345678901);
    B[3].setItem(456789012);
    B[4].setItem(567890123);
    B[5].setItem(678901234);
    cout << "Enter a target SSN as an int, without dashes: " << endl;
    cin >> targetSSN;
    target.setItem(targetSSN);
    try{
        result = findBox(B, 6, target);
        cout << "SSN " << result.getItem() << " found." << endl;
    }
    catch(logic_error e){
        cout << e.what() << endl;
    }
    return 0;
}
/* SAMPLE OUTPUT
victoria on hills.ccsf.edu in ~/CS110C/week2  > ./a.out

Enter a target SSN as an int, without dashes:
123456789
SSN 123456789 found.
victoria on hills.ccsf.edu in ~/CS110C/week2  > ./a.out

Enter a target SSN as an int, without dashes:
-123456789
SSN must be a positive integer and a valid 9-digit SSN
victoria on hills.ccsf.edu in ~/CS110C/week2  > ./a.out

Enter a target SSN as an int, without dashes:
onetwothree
SSN must be a positive integer and a valid 9-digit SSN
victoria on hills.ccsf.edu in ~/CS110C/week2  > ./a.out

Enter a target SSN as an int, without dashes:
32143
SSN not in this array
victoria on hills.ccsf.edu in ~/CS110C/week2  > ./a.out

Enter a target SSN as an int, without dashes:
999999999
SSN not in this array
*/