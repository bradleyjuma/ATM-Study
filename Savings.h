#pragma once
#include "Account.h"

class Savings : public Account
{
public:
	Savings();
	Savings(double inIR, double inBalance);
	
	//reporters
	inline double GetIR() { return InterestRate; };

	//mutators
	inline void SetIR(double inIR) { InterestRate = inIR; };

	int Withdraw(int MoneyToWithdraw);
	void Deposit(int MoneyToDeposit);

private:
	double InterestRate;
};