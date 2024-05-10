// James Lightner
// CS 210
// 02/09/2024
// Module 5: Project 2

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <stdexcept>
#include "Banking.h"

using namespace std;

Banking myInvestment;
double initialInvestment;
double monthlyDeposit;
double annualInterest;
double months;
int years;
char user_input = 'a';
void PrintHomeScreen();
int validIntInput();
double validDoubleInput();

// Main function
int main() {
	while (user_input != 'q') {
		system("cls");
		PrintHomeScreen();

		myInvestment.calcBalanceWithoutMonthlyDeposit(myInvestment.GetInitialInvestment(), myInvestment.GetInterestRate(), myInvestment.GetNumberOfYears());
		myInvestment.balanceWithMonthlyDeposit(myInvestment.GetInitialInvestment(), myInvestment.GetMonthlyDeposit(), myInvestment.GetInterestRate(), myInvestment.GetNumberOfYears());

		cout << "Please enter 'q' to quit. Enter any other character or number to run another report. ";
		cin >> user_input;
	}

	return 0;
}

// Function to print the home screen and receive input from the user
void PrintHomeScreen() {
	try {
		cout << "**********************************" << endl;
		cout << "********** Data Input ************" << endl;
		cout << "Initial Investment Amount: $";
		//cin >> initialInvestment;
		initialInvestment = validDoubleInput();
		if (initialInvestment < 0) {
			throw runtime_error("Invalid Entry.");
		}
		myInvestment.SetInitialInvestment(initialInvestment);
		cout << "Monthly Deposit: $";
		monthlyDeposit = validDoubleInput();
		if (monthlyDeposit < 0) {
			throw runtime_error("Invalid Entry.");
		}
		myInvestment.SetMonthlyDeposit(monthlyDeposit);
		cout << "Annual Interest: %";
		annualInterest = validDoubleInput();;
		if (annualInterest < 0) {
			throw runtime_error("Invalid Entry.");
		}
		myInvestment.SetInterestRate(annualInterest);
		cout << "Number of years: ";
		years = validIntInput();
		if (years <= 0) {
			throw runtime_error("Invalid entry.");
		}
		myInvestment.SetNumberOfYears(years);

		system("PAUSE");
	}

	// Displays error to user and returns to the home screen 
	catch (runtime_error& excpt) {
		cout << excpt.what() << endl;
		cout << "Negative value is invalid." << endl;
		system("PAUSE");
		system("cls");
		PrintHomeScreen();
	}
}

// Validating to make sure input is an integer
int validIntInput() {
	int x;

	while (1) {
		if (cin >> x) {
			// valid number submitted
			break;
		}
		else {
			// invalid number submitted
			cout << "Invalid Entry!";
			cin.clear();
			while (cin.get() != '\n');
		}
	}

	return x;
}

// Validating to make sure input is a double
double validDoubleInput() {
	double x;

	while (1) {
		if (cin >> x) {
			// valid number
			break;
		}
		else {
			// not a valid number
			cout << "Invalid Entry!";
			cin.clear();
			while (cin.get() != '\n');
		}
	}

	return 0;
}