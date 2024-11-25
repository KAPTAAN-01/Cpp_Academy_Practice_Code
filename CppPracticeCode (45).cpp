#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <memory>

using namespace std;

class Employee {
protected:
    string name;
    int attendance;
    double payPerDay;
public:
    Employee(const string& name, double payPerDay) : name(name), attendance(0), payPerDay(payPerDay) {}

    void markAttendance() {
        attendance++;
    }

    void resetAttendance() {
        attendance = 0;
    }

    double calculatePay() const {
        return attendance * payPerDay;
    }

    string getName() const {
        return name;
    }

    int getAttendance() const {
        return attendance;
    }

    virtual string getSection() const = 0;
    virtual ~Employee() = default; // Use default destructor
};

class Teacher : public Employee {
public:
    Teacher(const string& name, double payPerDay) : Employee(name, payPerDay) {}

    string getSection() const override {
        return "Teacher";
    }
};

class Admin : public Employee {
public:
    Admin(const string& name, double payPerDay) : Employee(name, payPerDay) {}

    string getSection() const override {
        return "Admin";
    }
};

class Cleaner : public Employee {
public:
    Cleaner(const string& name, double payPerDay) : Employee(name, payPerDay) {}

    string getSection() const override {
        return "Cleaner";
    }
};

class HRManagement {
private:
    vector<unique_ptr<Employee>> employees;  // Use unique_ptr to manage memory automatically
public:
    HRManagement() = default;

    void addEmployee(unique_ptr<Employee> employee) {
        employees.push_back(move(employee));
    }

    void markAttendance(const string& name) {
        bool found = false;
        for (const auto& employee : employees) {
            if (employee->getName() == name) {
                employee->markAttendance();
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Employee with name \"" << name << "\" not found." << endl;
        }
    }

    void resetAllAttendance() {
        for (const auto& employee : employees) {
            employee->resetAttendance();
        }
    }

    void saveRecordsToCSV(const string& filename) const {
        ofstream file(filename);
        if (file.is_open()) {
            file << "Section,Name,Attendance,Pay\n";
            for (const auto& employee : employees) {
                file << employee->getSection() << ","
                     << employee->getName() << ","
                     << employee->getAttendance() << ","
                     << employee->calculatePay() << "\n";
            }
            file.close();
            cout << "Records successfully saved to " << filename << endl;
        } else {
            cerr << "Error: Unable to open file " << filename << endl;
        }
    }

    void displayRecords() const {
        cout << "Section,Name,Attendance,Pay\n";
        for (const auto& employee : employees) {
            cout << employee->getSection() << ","
                 << employee->getName() << ","
                 << employee->getAttendance() << ","
                 << employee->calculatePay() << "\n";
        }
    }

    // Rule of five: Destructor, copy/move constructors, and assignment operators.
    ~HRManagement() = default;
    HRManagement(const HRManagement&) = delete;
    HRManagement& operator=(const HRManagement&) = delete;
    HRManagement(HRManagement&&) = default;
    HRManagement& operator=(HRManagement&&) = default;
};

int main() {
    HRManagement hr;

    int numEmployees;
    cout << "Enter the number of employees: ";
    cin >> numEmployees;

    for (int i = 0; i < numEmployees; i++) {
        string name, section;
        double payPerDay;
        cout << "Enter employee name: ";
        cin >> ws;  // Consume any leading whitespace
        getline(cin, name);
        cout << "Enter pay per day: ";
        cin >> payPerDay;
        cout << "Enter section (Teacher/Admin/Cleaner): ";
        cin >> ws;  // Consume any leading whitespace
        getline(cin, section);
        
        if (section == "Teacher") {
            hr.addEmployee(make_unique<Teacher>(name, payPerDay));
        } else if (section == "Admin") {
            hr.addEmployee(make_unique<Admin>(name, payPerDay));
        } else if (section == "Cleaner") {
            hr.addEmployee(make_unique<Cleaner>(name, payPerDay));
        } else {
            cout << "Invalid section. Skipping employee." << endl;
        }
    }

    int numAttendances;
    cout << "Enter the number of attendance markings: ";
    cin >> numAttendances;

    for (int i = 0; i < numAttendances; ++i) {
        string name;
        cout << "Enter employee name to mark attendance: ";
        cin >> ws;  
        getline(cin, name);
        hr.markAttendance(name);
    }

    hr.displayRecords();

    hr.saveRecordsToCSV("employees.csv");

    return 0;
}

