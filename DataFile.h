#pragma once

#include <fstream>
#include <string>
#include "BankData.h"

using namespace std;

class DataFile
{
public:
	DataFile();
	DataFile(string fname) { FileName = fname; }
	//reporters
	

	//mutators
	bool OpenFile();
	bool CloseFile();

	void ReadAccount(BankData& data);
	void UpdateAccount();

	inline void SetFileName(string inFileName) { FileName = inFileName; };

private:
	ifstream File;
	string FileName;
	
	char Delimiter;
	
};