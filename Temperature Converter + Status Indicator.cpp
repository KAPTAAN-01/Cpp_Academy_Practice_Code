#include <iostream>
using namespace std;

int main() {

    double celsius;          // User input temperature
    double fahrenheit;       // Convert result
    double kelvin;
    char again;              // Repeat input

    do {

        cout << "Enter temperature in Celsius: ";
        cin >> celsius;

        // -------- CONVERSIONS --------
        fahrenheit = (celsius * 9/5) + 32;            // Celsius to Fahrenheit
        kelvin = celsius + 273.15;                    // Celsius to Kelvin

        cout << "Fahrenheit = " << fahrenheit << endl;
        cout << "Kelvin = " << kelvin << endl;

        // -------- TEMPERATURE STATUS --------
        if (celsius > 40)
            cout << "Status: Very Hot\n";
        else if (celsius >= 30)
            cout << "Status: Hot\n";
        else if (celsius >= 20)
            cout << "Status: Warm\n";
        else if (celsius >= 10)
            cout << "Status: Cool\n";
        else
            cout << "Status: Cold\n";

        cout << "Check another temperature? (y/n): ";
        cin >> again;

    } while (again == 'y' || again == 'Y');           // Repeat until user chooses no

    return 0;
}
