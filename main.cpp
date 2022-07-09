#include <iostream>
#include <iomanip>
#include <stdlib.h>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::setw;
using std::left;

int main(){
    string username, password;
    int choice = 0;

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
         << "Welcome to the Student management system!" << endl
         << "=====================================================" << endl << endl;

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
        }

    }
    return 0;
}