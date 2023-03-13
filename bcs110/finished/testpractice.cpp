//#19 - ee function
#include <iostream>
#include <string>
using namespace std;

//prototypes
bool ee(char *str);

/*
Write a function called ee which accepts a pointer to a C-string as its argument.  
It should detect if the characters "ee" appear next to each other in the C-string. If so, it should return true. If not, it should return false. 
You may assume that parameter str points to a valid, null-terminated C-string containing only lowercase letters, 
and has at least two characters (plus the null character). You can use the strlen() function if you wish, 
but you are not required to. You are not allowed to use any other library functions, e.g. strcpy(), strstr(), etc. 
-- submissions which use library functiofns other than strlen() will receive no credit. You do not need to demonstrate calling this function. 
Example: if str points to an array containing "cheeky" the function should return true. 
If str points to an array containing "cheapie" the function should return false. 
You must use this function signature:

bool ee(char *str)
*/
int main()
{
    char str[] = "cheeky";
    char str2[] = "cheapie";
    cout << ee(str) << endl;
    cout << ee(str2) << endl;
    return 0;
}
bool ee(char *str){
    for (int i = 0; str[i] != '\0'; i++){
        if (str[i] == 'e' && str[i + 1] == 'e'){
            return true;
        }
    }
    return false;
}