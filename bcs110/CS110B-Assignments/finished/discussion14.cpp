/*[rbarne34@hills gradedactivity]$ g++ main.cpp gradedactivity.cpp assignment.cpp
[rbarne34@hills gradedactivity]$ ls
a.out  assignment.cpp  assignment.h  gradedactivity.cpp  gradedactivity.h  main.cpp
*/
//[rbarne34@hills gradedactivity]$ cat assignment.cpp
#include "assignment.h"
#include <iostream>

using namespace std;

void Assignment::set(int f, int e, int s){
    if (f < 0 || f > 50 || e < 0 || e > 25 || s < 0 || s > 25){
        cout << "Invalid input. Score set to 0." << endl;
        score = 0;
    }
    else{
        functionality = f;
        efficiency = e;
        style = s;
        score = (f + e + s);
    }
}
//[rbarne34@hills gradedactivity]$ cat assignment.h
#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H
#include "gradedactivity.h"


class Assignment : public GradedActivity
{
private:
    int functionality;
    int efficiency;
    int style;
public:
    Assignment()
    { functionality = 0; efficiency = 0; style = 0; }
    void set(int f, int e, int s);
};

#endif

//[rbarne34@hills gradedactivity]$ cat gradedactivity.cpp
#include "gradedactivity.h"
#include <iostream>

using namespace std;

char GradedActivity::getLetterGrade() const{
    char letterGrade;
    if (score > 89)
        letterGrade = 'A';
    else if (score > 79)
        letterGrade = 'B';
    else if (score > 69)
        letterGrade = 'C';
    else if (score > 59)
        letterGrade = 'D';
    else
        letterGrade = 'F';
    return letterGrade;
}
//[rbarne34@hills gradedactivity]$ cat gradedactivity.h
#ifndef GRADEDACTIVITY_H
#define GRADEDACTIVITY_H

class GradedActivity
{
protected:
    double score;
public:
    GradedActivity()
    { score = 0.0; }
    GradedActivity(double s)
    { score = s; }
    void setScore(double s)
    { score = s; }
    double getScore() const
    { return score; }
    char getLetterGrade() const;
};

#endif
//[rbarne34@hills gradedactivity]$ cat main.cpp
#include "gradedactivity.h"
#include "assignment.h"
#include <iostream>

using namespace std;

int main(){
    Assignment a1;
    int f, e, s;
    cout << "Enter functionality score out of 50: ";
    cin >> f;
    cout << "Enter efficiency score out of 25: ";
    cin >> e;
    cout << "Enter style score out of 25: ";
    cin >> s;
    a1.set(f, e, s);

    cout << "Score: " << a1.getScore() << endl;
    cout << "Grade: " << a1.getLetterGrade() << endl;

    return 0;
}
/* OUTPUT
[rbarne34@hills gradedactivity]$ ls
a.out  assignment.cpp  assignment.h  gradedactivity.cpp  gradedactivity.h  main.cpp
[rbarne34@hills gradedactivity]$ ./a.out
Enter functionality score out of 50: 38
Enter efficiency score out of 25: 18
Enter style score out of 25: 15
Score: 71
Grade: C
[rbarne34@hills gradedactivity]$ ./a.out
Enter functionality score out of 50: 50
Enter efficiency score out of 25: 25
Enter style score out of 25: 25
Score: 100
Grade: A
*/