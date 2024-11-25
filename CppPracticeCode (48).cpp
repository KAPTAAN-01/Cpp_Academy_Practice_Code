#include <iostream>
#include <fstream>
#include <cstdlib>
#include <limits> // For std::numeric_limits

using namespace std;

class Fees {
private:
    double fees;
    double discount;
    double finalFees;
    double installments;
    double perInstallmentFee;
    double extraFund;
    double totalFees;

public:
    void account() {
        cout << "ENTER THE ANNUAL FEES OF A STUDENT: ";
        while (!(cin >> fees) || fees < 0) {
            cout << "Invalid input. Please enter a positive number for annual fees: ";
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        }
        cout << endl;

        cout << "ENTER THE DISCOUNT PERCENTAGE OF A STUDENT: ";
        while (!(cin >> discount) || discount < 0 || discount > 100) {
            cout << "Invalid input. Please enter a percentage between 0 and 100: ";
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        }
        cout << endl;

        double discountAmount = fees * discount / 100;
        finalFees = fees - discountAmount;
        cout << "STUDENT FINAL FEES: " << finalFees << endl;

        cout << "HOW MANY INSTALLMENTS YOU WANT: ";
        while (!(cin >> installments) || installments <= 0) {
            cout << "Invalid input. Please enter a positive number for installments: ";
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        }
        cout << endl;

        perInstallmentFee = finalFees / installments;
        cout << "PER INSTALLMENT FEES OF A STUDENT: " << perInstallmentFee << endl;

        cout << "ENTER THE FEES OF NOTES AND OTHER THINGS: ";
        while (!(cin >> extraFund) || extraFund < 0) {
            cout << "Invalid input. Please enter a positive number for extra funds: ";
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        }
        cout << endl;

        totalFees = finalFees + extraFund;
        cout << "STUDENT FEES AFTER ADDING EXTRA FUNDS: " << totalFees << endl;

        saveToCSV();
    }

    void saveToCSV() {
        ofstream outFile("student_fees.csv", ios::app); // open file in append mode
        if (outFile.is_open()) {
            outFile << fees << "," << discount << "," << finalFees << "," << installments << "," << perInstallmentFee << "," << extraFund << "," << totalFees << endl;
            outFile.close();
            cout << "Data saved to student_fees.csv successfully." << endl;
        } else {
            cout << "Unable to open file." << endl;
        }
    }
};

int main() {
    Fees ff;
    ff.account();
    return 0;
}

