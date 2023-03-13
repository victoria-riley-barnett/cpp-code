/* Consider the following class and member function implementation.  
Derive a class from GradedActivity named Presentation which has two member variable ints, 
content and delivery which determine a Presentation’s score.  Implement the following member functions for Presentation: 

- a default constructor which sets both member variables and the score to zero
- a void member function named set which takes two int parameters c and d, sets content to c 
and delivery to d, and sets the score to c+d.  This function may assume that 0 <= c+d <=100, you don't have to check it.

Additionally, provide a simple main() function which creates an object of class Presentation, 
uses set() to set the object’s member data with some example values, and calls getLetterGrade() to print out the letter grade.
*/
#include <iostream>
#include <string>
using namespace std;

class GradedActivity
{
    private:
    int score;
    public:
    GradedActivity() 
    { score = 0.0; }
    GradedActivity(int s)
    { score = s; }
    void setScore(int s)
    { score = s; }
    int getScore()
    { return score; }
    char getLetterGrade();
};
char GradedActivity::getLetterGrade(){
    char letterGrade;
    if(score > 89)
        letterGrade = 'A';
    else if(score > 79)
        letterGrade = 'B';
    else if(score > 69)
        letterGrade = 'C';
    else if(score > 59)
        letterGrade = 'D';
    else
        letterGrade = 'F';
    return letterGrade;
};
class Presentation : public GradedActivity
{
    private:
    int content;
    int delivery;
    public:
    Presentation() : GradedActivity()
    {
        content = 0;
        delivery = 0;
    }
    void set(int c, int d)
    {
        content = c;
        delivery = d;
        int score = c+d;
        setScore(score);
    }
};
int main(){
    Presentation p1;
    Presentation p2;
    p1.set(50, 50);
    p2.set(40, 42); //-10 content for missing slides, -3 delivery for not being able to answer question, -5 delivery for short presentation.
    cout << "p1 grade: " << endl;
    cout << p1.getLetterGrade() << endl;
    cout << "p2 grade: " << endl;
    cout << p2.getLetterGrade() << endl;
    return 0;
}