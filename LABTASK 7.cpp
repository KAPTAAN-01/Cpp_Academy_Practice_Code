// LABTASK 7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
    int employe_Type;
    char calculation_Type;
    int hours,salary;
    float medicalCharges;
    cout << "Press 1 for Permanent Employee \n Press 2 for Daily wages Employee: ";
    cin >> employe_Type;
    if (employe_Type == 1)
    {
        cout << "Enter the number of hours you work";
        cin >> hours;
        cout << "Press a to calculate Salary \n Press b to calculate medical charges: ";
        cin >> calculation_Type;
        if(calculation_Type == 'a')
        {
            
            salary = hours * 800;
            cout << "Your salary is: " << salary<<endl;

        }
        else if (calculation_Type == 'b')
        {
            
            salary = hours * 800;
            medicalCharges = 5 * (salary / 100);
            cout << "Your Medical Charges are: " << medicalCharges<<endl;
            cout << "Your salary fter adding medical charges: " << salary + medicalCharges<<endl;
        }
        else
        {
            cout << "Invalid Character";

        }

    }
    else if (employe_Type == 2) 
    {
        cout << "Enter the number of hours you work";
        cin >> hours;
        cout << "Press a to calculate Salary \n Press b to calculate medical charges: ";
        cin >> calculation_Type;
        if (calculation_Type == 'a')
        {
            
            salary = hours * 400;
            cout << "Your salary is: " << salary<<endl;

        }
        else if (calculation_Type == 'b')
        {
            
            salary = hours * 400;
            medicalCharges = 3 * (salary / 100);
            cout << "Your Medical Charges are: " << medicalCharges<<endl;
            cout << "Your salary fter adding medical charges: " << salary + medicalCharges<<endl;
        }
        else
        {
            cout << "Invalid Character";

        }
        
    }
    else 
    {
        cout << "Invalid Input";
    }

    
    return 0;
    system("Pause");
}

/*int marks1, marks2, marks3;
    cout << "Enter the marks of first Assignment: ";
    cin >> marks1;

    cout << "Enter the marks of Second Assignment: ";
    cin >> marks2;

    cout << "Enter the marks of Third Assignment: ";
    cin >> marks3;

    if (marks1 > 50) {
        cout << "Congradulations!! You are Passed";
    }
    else {
        cout << "You are fail, Do hard work next time.";
    }

    if (marks2 > 50) {
        cout << "Congradulations!! You are Passed";
    }
    else {
        cout << "You are fail, Do hard work next time.";
    }

    if (marks3 > 50) {
        cout << "Congradulations!! You are Passed";
    }
    else {
        cout << "You are fail, Do hard work next time.";
    }*/

/*int marks1, marks2, marks3;
    cout << "Enter the marks of first Subject: ";
    cin >> marks1;

    cout << "Enter the marks of Second Subject: ";
    cin >> marks2;

    cout << "Enter the marks of Third Subject: ";
    cin >> marks3;
    float marks = marks1 + marks2 + marks3;
    if (marks1 >= 100) {
        cout << "Congradulations!! You are Passed";
    }
    else {
        cout << "You are fail, Do hard work next time.";
    }*/
/*int integerValue;
    cout << "Enter an Integer Value: ";
    cin >> integerValue;

    if (integerValue % 2 == 0) {
        cout << "Even number";
    }
    else {
        cout << "ODD number";
    }*/

/* int integer1, integer2;
    cout << "Enter first integer";
    cin >> integer1;

    cout << "Enter Second integer";
    cin >> integer2;

    int result = integer1 / integer2;

    if (result % 2 == 0) {
        cout << "Even number";
    }
    else {
        cout << "Odd number";
  
    }*/

/* int units;
    cout << "Enter the units you used: ";
    cin >> units;
    int bill;
    if (units < 300) {
        cout << "Your bill is:" << units * 5;
    }
    else{
        bill = units * 10;
        float bill_withTax = bill + (5 * (bill / 100));
        cout << "Your bill is: " << bill_withTax;
    }*/

/*int account;
    cout << "Press 1 for Current Account \n Press 2 for Savings Account: ";
    cin >> account;
    if (account == 1) {
        cout << "Your Current account is open";
    }
    else if (account == 2) {
        cout << "Your Saving account is open";
    }
    else{
        cout << "Invalid number";
    }*/