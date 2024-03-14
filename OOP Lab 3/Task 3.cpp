#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Student {
   int id;
   string name;
   char grade;
   Student(int i, string n, char g) : id(i), name(n), grade(g) {}
};

class StudentManager {
private:
   vector<Student*> records;
public:
   void addStudent(int id, string name, char grade) {
       Student* newStudent = new Student(id, name, grade);
       records.push_back(newStudent);
   }

   void updateGrade(int id, float newGrade) {
       bool found = false;
       for (Student* student : records) {
           if (student->id == id) {
               student->grade = newGrade;
               found = true;
               break;
           }
       }
       if (!found) {
           cout << "Student ID not found." << endl;
       }
   }

   void displayRecords() {
       if (records.empty()) {
           cout << "No student records found." << endl;
           return;
       }
       for (const Student* student : records) {
           cout << "ID: " << student->id << ", Name: " << student->name << ", Grade: " << student->grade << endl;
       }
   }

   ~StudentManager() {
       for (Student* student : records) {
           delete student;
       }
   }
};

int main() {
   StudentManager sm;
   int choice;

   do {
       cout << "\nStudent Record Management System\n";
       cout << "1. Add Student Record\n";
       cout << "2. Update Student Grade\n";
       cout << "3. Display All Student Records\n";
       cout << "4. Exit\n";
       cout << "Enter your choice: ";
       cin >> choice;

       switch (choice) {
       case 1:
       {
           int id;
           string name;
           char grade;
           cout << "Enter student ID: ";
           cin >> id;
           cout << "Enter student name: ";
           cin.ignore();
           getline(cin, name);
           cout << "Enter student grade: ";
           cin >> grade;
           sm.addStudent(id, name, grade);
           cout << "Student record added successfully." << endl;
           break;
       }
       case 2:
       {
           int id;
           char newGrade;
           cout << "Enter student ID: ";
           cin >> id;
           cout << "Enter new grade: ";
           cin >> newGrade;
           sm.updateGrade(id, newGrade);
           break;
       }
       case 3:
           sm.displayRecords();
           break;
       case 4:
           cout << "Exiting program." << endl;
           break;
       default:
           cout << "Invalid choice. Please try again." << endl;
       }
   } while (choice != 4);

   return 0;
}
