#include<iostream>
using namespace std;
int main()
{
	char fuleType;
	float distance;
	float fuleConsuption;
	float fulePrice;

	cout << "Enter the fule type for your car: ";
	cin >> fuleType;
	cout << "Enter the total distance you travel: ";
	cin >> distance;
	cout << "Enter the fule consuption of yoyur car per KM: ";
	cin >> fuleConsuption;
	cout << "Enter the price of fule per leter: ";
	cin >> fulePrice;
	double totalFule_Consuption = distance / fuleConsuption;
	double totalFule_Cost = totalFule_Consuption * fulePrice;
	cout << "Total fule cost of the trip is: " << totalFule_Cost << endl;


	system("pause");
	return 0;
}

/*char planType;
	float dataUsed;
	float cost_per_GP;
	int number_of_Days;

	cout << "Enter the plan type of your internet \n (M for)Monthly \n (W for) Weekly: \n";
	cin >> planType;
	cout << "Enter the used data in GBs: ";
	cin >> dataUsed;
	cout << "Enter the cost of data per GB: ";
	cin >> cost_per_GP;
	cout << "Enter the number of days of pakage: ";
	cin >> number_of_Days;
	float totalBill = dataUsed * cost_per_GP;
	cout << "Your Bill: " << totalBill << endl;*/

/*char mealCode;
	int number_Of_Meal;
	float price_per_meal;
	double gstTax;

	cout << "Enter the meal code like for Pizza P & for Burger B: ";
	cin >> mealCode;
	cout << "Enter the number of Meal you order: ";
	cin >> number_Of_Meal;
	cout << "Enter the price per meal: ";
	cin >> price_per_meal;
	cout << "Enter the GST: ";
	cin >> gstTax;

	double TotalBill = number_Of_Meal * price_per_meal;
	double bill_with_GST = TotalBill + (TotalBill * gstTax / 100);
	cout << "Your Bill is : " << TotalBill << endl;
	cout << "Your Bill After adding GST: " << bill_with_GST << endl;*/

/*char roomType;
	int number_of_Days;
	float dailyRent;
	float gstTax;

	cout << "Enter the Room Type: \n 1. (E for) Economy \n 2. (B for) Bussiness" << endl;
	cin >> roomType;
	cout << "For how many day you stay in this room: ";
	cin >> number_of_Days;
	cout << "Enter the per day rent of room: ";
	cin >> dailyRent;
	cout << "Enter the GST: ";
	cin >> gstTax;
	float totalBill = dailyRent * number_of_Days;
	float totalGst = totalBill + (totalBill * gstTax / 100);
	cout << "Total Bill: " << totalBill << endl;
	cout << "Bill after adding GST: " << totalGst << endl;*/

/* {
		int rollNumber;
		char gender;
		float GPA;
		double attendencePercentage;
		cout << "Enter the roll number: " << endl;
		cin >> rollNumber;
		cout << "Enter your gender: " << endl << "For male M,  For Female F, For Other O" << endl;
		cin >> gender;
		cout << "Enter your GPA: " << endl;
		cin >> GPA;
		cout << "Enter your Attendence Percentage: " << endl;
		cin >> attendencePercentage;

		cout << "Your Details are given below: " << endl;
		cout << "Your rollnumber is: " << rollNumber << endl;
		cout << "Your GPA is:" << GPA << endl;
		cout << "Your Gender is: " << gender << endl;
		cout << "Your Attendence is: " << attendencePercentage << endl;
	}*/
	/*{
		char productCategoriCode;
		int productId,quantity;
		float price;
		double discountRate;
		cout << "Enter the Product Categori Code in single Character: " << endl;
		cin >> productCategoriCode;
		cout << "Enter the product id: " << endl;
		cin >> productId;
		cout << "Enter the quantity of product: " << endl;
		cin >> quantity;
		cout << "enter the price of theproduct: " << endl;
		cin >> price;
		cout << "enter the amount of discount" << endl;
		cin >> discountRate;

		float total = price * quantity;
		double discount_Amount = total * (discountRate / 100);
		double bill = total - discount_Amount;

		cout << "Product Categori: " << productCategoriCode << endl;
		cout << "Product ID: " << productId << endl;
		cout << "Product Quantity: " << quantity << endl;
		cout << "Total Bill: " << total << endl;
		cout << "Discount: " << discount_Amount << endl;
		cout << "Bill after Discount: " << bill << endl;


	}*/

	/*
	{
		char employeType;
		int workingHours;
		float hourlyRate;

		cout << "Enter the employ type: " << endl << "1. For Permanent type P" << endl << "2. For Temporary Type T" << endl;
		cin >> employeType;
		cout << "Enter you Working Hours: ";
		cin >> workingHours;
		cout << "Enter the Rate of One Hour: ";
		cin >> hourlyRate;

		cout << "Your total salary is: " << workingHours * hourlyRate << endl;

	}
	*/