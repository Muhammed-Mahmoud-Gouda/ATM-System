#pragma once

#include<iostream>
#include"clsScreen.h"
#include"clsAtmSystem.h"
#include<iomanip>
#include<vector>
class clsTransactionsRegisterScreen:protected clsScreen
{
private:

	static void _PrintTransactionRecord(clsAtmSystem::stTransactionsRegister Transaction)
	{
		cout << "|" << setw(35) << left << Transaction.DateAndTime;
		cout << "|" << setw(30) << left << Transaction.AccountNumber;
		cout << "|" << setw(25) << left << Transaction.TransactionName;
		cout << "|" << setw(10) << left << Transaction.AmountOfTransaction;
	}

public:

	static void ShowTransactionScreen()
	{

		vector<clsAtmSystem::stTransactionsRegister> vTransactions = clsAtmSystem::GetTransactionsRegister();

		short Size = 0;

		for (clsAtmSystem::stTransactionsRegister Transaction : vTransactions)
		{

			if (Transaction.AccountNumber == CurrentClient.GetAccountNumber())
			{
				Size++;
				
			}
		}

		string Title = "\t  Transaction Register Screen";
		string SubTitle = "\t  ( " + to_string(Size) + " ) Transaction";
		

		clsScreen::_DrawScreenHeader(Title, SubTitle);

		cout << "\n_____________________________________________________________________________________________________";
		cout << "_______________\n\n";

		cout << "|" << setw(35)<<left << "Date And Time";
		cout << "|" << setw(30)<<left << "Account Number";
		cout << "|" << setw(25)<<left << "Transaction Name";
		cout << "|" << setw(10)<<left << "Amount OF Transaction";

		cout << "\n_____________________________________________________________________________________________________";
		cout << "_______________\n\n";

		if (Size == 0)
		{
			cout << "\n\n\t\t\t\t\tNo Transactions Found For This Account.\n";
			return;
		}
		
		for (clsAtmSystem::stTransactionsRegister Transaction : vTransactions)
		{

			if (Transaction.AccountNumber == CurrentClient.GetAccountNumber())
			{
				
				_PrintTransactionRecord(Transaction);

				cout << endl;
			}

		}


		cout << "\n_____________________________________________________________________________________________________";
		cout << "_______________\n\n";

	}


};

