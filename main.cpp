#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

bool auth(string& role, int& id); void showmenu(); 
void upload_member_info(int member_id[], string member_name[], int member_phone[], int member_birth[], int &size);
void upload_trainer_info(int trainer_id[], string trainer_name[], int trainer_phone[], int &size);
void upload_plan_info(int plan_id[], string plan_name[], string plan_desc[], int &size);
void upload_member_plan_info(int plan_id[], int member_id[], int duration[], int &size);
void upload_trainer_member_info(int trainer_id[], int member_id[], int &size);

void update_member_info(int member_id[], string member_name[], int member_phone[], int member_birth[], int size);
void update_member_file(int member_id[], string member_name[], int member_phone[], int member_birth[], int size);
void update_member_plan_file(int plan_id[], int member_id[], int duration[], int size);
void update_trainer_member_file(int trainer_id[], int member_id[], int size);

void add_member_info(int member_id[], string member_name[], int member_phone[], int member_birth[], int &size);
void print_member_info(int member_id[], string member_name[], int member_phone[], int member_birth[], int size);
void search_member(int member_id[], string member_name[], int member_phone[], int member_birth[], int size);
void delete_member(int member_id[], string member_name[], int member_phone[], int member_birth[], int &member_size,
                   int trainer_id[], int trainer_member_id[], int &trainer_member_size,
                   int plan_id[], int member_plan_id[], int duration[], int &member_plan_size);

void count_trainer_member(int trainer_id[], int member_id[], int size);
void assign_plan(int plan_id[], int plans_id[], int member_id[], int members_id[], int duration[], int &size, int member_size, int plan_size);
void assign_trainer(int trainer_id[], int trainers_id[], int member_id[], int members_id[], int &size, int trainer_size, int member_size);

    const int MAX_SIZE = 30;

int main() {
    string role;
    int id;
    if (!auth(role, id)) {
        return 0;
    }

    int user_input;
    // variable used to measure true size of the data
    int member_size = 0;
    int trainer_size = 0;
    int plan_size = 0;
    int member_plan_size = 0;
    int trainer_member_size = 0;

    // member info
    int member_id[MAX_SIZE];
    string member_name[MAX_SIZE];
    int member_phone[MAX_SIZE];
    int member_birth[MAX_SIZE];
    //trainer info
    int trainer_id[MAX_SIZE];
    string trainer_name[MAX_SIZE];
    int trainer_phone[MAX_SIZE];
    //plan info
    int plan_id[MAX_SIZE];
    string plan_name[MAX_SIZE];
    string plan_desc[MAX_SIZE];
    //member-plan
    int member_plan_member_id[MAX_SIZE];
    int member_plan_plan_id[MAX_SIZE];
    int duration[MAX_SIZE];    
    //trainer-member
    int trainer_member_member_id[MAX_SIZE];
    int trainer_member_trainer_id[MAX_SIZE];


    // initialize data from text files into the arrays
    upload_member_info(member_id, member_name, member_phone, member_birth, member_size);
    upload_trainer_info(trainer_id, trainer_name, trainer_phone, trainer_size);
    upload_plan_info(plan_id, plan_name, plan_desc, plan_size);
    upload_member_plan_info(member_plan_plan_id, member_plan_member_id, duration, member_plan_size);
    upload_trainer_member_info(trainer_member_trainer_id, trainer_member_member_id, trainer_member_size);

    // members panel
    if (role == "member") {
        for (int k = 0; k < member_size; k++) {
            if (member_id[k] == id) {
                cout << left << setw(15) << "Member ID:" << setw(16) << "Member Name:" << setw(15) << "Member phone:" << setw(15) << "Member Birthdate:" << endl;
                cout << setw(15) << member_id[k] << setw(16) << member_name[k] << setw(15) << member_phone[k] << setw(15) << member_birth[k] << endl;
                cout << "Plans:\n";
                for (int i = 0; i < member_plan_size; i++) {
                    if (member_id[k] == member_plan_member_id[i]) {
                        cout << "ID: " << setw(4) << member_plan_plan_id[i] << " ";
                        for (int j = 0; j < plan_size; j++) {
                            if (member_plan_plan_id[i] == plan_id[j]) { cout << "Name: " << setw(10) << plan_name[j] << " Duration: " << setw(3) << duration[i] << endl;}
                        }
                    }
                }
                cout << "Trainers:\n";
                for (int i = 0; i < trainer_member_size; i++) {
                    if (member_id[k] == trainer_member_member_id[i]) {
                        cout << "ID: " << setw(4) << trainer_member_trainer_id[i] << " ";
                        for (int j = 0; j < trainer_size; j++) {
                            if (trainer_member_trainer_id[i] == trainer_id[j]) { cout << "Name: " << setw(10) << trainer_name[j] << endl;}
                        }
                    }
                }
                return 0;
            }
        }
        cout << "This user is no longer registered.\n";
    }

    // admin panel
    if (role == "admin") {
        do {
            showmenu();
            cin >> user_input;
            switch (user_input) {
                case 1:
                    break;
                case 2:
                    print_member_info(member_id, member_name, member_phone, member_birth, member_size);
                    break;
                case 3:
                    delete_member(member_id, member_name, member_phone, member_birth, member_size,
                                  trainer_member_trainer_id, trainer_member_member_id, trainer_member_size,
                                  member_plan_plan_id, member_plan_member_id, duration, member_plan_size);
                    break;
                case 4:
                    search_member(member_id, member_name, member_phone, member_birth, member_size);
                    break;
                case 5:
                    assign_plan(member_plan_plan_id, plan_id, member_plan_member_id, member_id, duration, member_plan_size, member_size, plan_size);
                    break;
                case 6:
                    assign_trainer(trainer_member_trainer_id, trainer_id, trainer_member_member_id, member_id, trainer_member_size, trainer_size, member_size);
                    break;
                case 7:
                    break;
                case 8:
                    cout << "Exiting...";
                    update_member_file(member_id, member_name, member_phone, member_birth, member_size);
                    update_member_plan_file(member_plan_plan_id, member_plan_member_id, duration, member_plan_size);
                    update_trainer_member_file(trainer_member_trainer_id, trainer_member_member_id, trainer_member_size);
                    break;
                default:
                    cout << "Invalid input, please enter a number from 1-8\n";
                    break;
            }
        } while (user_input != 8);
    }
}

// Ensures correct password has been entered before starting the system.
bool auth(string& role, int& id) {
    string system_password;
    string user_password;
    string user;
    string system_user;
    string role_line;
    string id_line;
    fstream passfile;


    passfile.open("password.txt", ios::in);
    if (!passfile) {
        cout << "System has no password yet, can't continue.";
        return false;
    }

    cout << "Enter username: ";
    getline(cin, user);
    cout << "Enter password to access the system: ";
    getline(cin, user_password);
    while (getline(passfile, system_user) && getline(passfile, system_password) && getline(passfile, role) && getline(passfile, id_line)) {
        if (user == system_user && user_password == system_password) {
            cout << endl;
            passfile.close();
            id = stoi(id_line);
            return true;
        }
    }
    cout << "Incorrect username or password.";
    passfile.close();
    return false;
}


void showmenu() {
        cout << "---------------- Welcome to Gym Management System ----------------\n";
        cout << "Please select an option from the menu below:\n\n";

        cout << "1. Add a new member.\n";
        cout << "2. Show all members.\n";
        cout << "3. Delete a member.\n";
        cout << "4. Search for a member.\n";
        cout << "5. Assign a plan.\n";
        cout << "6. Assign a trainer.\n";
        cout << "7. Count number of members a trainer is training.\n";
        cout << "8. Exit.\n\n";

        cout << "Enter your choice: ";
}

// all other upload functions follow this one's template
void upload_member_info(int member_id[], string member_name[], int member_phone[], int member_birth[], int &size) {
    fstream member_file;
    int id, phone, birth, index=0;
    string name;
    size = 0;

    member_file.open("member.txt", std::ios::in); // opening with input only

    // creates file if it doesn't exist
    if (!member_file) {
        ofstream create("member.txt");
        create.close();
        member_file.open("member.txt", std::ios::in);
    }

    // loop line by line while ensuring it doesn't overflow
    while (member_file >> id >> name >> phone >> birth && index < MAX_SIZE) {
        member_id[index] = id;
        member_name[index] = name;
        member_phone[index] = phone;
        member_birth[index] = birth;
        size++;
        index++;
    }

    if (index >= MAX_SIZE) {
        cout << "Reached max system capacity for member array, any remaining data will be truncated\n";
    }

    member_file.close();
    // debugging line
    //cout << "done uploading member info.\n";
    //for (int i = 0; i<size; i++) {
    //    cout << member_id[i] << " " << member_name[i] << " " << member_phone[i] << " " << member_birth[i] << endl;
    //}
}

void upload_trainer_info(int trainer_id[], string trainer_name[], int trainer_phone[], int &size) {
    fstream trainer_file;
    int id, phone, index=0;
    string name;
    size = 0;

    trainer_file.open("trainer.txt", std::ios::in);

    if (!trainer_file) {
        ofstream create("trainer.txt");
        create.close();
        trainer_file.open("trainer.txt", std::ios::in);
    }

    while (trainer_file >> id >> name >> phone && index < MAX_SIZE) {
        trainer_id[index] = id;
        trainer_name[index] = name;
        trainer_phone[index] = phone;
        size++;
        index++;
    }

    if (index >= MAX_SIZE) {
        cout << "Reached max system capacity for trainer array, any remaining data will be truncated\n";
    }

    trainer_file.close();
}

void upload_plan_info(int plan_id[], string plan_name[], string plan_desc[], int &size) {
    fstream plan_file;
    int id, index=0;
    string name, desc;
    size = 0;

    plan_file.open("plan.txt", std::ios::in);

    if (!plan_file) {
        ofstream create("plan.txt");
        create.close();
        plan_file.open("plan.txt", std::ios::in);
    }

    while (plan_file >> id >> name && index < MAX_SIZE) {
        getline(plan_file, desc); // this is done to allow description of plans to have spaces.
        plan_id[index] = id;
        plan_name[index] = name;
        plan_desc[index] = desc;
        size++;
        index++;
    }

    if (index >= MAX_SIZE) {
        cout << "Reached max system capacity for plan array, any remaining data will be truncated\n";
    }

    plan_file.close();
}

void upload_member_plan_info(int plan_id[], int member_id[], int duration[], int &size) {
    // added m to in-function variables to let them be different
    fstream member_plan_file;
    int mplan_id, mmember_id, index=0;
    int mduration;
    size = 0;

    member_plan_file.open("member_plan.txt", std::ios::in);

    if (!member_plan_file) {
        ofstream create("member_plan.txt");
        create.close();
        member_plan_file.open("member_plan.txt", std::ios::in);
    }

    while (member_plan_file >> mplan_id >> mmember_id >> mduration && index < MAX_SIZE) {
        plan_id[index] = mplan_id;
        member_id[index] = mmember_id;
        duration[index] = mduration;
        size++;
        index++;
    }

    if (index >= MAX_SIZE) {
        cout << "Reached max system capacity for member-plan array, any remaining data will be truncated\n";
    }

    member_plan_file.close();
}

void upload_trainer_member_info(int trainer_id[], int member_id[], int &size) {
    fstream trainer_member_file;
    int mtrainer_id, mmember_id, index=0;
    size = 0;

    trainer_member_file.open("trainer_member.txt", std::ios::in);

    if (!trainer_member_file) {
        ofstream create("trainer_member.txt");
        create.close();
        trainer_member_file.open("trainer_member.txt", std::ios::in);
    }

    while (trainer_member_file >> mtrainer_id >> mmember_id && index < MAX_SIZE) {
        trainer_id[index] = mtrainer_id;
        member_id[index] = mmember_id;
        size++;
        index++;
        }

    if (index >= MAX_SIZE) {
        cout << "Reached max system capacity for trainer-member array, any remaining data will be truncated\n";
    }

    trainer_member_file.close();
}

void update_member_file(int member_id[], string member_name[], int member_phone[], int member_birth[], int size) {
    fstream member_file;

    member_file.open("member.txt", ios::out);

    for (int i = 0; i < size; i++) {
        member_file << member_id[i] << " " << member_name[i] << " " << member_phone[i] << " " << member_birth[i] << endl;
    }

    member_file.close();
}

void update_member_plan_file(int plan_id[], int member_id[], int duration[], int size) {
    fstream member_plan_file;

    member_plan_file.open("member_plan.txt", ios::out);

    for (int i = 0; i < size; i++) {
        member_plan_file << plan_id[i] << " " << member_id[i] << " " << duration[i] << endl;
    }

    member_plan_file.close();
}

void update_trainer_member_file(int trainer_id[], int member_id[], int size) {
    fstream trainer_member_file;

    trainer_member_file.open("trainer_member.txt", ios::out);

    for (int i = 0; i < size; i++) {
        trainer_member_file << trainer_id[i] << " " << member_id[i] << endl;
    }
    
    trainer_member_file.close();
}

void print_member_info(int member_id[], string member_name[], int member_phone[], int member_birth[], int size) {
    cout << left << setw(15) << "Member ID:" << setw(16) << "Member Name:" << setw(15) << "Member phone:" << setw(15) << "Member Birthdate:" << endl;
    for (int i = 0; i < size; i++) {
        cout << setw(15) << member_id[i] << setw(16) << member_name[i] << setw(15) << member_phone[i] << setw(15) << member_birth[i] << endl;
    }
}

void search_member(int member_id[], string member_name[], int member_phone[], int member_birth[], int size) {
    int id;
    cout << "Write the ID of the member: ";
    cin >> id;

    for (int i = 0; i < size; i++) {
        if (member_id[i] == id) {
            cout << "Member ID:        " << member_id[i] << endl
                << "Member Name:      " << member_name[i] << endl
                << "Member Phone:     " << member_phone[i] << endl
                << "Member Birthdate: " << member_birth[i] << endl;
            return;
        }
    }

    cout << "Couldn't find this user in the system.\n";
    return; 
}

void assign_plan(int plan_id[], int plans_id[], int member_id[], int members_id[], int duration[], int &size, int member_size, int plan_size) {
    int member, plan, mduration;
    bool member_found = false, plan_found = false;
    
    if (size >= MAX_SIZE) {
        cout << "Sorry you can't assign anymore plans. consider increasing system limit.\n\n";
        return;
    }

    cout << "Enter member you want to assign a plan to: ";
    cin >> member;

    for (int i = 0; i < member_size; i++) {
        if (member == members_id[i]) {
            member_found = true;
            break;
        }
    }

    if (!member_found) {
        cout << "Sorry this member doesn't exist, add him first to assign a plan.\n\n";
        return;
    }

    cout << "Enter the plan you want to assign: ";
    cin >> plan;

    for (int i = 0; i < plan_size; i++) {
        if (plan == plans_id[i]) {
            plan_found = true;
            break;
        }
    }

    if (!plan_found) {
        cout << "Sorry this plan doesn't exist.\n\n";
        return;
    }

    for (int i = 0; i < size; i++) {
        if (plan == plan_id[i] && member == member_id[i]) {
            cout << "This member was already assigned this plan.\n\n";
            return;
        }
    }
    
    cout << "Enter duration in days: ";
    cin >> mduration;

    plan_id[size] = plan;
    member_id[size] = member;
    duration[size] = mduration;
    size++;

    cout << "Plan Assigned to the member.\n\n";
    return;

}

void assign_trainer(int trainer_id[], int trainers_id[], int member_id[], int members_id[], int &size, int trainer_size, int member_size) {
    int member, trainer;
    bool member_found = false, trainer_found = false;
    
    if (size >= MAX_SIZE) {
        cout << "Sorry you can't assign anymore trainers. consider increasing system limit.\n\n";
        return;
    }

    cout << "Enter member you want to assign a trainer to: ";
    cin >> member;

    for (int i = 0; i < member_size; i++) {
        if (member == members_id[i]) {
            member_found = true;
            break;
        }
    }

    if (!member_found) {
        cout << "Sorry this member doesn't exist, add him first to assign a trainer.\n\n";
        return;
    }

    cout << "Enter the trainer you want to assign: ";
    cin >> trainer;

    for (int i = 0; i < trainer_size; i++) {
        if (trainer == trainers_id[i]) {
            trainer_found = true;
            break;
        }
    }

    if (!trainer_found) {
        cout << "Sorry this trainer doesn't exist.\n\n";
        return;
    }

    for (int i = 0; i < size; i++) {
        if (trainer == trainer_id[i] && member == member_id[i]) {
            cout << "This member was already assigned this trainer.\n\n";
            return;
        }
    }

    trainer_id[size] = trainer;
    member_id[size] = member;
    size++;

    cout << "Trainer Assigned to the member.\n\n";
    return;
}

void delete_member(int member_id[], string member_name[], int member_phone[], int member_birth[], int &member_size,
                   int trainer_id[], int trainer_member_id[], int &trainer_member_size,
                   int plan_id[], int member_plan_id[], int duration[], int &member_plan_size) {
    int id;
    cout << "Enter the ID of the member you want to delete: ";
    cin >> id;
    for (int i = 0; i < member_size; i++) {
        // This loses ordering, but nothing depends on order so it still works
        // Left shifting by 1 has higher time complexity
        if (member_id[i] == id) {
            // member file deletion
            member_size--;
            member_id[i] = member_id[member_size];
            member_name[i] = member_name[member_size];
            member_phone[i] = member_phone[member_size];
            member_birth[i] = member_birth[member_size];
            // trainer member file deletion
            for (int j = 0; j < trainer_member_size; j++) {
                if (trainer_member_id[j] == id) {
                    --trainer_member_size;
                    trainer_id[j] = trainer_id[trainer_member_size];
                    trainer_member_id[j] = trainer_member_id[trainer_member_size];
                    j--;
                }
            }
            // plan member file deletion
            for (int j = 0; j < member_plan_size; j++) {
                if (member_plan_id[j] == id) {
                    --member_plan_size;
                    plan_id[j] = plan_id[member_plan_size];
                    member_plan_id[j] = member_plan_id[member_plan_size];
                    duration[j] = duration[member_plan_size];
                    j--;
                }
            }
            cout << "Successfully deleted the member.\n";
            return;
        }
    }
    cout << "Couldn't find a member with that ID.\n";
}
