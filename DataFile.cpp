#include "DataFile.h"

DataFile::DataFile()
{
	FileName = "";
	Delimiter = '\t';
}

bool DataFile::OpenFile()
{
	File.open(FileName);

	return File.is_open();
}

bool DataFile::CloseFile()
{
	File.close();

	return !File.is_open();
}

void DataFile::ReadAccount(BankData& data)
{
	if (OpenFile())
	{
		File.ignore(255,'\n');


		while (File.good())
		{
			char* ChkAcctId = new char[255];
			char* SavAcctID = new char[255];
			char* PIN = new char[255];
			char* ChkAcctBal = new char[255];
			char* SavAcctBal = new char[255];
			char* SvInt = new char[255];
			char OverdraftFlag;

			File >> ChkAcctId;
			File.ignore(1,Delimiter);
			File >> ChkAcctBal;
			File.ignore(1,Delimiter);
			File >> OverdraftFlag;
			File.ignore(1,Delimiter);
			File >> SavAcctID;
			File.ignore(1,Delimiter);
			File >> SavAcctBal;
			File.ignore(1,Delimiter);
			File >> SvInt;
			File.ignore(1,Delimiter);
			File >> PIN;

			data.AddAccount(atoi(ChkAcctId),atoi(SavAcctID),atoi(PIN),atof(ChkAcctBal),atof(SavAcctBal),atof(SvInt),OverdraftFlag == 'Y');

			delete[] ChkAcctId;
			delete[] SavAcctID;
			delete[] PIN;
			delete[] ChkAcctBal;
			delete[] SavAcctBal;
			delete[] SvInt;
		}
	}
}

void DataFile::UpdateAccount()
{
	
}