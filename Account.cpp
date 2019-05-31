#include "Account.h"

Account::Account()
{
	Balance = 0.0;
}

int Account::Transfer(Account& a, double d)
{
	if (GetBalance()-d < 0)
		return GetBalance()-d;

	a.SetBalance(a.GetBalance()+d);
	SetBalance(GetBalance()-d);

	return 0;
}