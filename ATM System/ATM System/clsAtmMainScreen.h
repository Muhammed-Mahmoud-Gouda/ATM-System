#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsLoginScreen.h"
#include"clsGlobal.h"
#include"clsCheckBalanceScreen.h"
#include"clsDepositScreen.h"
#include"clsNormalWithdrawScreen.h"
#include"clsQuickWithDrawScreen.h"
#include"clsChangePinCodeScreen.h"
#include"clsTransactionsRegisterScreen.h"
using namespace std;


class clsAtmMainScreen:protected clsScreen
{
private:

	enum enAtmMainMenue { eQuickWithDraw = 1, eNormalWithDraw = 2, eDeposit = 3, eCheckBalance = 4,eChangePinCode =5
		,eTransactionsRegister=6  , eLogOut = 7 };

	static short _ReadAtmMainMenueOptions()
	{
		short Number= 0;
		cout << "\n\t\t\t\tChoose What Do You Want To Do? [1 to 7] ? ";
		Number = clsInputValidate::ReadShortNumberBetween(1,7);
		return Number;
	}

	static void _GoBackToAtmMainMenue()
	{
		cout << "\n\nPress any key to go back to Atm Main Menue...";
		system("pause>0");
		ShowAtmMainMenueScreen();
	}

	static void _ShowQuickWithDrawScreen()
	{
		clsQuickWithDrawScreen::ShowQuickWithDrawScreen();
	}

	static void _ShowNormalWithDrawScreen()
	{
		clsNormalWithdrawScreen::ShowNormalWithdarwScreen();
	}

	static void _ShowDepositScreen()
	{
		clsDepositScreen::ShowDepositScreen();
	}

	static void _ShowCheckBalanceScreen()
	{
		clsCheckBalanceScreen::ShowCheckBalanceScreen();
	}

	static void _ShowChangePinCodeScreen()
	{
		clsChangePinCodeScreen::ShowChangePinCode();
	}

	static void _ShowTransactionsRegisterScreen()
	{
		clsTransactionsRegisterScreen::ShowTransactionScreen();
	}

	static void _Logout()
	{
		CurrentClient = clsAtmSystem::FindClient("", "");
		//then it will go back to main function.
	}

	static void _PerformAtmMainMenueOptions(enAtmMainMenue Option)
	{
		switch (Option)
		{
		case enAtmMainMenue::eQuickWithDraw:
			system("cls");
			_ShowQuickWithDrawScreen();
			_GoBackToAtmMainMenue();
			break;

		case enAtmMainMenue::eNormalWithDraw:
			system("cls");
			_ShowNormalWithDrawScreen();
			_GoBackToAtmMainMenue();
			break;

		case enAtmMainMenue::eDeposit:
			system("cls");
			_ShowDepositScreen();
			_GoBackToAtmMainMenue();
			break;

		case enAtmMainMenue::eCheckBalance:
			system("cls");
			_ShowCheckBalanceScreen();
			_GoBackToAtmMainMenue();
			break;

		case enAtmMainMenue::eChangePinCode:
			system("cls");
			_ShowChangePinCodeScreen();
			_GoBackToAtmMainMenue();
			break;

		case enAtmMainMenue::eTransactionsRegister:
			system("cls");
			_ShowTransactionsRegisterScreen();
			_GoBackToAtmMainMenue();
			break;


		case enAtmMainMenue::eLogOut:
			system("cls");
			_Logout();
			break;
		}


	}


public:

	static void ShowAtmMainMenueScreen()
	{
		system("cls");

		clsScreen::_DrawScreenHeader("\t   ATM Main Menue Screen");

		cout << "\n\t\t\t\t===========================================\n";
		cout << "\t\t\t\t\t     ATM Main Menue\n";
		cout << "\t\t\t\t===========================================\n";
		cout << "\t\t\t\t\t[1] Quick WithDraw.\n";
		cout << "\t\t\t\t\t[2] Normal WithDraw.\n";
		cout << "\t\t\t\t\t[3] Deposit.\n";
		cout << "\t\t\t\t\t[4] Check Balance.\n";
		cout << "\t\t\t\t\t[5] Change PinCode.\n";
		cout << "\t\t\t\t\t[6] Transactions Register.\n";
		cout << "\t\t\t\t\t[7] Logout.\n";
		cout << "\t\t\t\t===========================================";


		_PerformAtmMainMenueOptions((enAtmMainMenue)_ReadAtmMainMenueOptions());
	}

};

