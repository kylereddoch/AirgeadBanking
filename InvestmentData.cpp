#include <iostream>
using namespace std;

#include "InvestmentData.h"

void InvestmentData::setInitialInvestment(double t_initialInvestment) { // sets initial investment
	this->m_initialInvestment = t_initialInvestment;
}

void InvestmentData::setMonthlyDeposit(double t_monthlyDeposit) { // sets monthly deposit
	this->m_monthlyDeposit = t_monthlyDeposit;
}

void InvestmentData::setAnnualInterest(double t_annualInterest) { // sets annual interest
	this->m_annualInterest = t_annualInterest;
}

void InvestmentData::setNumOfYears(int t_numOfYears) { // sets number of years
	this->m_numOfYears = t_numOfYears;
}


double InvestmentData::calcInterestWithoutDeposits() { // calculates interest without deposits
	return ((this->m_totalWithoutDeposits) * ((this->m_annualInterest / 100) / 12));
}


double InvestmentData::calcInterestWithDeposits() { // calculates interest with deposits
	return ((this->m_totalWithDeposits) * ((this->m_annualInterest / 100) / 12));
}

void InvestmentData::setTotalWithoutDeposits(double t_amount) { // sets total without deposits
	this->m_totalWithoutDeposits += t_amount;
}

void InvestmentData::setTotalWithDeposits(double t_amount) { // sets total with deposits
	this->m_totalWithDeposits += t_amount;
}


double InvestmentData::getTotalWithDeposits() { // gets total with deposits
	return this->m_totalWithDeposits;
}

double InvestmentData::getTotalWithoutDeposits() { // gets total without deposits
	return this->m_totalWithoutDeposits;
}
