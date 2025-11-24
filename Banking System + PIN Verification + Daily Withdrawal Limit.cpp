#include <iostream>
using namespace std;

int main() {

    int correctPIN = 1234;     // System ka default PIN
    int enteredPIN;            // User se PIN lene ke liye variable
    int pinAttempts = 0;       // PIN attempt counter
    double balance = 1000.0;   // Initial bank balance
    int choice;                // Menu choice
    double amount;             // Deposit/Withdraw amount

    // ---------------- PIN VERIFICATION ----------------
    while (pinAttempts < 3) {                        // User ko max 3 attempts milte hain
        cout << "Enter PIN: ";
        cin >> enteredPIN;

        if (enteredPIN == correctPIN) {              // PIN sahi ho to loop break ho jaye
            cout << "Access Granted!\n\n";
            break;
        }
        else {
            cout << "Incorrect PIN. Try Again.\n";
            pinAttempts++;
        }
    }

    if (pinAttempts == 3) {                          // 3 wrong attempts → account locked
        cout << "Too many attempts. Account Locked.\n";
        return 0;
    }

    // ---------------- MAIN BANKING MENU ----------------
    do {
        cout << "\n--- Banking Menu ---\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. Check Balance\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            // ---------------- DEPOSIT LOGIC ----------------
            cout << "Enter deposit amount: ";
            cin >> amount;

            if (amount > 0) {                        // Amount positive honi chahiye
                balance += amount;
                cout << "Deposit successful. New balance: " << balance << endl;
            }
            else {
                cout << "Invalid amount.\n";
            }
            break;

        case 2:
            // ---------------- WITHDRAW LOGIC ----------------
            cout << "Enter withdrawal amount: ";
            cin >> amount;

            if (amount > 500) {                      // Daily withdraw limit
                cout << "Daily withdrawal limit is 500.\n";
            }
            else if (amount > balance) {             // Balance insufficient
                cout << "Insufficient balance.\n";
            }
            else {
                balance -= amount;                   // Withdraw successful
                cout << "Withdraw successful. Balance: " << balance << endl;
            }
            break;

        case 3:
            // ---------------- BALANCE CHECK ----------------
            cout << "Current Balance: " << balance << endl;
            break;

        case 4:
            cout << "Thank you for using our system.\n";
            break;

        default:
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 4);                           // Menu repeat until exit

    return 0;
}
