#include "ATM.h"
#include <iostream>
using namespace std;

ATM::ATM()
{
	PINAttempts = 0;
	cCustomer = NULL;
	CheckingAccount = NULL;
	SavingsAccount = NULL;
}

void ATM::MainMenu(BankData& data)
{
	int pin;
	bool bFound = false;
	int i=0;

	cout << "Welcome to the ATM" << endl
		<< "=================================" << endl
		<< "Enter your PIN #: ";

	while (!bFound && PINAttempts <= 3)
	{
		cin >> pin;

		if (cin.fail())
		{
			cout << "Not a valid PIN #" << endl;
			cin.clear();
			cin.ignore();
			return;
		}

		for (i=0;i<data.GetRecordCount();++i)
		{
			if (ConfirmPIN(data.GetCustomer(i),pin))
			{
				bFound = true;
				break;
			}
		}

		if (bFound)
			break;

		cout << "Incorrect PIN. Try again: ";
	}

	if (bFound)
	{
		cCustomer = &data.GetCustomer(i);
		CheckingAccount = &data.GetCustomer(i).GetCheckingAccount();
		SavingsAccount = &data.GetCustomer(i).GetSavingsAccount();
	}
	else
	{
		cout << "Too many incorrect entries" << endl;
		Exit();
	}

	string command;
	cout << "Enter a command" << endl
		<< "DisplayBalances" << endl
		<< "Deposit" << endl
		<< "Withdrawl" << endl
		<< "Transfer" << endl
		<< "Exit" << endl
		<< "Command: ";
	cin >> command;
	cin.ignore();

	if (command.compare("DisplayBalances") == 0)
	{
		DisplayBalances(*cCustomer);
	}
	else if (command.compare("Deposit") == 0)
	{
		int acc;
		double amt;

		cout << "How much would you like to deposit: ";
		cin >> amt;
		cin.ignore();

		cout << "Which account would you like to deposit into (1 - checking, 2 - savings): ";
		cin >> acc;
		cin.ignore();
		
		switch(acc)
		{
		case 1:
			cCustomer->CheckingDeposit(amt);
			break;
		case 2:
			cCustomer->SavingsDeposit(amt);
			break;
		}

		cout << "Deposit complete" << endl;
	}
	else if (command.compare("Withdrawl") == 0)
	{
		int acc;
		double amt;

		cout << "How much would you like to withdraw: ";
		cin >> amt;
		cin.ignore();

		cout << "Which account would you like to withdraw from (1 - checking, 2 - savings): ";
		cin >> acc;
		cin.ignore();
		
		if (acc == 1)
		{
			if (cCustomer->GetCheckingBal()-amt < 0)
				cout << "Insufficient funds" << endl;
			else
				cCustomer->CheckingWithdraw(amt);
		}
		else if (acc == 2)
		{
			if (cCustomer->GetSavingsBal()-amt < 0)
				cout << "Insufficient funds" << endl;
			else
				cCustomer->SavingsWithdraw(amt);
		}
		cout << "Withdrawl complete" << endl;
	}
	else if (command.compare("Transfer") == 0)
	{
		int acc;
		double amt;

		cout << "How much would you like to transfer: ";
		cin >> amt;
		cin.ignore();

		cout << "Which account would you like to withdraw from (1 - checking, 2 - savings): ";
		cin >> acc;
		cin.ignore();

		if (acc == 1)
		{
			if (!TransferFunds(cCustomer->GetCheckingAccount(),cCustomer->GetSavingsAccount(),amt))
				cout << "Insufficient funds" << endl;
			else
				cout << "Transfer complete" << endl;
		}
		else if (acc == 2)
		{
			if (!TransferFunds(cCustomer->GetSavingsAccount(),cCustomer->GetCheckingAccount(),amt))
				cout << "Insufficient funds" << endl;
			else
				cout << "Transfer complete" << endl;
		}
	}
	else if (command.compare("Exit") == 0)
		Exit();
			
}

void ATM::DisplayBalances(Customer myCustomer)
{
	cout << "Your Checking Account Balance: $" << setprecision(2) << fixed << CheckingAccount->GetBalance() << endl;
	cout << "Your Savings Account Balance: $" << setprecision(2) << fixed << SavingsAccount->GetBalance() << endl;
	cout << endl;
}

void ATM::Exit()
{
	cout << "Thank you for using the ATM" << endl;
	exit(0);
}

bool ATM::ConfirmPIN(Customer myCustomer, int pin)
{
	if (myCustomer.GetPIN() == pin)
		return true;
	else
		++PINAttempts;
}

bool ATM::TransferFunds(Account& SourceAccount, Account& DestinationAccount, double Amount)
{
	if (SourceAccount.Transfer(DestinationAccount,Amount) == 0)
		return true;

	return false;
}

void ATM::SetCustomer(Customer* e)
{
	cCustomer = e;


}