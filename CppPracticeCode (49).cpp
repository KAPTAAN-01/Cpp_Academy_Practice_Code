#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct AdmissionForm {
    string fullName;
    string dateOfBirth;
    string gender;
    string nationality;
    string phoneNumber;
    string email;
    string address;
    string photoPath;
    string previousInstitutions;
    string grades;
    string certificates;
    string transcripts;
    string testScores;
    string desiredCourse;
    string specialization;
    string modeOfStudy;
    string parentName;
    string parentContact;
    string parentOccupation;
    string extracurriculars;
    string workExperience;
    string references;
    string statementOfPurpose;
    string declaration;
};

void saveForm(const AdmissionForm &form) {
    ofstream file("admission_form.csv", ios::app);
    if (file.is_open()) {
        file << form.fullName << ","
             << form.dateOfBirth << ","
             << form.gender << ","
             << form.nationality << ","
             << form.phoneNumber << ","
             << form.email << ","
             << form.address << ","
             << form.photoPath << ","
             << form.previousInstitutions << ","
             << form.grades << ","
             << form.certificates << ","
             << form.transcripts << ","
             << form.testScores << ","
             << form.desiredCourse << ","
             << form.specialization << ","
             << form.modeOfStudy << ","
             << form.parentName << ","
             << form.parentContact << ","
             << form.parentOccupation << ","
             << form.extracurriculars << ","
             << form.workExperience << ","
             << form.references << ","
             << form.statementOfPurpose << ","
             << form.declaration << "\n";
        file.close();
        cout << "Form saved successfully!\n";
    } else {
        cout << "Unable to open file for writing.\n";
    }
}

void viewForm() {
    ifstream file("admission_form.csv");
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            cout << line << "\n";
        }
        file.close();
    } else {
        cout << "Unable to open file for reading.\n";
    }
}

int main() {
    AdmissionForm form;

    cout << "Enter Full Name: ";
    getline(cin, form.fullName);
    cout << "Enter Date of Birth: ";
    getline(cin, form.dateOfBirth);
    cout << "Enter Gender: ";
    getline(cin, form.gender);
    cout << "Enter Nationality: ";
    getline(cin, form.nationality);
    cout << "Enter Phone Number: ";
    getline(cin, form.phoneNumber);
    cout << "Enter Email: ";
    getline(cin, form.email);
    cout << "Enter Address: ";
    getline(cin, form.address);
    cout << "Enter Photo Path: ";
    getline(cin, form.photoPath);
    cout << "Enter Previous Educational Institutions: ";
    getline(cin, form.previousInstitutions);
    cout << "Enter Grades/Marks/CGPA: ";
    getline(cin, form.grades);
    cout << "Enter Certificates/Diplomas: ";
    getline(cin, form.certificates);
    cout << "Enter Transcripts: ";
    getline(cin, form.transcripts);
    cout << "Enter Standardized Test Scores (if applicable): ";
    getline(cin, form.testScores);
    cout << "Enter Desired Course/Program: ";
    getline(cin, form.desiredCourse);
    cout << "Enter Specialization (if any): ";
    getline(cin, form.specialization);
    cout << "Enter Mode of Study (Full-time, Part-time, Online): ";
    getline(cin, form.modeOfStudy);
    cout << "Enter Parent/Guardian Name: ";
    getline(cin, form.parentName);
    cout << "Enter Parent/Guardian Contact Information: ";
    getline(cin, form.parentContact);
    cout << "Enter Parent/Guardian Occupation: ";
    getline(cin, form.parentOccupation);
    cout << "Enter Extracurricular Activities: ";
    getline(cin, form.extracurriculars);
    cout << "Enter Work Experience: ";
    getline(cin, form.workExperience);
    cout << "Enter References: ";
    getline(cin, form.references);
    cout << "Enter Statement of Purpose: ";
    getline(cin, form.statementOfPurpose);
    cout << "Enter Declaration: ";
    getline(cin, form.declaration);

    saveForm(form);

    cout << "\nDo you want to view the saved form? (y/n): ";
    char choice;
    cin >> choice;
    cin.ignore(); // Clear the newline character left in the input buffer
    if (choice == 'y' || choice == 'Y') {
        viewForm();
    }

    return 0;
}
