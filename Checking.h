#pragma once

#include "Account.h"


class Checking : public Account
{
public:
	Checking();

	//reporters
	inline bool GetOverdraftEnabled() { return OverdraftEnabled; };
	
	//mutators
	inline void SetOverdraftEnabled(bool inOE) { OverdraftEnabled = inOE; };
	int Withdraw(int MoneyToWithdraw);
	void Deposit(int MoneyToDeposit);

private:
	bool OverdraftEnabled;
};