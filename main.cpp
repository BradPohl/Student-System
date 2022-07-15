#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <fstream>
#include <vector>

#include "members.h"
#include "student.h" //derived from members
#include "faculty.h" //derived from members

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::setw;
using std::left;
using std::vector;

/**
 * @brief show login then menu
 * 
 * @return int 
 */
void login(){
    string username, password;

    cout << "=====================================================" << endl
         << "\tEnter Username: ";
    cin >> username;

    if(username != "user"){ // Check username (sensitive info)
        cout << "Incorrect username" << endl;
        exit(0);
    }

    cout << endl << endl;

    cout << "\tEnter Password: ";
    cin >> password;

    if(password != "pass"){ // Check password (sensitive info)
        cout << "Incorrect password" << endl;
        exit(0);
    }

    cout << endl << endl;

    cout << "Login successful..." << endl
         << "Welcome to the School management system!" << endl
         << "=====================================================" << endl << endl;
}

int main(){
    login();

    int choice;
    string tempFirstName, tempLastName, tempID;
    double tempNumber;

    //object to read
    std::ifstream file;

    //create vector of members
    vector<Members*> members;

while(choice != 5){ //stay in loop until user exits
        cout << "=====================================================" << endl
             << "\tPress 1>" << left << setw(12) << " To Add" << "Records" << endl
             << "\tPress 2>" << left << setw(12) << " To View" << "Records" << endl
             << "\tPress 3>" << left << setw(12) << " To Modify" << "Records" << endl
             << "\tPress 4>" << left << setw(12) << " To Remove" << "Records" << endl
             << "\tPress 5>" << left << setw(12) << " To Exit" << "Program" << endl
             << "=====================================================" << endl << endl;

        cout << "Enter choice: ";
        cin >> choice;


        switch(choice){
            case 1:
                cout << "case 1" << endl;
            break;

            case 2:
                //open file object, input mode
                file.open("data.txt", std::ifstream::in);

                //read into members
                file.read((char*) &members, members.size());

                //set the data
                while(!file.eof() && !file.fail()){
                    file >> tempFirstName;
                    file >> tempLastName;
                    file >> tempID;
                    file >> tempNumber;
                    if(tempID.at(0) == '1')
                        members.push_back(new Faculty(tempFirstName, tempLastName, tempID, tempNumber));
                    else if(tempID.at(0) == '9')
                        members.push_back(new Student(tempFirstName, tempLastName, tempID, tempNumber));
                }

                for(size_t i = 0; i < members.size(); i++){
                    members[i]->print();
                }

                for(size_t i = 0; i < members.size(); i++){
                    delete members[i];
                }
            break;

            case 3:

            break;

            case 4:

            break;

            case 5:

            break;

            default:
                cout << "Invalid choice, please try again." << endl;
        }
}
    return 0;
}