#include <iostream>
#include <cctype>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char *argv[]){
    int i;
    string failmessage = "This is not a hills pass\n";
    char error;

    for(i = 0; i < 3; i++){
        if(!isalpha(argv[1][i]) && !islower(argv[1][i])){
            cout << failmessage << "char " << argv[1][i] << " breaks hills convention\n";
            error = 'y';
        }
    }
    for(i = 3; i < 7; i++){
        if(!isdigit(argv[1][i]) && error != 'y'){
            cout << failmessage << "char " << argv[1][i] << " breaks hills convention\n";
            error = 'y';
        }
    }
    for(i = 7; i < 8; i++){
        if(argv[1][i] != '.'  && error != 'y'){
            cout << failmessage << "char " <<argv[1][i] << " breaks hills convention\n";
            error = 'y';
        }
    }
    for(i = 8; i < 10; i++){
        if(!isalpha(argv[1][i]) && !islower(argv[1][i])  && error != 'y'){
            cout << failmessage << "char " << argv[1][i] << " breaks hills convention\n";
            error = 'y';
        }
    }
    if(error != 'y'){
        cout << "This is a hills password!" << endl;
    }
    return 0;
}