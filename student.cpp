#include "student.h"

Student::Student(const string& firstName, const string& lastName, const string& memberID, double gpa) : 
Members(firstName, lastName, memberID){
    setGpa(gpa);
}

void Student::setGpa(double gpa){
    this->gpa = gpa;
}

double Student::getGpa() const{
    return gpa;
}

void Student::print() const{
    Members::print();

    std::cout << "GPA: " << gpa << std::endl << std::endl;
}