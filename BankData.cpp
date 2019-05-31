#include "BankData.h"
#include <fstream>
using namespace std;

BankData::BankData()
{
	Customers = new Customer[25];
	ChkAccounts = new Checking[25];
	SavAccounts = new Savings[25];

	RecordCount = 0;
	MaximumAccounts = 25;
}

void BankData::AddAccount(int cid, int sid, int pin, double cbal, double sbal, double sint, bool odflag)
{
	if (RecordCount > MaximumAccounts+1)
	{
		Customer* tmp = new Customer[MaximumAccounts];

		for (int i=0;i<MaximumAccounts;++i)
			tmp[i] = Customers[i];

		Customers = new Customer[MaximumAccounts*2];

		for (int i=0;i<MaximumAccounts;++i)
			Customers[i] = tmp[i];

		delete[] tmp;

		MaximumAccounts *= 2;
	}
	Customers[RecordCount].SetID(RecordCount+1);
	Customers[RecordCount].SetCheckingID(cid);
	Customers[RecordCount].SetSavingsID(sid);
	Customers[RecordCount].SetPIN(pin);
	Customers[RecordCount].SetCheckingBal(cbal);
	Customers[RecordCount].SetSavingsBal(sbal);
	Customers[RecordCount].SetSavingsInt(sint);
	Customers[RecordCount].SetOverdraft(odflag);

	++RecordCount;
}

void BankData::WriteCustomersToFile()
{
	ofstream file;

	file.open("AccountReport.txt");

	file << this;

	file.close();
}

std::ostream& operator<< (std::ostream& os, BankData* dat)
{
	for (int i=0;i<dat->GetRecordCount();++i)
	{
		os << "Customer ID: " << dat->GetCustomer(i).GetID() << endl
			<< "PIN: " << dat->GetCustomer(i).GetPIN() << endl
			<< "Name: " << dat->GetCustomer(i).GetName() << endl
			<< "Address: " << dat->GetCustomer(i).GetCustomerInfo() << endl
			<< "Checking Acct No.: " << dat->GetCustomer(i).GetCheckingID() << endl
			<< "Checking Acct Bal: $" << setprecision(2) << dat->GetCustomer(i).GetCheckingBal() << endl
			<< "Overdraft: " << dat->GetCustomer(i).GetOverdraft() << endl
			<< "Savings Acct No.: " << dat->GetCustomer(i).GetSavingsID() << endl
			<< "Savings Acct Bal: $" << setprecision(2) << dat->GetCustomer(i).GetSavingsBal() << " (" << dat->GetCustomer(i).GetSavingsInt() << "%)" << endl
			<< endl;
	}

	return os;
}