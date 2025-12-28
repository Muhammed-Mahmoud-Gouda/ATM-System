#pragma once

#include<iostream>
#include<vector>
#include"clsAtmSystem.h"
#include"clsScreen.h"
#include"clsInputValidate.h"
using namespace std;

class clsDepositScreen:protected clsScreen
{
private:

	static double _ReadPositiveDepoistAmount()
	{
		double Amount = 0;

		do
		{
			cout << "\n\nPlease Enter A Positive Deposit Amount ? ";
			Amount = clsInputValidate::ReadDblNumber();

		}while (Amount <= 0);

		return Amount;
	}


public:

	static void ShowDepositScreen()
	{
		clsScreen::_DrawScreenHeader("\t   Deposit Screen");

		cout << "\n\t\t\t\t\tYour Balance = " << CurrentClient.GetAccountBalance() << endl;

		double Amount = _ReadPositiveDepoistAmount();

		char Answer = 'n';
		cout << "\nAre You Sure You Want Perform This Transactions ? y/n ? ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			CurrentClient.Deposit(Amount);
			cout << "\nDone Successfully , New Balance = " << CurrentClient.GetAccountBalance()<<" ." << endl;
		}
		else
		{
			cout << "\nThe Operation Is Cancelled.";
		}
	}
};

