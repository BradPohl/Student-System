#ifndef STUDENT_H
#define STUDENT_H

#include "members.h"

class Student : public Members{
    private:
        double gpa;

    public:
        Student() = default;
        Student(const string&, const string&, const string&, double);

        void setGpa(double);
        double getGpa() const;

        virtual void print() const;
};



#endif