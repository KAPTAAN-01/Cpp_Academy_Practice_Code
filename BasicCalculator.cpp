#include<iostream>
using namespace std;
int main()
{
	int choice;
	double numb1, numb2;
	cout << "Enter First number: ";
	cin >> numb1;
	cout << "Enter Second number: ";
	cin >> numb2;
	cout << "Press: \n '1' for Addition \n '2' for Subtraction \n '3' for Multiplication \n '4' for Division \n '5' for Remainder or Mod" << endl;
	cin >> choice;
	switch (choice) 
	{
	case 1:
		cout << "The Sum of " << numb1 << " & " << numb2 << " is " << numb1 + numb2;
		break;
	case 2:
		cout << "The Subtraction of " << numb1 << " & " << numb2 << " is " << numb1 - numb2;
		break;
	case 3:
		cout << "The Multiplication of " << numb1 << " & " << numb2 << " is " << numb1 * numb2;
		break;
	case 4:
		if (numb2 == 0) {
			cout << "Number 2 is zero so Division is not possible";
		}
		else {
			cout << "The Division of " << numb1 << " & " << numb2 << " is " << numb1 / numb2;
		}
		break;
	default:
		cout << "Invalid";
	}
}