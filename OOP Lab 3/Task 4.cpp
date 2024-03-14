#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Task {
public:
   string description;
   bool completed;
   Task(string desc) : description(desc), completed(false) {}
};

class ToDoList {
   vector<Task*> tasks;
public:
   void addTask(const string& desc) {
       tasks.push_back(new Task(desc));
   }

   void listTasks() {
       if (tasks.empty()) {
           cout << "No tasks found." << endl;
       }
       else {
           cout << "Tasks:" << endl;
           for (size_t i = 0; i < tasks.size(); ++i) {
               cout << i + 1 << ". " << tasks[i]->description;
               if (tasks[i]->completed) {
                   cout << " (Completed)";
               }
               cout << endl;
           }
       }
   }

   void completeTask(size_t index) {
       if (index >= 1 && index <= tasks.size()) {
           tasks[index - 1]->completed = true;
           cout << "Task marked as completed: " << tasks[index - 1]->description << endl;
       }
       else {
           cout << "Invalid task index." << endl;
       }
   }

   ~ToDoList() {
       for (auto& task : tasks) {
           delete task;
       }
   }
};

int main() {
   ToDoList myList;

   int choice;
   do {
       cout << "1. Add Task\n";
       cout << "2. List Tasks\n";
       cout << "3. Mark Task as Completed\n";
       cout << "4. Exit\n";
       cout << "Enter your choice: ";
       cin >> choice;

       switch (choice) {
       case 1:
       {
           cin.ignore();
           string taskDescription;
           cout << "Enter task description: ";
           getline(cin, taskDescription);
           myList.addTask(taskDescription);
           cout << "Task added successfully." << endl;
           break;
       }
       case 2:
           myList.listTasks();
           break;
       case 3:
       {
           size_t index;
           cout << "\nEnter the index of the task to mark as completed: ";
           cin >> index;
           myList.completeTask(index);
           break;
       }
       case 4:
           cout << "Exiting program." << endl;
           break;
       default:
           cout << "Invalid choice. Please try again." << endl;
       }
   } while (choice != 4);

   return 0;
}
