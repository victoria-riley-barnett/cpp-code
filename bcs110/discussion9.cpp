//09 - Graded Discussion - Taqueria with structs: Riley Barnett
#include <iostream>
#include <string>

using namespace std;
//vars
struct Cost {
    double wholesale;
    double retail;
};
struct SalesRecord {
    string burritoName;
    int burritosSold;
    Cost pricing;
};

//Prototyping
void initalizeRecord(SalesRecord * today, int size);
void printRecord(SalesRecord * today, int size);
int getTotal(SalesRecord * today, int size);
float getProfit(SalesRecord record);
void printReport(SalesRecord* records, int size);
float totalProfit(SalesRecord* records, int size);

//functions
void initalizeRecord(SalesRecord *today, int size){
    for(int i = 0; i < size; i++){
        cout << "Burrito type " << i+1 << " is: ";
        getline(cin, today[i].burritoName);
    }
    for(int i = 0; i < size; i++){
        string temp;
        cout << "How many " << today[i].burritoName << " burritos sold today?: ";
        getline(cin, temp);
        today[i].burritosSold = stoi(temp);
    }
    for(int i = 0; i < size; i++){
        string retailIn, wholesaleIn;
        cout << "How much does " << today[i].burritoName << " cost wholesale?: ";
        getline(cin, wholesaleIn);
        today[i].pricing.wholesale = stof(wholesaleIn);
        cout << "How much is " << today[i].burritoName << " sold for?: ";
        getline(cin, retailIn);
        today[i].pricing.retail = stof(retailIn);
    }
}
void printRecord(SalesRecord * today, int size){
    cout << "\nToday you sold: " << endl;
    for(int i = 0; i < size; i++){
        cout << "#" << today[i].burritosSold << " " << today[i].burritoName<< endl;
    }
}
int getTotal(SalesRecord *today, int size){
    int total = 0;
    for(int i = 0; i < size; i++){
        total += today[i].burritosSold;
    }
    return total;
}
float getProfit(SalesRecord record){
    return (record.pricing.retail - record.pricing.wholesale) * record.burritosSold;

}
void printReport(SalesRecord* records, int size){
    for(int i = 0; i < size; i++){
        cout << "You sold " << records[i].burritosSold << " units of " << records[i].burritoName << " for a profit of $" << getProfit(records[i]) << endl;
    }
}
float totalProfit(SalesRecord* records, int size){
    float total = 0;
    for(int i = 0; i < size; i++){
        total += getProfit(records[i]);
    }
    return total;
}
int main(){
    string burritosIn;
    int size;
    cout << "How many types of Burritos were sold today? " << endl;
    getline(cin, burritosIn);
    size = stoi(burritosIn);
    SalesRecord * today = nullptr;
    today = new SalesRecord[size];

    //function calls
    initalizeRecord(today, size);
    printRecord(today, size);
    cout << "\nTotal sales: " << getTotal(today, size) << endl << endl;
    printReport(today, size);
    cout << "\nTotal profit: $" << totalProfit(today, size) << endl;

    //Dynamic array
    delete [] today;
    today = nullptr;

    return 0;
}