#ifndef MEMBERS_H
#define MEMBERS_H

#include <iostream>
#include <string>

using std::string;

class Members{
    private:
        string firstName;
        string lastName;
        string memberID; //Students start with a 9, Faculty start with a 1

    public:
        //constructors
        Members() = default;
        Members(const string&, const string&, const string&);

        //destructor
        virtual ~Members();

        void setFirstName(const string&);
        const string& getFirstName() const;

        void setLastName(const string&);
        const string& getLastName() const;

        void setMemberID(const string&);
        const string& getMemberID() const;

        virtual void print() const;

};



#endif