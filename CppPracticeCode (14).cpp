#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int DATE_COLUMNS = 31;

class Attendance {
private:
    string studentName;
    string fatherName;
    string rollNo;
    int finePerAbsent;
    int fineForTestAbsent;

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

int main() {
    Attendance attendance;
    int choice;

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

        switch (choice) {
            case 1:
                attendance.createCSVWithHeaders();
                cout << "HOW MANY STUDENTS YOU WANT TO ADD: ";
                int y;
                cin >> y;
                for (int x = 0; x < y; ++x) {
                    attendance.addStudent();
                }
                break;
            case 2:
                cout << "HOW MANY STUDENTS YOU WANT TO ADD: ";
                int n;
                cin >> n;
                for (int i = 0; i < n; ++i) {
                    attendance.addStudent();
                }
                break;
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
                attendance.markTestScores();
                break;
            case 7:
                attendance.viewAllTestScores();
                break;
            case 8:
                cout << "EXITING PROGRAM SUCCESSFULLY" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }

    return 0;
}
