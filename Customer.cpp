#include "Customer.h"

Customer::Customer()
{
	ID = 0;
	PIN = 0;
	Name = "";
	Address = "";
	Phone = "";
	ZipCode = 0;
	City = "";
	State = "";
}

Customer::Customer(int inID, int inPIN, string inName, string inAddress, string inPhone, int inZipCode,
		string inCity, string inState)
{
	ID = inID;
	PIN = inPIN;
	Name = inName;
	Address = inAddress;
	Phone = inPhone;
	ZipCode = inZipCode;
	City = inCity;
	State = inState;
}

