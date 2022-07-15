#ifndef FACULTY_H
#define FACULTY_H

#include "members.h"

class Faculty : public Members{
    private:
        double salary;

    public:
        Faculty() = default;
        Faculty(const string&, const string&, const string&, double);

        void setSalary(double);
        double getSalary() const;

        virtual void print() const;
};

#endif