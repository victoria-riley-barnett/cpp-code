//[rbarne34@hills CS110B]$ g++ assignment8.cpp
//[rbarne34@hills CS110B]$ cat assignment8.cpp
//Assignment 8: Riley Barnett
//C-String manipulation
#include <iostream>
#include <cstring>

using namespace std;
//prototyping
int lastIndexOf(char *s, char target);
void reverse(char *s);
void printer(char *s, int size);
int replace(char *s, char target, char replacementChar);
int findSubstring(char *s, char substring[]);
bool isPalindrome(char *s);

int lastIndexOf(char *s, char target){
    int size = strlen(reinterpret_cast<const char*>(s));
    int hit;
    for(int i = 0; i < size; i++){
        if(s[i] == target){
            hit = i;
        }
    }
    if(hit != 0){
        return hit;
    }
    return -1;
}
void reverse(char *s) {
    int size = strlen(reinterpret_cast<const char*>(s));
    for(int i = 0, j = size - 1; i < j; i++, j--){
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}
void printer(char *s){
    int size = strlen(reinterpret_cast<const char*>(s));
    for (int i = 0; i < size; i++){
        cout << s[i];
    }
}
int replace(char *s, char target, char replacementChar){
    int size = strlen(reinterpret_cast<const char*>(s));
    int hits;
    for(int i = 0; i < size; i++){
        if(s[i] == target){
            s[i] = replacementChar;
            hits += 1;
        }
    }
    return hits;
}
int findSubstring(char *s, char substring[]){
    int indexHit = 0;
    int size = strlen(reinterpret_cast<const char*>(s));
    int subSize = strlen(reinterpret_cast<const char*>(substring));
    for(int i = 0; i < subSize; i++){
        for(int j = 0; j < size; j++){
            if(s[j] == substring[i]){
                indexHit = j;
            }
        }
    }
    if (indexHit > 0){
        return indexHit;
    }
    else{
        return -1;
    }
}
bool isPalindrome(char *s){
    int size = strlen(reinterpret_cast<const char*>(s));
    int hits = 0;
    for(int i = 0, j = size - 1; i < size; i++, j--){
        if (s[i] == s[j]){
            hits += 1;
        }
    }
    if(hits >= (size / 2)){
        return true;
    }
    else{
        return false;
    }
}
int main(){
    char s[] = "Giants";
    char target = 't';
    char replacementChar = 'o';
    char substring[] = "on";
    int size = strlen(reinterpret_cast<const char*>(s));
    char palStr[] = "Hannah";
    char nonpalStr[] = "Alex";
    cout << "The last index of char " << target << " is: " << lastIndexOf(s, target) << endl;
    reverse(s);
    cout << "The reverse of the str is: ";
    printer(s);
    reverse(s);
    target = 'a';
    cout << "\nReplacing a in Giants with o: ";
    replace(s, target, replacementChar);
    printer(s);
    cout << "\nSearching 'Gionts' for substring 'on', -1 means it was not found. Result at index: [" << findSubstring(s,substring) << ']' << endl;
    cout << "Is palindrome 'Hannah': " << isPalindrome(palStr) << "\nIs palindrome 'Alex': " << isPalindrome(nonpalStr) << endl;
}
/*
[rbarne34@hills CS110B]$ ./a.out
The last index of char t is: 4
The reverse of the str is: stnaiG
Replacing a in Giants with o: Gionts
Searching 'Gionts' for substring 'on', -1 means it was not found. Result at index: [3]
Is palindrome 'Hannah': 1
Is palindrome 'Alex': 0
[rbarne34@hills CS110B]$
/*