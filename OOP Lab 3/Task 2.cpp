#include <iostream>
#include <map>
#include <string>

using namespace std;


void displayMenu() {
    cout << "1. Add a contact\n";
    cout << "2. Search for a contact\n";
    cout << "3. Display all contacts\n";
    cout << "4. Exit\n";
}
int main() {
    map<string, string> contacts;
    int choice;
    string name, details;

    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter contact name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter contact details: ";
            getline(cin, details);
            contacts[name] = details;
            cout << "Contact added.\n";
        }
        else if (choice == 2) {
            cout << "Enter contact name to search: ";
            cin.ignore();
            getline(cin, name);
            if (contacts.find(name) != contacts.end()) {
                cout << "Contact details: " << contacts[name] << endl;
            }
            else {
                cout << "Contact not found.\n";
            }
        }
        else if (choice == 3) {
            cout << "All contacts:\n";
            for (auto const& pair : contacts) {
                cout << pair.first << ": " << pair.second << endl;
            }
        }
        else if (choice == 4) {
            cout << "Exiting program.\n";
        }
        else
            cout << "Invalid choice. Please try again.\n";
    } while (choice != 4);

    return 0;
}
