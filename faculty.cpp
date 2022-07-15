#include "faculty.h"

Faculty::Faculty(const string& firstName, const string& lastName, const string& memberID, double salary) : 
Members(firstName, lastName, memberID){
    setSalary(salary);
}

void Faculty::setSalary(double salary){
    this->salary = salary;
}


double Faculty::getSalary() const{
    return salary;
}


void Faculty::print() const{
    Members::print();

    std::cout << "Salary: " << salary << std::endl << std::endl;
}