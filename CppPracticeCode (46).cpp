#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <memory>
#include <unordered_map>
#include <algorithm>
#include <iomanip>
#include <ctime>

using namespace std;

class Employee {
protected:
    string name;
    int employeeNumber;
    double payPerDay;
    unordered_map<string, bool> attendanceRecords;  // Map to track attendance per date

public:
    Employee(const string& name, int empNumber, double payPerDay)
        : name(name), employeeNumber(empNumber), payPerDay(payPerDay) {}

    void markAttendance(const string& date, bool present) {
        attendanceRecords[date] = present;
    }

    void resetAttendance() {
        attendanceRecords.clear();
    }

    double calculatePay() const {
        double totalPay = 0.0;
        for (const auto& record : attendanceRecords) {
            if (record.second) {
                totalPay += payPerDay;
            }
        }
        return totalPay;
    }

    string getName() const {
        return name;
    }

    int getEmployeeNumber() const {
        return employeeNumber;
    }

    bool isPresent(const string& date) const {
        auto it = attendanceRecords.find(date);
        return (it != attendanceRecords.end()) ? it->second : false;
    }

    virtual string getSection() const = 0;
    virtual ~Employee() = default; // Use default destructor
};

class Teacher : public Employee {
public:
    Teacher(const string& name, int empNumber, double payPerDay)
        : Employee(name, empNumber, payPerDay) {}

    string getSection() const override {
        return "Teacher";
    }
};

class Admin : public Employee {
public:
    Admin(const string& name, int empNumber, double payPerDay)
        : Employee(name, empNumber, payPerDay) {}

    string getSection() const override {
        return "Admin";
    }
};

class Cleaner : public Employee {
public:
    Cleaner(const string& name, int empNumber, double payPerDay)
        : Employee(name, empNumber, payPerDay) {}

    string getSection() const override {
        return "Cleaner";
    }
};

class HRManagement {
private:
    vector<unique_ptr<Employee>> employees;  // Use unique_ptr to manage memory automatically
    unordered_map<int, Employee*> employeeMap;  // Map to access employees by number
    unordered_map<string, unordered_set<int>> holidayPayments;  // Map for holidays and employee numbers

    string getCurrentDate() const {
        time_t now = time(0);
        tm* ltm = localtime(&now);
        char date[11];
        snprintf(date, sizeof(date), "%d-%02d-%02d", ltm->tm_year + 1900, ltm->tm_mon + 1, ltm->tm_mday);
        return string(date);
    }

    void sortEmployees() {
        sort(employees.begin(), employees.end(),
            [](const unique_ptr<Employee>& a, const unique_ptr<Employee>& b) {
                return a->getEmployeeNumber() < b->getEmployeeNumber();
            });
    }

public:
    HRManagement() = default;

    void addEmployee(unique_ptr<Employee> employee) {
        int empNumber = employee->getEmployeeNumber();
        employees.push_back(move(employee));
        employeeMap[empNumber] = employees.back().get();
    }

    void markAttendance(const vector<int>& presentEmployeeNumbers) {
        string date = getCurrentDate();
        unordered_map<int, bool> presentMap(presentEmployeeNumbers.begin(), presentEmployeeNumbers.end());
        
        for (const auto& [empNumber, employee] : employeeMap) {
            bool present = presentMap.find(empNumber) != presentMap.end();
            employee->markAttendance(date, present);
        }
    }

    void addOrUpdateAttendance(const string& date, const vector<pair<int, bool>>& attendanceUpdates) {
        for (const auto& [empNumber, present] : attendanceUpdates) {
            auto it = employeeMap.find(empNumber);
            if (it != employeeMap.end()) {
                it->second->markAttendance(date, present);
            } else {
                cout << "Employee number " << empNumber << " not found.\n";
            }
        }
    }

    void resetAllAttendance() {
        for (const auto& employee : employees) {
            employee->resetAttendance();
        }
    }

    void handleHolidayPayments() {
        string holidayDate;
        cout << "Enter the date of the official holiday (YYYY-MM-DD): ";
        cin >> holidayDate;
        
        char choice;
        cout << "Do you want to pay employees during the holiday? (y/n): ";
        cin >> choice;

        if (choice == 'y' || choice == 'Y') {
            unordered_set<int> employeeNumbers;
            cout << "Enter employee numbers to pay during the holiday (end with -1): ";
            int empNumber;
            while (cin >> empNumber && empNumber != -1) {
                employeeNumbers.insert(empNumber);
            }
            holidayPayments[holidayDate] = employeeNumbers;
        }
    }

    void saveRecordsToCSV(const string& filename) const {
        ofstream file(filename);
        if (file.is_open()) {
            string currentDate = getCurrentDate();
            file << "Employee Number,Section,Name,Attendance\n";
            file << "Date: " << currentDate << "\n";
            file << "Employee Number,Name,Section,Attendance\n";
            for (const auto& employee : employees) {
                file << employee->getEmployeeNumber() << ","
                     << employee->getName() << ","
                     << employee->getSection() << ","
                     << (employee->isPresent(currentDate) ? "Present" : "Absent") << "\n";
            }
            file << "\n";
            file << "Employee Number,Name,Section,Pay\n";
            for (const auto& employee : employees) {
                file << employee->getEmployeeNumber() << ","
                     << employee->getName() << ","
                     << employee->getSection() << ","
                     << employee->calculatePay() << "\n";
            }
            file << "\n";
            file << "Holiday Payments:\n";
            for (const auto& [holidayDate, empNumbers] : holidayPayments) {
                file << "Holiday Date: " << holidayDate << "\n";
                file << "Employee Numbers:\n";
                for (int empNumber : empNumbers) {
                    file << empNumber << "\n";
                }
            }
            file.close();
            cout << "Records successfully saved to " << filename << endl;
        } else {
            cerr << "Error: Unable to open file " << filename << endl;
        }
    }

    void displayRecords() const {
        string currentDate = getCurrentDate();
        cout << "Employee Number,Name,Section,Attendance\n";
        for (const auto& employee : employees) {
            cout << employee->getEmployeeNumber() << ","
                 << employee->getName() << ","
                 << employee->getSection() << ","
                 << (employee->isPresent(currentDate) ? "Present" : "Absent") << "\n";
        }
        cout << "\n";
        cout << "Employee Number,Name,Section,Pay\n";
        for (const auto& employee : employees) {
            cout << employee->getEmployeeNumber() << ","
                 << employee->getName() << ","
                 << employee->getSection() << ","
                 << employee->calculatePay() << "\n";
        }
        cout << "\n";
        cout << "Holiday Payments:\n";
        for (const auto& [holidayDate, empNumbers] : holidayPayments) {
            cout << "Holiday Date: " << holidayDate << "\n";
            cout << "Employee Numbers:\n";
            for (int empNumber : empNumbers) {
                cout << empNumber << "\n";
            }
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

        int empNumber = i + 1;  // Assign employee number starting from 1
        
        if (section == "Teacher") {
            hr.addEmployee(make_unique<Teacher>(name, empNumber, payPerDay));
        } else if (section == "Admin") {
            hr.addEmployee(make_unique<Admin>(name, empNumber, payPerDay));
        } else if (section == "Cleaner") {
            hr.addEmployee(make_unique<Cleaner>(name, empNumber, payPerDay));
        } else {
            cout << "Invalid section. Skipping employee." << endl;
        }
    }

    // Sort employees by their employee number
    hr.sortEmployees();

    vector<int> presentEmployeeNumbers;
    cout << "Enter employee numbers present today (end with -1): ";
    int empNumber;
    while (cin >> empNumber && empNumber != -1) {
        presentEmployeeNumbers.push_back(empNumber);
    }

    hr.markAttendance(presentEmployeeNumbers);

    // Handle previous attendance updates
    char updateChoice;
    cout << "Do you want to enter or update previous attendance? (y/n): ";
    cin >> updateChoice;
    if (updateChoice == 'y' || updateChoice == 'Y') {
        string date;
        cout << "Enter the date for attendance update (YYYY-MM-DD): ";
        cin >> date;
        
        vector<pair<int, bool>> updates;
        cout << "Enter employee numbers and their attendance (1 for present, 0 for absent), end with -1:\n";
        while (cin >> empNumber && empNumber != -1) {
            bool present;
            cin >> present;
            updates.emplace_back(empNumber, present);
        }
        hr.addOrUpdateAttendance(date, updates);
    }

    // Handle holiday payments
    hr.handleHolidayPayments();

    hr.displayRecords();

    // Saving records to CSV
    hr.saveRecordsToCSV("employees.csv");

    return 0;
}

