#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void initiate_files();

bool auth(); void showmenu(); 


int main() {
    if (!auth()) {
        return 0;
    }

    int user_input;
    void initiate_files();
    // variable used to measure true size of the data
    int size = 0;

    const int GYM_SIZE = 10;
    // arrays to hold file content
    int member_id[GYM_SIZE];
    string member_name[GYM_SIZE];
    


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

void initiate_files() {
    fstream trainer_file, member_file, take_trainer_file, plan_file;
    trainer_file.open("trainer.txt", ios::in);
    if (!trainer_file) {
        trainer_file.open("trainer.txt", ios::out);
        trainer_file.close();
    }
    member_file.open("member.txt", ios::in);
    if (!member_file) {
        member_file.open("member.txt", ios::out);
        member_file.close();
    }
    take_trainer_file.open("take_trainer.txt", ios::in);
    if (!take_trainer_file) {
        take_trainer_file.open("take_trainer.txt", ios::out);
        take_trainer_file.close();
    }
    plan_file.open("plan.txt", ios::in);
    if (!plan_file) {
        plan_file.open("plan.txt", ios::out);
        plan_file.close();
    }

}

void showmenu() {

}