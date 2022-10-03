#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <string>
using namespace std;

#include "UserDataCalculations.h"

void UserDataCalculations::dataWithoutDeposits(InvestmentData t_userInvestment) {
	/* first display without monthly deposits */

	// initializing local vars with the user data
	double initialInvestment = t_userInvestment.getInitialInvestment();
	int years = t_userInvestment.getNumOfYears();

	// data for proper message alignment
	int screenWidth = 80;
	string balanceMsg = "Balance & Interest Without Additional Monthly Deposits";
	int centerScreen = balanceMsg.length() / 2;
	int halfWidth = screenWidth / 2;
	int sizeToCenter = halfWidth + centerScreen;

	cout << endl;

	/* main header for data */
	cout << setfill(' ') << setw(sizeToCenter) << balanceMsg << setfill(' ') << setw(sizeToCenter) << endl;
	cout << setfill('=') << setw(80) << '=' << endl;
	cout << setfill(' ') << left << setw(26) << "Year" << "Year End Earned Interest" << right << setw(30) << "Year End Balance" << endl;
	cout << setfill('-') << setw(80) << '-' << endl;

	// adds the initial amount to the total

	t_userInvestment.setTotalWithoutDeposits(initialInvestment);
	double interestYTD = 0;

	unsigned int yearCount, monthCount;

	// runs calculations
	for (yearCount = 1; yearCount <= years; yearCount++) {
		for (monthCount = 1; monthCount <= 12; monthCount++) {
			interestYTD += t_userInvestment.calcInterestWithoutDeposits();
		}
		t_userInvestment.setTotalWithoutDeposits(interestYTD);	// adds total interest from the year to main total
		cout << setfill(' ') << left << setw(30) << yearCount;
		cout << "$" << fixed << setprecision(2) << interestYTD;
		cout << right << setw(35) << "$" << fixed << setprecision(2) << t_userInvestment.getTotalWithoutDeposits() << endl;

		interestYTD = 0; // reset 
	}
}

void UserDataCalculations::dataWithDeposits(InvestmentData t_userInvestment) {
	/* second display without monthly deposits */

	// initializing local vars with the user data
	double initialInvestment = t_userInvestment.getInitialInvestment();
	double monthlyDeposit = t_userInvestment.getMonthlyDeposit();
	int years = t_userInvestment.getNumOfYears();

	string balanceMsg = "Balance & Interest With Additional Monthly Deposits";
	int screenWidth = 80;

	// data for proper message alignment
	int centerScreen = balanceMsg.length() / 2;
	int halfWidth = screenWidth / 2;
	int sizeToCenter = halfWidth + centerScreen;

	cout << endl;

	/* main header for data */
	cout << setfill(' ') << setw(sizeToCenter) << balanceMsg << setfill(' ') << setw(sizeToCenter) << endl;
	cout << setfill('=') << setw(80) << '=' << endl;
	cout << setfill(' ') << left << setw(26) << "Year" << "Year End Earned Interest" << right << setw(30) << "Year End Balance" << endl;
	cout << setfill('-') << setw(80) << '-' << endl;

	// adds the initial amount to the total
	t_userInvestment.setTotalWithDeposits(initialInvestment);

	// reset interest totals
	double interestYTD = 0;

	unsigned int yearCount, monthCount;

	// runs the calculations
	for (yearCount = 1; yearCount <= years; yearCount++) {
		for (monthCount = 1; monthCount <= 12; monthCount++) {
			t_userInvestment.setTotalWithDeposits(monthlyDeposit);			// adds the monthly deposit to total
			double interest = t_userInvestment.calcInterestWithDeposits();	// gets interest calculation
			t_userInvestment.setTotalWithDeposits(interest);				// adds the new interest to total
			interestYTD += interest;
		}
		// adds total interest from the year to main total
		cout << setfill(' ') << left << setw(26) << yearCount;
		cout << "$" << fixed << setw(37) << setprecision(2) << interestYTD;
		cout << left << "$" << fixed << setprecision(2) << t_userInvestment.getTotalWithDeposits() << endl;

		interestYTD = 0; // reset
	}
}

// end code