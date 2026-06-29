#include <iostream>
#include <vector>
using namespace std;
struct Contact {
    string name;
    string phone;
    string email;
};
int main() {
    vector<Contact> contacts;
    int choice;
    do {
        cout << "\n===== Contact Management System =====\n";
        cout << "1. Add Contact\n";
        cout << "2. View Contacts\n";
        cout << "3. Edit Contact\n";
        cout << "4. Delete Contact\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();
        switch (choice) {
        case 1: {
            Contact c;
            cout << "Enter Name: ";
            getline(cin, c.name);
            cout << "Enter Phone Number: ";
            getline(cin, c.phone);
            cout << "Enter Email: ";
            getline(cin, c.email);
            contacts.push_back(c);
            cout << "Contact Added Successfully!\n";
            break;
        }

        case 2: {
            if (contacts.empty()) {
                cout << "No Contacts Found!\n";
            } else {
                cout << "\n----- Contact List -----\n";
                for (int i = 0; i < contacts.size(); i++) {
                    cout << "\nContact " << i + 1 << endl;
                    cout << "Name : " << contacts[i].name << endl;
                    cout << "Phone: " << contacts[i].phone << endl;
                    cout << "Email: " << contacts[i].email << endl;
                }
            }
            break;
        }

        case 3: {
            int index;
            cout << "Enter Contact Number to Edit: ";
            cin >> index;
            cin.ignore();
            if (index > 0 && index <= contacts.size()) {
                cout << "Enter New Name: ";
                getline(cin, contacts[index - 1].name);

                cout << "Enter New Phone Number: ";
                getline(cin, contacts[index - 1].phone);

                cout << "Enter New Email: ";
                getline(cin, contacts[index - 1].email);

                cout << "Contact Updated Successfully!\n";
            } else {
                cout << "Invalid Contact Number!\n";
            }
            break;
        }
        case 4: {
            int index;
            cout << "Enter Contact Number to Delete: ";
            cin >> index;
            if (index > 0 && index <= contacts.size()) {
                contacts.erase(contacts.begin() + index - 1);
                cout << "Contact Deleted Successfully!\n";
            } else {
                cout << "Invalid Contact Number!\n";
            }
            break;
        }
        case 5:
            cout << "Thank You for Using Contact Management System!\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }

    } while (choice != 5);

    return 0;
}