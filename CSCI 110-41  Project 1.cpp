/****************************************************************
File: CSCI 110-41  Project 1.cpp
Description: Cashier's Calculator

Author:	Nathan Bush
Class: CSCI 110-41 - Introduction to Computer Science I
Date: 9/27/2020

I hereby certify that this program is entirely my own work.
*****************************************************************/
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <limits>

using namespace std;

/* Function to prompt user to repeat program or end with input validation
   Parameter: none
   Returns: boolean value. true == repeat, false == end */
bool RunAgain() {
	// get user input 
	char againChoice;
	cout << "Would you to start another order? (y/n)";
	cin >> againChoice;

	// input validation for any value not n, N, y, or Y
	while ((!cin) || ((againChoice != 'n') && (againChoice != 'N') &&
		(againChoice != 'y') && (againChoice != 'Y'))) {
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Invalid input, please use (y/n): ";
		cin >> againChoice;
	}

	// return boolean
	if ((againChoice == 'n') || (againChoice == 'N')) {
		return false;
	}
	else {
		return true;
	}
}

/* Function to prompt user for item price with input validation
   Parameter: string containing name of the item
   Returns: double representing price of the item */
double GetPrice(string itemName) {
	// get user input for price
	double itemPrice;
	cout << "Enter the price of " << itemName << ": $";
	cin >> itemPrice;

	// input validation for type error and positive value
	while ((!cin) || (itemPrice <= 0.00)) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Bad input, please enter a dollar amount in the format x.xx: $";
		cin >> itemPrice;
	}

	return itemPrice;
}

/* Function to test if string contains all alpha or white space characters
   Parameter: string to be tested
   Returns: true if string is all alpha or white space, false otherwise */
bool AllAlpha(string testString) {
	for (int i = 0; i < testString.size(); i++) {
		if (!(isalpha(testString[i]) || (isspace(testString[i])))) {
			return false;
		}
	}
	return true;
}

/* Function to prompt user for item name with input validation
   Parameter: int containing the number of the item in the list
   Returns: string containing the name of the item */
string GetName(int i) {
	// get user data for itemName
	string itemName;
	cout << "Enter the name of item " << i << ": ";
	cin >> ws;
	getline(cin, itemName);

	// input validation for all alpha and white space using AllAlpha function call
	while (!AllAlpha(itemName)) {
		cout << "Bad input, please enter the name of item " << i << " using letters and spaces only: ";
		cin >> ws;
		getline(cin, itemName);
	}

	return itemName;
}

/* Function to prompt user for item quantity with input validation
   Parameter: string containing name of the item
   Returns: int representing the quantity */
int GetQty(string itemName) {
	// get user input for item quantity
	int itemQty;
	cout << "Enter the quantity of " << itemName << ": ";
	cin >> itemQty;

	// input validation for type error and positive value
	while ((!cin) || (itemQty <= 0)) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Bad input, please enter a valid quantity: ";
		cin >> itemQty;
	}

	cout << endl;
	return itemQty;
}

int main()
{
	// initialize loop variable to true and begin program loop
	bool runProgram = true;
	while (runProgram == true) {
		cout << "---------- Nate's Pretty Decent Store Cashier's Program ----------" << endl << endl;

		// call functions to get user data for item 1
		string firstName = GetName(1);
		double firstPrice = GetPrice(firstName);
		int firstQty = GetQty(firstName);

		// call functions to get user data for item 2
		string secondName = GetName(2);
		double secondPrice = GetPrice(secondName);
		int secondQty = GetQty(secondName);

		// call functions to get user data for item 3
		string thirdName = GetName(3);
		double thirdPrice = GetPrice(thirdName);
		int thirdQty = GetQty(thirdName);

		// prompt user input for tax rate
		double taxRate;
		cout << "Enter tax rate (%): ";
		cin >> taxRate;

		// input validation for taxRate type error and positive value between 0-100, inclusive
		while ((!cin) || (taxRate < 0.00) || (taxRate > 100.00)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Bad input, please enter a valid tax rate between 0%-100%: ";
			cin >> taxRate;
		}

		// perform calculations for totals table
		double firstTotal = firstPrice * firstQty;
		double secondTotal = secondPrice * secondQty;
		double thirdTotal = thirdPrice * thirdQty;

		double subTotal = firstTotal + secondTotal + thirdTotal;
		double taxAmount = subTotal * (taxRate / 100);
		double grandTotal = subTotal + taxAmount;

		// display totals table
		cout << endl << endl;
		cout << "-------------------- Cost Summary --------------------" << endl;
		cout << left << setw(16) << "Item" << setw(4) << "Unit" << right << setw(6) << "Price" << setw(10) << "Quantity" << setw(8) << " " << setw(10) << "Cost" << endl;
		cout << left << setw(16) << "----" << setw(4) << "----" << right << setw(6) << "------" << setw(10) << "--------" << setw(8) << "-" << setw(10) << "----------" << endl;
		cout << fixed << setprecision(2) << left << setw(16) << firstName << setw(4) << "$" << right << setw(6) << firstPrice << setw(10) << firstQty << setw(8) << "$" << setw(10) << firstTotal << endl
			<< left << setw(16) << secondName << setw(4) << "$" << right << setw(6) << secondPrice << setw(10) << secondQty << setw(8) << "$" << setw(10) << secondTotal << endl
			<< left << setw(16) << thirdName << setw(4) << "$" << right << setw(6) << thirdPrice << setw(10) << thirdQty << setw(8) << "$" << setw(10) << thirdTotal << endl;
		cout << "------------------------------------------------------" << endl;
		cout << fixed << setprecision(2) << left << setw(36) << "Total before tax:" << right << setw(8) << "$" << setw(10) << subTotal << endl;
		cout << fixed << setprecision(2) << left << setw(36) << "Tax:" << right << setw(8) << "$" << setw(10) << taxAmount << endl;
		cout << "------------------------------------------------------" << endl;
		cout << fixed << setprecision(2) << left << setw(36) << "Total Cost:" << right << setw(8) << "$" << setw(10) << grandTotal << endl << endl;
		cout << "Now tell the customer the total cost of the purchase" << endl;

		// prompt for cash tendered
		double cashTendered;
		cout << "How much money did the customer give you?  $";
		cin >> cashTendered;

		// input validation for cashTendered type error and > grandTotal
		while ((!cin) || (cashTendered < grandTotal)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Bad input, please enter a valid dollar amount greater than the order total: ";
			cin >> cashTendered;
		}

		// calculate change
		double custChange = cashTendered - grandTotal;

		int hundBill = custChange / 100;
		double newChange = custChange - (hundBill * 100);

		int twentyBill = newChange / 20;
		newChange = newChange - (twentyBill * 20);

		int fiveBill = newChange / 5;
		newChange = newChange - (fiveBill * 5);

		int oneBill = newChange / 1;
		newChange = newChange - (oneBill);

		int quartCoin = newChange / 0.25;
		newChange = newChange - (quartCoin * 0.25);

		int dimeCoin = newChange / 0.1;
		newChange = newChange - (dimeCoin * .1);

		int nickCoin = newChange / 0.05;
		newChange = newChange - (nickCoin * 0.05);

		int pennyCoin = newChange / 0.01;


		// display change table
		cout << endl << "Calculating change..." << endl
			<< "------------------------------" << endl
			<< fixed << setprecision(2) << left << setw(20) << "Change: $" << right << setw(10) << cashTendered - grandTotal << endl
			<< "------------------------------" << endl << endl;
		cout << "Denominations..." << endl;
		cout << left << setw(20) << "$100 bills:" << right << setw(10) << hundBill << endl;
		cout << left << setw(20) << "$20 bills:" << right << setw(10) << twentyBill << endl;
		cout << left << setw(20) << "$5 bills:" << right << setw(10) << fiveBill << endl;
		cout << left << setw(20) << "$1 bills:" << right << setw(10) << oneBill << endl;
		cout << left << setw(20) << "quarters:" << right << setw(10) << quartCoin << endl;
		cout << left << setw(20) << "dimes:" << right << setw(10) << dimeCoin << endl;
		cout << left << setw(20) << "nickels:" << right << setw(10) << nickCoin << endl;
		cout << left << setw(20) << "pennies:" << right << setw(10) << pennyCoin << endl << endl;

		// prompt user to repeat program or end
		runProgram = RunAgain();
	}
}

