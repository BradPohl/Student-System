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

    //object to read/write
    std::ifstream infile;
    std::ofstream outfile;

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
        cout << endl << endl;


        switch(choice){
            case 1:
                cout << "case 1" << endl;
                //open file object, output mode at the end of file
                outfile.open("data.txt", std::ofstream::app);

                //get data for output to file
                if(outfile.is_open()){
                    cout << "Enter first name: ";
                    cin >> tempFirstName;
                    cout << endl << "Enter last name: ";
                    cin >> tempLastName;
                    cout << endl << "Enter member ID: ";
                    cin >> tempID;
                    if(tempID.at(0) == 1)
                        cout << endl << "Enter salary: ";
                    else
                        cout << endl << "Enter GPA: ";
                    cin >> tempNumber;
                        
                    outfile << "\n\n" << tempFirstName << " " << tempLastName << " " << tempID << " " << tempNumber;

                    outfile.close();
                }
                else
                    cout << "Can't open file" << endl;
                
            break;

            case 2:
                //open file object, input mode
                infile.open("data.txt", std::ifstream::in);

                //read into members
                infile.read((char*) &members, members.size());

                cout << "SEG FAULT???" << endl << endl;

                //set the data
                while(!infile.eof() && !infile.fail()){
                    infile >> tempFirstName;
                    infile >> tempLastName;
                    infile >> tempID;
                    infile >> tempNumber;
                    if(tempID.at(0) == '1')
                        members.push_back(new Faculty(tempFirstName, tempLastName, tempID, tempNumber));
                    else if(tempID.at(0) == '9')
                        members.push_back(new Student(tempFirstName, tempLastName, tempID, tempNumber));
                }

                cout << "SEG FAULT???" << endl << endl;

                for(size_t i = 0; i < members.size(); i++){
                    members[i]->print();
                }

                for(size_t i = 0; i < members.size(); i++){
                    delete members[i];
                } 

                infile.close();
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