#include<iostream>
using namespace std;
int main() {
	float carFuel;
	cout << "Enter the fuel (In liters) in : ";
	cin >> carFuel;

	int totalDistance = 0;
	while (carFuel >= 2.5) {
		int distance;
		cout << "Enter Distanced(IN kilometers) you travelled: ";
		cin >> distance;

		float usedFule = distance * 0.1;   
		if (carFuel - usedFule < 2.5) {
			cout << "Low fule!!!" << endl;
			
			break;
		}

		carFuel -= usedFule;
		totalDistance += distance;
	}

	cout << "Total distance you travelled: " << totalDistance << " km" << endl;
			
	system("pause");
	return 0;
}
/*int integer;
	int even = 0;
	int odd = 0;
	cout << "Enter 10 Integers: " << endl;
	for (int i = 0; i < 10; i++) {
		cin >> integer;
		if (integer % 2 == 0) {
			even += 1;
		}
		else {
			odd += 1;
		}
	}
	cout << "Even numberzs are : " << even << endl;
	cout << "Odd numbers are : " << odd << endl;*/

/*int x, y;
	cout << "Enter a base integer: ";
	cin >> x;
	cout << "Enter the power: ";
	cin >> y;
	int power=1;
	for (int i = 1; i <= y; i++) {
		power *=x;
	}
	cout << power;*/

/*for (int j = 1; j <= 6; j++) {
		for (int i = 1; i <= 50; i++) {
			if (i % 2 == 0) {
				cout << i<<"  ";
			}
		}
		cout << endl;
	}*/

/*float previousReading, currentReading;

		cout << "Enter first temperature Reading: ";
		cin >> previousReading;

		while (true) {
			cout << "Enter next temperature Reading: ";
			cin >> currentReading;

			float difference = currentReading - previousReading;
			if (difference < 0)
				difference = -difference;

			if (difference < 0.5) {
				cout << "Liquid is stable now, Stopping The Service..." << endl;
				break;
			}

			previousReading = currentReading; 
		}*/