#include <iostream>
#include <fstream>
#include <cstdlib>

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

int main() {
    Fees ff;
    ff.account();
    return 0;
}
