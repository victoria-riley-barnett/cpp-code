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
    