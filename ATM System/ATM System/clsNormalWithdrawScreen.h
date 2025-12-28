#pragma once

#include<iostream>
#include"clsAtmSystem.h"
#include"clsScreen.h"
#include"clsInputValidate.h"
using namespace std;

class clsNormalWithdrawScreen:protected clsScreen
{
private:

	static int _ReadNormalWithDrawAmount()
	{
		int Amount = 0;

		do
		{

			cout << "\n\nPlease Enter An Positive Amount Multiple Of 5's : ";
			Amount = clsInputValidate::ReadIntNumber();

		} while (Amount % 5 != 0 || Amount <= 0);

		return Amount;
	}

	static int _CheckIFAmountMoreThanBalance()
	{
		double Amount = _ReadNormalWithDrawAmount();

		while (Amount > CurrentClient.AccountBalance)
		{
			cout << "\nAmount Exceeds The Available Balance , Enter Another Amount. ";
			Amount = _ReadNormalWithDrawAmount();
		}
		
		return Amount;
	}

public:

	static void ShowNormalWithdarwScreen()
	{
		clsScreen::_DrawScreenHeader("\t   Normal WithDraw Screen");

		cout << "\n\t\t\t\t\tYour Balance = " << CurrentClient.AccountBalance;

		if (CurrentClient.GetAccountBalance() == 0)
		{
			cout << "\n\nYour Balance is Zero Not Can WithDraw.\n";
			return;
		}


		int Amount = _CheckIFAmountMoreThanBalance();


		char Answer = 'n';
		cout << "\n\nAre You Sure You Want Perform This Transactions ? y/n ? ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			if (CurrentClient.Withdraw(Amount))
			{
				cout << "\n\nDone Successfully , New Balance = " << CurrentClient.GetAccountBalance()<<" ." << endl;
			}
			else
			{
				cout << "\n\nThis Operation Not Completed.";
			}

		}
		else
		{
			cout << "\n\nThe Operation is Cancelled.";
		}

	}

};

