#include "Checking.h"

Checking::Checking()
{
	OverdraftEnabled = true;
}

void Checking::Deposit(int MoneyToDeposit)
{
	SetBalance(GetBalance() + MoneyToDeposit);
}

int Checking::Withdraw(int MoneyToWithdraw)
{
	if (GetBalance()-MoneyToWithdraw < 0)
		return GetBalance()-MoneyToWithdraw < 0;

	SetBalance(GetBalance() - MoneyToWithdraw);
	return 0;
}