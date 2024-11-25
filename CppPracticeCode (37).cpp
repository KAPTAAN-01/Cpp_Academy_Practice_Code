#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> // for system() function
using namespace std;

// Class definition for Admission Form
class AdmissionForm {
private:
    string name;
    int age;
    string dob;
    string bFormNo;
    string fatherName;
    string contactno;
    string fatherCNIC;
    string gender;
    string email;
    string pastSchool;
    string address;
    double percentage;

public:
    // Method to input details
    void fillForm() {
        cout << "Enter Name: ";
        getline(cin, name);

        cout << "Enter Age: ";
        cin >> age;
        cin.ignore(); // Ignore newline left in buffer

        cout << "Enter Date of Birth (dd/mm/yyyy): ";
        getline(cin, dob);

        cout << "Enter B Form No: ";
        getline(cin, bFormNo);
        
        cout << "Contact No: ";
        getline(cin, contactno);

        cout << "Enter Father's Name: ";
        getline(cin, fatherName);

        cout << "Enter Father's CNIC: ";
        getline(cin, fatherCNIC);

        cout << "Enter Gender: ";
        getline(cin, gender);

        cout << "Enter Email: ";
        getline(cin, email);

        cout << "Enter Name of Past School: ";
        getline(cin, pastSchool);

        cout << "Enter Full Address: ";
        getline(cin, address);

        cout << "Enter Percentage in Previous Class: ";
        cin >> percentage;
        cin.ignore(); // Ignore newline left in buffer
    }

    // Method to display form details
    void displayForm() {
        cout << "\nAdmission Form Details\n";
        cout << "----------------------\n";
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Date of Birth: " << dob << endl;
        cout << "B Form No: " << bFormNo << endl;
        cout << "Contact No: " << contactno << endl;
        cout << "Father's Name: " << fatherName << endl;
        cout << "Father's CNIC: " << fatherCNIC << endl;
        cout << "Gender: " << gender << endl;
        cout << "Email: " << email << endl;
        cout << "Past School: " << pastSchool << endl;
        cout << "Address: " << address << endl;
        cout << "Percentage in Previous Class: " << percentage << endl;
    }

    // Method to save form data to a file
    void saveToFile() {
        ofstream file("admission_form.txt");
        if (file.is_open()) {
            file << "Admission Form Details\n";
            file << "----------------------\n";
            file << "Name: " << name << endl;
            file << "Age: " << age << endl;
            file << "Date of Birth: " << dob << endl;
            file << "B Form No: " << bFormNo << endl;
            file << "Contact No: " << contactno << endl;
            file << "Father's Name: " << fatherName << endl;
            file << "Father's CNIC: " << fatherCNIC << endl;
            file << "Gender: " << gender << endl;
            file << "Email: " << email << endl;
            file << "Past School: " << pastSchool << endl;
            file << "Address: " << address << endl;
            file << "Percentage in Previous Class: " << percentage << endl;
            file.close();
            cout << "\nForm data saved to admission_form.txt" << endl;
        } else {
            cout << "Unable to open file for saving." << endl;
        }
    }

    // Method to open saved file using system default text editor
    void openFile() {
        cout << "\nOpening admission_form.txt using default text editor..." << endl;
        system("start admission_form.txt");
    }
};

int main() {
    AdmissionForm form;

    // Fill the admission form
    form.fillForm();

    // Display the admission form details
    form.displayForm();

    // Save form data to a file
    form.saveToFile();

    // Open the saved file using default text editor
    form.openFile();

    return 0;
}
