#include "Savings.h"

Savings:: Savings()
{
	InterestRate = .02;
}

Savings::Savings(double inIR, double inBalance)
{
	InterestRate = inIR;
	SetBalance(inBalance);
}

void Savings::Deposit(int MoneyToDeposit)
{
	SetBalance(GetBalance() + MoneyToDeposit);
}

int Savings::Withdraw(int MoneyToWithdraw)
{
	if (GetBalance()-MoneyToWithdraw < 0)
		return GetBalance()-MoneyToWithdraw < 0;

	SetBalance(GetBalance() - MoneyToWithdraw);
	return 0;
}