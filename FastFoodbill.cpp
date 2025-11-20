#include<iostream>
using namespace std;
int main() {

	cout << "\t ----//Welcome to Riphah Fast Foods\\---- \n";
	cout << "\tItem \t\t Price \t\t Key\n";
	cout << "\tBurger \t\t 250\\- \t\t B\n";
	cout << "\tPizza \t\t 1250\\- \t P\n";
	cout << "\tFries \t\t 250\\- \t\t F\n";

	cout << "\n \t Press Key: ";

	char choice;
	int quantity;
	double bill;
	double tax;
	double totalBill;
	char paymentMethod;
	cin >> choice;
	choice=tolower (choice);
		
	switch (choice)
	{
	 case 'p':
		 cout << "\t Enter The Quantity of Pizza: ";
		 cin >> quantity;
		 if (quantity <= 0) {
			 cout << "Invalid Quantity";
		 }
		 else {
			 bill = quantity * 1250;
		 }

		 break;
     
	 case 'b':
		 cout << "\tEnter The Quantity of Burger: ";
		 cin >> quantity;
		 if (quantity <= 0) {
			 cout << "Invalid Quantity";
		 }
		 else {
			 bill = quantity * 250;
		 }


		 break;

	 case 'f':
		 cout << "\tEnter The Quantity of Fries: ";
		 cin >> quantity;
		 if (quantity <= 0) {
			 cout << "Invalid Quantity";
		 }
		 else {
			 bill = quantity * 250;
		 }


		 break;
	 default:
		 cout << "\t Invalid Key";
		 return 0;
	}

	cout << "\t Payment Method \t\t Key \t\t Tax \n";
	cout << "\t Online \t\t    \t O \t\t 6% \n";
	cout << "\t Cash \t\t        \t C \t\t 16% \n";

	cout << "\t Press Key: ";
	cin >> paymentMethod;
	paymentMethod = tolower(paymentMethod);

	switch (paymentMethod)
	{
	case 'o':
		tax = (bill / 100) * 6;
		totalBill = tax + bill;
		break;
	case 'c':
		tax = (bill / 100) * 16;
		totalBill = tax + bill;
		break;
	default:
		cout << "\tInvalid Key";
		return 0;
	}

	// Displaying Bill
	if (paymentMethod == 'o') {
		if (choice == 'b') {
			cout << "\t *** Bill Details *** \n";
			cout << "\tYour Bill: " << bill << endl;
			cout << "\tTax on Bill: " << tax << endl;
			cout << "\tYour TotalBill: " << totalBill << endl;
			cout << "\tThanks For Coming...\n";
		}
		else if(choice=='p')
		{
			cout << "\t *** Bill Details *** \n";
			cout << "\tYour Bill: " << bill << endl;
			cout << "\tTax on Bill: " << tax << endl;
			cout << "\tYour TotalBill: " << totalBill << endl;
			cout << "\tThanks For Coming...\n";
		}
		else{
			cout << "\t *** Bill Details *** \n";
			cout << "\tYour Bill: " << bill << endl;
			cout << "\tTax on Bill: " << tax << endl;
			cout << "\tYour TotalBill: " << totalBill << endl;
			cout << "\tThanks For Coming...\n";
		}
	}
	else  {
		if (choice == 'b') {
			cout << "\t *** Bill Details *** \n";
			cout << "\tYour Bill: " << bill << endl;
			cout << "\tTax on Bill: " << tax << endl;
			cout << "\tYour TotalBill: " << totalBill << endl;
			cout << "\tThanks For Coming...\n";
		}
		else if (choice == 'p')
		{
			cout << "\t *** Bill Details *** \n";
			cout << "\tYour Bill: " << bill << endl;
			cout << "\tTax on Bill: " << tax << endl;
			cout << "\tYour TotalBill: " << totalBill << endl;
			cout << "\tThanks For Coming...\n";
		}
		else {
			cout << "\t *** Bill Details *** \n";
			cout << "\tYour Bill: " << bill << endl;
			cout << "\tTax on Bill: " << tax << endl;
			cout << "\tYour TotalBill: " << totalBill << endl;
			cout << "\tThanks For Coming...\n";
		}

	}
	  

	return 0;
}