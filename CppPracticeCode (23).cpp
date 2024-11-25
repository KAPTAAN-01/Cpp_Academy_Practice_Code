#include <iostream>
using namespace std;

// Functions for arithmetic operations
double add(double* a, double* b) {
    return (*a) + (*b);
}

double subtract(double* a, double* b) {
    return (*a) - (*b);
}

double multiply(double* a, double* b) {
    return (*a) * (*b);
}

double divide(double* a, double* b) {
    if (*b != 0) {
        return (*a) / (*b);
    } else {
        cout << "Error! Division by zero." << endl;
        return 0;
    }
}

double squareRoot(double* a) {
    if (*a < 0) {
        cout << "Error! Negative input for square root." << endl;
        return -1;
    }
    double guess = *a / 2;
    while (abs(guess * guess - *a) > 0.00001) {
        guess = (guess + (*a / guess)) / 2;
    }
    return guess;
}

// Function to display the menu
void displayMenu() {
    cout << "\n**************************" << endl;
    cout << "*       Menu Table       *" << endl;
    cout << "**************************" << endl;
    cout << "* 1. Add                 *" << endl;
    cout << "* 2. Subtract            *" << endl;
    cout << "* 3. Multiply            *" << endl;
    cout << "* 4. Divide              *" << endl;
    cout << "* 5. Square Root         *" << endl;
    cout << "* 6. Exit                *" << endl;
    cout << "**************************" << endl;
    cout << "Enter your choice (1-6): ";
}

int main() {
    double a, b;
    double* p_a = &a;
    double* p_b = &b;
    int choice;

    while (true) {
        displayMenu();
        cin >> choice;

        if (choice == 6) {
            cout << "Exiting the program." << endl;
            break;
        }

        switch (choice) {
            case 1:
                cout << "Enter two numbers: ";
                cin >> *p_a >> *p_b;
                cout << "Result: " << add(p_a, p_b) << endl;
                break;

            case 2:
                cout << "Enter two numbers: ";
                cin >> *p_a >> *p_b;
                cout << "Result: " << subtract(p_a, p_b) << endl;
                break;

            case 3:
                cout << "Enter two numbers: ";
                cin >> *p_a >> *p_b;
                cout << "Result: " << multiply(p_a, p_b) << endl;
                break;

            case 4:
                cout << "Enter two numbers: ";
                cin >> *p_a >> *p_b;
                cout << "Result: " << divide(p_a, p_b) << endl;
                break;

            case 5:
                cout << "Enter a number: ";
                cin >> *p_a;
                cout << "Result: " << squareRoot(p_a) << endl;
                break;

            default:
                cout << "Invalid choice. Please select a number between 1 and 6." << endl;
                break;
        }
    }

    return 0;
}
