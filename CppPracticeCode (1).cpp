#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Class to manage fees
class Fees {
public:
    double totalFees;
    double discount;
    double otherFunds;
    int installments;

    // Constructor
    Fees(double tf, double d, double of, int inst) 
        : totalFees(tf), discount(d), otherFunds(of), installments(inst) {}

    // Function to calculate the amount per installment
    double calculateInstallmentAmount() const {
        double discountedFees = totalFees - (totalFees * discount / 100);
        double finalFees = discountedFees + otherFunds;
        return finalFees / installments;
    }
};

// Class to manage student details
class Student {
public:
    string studentID;
    string name;
    Fees fees;

    // Constructor
    Student(string id, string n, Fees f) 
        : studentID(id), name(n), fees(f) {}

    // Function to display student details
    void displayStudentDetails() const {
        cout << "Student ID: " << studentID << endl;
        cout << "Name: " << name << endl;
        cout << "Total Fees: $" << fees.totalFees << endl;
        cout << "Discount: " << fees.discount << "%" << endl;
        cout << "Other Funds: $" << fees.otherFunds << endl;
        cout << "Number of Installments: " << fees.installments << endl;
        cout << "Installment Amount: $" << fees.calculateInstallmentAmount() << endl;
    }

    // Function to save student details to a CSV file
    void saveToCSV(const string& filename) const {
        ofstream file(filename, ios::app);  

        if (file.is_open()) {
            file << studentID << "," << name << "," 
                 << fees.totalFees << "," << fees.discount << "," 
                 << fees.otherFunds << "," << fees.installments << "," 
                 << fees.calculateInstallmentAmount() << endl;
            file.close();
            cout << "Student details saved to " << filename << endl;
        } else {
            cout << "Unable to open file" << endl;
        }
    }
};

int main() {
    // Creating a Fees object
    Fees fee1(10000, 10, 500, 4);  // Total Fees: 10000, Discount: 10%, Other Funds: 500, Installments: 4

    // Creating a Student object
    Student student1("S12345", "John Doe", fee1);

    // Displaying student details
    student1.displayStudentDetails();

    // Saving student details to CSV file
    student1.saveToCSV("student_fees.csv");

    return 0;
}

