#pragma once

#include <iostream>
#include <iomanip>
#include "Customer.h"

class BankData
{
private:
	Customer* Customers;
	Checking* ChkAccounts;
	Savings* SavAccounts;
	int RecordCount;
	int MaximumAccounts; //total account record data structure size
public:
	BankData();
	void AddAccount(int cid, int sid, int pin, double cbal, double sbal, double sint, bool odflag);
	void WriteCustomersToFile();
	inline int GetRecordCount() { return RecordCount; }
	Customer& GetCustomer(int i) { return Customers[i]; }
};

std::ostream& operator<< (std::ostream& os, BankData* dat);
