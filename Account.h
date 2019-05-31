#pragma once

class Account
{
public:
	Account();

	//reporters
	inline double GetBalance() { return Balance; };
	inline int GetID() { return ID; }
	inline int GetPIN() { return CustomerPIN; }

	//mutator
	inline void SetBalance(double inBalance) { Balance = inBalance; };
	inline void SetID(int id) { ID = id; }
	inline void SetPIN(int pin) { CustomerPIN = pin; }

	int Transfer(Account& a, double d);

	virtual int Withdraw(int MoneyToWithdraw) = 0;
	virtual void Deposit(int MoneyToDeposit) = 0;

private:
	double Balance;

	int ID;
	int CustomerPIN;
};