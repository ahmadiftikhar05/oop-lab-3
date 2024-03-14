#include <vector>
#include <iostream>

using namespace std;

void displayMenu() {
    cout << "1. Add a student grade\n";
    cout << "2. Display all student grades\n";
    cout << "3. Exit\n";
}

int main() {
    vector<char> studentGrades;
    int choice;
    char grade;

    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
           cout << "Enter student grade: ";
            cin >> grade;
            studentGrades.push_back(grade);
            cout << "Student grade added.\n";
           break;
        case 2:
            cout << "Student grades:\n";
          for (int i = 0; i < studentGrades.size(); ++i) {
              cout << "Student " << (i + 1) << ": " << studentGrades[i] << endl;
          }
           break;
       case 3:
            cout << "Exiting program.\n";
            break;
        default:
           cout << "Invalid choice. Please try again.\n";
       }
    } while (choice != 3);

    return 0;
}