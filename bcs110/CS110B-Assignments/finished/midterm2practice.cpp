//1. What is the purpose of the new operator?
//1. New allocates dynamic memory for a new object.

//2. True/False: if you use the new operator, you later should use delete.  Why or why not?
//2. True. If you use the new operator, you should use delete to free the memory the dynamic object is using.

//3. True/False: When you add 1 to a pointer using the ++ operator, you are actually adding the size of the data type referenced by the pointer
//3. True. When you increment a pointer, you are adding the size of the data type referenced by the pointer. For example, an incremented int pointer will add 4 to the pointer, but a char will add 1.

/* 4.  You are reading a program which includes the following lines:

int size = 5;
int *cards = new int[size];

Which of the below statements is true:


a) int *cards is a function to print cards

b) If there is no delete statement anywhere else in this program, this program has a memory leak.

c) The program won’t compile if there is no delete statement elsewhere in this program.

d) None of the above

statement B is true. If there is no delete statement anywhere else in this program, this program has a memory leak.*/
*/
/*
5. Write a function which accepts an int array and the array size as arguments.  
The function should dynamically create a new array which is the same size as the array passed in.  
Each element in the new array should be double the corresponding element in the array passed in.  
Return a pointer to the new array. 

E.g. if you pass in the array {2, -3, 5} of size 3, it should create a new array of size 3 with values {4, -6, 10} 
and return a pointer to it.

int *doubler(int a[], int size)
*/
int *doubler(int a[], int size)
{
    int *newArray = new int[size];
    for (int i = 0; i < size; i++)
    {
        newArray[i] = a[i] * 2;
    }
    return newArray;
}

/*  
6. Consider the following line of code:

  int temps[3] = {68, 72, 62};

// What does *temps contain?
//*temps contains the value of the first element in the array, 68.

//What does *(temps+1) contain?
//*(temps+1) decays to &temps[1] and contains the value of the second element in the array, 72.

//What does temps[1] contain?
//temps[1] contains the value of the second element in the array, 72.
*/
/*
7.  The _____ function returns true if the character is an upper case letter of the alphabet:

a) toupper()   b) isupper()   c) isalpha()   d) isdigit()  e) none of these
// b) isupper()

8.  The _____ function converts a C-string to an int:

a) strlen()   b) length()  c) len()  d) atoi()   e) none of these
// d) atoi()

9.  True/False: the strcpy() function will make sure there is enough memory allocated in the destination string before copying C-strings
// False. The dest arg for strcpy must be large enough to hold the source string.

10.  True/False: when creating a string object, you must dynamically allocate enough bytes to hold the string
// False. When creating a string object, you must dynamically allocate enough bytes to hold the string plus the null terminator.
11.  Consider the following statement, assuming goAgain is a valid char.  Rewrite it using toupper() or tolower()

if (goAgain == 'y' || goAgain == 'Y')

if (toupper(goAgain) == 'Y')
*/
/*
12.  Write a function which accepts a pointer to a C-string as its argument.  It should return the number of words in the C-string.  
For example, for the C-string “The Giants won the pennant!” your function should return 5.  
You may assume the parameter passed is a pointer to a valid, null-terminated C-string with no newlines or tabs, 
exactly one space separates each word, and there is at least one word.
*/
int wordCounter(char* str){
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ' ')
        {
            count++;
        }
    }
    return count + 1;
}

/*
13.  Assuming slogan is a valid char array storing C-String "Giants", what is the minimum size that slogan needs to be?
13. The minimum size that slogan needs to be is 7. The null terminator is not included in the size of the array.
*/

For questions 14-16, refer to the following code:

struct Resort
{
    string resortName;
    int numberLifts;
    int vertical;
    int averageSnowfall;
};

Resort r = { "Kirkwood", 15, 2000, 125 };
Resort resorts[100];
Resort *rPtr = NULL;
*/
14.  What value is stored in r.averageSnowfall?

a) 2000 b) "Kirkwood"  c) 15  d) 125  e) we can't determine the value based on this code
14. d) 125

15.  True/False: rPtr = &(resorts[9]); will assign the address of the 10th element of resorts to rPtr
15. True. rPtr = &(resorts[9]); will assign the address of the 10th element of resorts to rPtr

16.  Write a function which will take a Resort structure as a parameter, and ask the user to input new values for each field of the structure.  
The values in the parameter must be changed to the new values and remain changed after the function call.  
You can assume the user enters valid input, and that the resort name entered doesn’t contain any whitespace.
16. void resortInput(Resort &r)
{
    cout << "Enter the name of the resort: ";
    cin >> r.resortName;
    cout << "Enter the number of lifts: ";
    cin >> r.numberLifts;
    cout << "Enter the vertical: ";
    cin >> r.vertical;
    cout << "Enter the average snowfall: ";
    cin >> r.averageSnowfall;
}

17. True/False: a class may have more than one destructor.
17. True. A class may have more than one destructor.

18.  True/False: assume a class has a default constructor implemented.  Any time an object of this class is instantiated, a constructor is called.
18. True. Any time an object of this class is instantiated, a constructor is called.
19.  Public members of an object may be accessed using the following operator:

a) .        b) >         c) -        d) None of these
19. a) .

20. A header file (.h file) of a class typically contains:

a) The code to implement the class

b) a program using the class

c) The class declaration

d) None of the above
20. c) The class declaration

21. The preprocessor directive #ifndef can be used in a class header file to

a) Prevent the class declaration from being included multiple times

b) Declare a class namespace

c) Implement the class member functions

d) None of the above
21. a) Prevent the class declaration from being included multiple times

For questions 22 and 23, refer to the following code:

class SwimmingPool
{ 
  private:
    int area;
    int gallons;
  public:
    SwimmingPool();
    void setArea(int);
    void setGallons(int);
    int getGallons() const
      { return gallons; }
};

22. Which of the following lines of code would you have in an implementation of the setGallons function?

a) SwimmingPool()

b) void SwimmingPool::setGallons(int g)

c) SwimmingPool::SwimmingPool()

d) void SwimmingPool()::setGallons(int g)

e) SwimmingPool::setGallons(int g)

23. True/False: function getGallons() is an inline member function
23. True. function getGallons() is an inline member function

24. Design a class called Date. 

The class should store a date in three private integers: month, day, year. 

There should be a member function to print out the date in the month/day/year format, e.g. 12/25/2015, 4/1/1970

There should be a constructor which takes three parameters to initialize the date.  It should not accept values for day greater than 31 or less than 1, or values for month greater than 12 or less than 1.  If the constructor is called with these values an error message should be printed out and the field set to 0.  Any value for year is acceptable.

There do not need to be any other member functions.

Provide the class declaration and also the implementation of the member function and constructor.

class Date
{
  private:
    int month;
    int day;
    int year;
  public:
    Date(int m, int d, int y);
    void printDate();
};
Date::Date(int m, int d, int y)
{
    if (m > 12 || m < 1)
    {
        cout << "Invalid month. Setting to 0." << endl;
        month = 0;
    }
    else
    {
        month = m;
    }
    if (d > 31 || d < 1)
    {
        cout << "Invalid day. Setting to 0." << endl;
        day = 0;
    }
    else
    {
        day = d;
    }
    year = y;
}
void Date::printDate()
{
    cout << month << "/" << day << "/" << year << endl;
}