#include <iostream>

using namespace std;

int main()
{
   /*
    Q 1 : Write a program in C++ that add two integer values from user using variables concept
    and display the result the on screen.

    cout << "Enter two integers : ";
    int integer1, integer2;
    cin >> integer1 >> integer2;
    cout << endl;
    cout << "The sum of " << integer1 << " and " << integer2 << " is " << integer1 + integer2 << endl;
 
    return 0;
    system("pause");


   */ 
    /*
     Q 2 : Write a program in C++ that multiply two integer values using variables concept and
     display the result the on screen.

     cout << "Enter two integers : ";
     int integer1, integer2;
     cin >> integer1 >> integer2;
     cout << endl;
     cout << "The product of " << integer1 << " and " << integer2 << " is " << integer1 * integer2 << endl;
 
     return 0;
     system("pause");

    
    */
    /*
      Q 3 : Write down a program in C++ in which you have to take a number from user and then
      calculate the percentage of that number and then display the result on screen. 

      int obtainedMarks, totalMarks;
       cout << "Enter your obtained marks: ";
       cin >> obtainedMarks;
       cout << endl <<"Enter your total marks : ";
       cin >> totalMarks;
       float percentage;
       percentage = (obtainedMarks / totalMarks) * 100;
       cout<< endl << "Your percentage is " << percentage << "%";
 
       return 0;
       system("pause");

    */
    /*
        Q 4 : Take length and width of a rectangular box from user and then calculate the area and
              perimeter of the rectangular box using variable concept. Write down its code in C++.

        int lenth, width;
        cout << "Enter the lenght: ";
        cin >> lenth;
        cout << endl <<"Enter the width : ";
        cin >> width;
        float area = lenth * width;
        float peremeter = 2 * (lenth + width);
        cout<< endl << "Area is " << area<<endl << "Perimeter is "<< peremeter;
 
         return 0;
         system("pause");
   

    */

    /*
      Q 5 : Write down a program in C++ that take three integer value from user and you have to
            calculate average of those three numbers. Store the average answer in a variable and
            then display the result on screen using variable concept.

    */
    int integer1, integer2, integer3;
    cout << "Enter three integers: ";
    cin >> integer1 >> integer2 >> integer3;
    
    float average = (integer1 + integer2 + integer3) / 3;
    cout << endl << "Average of the number is : " << average;
    system("pause");
    return 0;    
}


