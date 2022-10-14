#include <iostream>
#include <cstring>

using namespace std;
//prototyping
int lastIndexOf(char *s, char target);
void reverse(char *s);
//int replace(char *s, char target, char replacementChar);
//int findSubstring(char *s, char substring[]);
//bool isPalindrome(char *s);
//void reverseWords(char *s);

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
    char temp;
    for(int i = 0; i < (size / 2); i++){
        
    }

}
int main(){
    char s[] = "Giants";
    char target = 't';
    cout << "The last index of char " << target << " is: " << lastIndexOf(s, target) << endl;
    reverse(s);
    for(int i = 0; i < 15; i++){
        cout << s[i] << endl;
    }
}
