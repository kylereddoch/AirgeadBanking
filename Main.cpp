/*
Project Two: Airgead Banking App
Author: Kyle Reddoch
Date: 10/02/2022
Class: CS-210
 */

#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <string>
using namespace std;

#include "InvestmentData.h"
#include "UserDataCalculations.h"

// Function Prototypes
void dataInterface() {
	InvestmentData userInvestment; // Creates an object of the InvestmentData class
	UserDataCalculations dataCalculations; // Creates an object of the UserDataCalculations class

	double initialAmount, monthlyDeposit, interest; // User input variables
	int years;

	string choice;	// used later in the loop
	bool contRunning = true;	// determines if the loop continues

	do {

		system("cls");
		cout << setfill('*') << setw(34) << '*' << endl;
		cout << "*\t" << "Financial Data Input" << "\t *" << endl;
		cout << setfill('-') << setw(34) << '-' << endl;

		cout << "Initial Investment Amount: $";
		cin >> initialAmount;
		cout << endl;

		cout << "Monthly Deposit: $";
		cin >> monthlyDeposit;
		cout << endl;

		cout << "Annual Interest: %";
		cin >> interest;
		cout << endl;

		cout << "Number of years: ";
		cin >> years;
		cout << endl;


		// setting the data
		userInvestment.setInitialInvestment(initialAmount);
		userInvestment.setMonthlyDeposit(monthlyDeposit);
		userInvestment.setAnnualInterest(interest);
		userInvestment.setNumOfYears(years);

		// displaying the data
		cout << "Initial Investment Amount: " << setfill(' ') << right << setw(10) << "$" << userInvestment.getInitialInvestment() << endl;
		cout << "Monthly Deposit: " << setfill(' ') << right << setw(20) << "$" << userInvestment.getMonthlyDeposit() << endl;
		cout << "Annual Interest: " << setfill(' ') << right << setw(20) << " " << userInvestment.getAnnualInterest() << "%" << endl;
		cout << "Number of years: " << setfill(' ') << right << setw(20) << " " << userInvestment.getNumOfYears() << endl;

		cout << endl;
		// waiting for use input
		system("pause");


		// executing the methods to display calculated data
		try {
			dataCalculations.dataWithoutDeposits(userInvestment);
		}
		catch (const std::exception& exc) {
			cout << exc.what() << endl;
			cout << "error occurred with dataWithoutDeposits" << endl;
			contRunning = false;
		}

		try
		{
			dataCalculations.dataWithDeposits(userInvestment);
		}
		catch (const std::exception& exc)
		{
			cout << exc.what() << endl;
			cout << "error occurred with dataWithDeposits" << endl;
			contRunning = false;
		}

		cout << endl;

		// asking user if they want to continue
		cout << "Continue? y/n" << endl;
		cin >> choice;
		if (choice == "n") {
			contRunning = false;
		}
		else {
			continue;
		}



	} while (contRunning == true);

}
// Main Function
int main() {

	try {
		dataInterface();
	}
	catch (const std::exception& exc) {
		cout << exc.what() << endl;
		cout << "error occurred with dataInterface" << endl;
		system("pause");
	}
}

// end code