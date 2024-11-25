#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

const string CSV_FILENAME = "students.csv";
const int DATE_COLUMNS = 31;

void createCSVWithHeaders() {
    ifstream infile("students.csv");
    if (!infile.is_open()) {
        // File doesn't exist or cannot be opened
        ofstream outfile("students.csv");
        if (outfile.is_open()) {
            outfile << "Student Name   ,Father Name ";
            for (int i = 1; i <= DATE_COLUMNS; ++i) {
                outfile << "," << i;
            }
            outfile <<endl;
            outfile.close();
            cout << "CSV file created with headers." <<endl;
        } else {
            cerr << "Unable to create file." <<endl;
        }
    } else {
        string line;
        if (getline(infile, line)) {
            // File is not empty
            cout << "CSV file already has content." <<endl;
        } else {
            // File is empty
            ofstream outfile("students.csv");
            if (outfile.is_open()) {
                outfile << "Name,Father Name";
                for (int i = 1; i <= DATE_COLUMNS; ++i) {
                    outfile << ",Date" << i;
                }
                outfile << std::endl;
                outfile.close();
                cout << "Headers added to the empty CSV file." <<endl;
            } else {
                cerr << "Unable to open file to write headers." << endl;
            }
        }
    }
    infile.close();
}

int main() {
    createCSVWithHeaders();
    return 0;
}
