/*BMI Calculator*/
/*#include <iostream>
using namespace std;

int main() {
    float weight, height;
    cout << "Enter your weight in kg: ";
    cin >> weight;
    cout << "Enter your height in meters: ";
    cin >> height;
    
    cout << "\n\nYour BMI is: " << weight / (height * height);
    system("pause");
    return 0;
}*/

/*2️⃣ Total and Percentage of 5 Subjects*/
/*#include <iostream>
using namespace std;

int main() {
    int subject1, subject2, subject3, subject4, subject5, totalMarks;
    float percentage;
    cout << "Enter marks of 5 subjects (out of 100): ";
    cin >> subject1 >> subject2 >> subject3 >> subject4 >> subject5;
    totalMarks = subject1 + subject2 + subject3 + subject4 + subject5;
    percentage = totalMarks / 5;
    cout << "\nTotal Marks:\t" << totalMarks;
    cout << "\nPercentage:\t" << percentage << "%";

    system("pause");
    return 0;
}*/

/*3️⃣ Water Bill Calculation*/
/*#include <iostream>
using namespace std;

int main() {
    const float rate = 25.75;
    int units;
    cout << "Enter total units used: ";
    cin >> units;
    cout << "\nTotal Water Bill = Rs. " << rate * units;
    system("pause");
    return 0;
}*/


/*4️⃣ Simple Interest Calculation*/
/*#include <iostream>
using namespace std;

int main() {
    float distance, fuel, mileage;
    cout << "Enter distance travelled (km): ";
    cin >> distance;
    cout << "Enter fuel used (litres): ";
    cin >> fuel;
    mileage = distance / fuel;
    cout << endl <<"Mileage = " << mileage << " km/l";
    return 0;
}*/

/*5️⃣ Net Salary After Tax*/
/*#include <iostream>
using namespace std;

int main() {
    float salary, netSalary;
    const float taxRate = 0.07;
    cout << "Enter your salary: ";
    cin >> salary;
    netSalary = salary - (salary * taxRate);
    cout << endl <<"Salary ater ctting tax = Rs. " << netSalary;
    return 0;
}*/

/*6️⃣ Laptop Price After Sales Tax*/
/*#include <iostream>
using namespace std;

int main() {
    const float taxRate = 0.12;
    float basePrice, finalPrice;
    cout << "Enter the price of laptop: ";
    cin >> basePrice;
    finalPrice = basePrice + (basePrice * taxRate);
    cout << "\nFinal Price:\tRs. " << finalPrice;
    return 0;
}*/

/*7️⃣ Age Difference*/
/*#include <iostream>
using namespace std;

int main() {
    int myAge, friendAge, diff;
    cout << "Enter your age: ";
    cin >> myAge;
    cout << "Enter your friend's age: ";
    cin >> friendAge;
    diff = friendAge - myAge;
    cout << endl << "Age Difference: " << diff << " years";
    return 0;
}
*/

/*8️⃣ Electricity Bill*/
#include <iostream>
using namespace std;

int main() {
    const float rate = 22.50;
    int units;
    float bill;
    cout << "Enter number of units consumed: ";
    cin >> units;
    bill = rate * units;
    cout << endl << "Total Electricity Bill = Rs. " << bill;
    return 0;
}



