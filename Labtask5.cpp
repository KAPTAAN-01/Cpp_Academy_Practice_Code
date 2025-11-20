#include<iostream>
using namespace std;
int main() {
	/* const int lenght = 5;
	const int width = 12;
	float area = 0.0;

	area = lenght * width;
	cout << "Area of rectangle is: " << area << endl; */

	// Calculate total bill of 5 items and apply 15% discount
	/* int rice, chocolate, biscuits, soda, cream;
	const float discount = 0.15;
	cout << "Price of rice :  ";
	cin >> rice;
	cout << "Price of chocolate :  ";
	cin >> chocolate;
	cout << "Price of biscuits :  ";
	cin >> biscuits;
	cout << "Price of soda :  ";
	cin >> soda;
	cout << "Price of cream :  ";
	cin >> cream;
	float total = rice + chocolate + biscuits + soda + cream;
	cout << "Total Bill is : " << total << endl;
	float discounted_price = total - (total * discount);
	cout << "Total Bill after discount is : " << discounted_price << endl; */


	/*
	int x = 10;
	cout<< "Value of x is after --x: " << --x << endl;
	cout<< "Value of x is after x--: " << x-- << endl;
	cout<< "Value of x is: " << x << endl;
	cout<< "Value of x is after ++x: " << ++x << endl;
	cout<< "Value of x is after x++: " << x++ << endl;
	cout<< "Value of x is: " << x << endl;
	*/

	/*
	int x;
	cout << "Enter value"<<endl;
	cin>> x;
	x += 2;
	cout << x<<endl;
	x += 2;
	cout<< x<<endl;
	x += 2;
	cout << x<<endl;
	x += 2;
	cout << x<<endl;
	*/
	
	/*float bonus = 0.10;
	int salarey;
	cout << "Enter your salary: ";
	cin >> salarey;
	cout << "Your bonus is: " << salarey * bonus << endl;
	cout << "Your total salarey is: " << salarey + (salarey * bonus) << endl;*/

	/*
	  float _1dollor = 278.5;
	  float dollor;
	  cout << "Enter dollors : ";
	  cin >> dollor;
	  cout<<"Currency in PKR is : "<< dollor * _1dollor << endl;

	*/
	const float unitRate = 22.5;
	int units;
	cout << "Enter the units : ";
	cin >> units;
	cout << "Total bill is : " << units * unitRate << endl;

	
	return 0;
	system("pause");
}