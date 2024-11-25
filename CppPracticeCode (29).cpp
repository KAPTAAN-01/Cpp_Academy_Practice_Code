#include <iostream>
#include <deque>
#include <algorithm>
#include <string>
#include <limits>

using namespace std;

struct Task {
    string name;
    int priority;
    string status;

    Task(const string& name, int priority) : name(name), priority(priority), status("Pending") {}
};

class TaskScheduler {
private:
    deque<Task> tasks;

public:
    void addTask(const string& name, int priority) {
        tasks.emplace_back(name, priority);
        cout << "Task added: " << name << " with priority " << priority << ".\n";
    }

    void executeNextTask() {
        if (tasks.empty()) {
            cout << "No tasks to execute.\n";
            return;
        }
        Task& nextTask = tasks.front();
        nextTask.status = "In Progress";
        cout << "Executing task: " << nextTask.name << " with priority " << nextTask.priority << ".\n";
        nextTask.status = "Completed";
        cout << "Task " << nextTask.name << " is now completed.\n";
        tasks.pop_front();
    }

    void removeTask(const string& name) {
        auto it = find_if(tasks.begin(), tasks.end(), [&](const Task& task) {
            return task.name == name;
        });

        if (it != tasks.end()) {
            cout << "Removing task: " << it->name << ".\n";
            tasks.erase(it);
        } else {
            cout << "Task '" << name << "' not found.\n";
        }
    }

    void displayTasks() const {
        if (tasks.empty()) {
            cout << "No tasks to display.\n";
            return;
        }
        cout << "Current tasks:\n";
        for (const auto& task : tasks) {
            cout << "Task: " << task.name << ", Priority: " << task.priority << ", Status: " << task.status << "\n";
        }
    }
};

int getMenuChoice() {
    int choice;
    for (;;) {
        cout << "\nMenu:\n1. Add Task\n2. Execute Next Task\n3. Remove Task by Name\n4. Display All Tasks\n5. Exit\nChoose an option: ";
        if (cin >> choice) break;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid option. Please choose a number: ";
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return choice;
}

int getPriority() {
    int priority;
    for (int i = 0; i < 3; i++) {
        cout << "Enter task priority: ";
        if (cin >> priority) break;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid priority. Please enter an integer: ";
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return priority;
}

int main() {
    TaskScheduler scheduler;
    for (;;) {
        int choice = getMenuChoice();
        if (choice == 1) {
            string name;
            int priority = getPriority();
            cout << "Enter task name: ";
            getline(cin, name);
            scheduler.addTask(name, priority);
        } else if (choice == 2) {
            scheduler.executeNextTask();
        } else if (choice == 3) {
            string name;
            cout << "Enter task name to remove: ";
            getline(cin, name);
            scheduler.removeTask(name);
        } else if (choice == 4) {
            scheduler.displayTasks();
        } else if (choice == 5) {
            cout << "Exiting program.\n";
            break;
        } else {
            cout << "Invalid option.\n";
        }
    }
    return 0;
}
