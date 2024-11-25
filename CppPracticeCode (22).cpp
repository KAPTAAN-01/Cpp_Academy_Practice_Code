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
        cout << "6. EXIT FROM PROGRAM" << endl;
        cin >> choice;

        switch (choice) {
            case 1:
                attendance.createCSVWithHeaders();
                cout << "HOW MANY STUDENTS YOU WANT TO ADD" << endl;
                int y;
                cin >> y;
                for (int x = 0; x < y; ++x) {
                    attendance.addStudent();
                }
                break;
            case 2:
                cout << "HOW MANY STUDENTS YOU WANT TO ADD" << endl;
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
                cout << "EXITING PROGRAM SUCCESSFULLY" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }

    return 0;
}
