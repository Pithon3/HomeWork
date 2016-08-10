//Assignment.h - Aidan St. G

#include <iostream>
#include <string>

#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H

using std::cout;
using std::string;

class Assignment
{
    public:
        Assignment();
        virtual ~Assignment();

    private:
        string name;
        int classNum;
        int priority;
        //int
};

#endif // ASSIGNMENT_H
