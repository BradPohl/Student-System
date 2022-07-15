#include "members.h"

//Constructor. Used to set a basic member (first, last, id)
Members::Members(const string& firstName, const string& lastName, const string& memberID){
    this->firstName = firstName;
    this->lastName = lastName;
    this->memberID = memberID;
}

//Destructor
Members::~Members(){}

//set method. Used to set first name
void Members::setFirstName(const string& firstName){
    this->firstName = firstName;
}

//get method. Used to pull first name
const string& Members::getFirstName() const{
    return firstName;
}

//set last
void Members::setLastName(const string& lastName){
    this->lastName = lastName;
}

//get last
const string& Members::getLastName() const{
    return lastName;
}

//set ID
void Members::setMemberID(const string& memberID){
    this->memberID = memberID;
}

//get ID
const string& Members::getMemberID() const{
    return memberID;
}

//basic print function
void Members::print() const{
    std::cout << "Name: " << lastName << ", " << firstName << std::endl
              << "ID: " << memberID << std::endl;
}