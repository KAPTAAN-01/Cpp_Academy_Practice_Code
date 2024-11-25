#include <iostream>
#include <fstream>
#include <limits>
#include <vector>
#include <string>
#include <memory>
#include <unordered_map>
#include <algorithm>
#include <iomanip>
#include <ctime>
#include <sstream>
#include <numeric>
#include <unordered_set>
#include <iostream>


using namespace std;
 
class admissionform {
private:
    string name;
    string dateofbirth;
    string gender;
    string age;
    string cnicnumber;
    string fathername;
    string fcnicnumber;
    string adress;
    string phonenumber;
    string email;
    string schoolname;
    string matricmarks;

public:
    void fillform() {
        cout << "STUDENT NAME : ";
        cin >> ws;
        getline(cin, name);

        cout << "BIRTH DATE OF STUDENT IN FORMAT (DD/MM/YYYY): ";
        cin >> ws;
        getline(cin, dateofbirth);

        cout << "STUDENT GENDER : ";
        cin >> ws;
        getline(cin, gender);

        cout << "STUDENT AGE : ";
        cin >> ws;
        getline(cin, age);

        cout << "STUDENT CNIC NUMBER : ";
        cin >> ws;
        getline(cin, cnicnumber);

        cout << "FATHER NAME : ";
        cin >> ws;
        getline(cin, fathername);

        cout << "CNIC NUMBER OF STUDENT'S FATHER : ";
        cin >> ws;
        getline(cin, fcnicnumber);

        cout << "ADDRESS : ";
        cin >> ws;
        getline(cin, adress);

        cout << "CONTACT NUMBER : ";
        cin >> ws;
        getline(cin, phonenumber);

        cout << "STUDENT EMAIL : ";
        cin >> ws;
        getline(cin, email);

        cout << "PREVIOUS SCHOOL NAME : ";
        cin >> ws;
        getline(cin, schoolname);

        cout << "MARKS OF MATRIC : ";
        cin >> ws;
        getline(cin, matricmarks);
    }

    // Function to display admission form
    void displayform() {
        cout << "Admission Form of a student" << endl;
        cout << "---------------------------" << endl;
        cout << "NAME OF STUDENT : " << name << endl;
        cout << "DATE OF BIRTH : " << dateofbirth << endl;
        cout << "GENDER : " << gender << endl;
        cout << "AGE : " << age << endl;
        cout << "CNIC NUMBER OF STUDENT : " << cnicnumber << endl;
        cout << "NAME OF STUDENT'S FATHER : " << fathername << endl;
        cout << "CNIC NUMBER OF STUDENT'S FATHER : " << fcnicnumber << endl;
        cout << "ADDRESS : " << adress << endl;
        cout << "CONTACT NUMBER : " << phonenumber << endl;
        cout << "EMAIL : " << email << endl;
        cout << "PREVIOUS SCHOOL NAME : " << schoolname << endl;
        cout << "MARKS OF MATRIC EXAMS : " << matricmarks << endl;
    }

    // Method to save form data to a CSV file
  // Ensure file extension is .csv and correct formatting inside
void saveToFile() {
    ofstream file("admission_form.csv");
    if (file.is_open()) {
        // Write CSV header
        file << "Name,Age,Date of Birth,B Form No,Father's Name,Father's CNIC,Gender,Email,Past School,Address,Marks of Matric,Contact Number\n";

        // Write values in CSV format
        file << name << ","
             << age << ","
             << dateofbirth << ","
             << cnicnumber << ","
             << fathername << ","
             << fcnicnumber << ","
             << gender << ","
             << email << ","
             << schoolname << ","
             << adress << ","
             << matricmarks << ","
             << phonenumber << endl;

        file.close();
        cout << "\nForm data saved to admission_form.csv" << endl;
    } else {
        cout << "Unable to open file for saving." << endl;
    }
}

// Method to open CSV with Excel (change based on system)
void openFile() {
    cout << "\nOpening admission_form.csv using default application..." << endl;
    system("start excel.exe admission_form.csv");  // Windows command to open in Excel
}

};
 class Fees {
private:
    double fees;
    double discount;
    double finalFees;
    double installments;
    double perInstallmentFee;
    double extraFund;
    double totalFees;
    string name;

public:
    void account() {
    cout<<"ENTER THE NAME OF STUDENT : ";
    	cin>>name;
    cout << "ENTER THE ANNUAL FEES OF A STUDENT: ";
        cin >> fees;
    cout << endl;

    cout << "ENTER THE DISCOUNT PERCENTAGE OF A STUDENT: ";
        cin >> discount;
        double discountAmount = fees * discount / 100;
        finalFees = fees - discountAmount;
    cout << "STUDENT FINAL FEES: " << finalFees << endl;

    cout << "HOW MANY INSTALLMENTS YOU WANT: ";
        cin >> installments;
    cout << endl;
        perInstallmentFee = finalFees / installments;
    cout << "PER INSTALLMENT FEES OF A STUDENT: " << perInstallmentFee << endl;

    cout << "ENTER THE FEES OF NOTES AND OTHER THINGS: ";
        cin >> extraFund;
    cout << endl;
        totalFees = finalFees + extraFund;
    cout << "STUDENT FEES AFTER ADDING EXTRA FUNDS: " << totalFees << endl;

        saveToCSV();
    }

    void saveToCSV() {
        ofstream outFile("student_fees.csv", ios::app); // open file in append mode
        if (outFile.is_open()) {
            outFile << name << ","<< fees << "," << discount << "," << finalFees << "," << installments << "," << perInstallmentFee << "," << extraFund << "," << totalFees << endl;
            outFile.close();
            cout << "Data saved to student_fees.csv successfully." << endl;
        } else {
            cout << "Unable to open file." << endl;
        }
    }
};

 
const int DATE_COLUMNS = 31;

class Attendance {
private:
    string studentName;
    string fatherName;
    string rollNo;
    int finePerAbsent;

    // Static helper function to split a string by delimiter
    static vector<string> split(const string& line, char delimiter) {
        vector<string> tokens;
        stringstream ss(line);
        string item;
        while (getline(ss, item, delimiter)) {
            tokens.push_back(item);
        }
        return tokens;
    }

    // Helper function to count 'A' and 'P' in the attendance record
    void countAttendance(const vector<string>& records, int& countA, int& countP) {
        countA = countP = 0;
        for (size_t i = 5; i < records.size(); ++i) { // Skip first five columns
            if (records[i] == "A") {
                ++countA;
            } else if (records[i] == "P") {
                ++countP;
            }
        }
    }

    bool doesStudentExist() {
        ifstream file("students.csv");
        if (!file.is_open()) {
            cerr << "Error opening file." << endl;
            return false;
        }

        string line;
        while (getline(file, line)) {
            vector<string> records = split(line, ',');
            if (records.size() > 4 && records[0] == studentName && records[1] == fatherName && records[2] == rollNo) {
                file.close();
                return true;
            }
        }
        file.close();
        return false;
    }

    void sortStudentsByRollNo(vector<string>& lines) {
        sort(lines.begin(), lines.end(), [](const string& a, const string& b) {
            vector<string> recordsA = Attendance::split(a, ',');
            vector<string> recordsB = Attendance::split(b, ',');
            if (recordsA.size() > 2 && recordsB.size() > 2) {
                return recordsA[2] < recordsB[2];
            }
            return false;
        });
    }

    void writeCSVHeaders(ofstream& outfile) {
        outfile << "StudentName,FatherName,RollNo,Fine,StuckOff";
        for (int i = 1; i <= DATE_COLUMNS; ++i) {
            outfile << ",Date" << i;
        }
        outfile << endl;
    }

public:
    void createCSVWithHeaders() {
        const string CSV_FILENAME = "students.csv";
        ifstream infile(CSV_FILENAME);
        bool fileExists = infile.is_open();
        infile.close();

        ofstream outfile(CSV_FILENAME, ios::app);
        if (!outfile.is_open()) {
            cerr << "Unable to open file to write headers." << endl;
            return;
        }

        if (!fileExists) {
            writeCSVHeaders(outfile);
            cout << "CSV file created with headers." << endl;
        } else {
            string firstLine;
            if (getline(ifstream(CSV_FILENAME), firstLine)) {
                cout << "CSV file already has content." << endl;
            } else {
                writeCSVHeaders(outfile);
                cout << "Headers added to the empty CSV file." << endl;
            }
        }
        outfile.close();
    }

    void addStudent() {
        cout << "Enter Student Name: ";
        cin >> studentName;
        cout << "Enter Father's Name: ";
        cin >> fatherName;
        cout << "Enter Roll Number: ";
        cin >> rollNo;

        if (doesStudentExist()) {
            cout << "This student record already exists." << endl;
            return;
        }

        cout << "Enter fine amount per absent day: ";
        cin >> finePerAbsent;
        
        saveToCSV();
    }

    void markAttendance() {
        cout << "Enter Roll Number of the student to mark attendance: ";
        string rollNoToUpdate;
        cin >> rollNoToUpdate;

        ifstream infile("students.csv");
        if (!infile.is_open()) {
            cerr << "Error opening file." << endl;
            return;
        }

        vector<string> fileLines;
        string line;
        while (getline(infile, line)) {
            fileLines.push_back(line);
        }
        infile.close();

        ofstream outfile("students.csv");
        if (!outfile.is_open()) {
            cerr << "Error opening file for writing." << endl;
            return;
        }

        bool studentFound = false;
        for (auto& line : fileLines) {
            vector<string> records = split(line, ',');
            if (records.size() > 5 && records[2] == rollNoToUpdate) {
                studentFound = true;
                cout << "Enter the date (1-31) to mark attendance: ";
                int date;
                cin >> date;
                cout << "Enter 'P' for Present or 'A' for Absent: ";
                char status;
                cin >> status;

                if (date >= 1 && date <= 31 && (status == 'P' || status == 'A')) {
                    records[5 + date] = status;

                    int absences = 0;
                    for (size_t i = 5; i < records.size(); ++i) {
                        if (records[i] == "A") {
                            ++absences;
                        }
                    }

                    int fine = absences * finePerAbsent;
                    string stuckOff = absences >= 3 ? "Yes" : "No";

                    records[3] = to_string(fine);
                    records[4] = stuckOff;
                    
                    line.clear();
                    for (size_t i = 0; i < records.size(); ++i) {
                        if (i > 0) line += ",";
                        line += records[i];
                    }
                } else {
                    cout << "Invalid date or status." << endl;
                    return;
                }
            }
            outfile << line << endl;
        }

        if (studentFound) {
            cout << "Attendance updated successfully." << endl;
        } else {
            cout << "Student with Roll Number " << rollNoToUpdate << " not found." << endl;
        }

        outfile.close();
    }

    void viewAttendance() {
        cout << "Do you want to sort the records by Roll Number? (yes/no): ";
        string sortChoice;
        cin >> sortChoice;

        ifstream file("students.csv");
        if (!file.is_open()) {
            cerr << "Error opening file." << endl;
            return;
        }

        vector<string> fileLines;
        string line;
        while (getline(file, line)) {
            fileLines.push_back(line);
        }
        file.close();

        if (sortChoice == "yes") {
            sortStudentsByRollNo(fileLines);
        }

        ofstream outfile("students.csv");
        if (!outfile.is_open()) {
            cerr << "Error opening file for writing." << endl;
            return;
        }

        for (const auto& l : fileLines) {
            outfile << l << endl;
        }
        outfile.close();

        cout << "Attendance records:" << endl;
        for (const auto& l : fileLines) {
            cout << l << endl;
        }
    }

    void viewStudentAttendance() {
        ifstream file("students.csv");
        if (!file.is_open()) {
            cerr << "Error opening file." << endl;
            return;
        }

        cout << "Enter Roll Number of the student: ";
        string searchRollNo;
        cin >> searchRollNo;

        string line;
        while (getline(file, line)) {
            vector<string> records = split(line, ',');
            if (records.size() > 5 && records[2] == searchRollNo) {
                int countA, countP;
                countAttendance(records, countA, countP);
                cout << "Student Name: " << records[0] << endl;
                cout << "Father's Name: " << records[1] << endl;
                cout << "Total Absent Days (A): " << countA << endl;
                cout << "Total Present Days (P): " << countP << endl;
                cout << "Total Fine: " << records[3] << endl;
                cout << "Stuck Off: " << records[4] << endl;
                return;
            }
        }

        cout << "Student with Roll Number " << searchRollNo << " not found." << endl;
        file.close();
    }

    void saveToCSV() {
        ofstream outFile("students.csv", ios::app);
        if (outFile.is_open()) {
            outFile << studentName << "," << fatherName << "," << rollNo << ",0,No";
            for (int i = 1; i <= DATE_COLUMNS; ++i) {
                outFile << ",0";
            }
            outFile << endl;
            outFile.close();
            cout << "Data saved to students.csv successfully." << endl;
        } else {
            cerr << "Unable to open file." << endl;
        }
    }
};

class Testmang {
private:
    string studentName;
    string fatherName;
    string rollNo;
    int finePerAbsent;
    int fineForTestAbsent;
    const int DATE_COLUMNS = 31;

    // Static helper function to split a string by delimiter
    static vector<string> split(const string& line, char delimiter) {
        vector<string> tokens;
        stringstream ss(line);
        string item;
        while (getline(ss, item, delimiter)) {
            tokens.push_back(item);
        }
        return tokens;
    }

    // Helper function to count 'A' and 'P' in the attendance record
    void countAttendance(const vector<string>& records, int& countA, int& countP) {
        countA = countP = 0;
        for (size_t i = 5; i < records.size(); ++i) { // Skip first five columns
            if (records[i] == "A") {
                ++countA;
            } else if (records[i] == "P") {
                ++countP;
            }
        }
    }

    bool doesStudentExist() {
        ifstream file("students.csv");
        if (!file.is_open()) {
            cerr << "Error opening file." << endl;
            return false;
        }

        string line;
        while (getline(file, line)) {
            vector<string> records = split(line, ',');
            if (records.size() > 4 && records[0] == studentName && records[1] == fatherName && records[2] == rollNo) {
                file.close();
                return true;
            }
        }
        file.close();
        return false;
    }

    // Function to compare records by Roll Number (for sorting)
    static bool compareByRollNo(const string& a, const string& b) {
        vector<string> recordsA = split(a, ',');
        vector<string> recordsB = split(b, ',');
        if (recordsA.size() > 2 && recordsB.size() > 2) {
            return recordsA[2] < recordsB[2];
        }
        return false;
    }

    void sortStudentsByRollNo(vector<string>& lines) {
        sort(lines.begin(), lines.end(), compareByRollNo);
    }

    void writeCSVHeaders(ofstream& outfile) {
        outfile << "StudentName,FatherName,RollNo,Fine,StuckOff";
        for (int i = 1; i <= DATE_COLUMNS; ++i) {
            outfile << ",Date" << i;
        }
        outfile << ",TestScores" << endl;
    }

public:
    void createCSVWithHeaders() {
        const string CSV_FILENAME = "students.csv";
        ifstream infile("students.csv");
        bool fileExists = infile.is_open();
        infile.close();

        ofstream outfile("students_csv", ios::app);
        if (!outfile.is_open()) {
            cerr << "Unable to open file to write headers." << endl;
            return;
        }

        if (!fileExists) {
            writeCSVHeaders(outfile);
            cout << "CSV file created with headers." << endl;
        } else {
            string firstLine;
            ifstream infile("students.csv");
            if (infile.is_open() && getline(infile, firstLine)) {
                // File already has content; nothing to do
            }
            infile.close();
        }
        outfile.close();
    }

    void addStudent() {
        cout << "Enter Student Name: ";
        cin >> studentName;
        cout << "Enter Father's Name: ";
        cin >> fatherName;
        cout << "Enter Roll Number: ";
        cin >> rollNo;

        if (doesStudentExist()) {
            cout << "This student record already exists." << endl;
            return;
        }

        cout << "Enter fine amount per absent day: ";
        cin >> finePerAbsent;
        
        saveToCSV();
    }

    void markAttendance() {
        cout << "Enter Roll Number of the student to mark attendance: ";
        string rollNoToUpdate;
        cin >> rollNoToUpdate;

        ifstream infile("students.csv");
        if (!infile.is_open()) {
            cerr << "Error opening file." << endl;
            return;
        }

        vector<string> fileLines;
        string line;
        bool studentFound = false;
        while (getline(infile, line)) {
            vector<string> records = split(line, ',');
            if (records.size() > 2 && records[2] == rollNoToUpdate) {
                studentFound = true;
                cout << "Enter date (1-31): ";
                int date;
                cin >> date;
                cout << "Enter status (P/A): ";
                string status;
                cin >> status;
                if (date >= 1 && date <= DATE_COLUMNS && (status == "P" || status == "A")) {
                    records[4 + date] = status;
                    line.clear();
                    for (size_t i = 0; i < records.size(); ++i) {
                        if (i > 0) line += ",";
                        line += records[i];
                    }
                } else {
                    cout << "Invalid date or status." << endl;
                    return;
                }
            }
            fileLines.push_back(line);
        }
        infile.close();

        ofstream outfile("students.csv");
        if (!outfile.is_open()) {
            cerr << "Error opening file for writing." << endl;
            return;
        }

        for (const auto& fileLine : fileLines) {
            outfile << fileLine << endl;
        }

        if (studentFound) {
            cout << "Attendance updated successfully." << endl;
        } else {
            cout << "Student with Roll Number " << rollNoToUpdate << " not found." << endl;
        }

        outfile.close();
    }

    void viewAttendance() {
        cout << "Do you want to sort the records by Roll Number? (yes/no): ";
        string sortChoice;
        cin >> sortChoice;

        ifstream file("students.csv");
        if (!file.is_open()) {
            cerr << "Error opening file." << endl;
            return;
        }

        vector<string> fileLines;
        string line;
        while (getline(file, line)) {
            fileLines.push_back(line);
        }
        file.close();

        if (sortChoice == "yes") {
            sortStudentsByRollNo(fileLines);
        }

        ofstream outfile("students.csv");
        if (!outfile.is_open()) {
            cerr << "Error opening file for writing." << endl;
            return;
        }

        for (const auto& fileLine : fileLines) {
            outfile << fileLine << endl;
        }
        outfile.close();

        cout << "Attendance records:" << endl;
        for (const auto& fileLine : fileLines) {
            cout << fileLine << endl;
        }
    }

    void viewStudentAttendance() {
        cout << "Enter Roll Number of the student to view attendance: ";
        string searchRollNo;
        cin >> searchRollNo;

        ifstream file("students.csv");
        if (!file.is_open()) {
            cerr << "Error opening file." << endl;
            return;
        }

        string line;
        bool studentFound = false;
        while (getline(file, line)) {
            vector<string> records = split(line, ',');
            if (records.size() > 2 && records[2] == searchRollNo) {
                studentFound = true;
                cout << "Attendance record for " << records[0] << " (Roll No: " << records[2] << "):" << endl;
                for (size_t i = 5; i < records.size() - 1; ++i) { // Skip the last column (TestScores)
                    cout << "Date" << (i - 4) << ": " << records[i] << endl;
                }
                cout << "Test Scores: " << records.back() << endl;
                break;
            }
        }

        if (!studentFound) {
            cout << "Student with Roll Number " << searchRollNo << " not found." << endl;
        }

        file.close();
    }

    void markTestScores() {
        cout << "Enter Roll Number of the student to mark test scores: ";
        string rollNoToUpdate;
        cin >> rollNoToUpdate;

        cout << "Enter fine amount for being absent on test day: ";
        cin >> fineForTestAbsent;

        ifstream infile("students.csv");
        if (!infile.is_open()) {
            cerr << "Error opening file." << endl;
            return;
        }

        vector<string> fileLines;
        string line;
        bool studentFound = false;
        while (getline(infile, line)) {
            vector<string> records = split(line, ',');
            if (records.size() > 2 && records[2] == rollNoToUpdate) {
                studentFound = true;
                cout << "Enter test scores: ";
                string scores;
                cin >> scores;

                // Check if the student was absent on the test day
                bool wasAbsent = false;
                for (size_t i = 5; i < records.size() - 1; ++i) {
                    if (records[i] == "A") {
                        wasAbsent = true;
                        break;
                    }
                }

                if (wasAbsent) {
                    int currentFine = atoi(records[3].c_str());
                    currentFine += fineForTestAbsent;
                    records[3] = to_string(currentFine);
                }

                records.back() = scores;
                line.clear();
                for (size_t i = 0; i < records.size(); ++i) {
                    if (i > 0) line += ",";
                    line += records[i];
                }
            }
            fileLines.push_back(line);
        }
        infile.close();

        ofstream outfile("students.csv");
        if (!outfile.is_open()) {
            cerr << "Error opening file for writing." << endl;
            return;
        }

        for (const auto& fileLine : fileLines) {
            outfile << fileLine << endl;
        }

        if (studentFound) {
            cout << "Test scores and fines updated successfully." << endl;
        } else {
            cout << "Student with Roll Number " << rollNoToUpdate << " not found." << endl;
        }

        outfile.close();
    }

    void viewAllTestScores() {
        ifstream file("students.csv");
        if (!file.is_open()) {
            cerr << "Error opening file." << endl;
            return;
        }

        string line;
        cout << "Test Scores for all students:" << endl;
        while (getline(file, line)) {
            vector<string> records = split(line, ',');
            if (records.size() > 2) {
                cout << "Student: " << records[0] << " (Roll No: " << records[2] << ") - Test Scores: " << records.back() << endl;
            }
        }
        file.close();
    }

    void saveToCSV() {
        ofstream outFile("students.csv", ios::app);
        if (outFile.is_open()) {
            outFile << studentName << "," << fatherName << "," << rollNo << ",0,No";
            for (int i = 1; i <= DATE_COLUMNS; ++i) {
                outFile << ",0";
            }
            outFile << ",0" << endl; // Initialize TestScores with 0
            outFile.close();
            cout << "Data saved to students.csv successfully." << endl;
        } else {
            cerr << "Unable to open file." << endl;
        }
    }
};



class Employee {
protected:
    string name;
    int employeeNumber;
    double payPerDay;
    vector<string> attendanceRecords;  // Attendance records for each day of the month
private:
const int DATE_COLUMNS = 31;
public:
    Employee(const string& name, int empNumber, double payPerDay)
        : name(name), employeeNumber(empNumber), payPerDay(payPerDay), attendanceRecords(DATE_COLUMNS, "0") {}

    void markAttendance(int day, char status) {
        if (day >= 1 && day <= DATE_COLUMNS) {
            attendanceRecords[day - 1] = status;
        }
    }

    void resetAttendance() {
        fill(attendanceRecords.begin(), attendanceRecords.end(), "0");
    }

    double calculatePay() const {
        int presentDays = count(attendanceRecords.begin(), attendanceRecords.end(), "P");
        return presentDays * payPerDay;
    }

    string getName() const {
        return name;
    }

    int getEmployeeNumber() const {
        return employeeNumber;
    }

    string getAttendanceRecord() const {
        return accumulate(attendanceRecords.begin(), attendanceRecords.end(), string(),
                          [](const string& a, const string& b) { return a + "," + b; });
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

    void writeCSVHeaders(ofstream& outfile) const{
        outfile << "Employee Number,Section,Name,Fine";
        for (int i = 1; i <= DATE_COLUMNS; ++i) {
            outfile << ",Date" << i;
        }
        outfile << ",Pay\n";
    }

public:
    HRManagement() = default;

    void addEmployee(unique_ptr<Employee> employee) {
        int empNumber = employee->getEmployeeNumber();
        employees.push_back(move(employee));
        employeeMap[empNumber] = employees.back().get();
    }

    void markAttendance() {
        cout << "Enter employee number to mark attendance: ";
        int empNumber;
        cin >> empNumber;

        auto it = employeeMap.find(empNumber);
        if (it != employeeMap.end()) {
            Employee* employee = it->second;
            cout << "Enter the date (1-31) to mark attendance: ";
            int date;
            cin >> date;
            cout << "Enter 'P' for Present or 'A' for Absent: ";
            char status;
            cin >> status;

            if (date >= 1 && date <= DATE_COLUMNS && (status == 'P' || status == 'A')) {
                employee->markAttendance(date, status);
                cout << "Attendance updated successfully." << endl;
            } else {
                cout << "Invalid date or status." << endl;
            }
        } else {
            cout << "Employee number " << empNumber << " not found." << endl;
        }
    }

    void addOrUpdateAttendance(const string& date, const vector<pair<int, char>>& attendanceUpdates) {
        for (const auto& [empNumber, status] : attendanceUpdates) {
            auto it = employeeMap.find(empNumber);
            if (it != employeeMap.end()) {
                int day = stoi(date.substr(8, 2));  // Extract day from date
                it->second->markAttendance(day, status);
            } else {
                cout << "Employee number " << empNumber << " not found." << endl;
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
            writeCSVHeaders(file);

            for (const auto& employee : employees) {
                file << employee->getEmployeeNumber() << ","
                     << employee->getSection() << ","
                     << employee->getName() << ","
                     << "0,"; // Placeholder for fine; implement if needed

                file << employee->getAttendanceRecord() << ","
                     << employee->calculatePay() << "\n";
            }

            file << "\nHoliday Payments:\n";
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
                 << (employee->getAttendanceRecord()) << "\n";
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
#include <iostream>
#include <memory>
#include <limits>
#include <vector>
#include <string>

using namespace std;

// Forward declarations of classes used
class admissionform;
class Fees;
class Attendance;
class Testmang;
class HRManagement;
class Employee;
class Teacher;
class Admin;
class Cleaner;

// Function declaration
void management();

int main() {
    char runAgain = 'Y';

    while (runAgain == 'Y' || runAgain == 'y') {
        management();
        cout << "IF YOU WANT TO RUN THIS PROGRAM AGAIN ENTER YES (Y/y), OTHERWISE ENTER ANY OTHER KEY" << endl;
        cin >> runAgain;

        // Clear the input buffer to handle any leftover newline characters
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    return 0;
}

void managment() {
    int v, n, choice;

    while (true) {
        cout << "Enter YOUR CHOICE" << endl;
        cout << "ENTER 1 FOR ADMISSION FORM" << endl;
        cout << "ENTER 2 FOR FEES" << endl;
        cout << "ENTER 3 FOR ATTENDANCE" << endl;
        cout << "ENTER 4 FOR TEST MANAGEMENT" << endl;
        cout << "ENTER 5 FOR EMPLOYEES MANAGEMENT" << endl;
        cin >> v;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer

        switch (v) {
            case 1: {
                admissionform form;
                form.fillform();
                form.displayform();
                form.saveToFile();
                form.openFile();
                break;
            }
            case 2: {
                Fees ff;
                ff.account();
                break;
            }
            case 3: {
                Attendance attendance;
                while (true) {
                    cout << "WHAT DO YOU WANT TO DO:" << endl;
                    cout << "1. CREATE A NEW SHEET" << endl;
                    cout << "2. ADD A NEW STUDENT" << endl;
                    cout << "3. MARK ATTENDANCE" << endl;
                    cout << "4. VIEW ATTENDANCE SHEET" << endl;
                    cout << "5. VIEW ATTENDANCE OF A STUDENT" << endl;
                    cout << "6. EXIT FROM PROGRAM" << endl;
                    cin >> choice;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer

                    switch (choice) {
                        case 1: {
                            attendance.createCSVWithHeaders();
                            cout << "HOW MANY STUDENTS YOU WANT TO ADD" << endl;
                            int y;
                            cin >> y;
                            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer
                            for (int x = 0; x < y; ++x) {
                                attendance.addStudent();
                            }
                            break;
                        }
                        case 2: {
                            cout << "HOW MANY STUDENTS YOU WANT TO ADD" << endl;
                            cin >> n;
                            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer
                            for (int i = 0; i < n; ++i) {
                                attendance.addStudent();
                            }
                            break;
                        }
                        case 3:
                            attendance.markAttendance();
                            break;
                        case 4:
                            attendance.viewAttendance();
                            break;
                        case 5:
                            attendance.viewStudentAttendance();
                            break;
                        case 6:
                            cout << "EXITING ATTENDANCE MENU" << endl;
                            return; // Exit the loop
                        default:
                            cout << "Invalid choice. Please try again." << endl;
                            break;
                    }
                }
                break;
            }
            case 4: {
                Testmang attendanc;
                while (true) {
                    cout << "WHAT DO YOU WANT TO DO:" << endl;
                    cout << "1. CREATE A NEW SHEET" << endl;
                    cout << "2. ADD A NEW STUDENT" << endl;
                    cout << "3. MARK ATTENDANCE" << endl;
                    cout << "4. VIEW ATTENDANCE SHEET" << endl;
                    cout << "5. VIEW ATTENDANCE OF A STUDENT" << endl;
                    cout << "6. MARK TEST SCORES" << endl;
                    cout << "7. VIEW ALL TEST SCORES" << endl;
                    cout << "8. EXIT FROM PROGRAM" << endl;
                    cin >> choice;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer

                    switch (choice) {
                        case 1: {
                            attendanc.createCSVWithHeaders();
                            cout << "HOW MANY STUDENTS YOU WANT TO ADD: ";
                            int y;
                            cin >> y;
                            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer
                            for (int x = 0; x < y; ++x) {
                                attendanc.addStudent();
                            }
                            break;
                        }
                        case 2: {
                            cout << "HOW MANY STUDENTS YOU WANT TO ADD: ";
                            cin >> n;
                            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer
                            for (int i = 0; i < n; ++i) {
                                attendanc.addStudent();
                            }
                            break;
                        }
                        case 3:
                            attendanc.markAttendance();
                            break;
                        case 4:
                            attendanc.viewAttendance();
                            break;
                        case 5:
                            attendanc.viewStudentAttendance();
                            break;
                        case 6:
                            attendanc.markTestScores();
                            break;
                        case 7:
                            attendanc.viewAllTestScores();
                            break;
                        case 8:
                            cout << "EXITING TEST MANAGEMENT MENU" << endl;
                            return; // Exit the loop
                        default:
                            cout << "Invalid choice. Please try again." << endl;
                            break;
                    }
                }
                break;
            }
            case 5: {
                HRManagement hr;
                int numEmployees;
                cout << "Enter the number of employees: ";
                cin >> numEmployees;
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer

                for (int i = 0; i < numEmployees; i++) {
                    string name, section;
                    double payPerDay;
                    cout << "Enter employee name: ";
                    getline(cin, name);
                    cout << "Enter pay per day: ";
                    cin >> payPerDay;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer
                    cout << "Enter section (Teacher/Admin/Cleaner): ";
                    getline(cin, section);

                    unique_ptr<Employee> employee;
                    int empNumber = 1000 + i;  // Assign a unique employee number

                    if (section == "Teacher") {
                        employee = make_unique<Teacher>(name, empNumber, payPerDay);
                    } else if (section == "Admin") {
                        employee = make_unique<Admin>(name, empNumber, payPerDay);
                    } else if (section == "Cleaner") {
                        employee = make_unique<Cleaner>(name, empNumber, payPerDay);
                    } else {
                        cerr << "Invalid section!" << endl;
                        continue;
                    }
                    hr.addEmployee(move(employee));
                }

                while (true) {
                    cout << "\nHR Management Menu:\n";
                    cout << "1. Mark Attendance\n";
                    cout << "2. Add or Update Attendance\n";
                    cout << "3. Reset All Attendance\n";
                    cout << "4. Handle Holiday Payments\n";
                    cout << "5. Save Records to CSV\n";
                    cout << "6. Display Records\n";
                    cout << "7. Exit\n";
                    cout << "Enter your choice: ";
                    cin >> choice;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer

                    switch (choice) {
                        case 1:
                            hr.markAttendance();
                            break;
                        case 2: {
                            cout << "Enter the date (YYYY-MM-DD) for attendance updates: ";
                            string date;
                            cin >> date;
                            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer
                            cout << "Enter number of updates: ";
                            int numUpdates;
                            cin >> numUpdates;
                            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer
                            vector<pair<int, char>> updates(numUpdates);
                            for (int i = 0; i < numUpdates; i++) {
                                int empNumber;
                                char status;
                                cout << "Enter employee number and attendance status (P/A): ";
                                cin >> empNumber >> status;
                                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer
                                updates[i] = {empNumber, status};
                            }
                            hr.addOrUpdateAttendance(date, updates);
                            break;
                        }
                        case 3:
                            hr.resetAllAttendance();
                            break;
                        case 4:
                            hr.handleHolidayPayments();
                            break;
                        case 5:
                            hr.saveRecordsToCSV("attendance_records.csv");
                            break;
                        case 6:
                            hr.displayRecords();
                            break;
                        case 7:
                            cout << "EXITING HR MANAGEMENT MENU" << endl;
                            return; // Exit the loop
                        default:
                            cout << "Invalid choice, please try again.\n";
                            break;
                    }
                }
                break;
            }
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }
}

