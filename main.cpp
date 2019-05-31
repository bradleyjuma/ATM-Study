#include "ATM.h"
#include "BankData.h"
#include "DataFile.h"
#include "Customer.h"

int main()
{
	DataFile datafile("accounts.txt");
	BankData bankData;
	ATM Atm;

	datafile.ReadAccount(bankData);

	//ifstream file("Customers.txt");

	while (true)
		Atm.MainMenu(bankData);
	
}