// Online C++ compiler to run C++ program online
#include <iostream>
#include<fstream>
#include<string>
#include<cstdlib>
using namespace std;
 class admissionform{
     private:
     string name;
     string dateofbirth;
     string gender;
     string age;
     string cnicnumber;
     string fathername;
     string fcnicnumber;
     string adress;
     string phonenumber;
     string email;
     string schoolname;
     string matricmarks;
     public:
     void fillform(){
     cout<<"STUDENT NAME : ";
     cin>>ws;
     getline(cin , name);
     
      cout<<" BIRTH DATE OF STUDENT IN FORMATE (DD/MM/YYYY): ";
     cin>>ws;
     getline(cin , dateofbirth);
     
      cout<<"STUDENT GENDER : ";
     cin>>ws;
     getline(cin , gender);
     
     
      cout<<"STUDENT AGE : ";
     cin>>ws;
     getline(cin , age);
     
      cout<<"STUDENT CNIC NUMBER : ";
     cin>>ws;
     getline(cin , cnicnumber);
     
      cout<<"FATHER NAME : ";
     cin>>ws;
     getline(cin , fathername);
     
      cout<<"CNIC NUMBER OF STUDENT FATHERS : ";
     cin>>ws;
     getline(cin , fcnicnumber);
     
      cout<<" ADRESS  : ";
     cin>>ws;
     getline(cin , adress);
     
      cout<<" CONTACT NUMBER : ";
     cin>>ws;
     getline(cin , phonenumber);
     
      cout<<"STUDENT EMAIL : ";
     cin>>ws;
     getline(cin , email);
     
      cout<<"SCHOOL NAME : ";
     cin>>ws;
     getline(cin , schoolname);
     
     
       cout<<"MARKS OF MATRIX : ";
     cin>>ws;
     getline(cin , matricmarks);
     }
     
     // function to display admissionform

void displayform(){
    
    cout<<" Admission Form of a student"<<endl;
    cout<<",,,,,,,,,,,,,,,,,,,,,,,,,,,,"<<endl;
    cout<<" NAME OF STUDENT : "<<endl;
    cout<<" DATE OF BIRH : "<<dateofbirth<<endl;
    cout<<" GENDER : "<<gender<<endl;
    cout<<" AGE : "<<age<<endl;
    cout<<" CNIC NUMBER OF STUDENT : "<<cnicnumber<<endl;
    cout<<" NAME OF STUDENT FATHER : "<<fathername<<endl;
    cout<<" CNIC NUMBER OF STUDENTS FATHER : "<<fcnicnumber<<endl;
    cout<<" ADRESS : "<<adress<<endl;
    cout<<" CONTACT NUMBER : "<<phonenumber<<endl;
    cout<<" EMAIL : "<<email<<endl;
    cout<<"SCHOOL NAME : "<<schoolname<<endl;
    cout<<"MARKS OF A MATRIC EXAMS : "<<matricmarks<<endl;
    
}
 // Method to save form data to a file
    void saveToFile(){
        ofstream file("admission_form.txt");
        if (file.is_open()) {
            file << "Admission Form Details\n";
            file << "----------------------\n";
            file << "Name: " << name << endl;
            file << "Age: " << age << endl;
            file << "Date of Birth: " << dateofbirth << endl;
            file << "B Form No: " << cnicnumber << endl;
            file << "Father's Name: " << fathername << endl;
            file << "Father's CNIC: " << fcnicnumber << endl;
            file << "Gender: " << gender << endl;
            file << "Email: " << email << endl;
            file << "Past School: " << schoolname << endl;
            file << "Adress: " << adress << endl;
            file << "MARKS OF MATRIC: " << matricmarks << endl;
              file << "CONTACT NUMBER: " << phonenumber << endl;
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
 admissionform form;

    // Fill the admission form
    form.fillform();

    // Display the admission form details
    form.displayform();

    // Save form data to a file
    form.saveToFile();

    // Open the saved file using default text editor
    form.openFile();


    return 0;
}