#pragma once

#include <string>
#include "Checking.h"
#include "Savings.h"

using namespace std;

class Customer
{
private:
	int ID;
	int PIN;
	string Name;
	string Address;
	string Phone;
	int ZipCode;
	string City;
	string State;

	Checking CheckingAccount;
	Savings SavingsAccount;

public:
	Customer();
	Customer(int inID, int inPIN, string inName, string inAddress, string inPhone, int inZipCode,
		string inCity, string inState);
	
	//Reporters
	inline int GetID() { return ID; }
	inline int GetPIN() { return PIN; };
	inline string GetName() { return Name; };
	inline string GetCustomerInfo() { return (Address + City + State); };
	inline int GetCheckingID() { return CheckingAccount.GetID(); }
	inline int GetSavingsID() { return SavingsAccount.GetID(); }
	inline double GetCheckingBal() { return CheckingAccount.GetBalance(); }
	inline double GetSavingsBal() { return SavingsAccount.GetBalance(); }
	inline double GetSavingsInt() { return SavingsAccount.GetIR(); }
	inline char GetOverdraft() { if (CheckingAccount.GetOverdraftEnabled()) return 'Y'; else return 'N'; }
	Checking& GetCheckingAccount() { return CheckingAccount; }
	Savings& GetSavingsAccount() { return SavingsAccount; }

	//Mutators
	inline void SetID(int custid) { ID = custid; }
	inline void SetPIN(int inPIN) { PIN = inPIN; };
	inline void SetName(string inName) { Name = inName; };
	inline void SetCheckingID(int id) { CheckingAccount.SetID(id); }
	inline void SetSavingsID(int id) { SavingsAccount.SetID(id); }
	inline void SetCheckingBal(double bal) { CheckingAccount.SetBalance(bal); }
	inline void SetSavingsBal(double bal) { SavingsAccount.SetBalance(bal); }
	inline void SetSavingsInt(double intr) { SavingsAccount.SetIR(intr); }
	inline void SetOverdraft(bool od) { CheckingAccount.SetOverdraftEnabled(od); }

	inline void CheckingDeposit(double n) { CheckingAccount.Deposit(n); }
	inline void SavingsDeposit(double n) { SavingsAccount.Deposit(n); }
	inline void CheckingWithdraw(double n) { CheckingAccount.Withdraw(n); }
	inline void SavingsWithdraw(double n) { SavingsAccount.Withdraw(n); }

};