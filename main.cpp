#include <iostream>
#include <fstream>
#include <string>

using namespace std;


bool auth(); void showmenu(); 


int main() {
    if (!auth()) {
        return 0;
    }

    int user_input;

    // variable used to measure true size of the data
    int size = 0;

    const int MAX_SIZE = 10;

    // member info
    int member_id[MAX_SIZE];
    string member_name[MAX_SIZE];
    int member_phone[MAX_SIZE];
    int member_birth[MAX_SIZE];
    //trainer info
    int trainer_id[MAX_SIZE];
    string trainer_name[MAX_SIZE];
    int trainder_phone[MAX_SIZE];
    //plan info
    int plan_id[MAX_SIZE];
    string plan_name[MAX_SIZE];
    string plan_desc[MAX_SIZE];
    //plan-member
    string duration[MAX_SIZE];    


    do {
        showmenu();
        cin >> user_input;
        switch (user_input) {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                cout << "Existing...";
                break;
            default:
                cout << "Invalid input, please enter a number from 1-7";
                break;
        }
    } while (user_input != 7);
}

// Ensures correct password has been entered before starting the system.
bool auth() {
    string system_password;
    string user_password;
    fstream passfile;
    passfile.open("password.txt", ios::in);
    if (!passfile) {
        cout << "System has no password yet, can't continue.";
        passfile.close();
        return false;
    }
    cout << "Enter password to access the system: ";
    getline(cin, user_password);
    getline(passfile, system_password);
    if (user_password == system_password) {
        passfile.close();
        return true;
    }
    else {
        cout << "Incorrect password.";
        passfile.close();
        return false;
    }
}


void showmenu() {

}
