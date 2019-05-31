#pragma once

#include "Customer.h"
#include "Savings.h"
#include "Checking.h"
#include "BankData.h"

class ATM
{
public:
	ATM();

	//reporters
	inline int GetPINAttempts() { return PINAttempts; };
	void DisplayBalances(Customer myCustomer);
	void Exit();
	bool ConfirmPIN(Customer myCustomer, int pin);
	void MainMenu(BankData& data); //returns pin

	//mutators
	bool TransferFunds(Account& SourceAccount, Account& DestinationAccount, double Amount);

	void SetCustomer(Customer* e);

private:
	int PINAttempts;
	Customer* cCustomer; //current customer
	Checking* CheckingAccount;
	Savings* SavingsAccount;
};