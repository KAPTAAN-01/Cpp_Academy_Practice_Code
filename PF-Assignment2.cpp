/*#include <iostream>
using namespace std;

int main() {
    int usage;
    cout << "Enter daily water usage in liters: ";
    cin >> usage;

    if (usage >= 500)
    {
        cout << "Warning!!!! \n \t\t Please conserve water!";
    }
    else
    {
        cout << "Water usage is within the limit.";
    }

    return 0;
}
*/
/*#include <iostream>
using namespace std;

int main() {
    float bodyTempreature;
    cout << "Enter your body temperature in Celsius: ";
    cin >> bodyTempreature;

    if (bodyTempreature > 38)
    {
        cout << "Please consult a doctor for a medical checkup.";
    }
    else
    {
        cout << "Temperature is normal.";
    }

    return 0;
}*/
/*#include <iostream>
using namespace std;

int main() {
    float bill, discount = 0, tax, finalBill;
    char filer;

    cout << "Enter total bill amount: ";
    cin >> bill;
    cout << "Are you a filer? (y/n): ";
    cin >> filer;

    if (bill > 10000) {
        discount = bill * 0.15;
    }
    else {
        discount = 0;
    }
    bill -= discount;

    if (filer == 'y' || filer == 'Y')
        tax = bill * 0.05;
    else if (filer == 'n' || filer == 'N')
        tax = bill * 0.17;
    else
        tax = 0;

    finalBill = bill + tax;

    cout << "Original Amount: Rs. " << bill + discount << endl;
    cout << "Discount: Rs. " << discount << endl;
    cout << "Tax: Rs. " << tax << endl;
    cout << "Final Amount: Rs. " << finalBill << endl;

    return 0;
}
*/
#include <iostream>
using namespace std;

int main() {
    double savings;
    cout << "Enter your total savings (Rs): ";
    cin >> savings;

    if (savings >= 2452992)
        cout << "Zakat is due.";
    else
        cout << "You are eligible to receive Zakat.";

    return 0;
}

