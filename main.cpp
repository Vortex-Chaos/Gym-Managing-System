#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool auth(); void showmenu(); 
void upload_member_info(int member_id[], string member_name[], int member_phone[], int member_birth[], int &size);
void upload_trainer_info(int trainer_id[], string trainer_name[], int trainer_phone[], int &size);
void upload_plan_info(int plan_id[], string plan_name[], string plan_desc[], int &size);
void upload_member_plan_info(int plan_id[], int member_id[], string duration[], int &size);
void upload_trainer_member_info(int trainer_id[], int member_id[], int &size);

void update_member_info(int member_id[], string member_name[], int member_phone[], int member_birth[], int size);
void update_member_file(int member_id[], string member_name[], int member_phone[], int member_birth[], int size);

void add_member_info(int member_id[], string member_name[], int member_phone[], int member_birth[], int &size);
void print_member_info(int member_id[], string member_name[], int member_phone[], int member_birth[], int size);
void delete_member(int member_id[], string member_name[], int member_phone[], int member_birth[], int &size);

void count_trainer_member(int trainer_id[], int member_id[], int size);
void assign_plan(int plan_id[], int member_id[], int &size);
void assign_trainer(int trainer_id[], int member_id[], int size);

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


    int choice;

    do {
        cout << "---------------- Welcome to Gym Management System ----------------\n";
        cout << "Please select an option from the menu below:\n\n";

        cout << "1. Add a new member.\n";
        cout << "2. Show all members.\n";
        cout << "3. Delete a member.\n";
        cout << "4. Assign a plan.\n";
        cout << "5. Assign a trainer.\n";
        cout << "6. Count number of members a trainer is training.\n";
        cout << "7. Exit.\n\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Add a new member selected.\n";
            break;

        case 2:
            cout << "Show all members selected.\n";
            break;

        case 3:
            cout << "Delete a member selected.\n";
            break;

        case 4:
            cout << "Assign a plan selected.\n";
            break;

        case 5:
            cout << "Assign a trainer selected.\n";
            break;

        case 6:
            cout << "Count number of members a trainer is training selected.\n";
            break;

        case 7:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice, please try again.\n";
        }

        cout << endl;

    } while (choice != 7);

    return 0;
}
