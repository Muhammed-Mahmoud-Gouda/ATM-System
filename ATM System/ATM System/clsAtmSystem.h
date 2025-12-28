#pragma once
#include <iostream>
#include<vector>
#include<fstream>
#include"clsPerson.h"
#include"clsString.h"
#include"clsUtil.h"
using namespace std;

class clsAtmSystem:public clsPerson
{
private:

	enum enMode {EmptyMode , UpdateMode};

	enMode _Mode;

	string _AccountNumber;
	string _PinCode;
	double _AccountBalance;

	struct stLoginRegister;
	struct stTransactionsRegister;


	static string _ConvertLoginRecordToLine(stLoginRegister LoginRegister, string Sperator = "#//#")
	{
		string Line;

		Line += LoginRegister.DateAndTime + Sperator;
		Line += LoginRegister.AccountNumber + Sperator;
		Line += LoginRegister.PinCode;

		return Line;
	}

	static string _ConvertTransactionRecordToLine(stTransactionsRegister TransactionRegister, string Sperator = "#//#")
	{
		string Line;

		Line += TransactionRegister.DateAndTime + Sperator;
		Line += TransactionRegister.AccountNumber + Sperator;
		Line += TransactionRegister.TransactionName;
		Line += Sperator + to_string(TransactionRegister.AmountOfTransaction);
		
		return Line;
	}

	static stLoginRegister _ConvertLoginLineToRecord(string Line,string Sperator ="#//#")
	{
		stLoginRegister LoginRegister;
		vector<string> vString = clsString::Split(Line, Sperator);

		LoginRegister.DateAndTime = vString[0];
		LoginRegister.AccountNumber = vString[1];
		LoginRegister.PinCode = vString[2];

		return LoginRegister;
	}

	static stTransactionsRegister _ConvertTransactionLineToRecord(string Line, string Sperator = "#//#")
	{
		stTransactionsRegister Transaction;
		vector<string> vString = clsString::Split(Line, Sperator);

		Transaction.DateAndTime = vString[0];
		Transaction.AccountNumber = vString[1];
		Transaction.TransactionName = vString[2];
		Transaction.AmountOfTransaction = stod(vString[3]);
	
		return Transaction;
	}

	static vector<stLoginRegister> _LoadLoginRegisterDataFromFile()
	{
		vector<stLoginRegister> vLoginRegister;

		fstream MyFile;
		MyFile.open("LoginRegister.txt", ios::in);

		if(MyFile.is_open())
		{
			string Line;

			stLoginRegister LoginRegister;

			while (getline(MyFile, Line))
			{

				LoginRegister = _ConvertLoginLineToRecord(Line);

				vLoginRegister.push_back(LoginRegister);

			}

			MyFile.close();
		}

		return vLoginRegister;
	}

	static vector<stTransactionsRegister> _LoadTransactionRegisterDataFromFile()
	{
		vector<stTransactionsRegister> vTransactionRegister;

		fstream MyFile;
		MyFile.open("Transactions.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;

			stTransactionsRegister TransactionRegister;

			while (getline(MyFile, Line))
			{

				TransactionRegister = _ConvertTransactionLineToRecord(Line);

				vTransactionRegister.push_back(TransactionRegister);

			}

			MyFile.close();
		}

		return vTransactionRegister;
	}

	static void _AddRegisterDataToFile(string Line , string FileName)
	{
		fstream MyFile;

		MyFile.open(FileName, ios::out | ios::app);

		if (MyFile.is_open())
		{

			MyFile << Line << endl;

		}

	}

	static clsAtmSystem _ConvertLineToClientObject(string Line, string Sperator = "#//#")
	{
		vector<string> vString = clsString::Split(Line, Sperator);

		return clsAtmSystem(enMode::UpdateMode, vString[0], vString[1], vString[2], vString[3], vString[4], vString[5]
			, stod(vString[6]) );
	}

	static string _ConverClientObjectToLine(clsAtmSystem Client, string Seperator = "#//#")
	{

		string stClientRecord = "";
		stClientRecord += Client.FirstName + Seperator;
		stClientRecord += Client.LastName + Seperator;
		stClientRecord += Client.Email + Seperator;
		stClientRecord += Client.Phone + Seperator;
		stClientRecord += Client.GetAccountNumber() + Seperator;
		stClientRecord += Client.PinCode + Seperator;
		stClientRecord += to_string(Client.AccountBalance);

		return stClientRecord;

	}

	static clsAtmSystem _GetEmptyClientObject()
	{
		return clsAtmSystem(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

	static  vector <clsAtmSystem> _LoadClientsDataFromFile()
	{

		vector <clsAtmSystem> vClients;

		fstream MyFile;

		MyFile.open("Clients.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{

			string Line;


			while (getline(MyFile, Line))
			{

				clsAtmSystem Client = _ConvertLineToClientObject(Line);

				vClients.push_back(Client);
			}

			MyFile.close();

		}

		return vClients;

	}

	static void _SaveClientsDataToFile(vector <clsAtmSystem> vClients)
	{

		fstream MyFile;
		MyFile.open("Clients.txt", ios::out);//overwrite

		string DataLine;

		if (MyFile.is_open())
		{

			for (clsAtmSystem C : vClients)
			{
				
					//we only write records that are not marked for delete.  
				DataLine = _ConverClientObjectToLine(C);
				MyFile << DataLine << endl;

			}

			MyFile.close();

		}

	}

	void _Update()
	{
		vector <clsAtmSystem> _vClients;

		_vClients = _LoadClientsDataFromFile();

		for (clsAtmSystem& C : _vClients)
		{
			if (C.GetAccountNumber() == GetAccountNumber())
			{
				C = *this;
				break;
			}

		}

		_SaveClientsDataToFile(_vClients);

	}

public:

	struct stLoginRegister
	{
		string DateAndTime;
		string AccountNumber;
		string PinCode;
	};

	struct stTransactionsRegister
	{
		string DateAndTime;
		string AccountNumber;
		string TransactionName;
		double AmountOfTransaction;
	};

	clsAtmSystem(enMode Mode,string FirstName, string LastName, string Email, string Phone, string AccountNumber, string PinCode,
		double AccountBalance) :clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_AccountBalance = AccountBalance;
	}

	bool IsEmpty()
	{
		return _Mode == enMode::EmptyMode;
	}

	string GetAccountNumber()
	{
		return _AccountNumber;
	}

	void SetPinCode(string PinCode)
	{
		_PinCode = PinCode;
	}

	string GetPinCode()
	{
		return _PinCode;
	}

	__declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

	void SetAccountBalance(double AccountBalance)
	{
		_AccountBalance = AccountBalance;
	}

	double GetAccountBalance()
	{
		return _AccountBalance;
	}

	__declspec(property(get = GetAccountBalance, put = SetAccountBalance)) double AccountBalance;

	static clsAtmSystem FindClient(string AccountNumber, string PinCode)
	{
		fstream MyFile;

		MyFile.open("Clients.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{

				clsAtmSystem Client = _ConvertLineToClientObject(Line);

				if (Client.GetAccountNumber() == AccountNumber && clsUtil::DecryptText(Client.GetPinCode()) == PinCode )
				{
					MyFile.close();
					return Client;
				}

			}

			MyFile.close();
		}

		return _GetEmptyClientObject();
	}

	static bool IsClientExist(string AccountNumber,string PinCode)
	{

		clsAtmSystem Client1 = clsAtmSystem::FindClient(AccountNumber,PinCode);

		return (!Client1.IsEmpty());
	}

	enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1};

	enSaveResults Save()
	{
		switch (_Mode)
		
		{
		case enMode::EmptyMode:
		{
			return enSaveResults::svFaildEmptyObject;
		}

		case enMode::UpdateMode:
		{


			_Update();

			return enSaveResults::svSucceeded;

		}
	}
	
	}

	void Deposit(double Amount)
	{
		_AccountBalance += Amount;
		Save();
		TransactionRegister("Deposit", Amount);
	}

	bool Withdraw(int Amount)
	{
		if (Amount > _AccountBalance)
		{
			return false;
		}
		else
		{
			_AccountBalance -= Amount;
			Save();
			TransactionRegister("WithDraw", Amount);

			return true;
		}
	}

	void LoginRegister()
	{
		stLoginRegister LoginRegister;

		LoginRegister.DateAndTime = clsDate::GetSystemDateTimeString();
		LoginRegister.AccountNumber = GetAccountNumber();
		LoginRegister.PinCode = GetPinCode();

		_AddRegisterDataToFile(_ConvertLoginRecordToLine(LoginRegister) , "LoginRegister.txt");

	}

	static vector<stLoginRegister> GetLoginRegisterDataFromFile()
	{
		return _LoadLoginRegisterDataFromFile();
	}

	void ChangePinCode(string PinCode)
	{
		_PinCode = clsUtil::EncryptText(PinCode);

		Save();

		TransactionRegister("Change Pin Code");

	}

	void TransactionRegister(string TransactionName, double Amount = 0)
	{
		stTransactionsRegister TransactionRegister;

		TransactionRegister.DateAndTime = clsDate::GetSystemDateTimeString();
		TransactionRegister.AccountNumber = _AccountNumber;
		TransactionRegister.TransactionName = TransactionName;
		TransactionRegister.AmountOfTransaction = Amount;


		_AddRegisterDataToFile(_ConvertTransactionRecordToLine(TransactionRegister), "Transactions.txt");

	}

	static  vector<stTransactionsRegister> GetTransactionsRegister()
	{
		return _LoadTransactionRegisterDataFromFile();
	}

};

