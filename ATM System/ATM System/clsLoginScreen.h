#pragma once
#include<iostream>
#include"clsAtmSystem.h"
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsAtmMainScreen.h"

class clsLoginScreen:protected clsScreen
{
private:

	static bool _Login()
	{
		bool Login = false;
		short FaildLogin = 0;
		string AccountNumber;
		string Password;

		do
		{
		

			if (Login)
			{
				FaildLogin++;
				cout << "\n\nInvalid Account Number And Password ! \n";
				cout << "\nYou have " << (3 - FaildLogin) << " Trial(s) to login.\n\n";
			}

			if (FaildLogin == 3)
			{
				cout << "\nYour are Locked After 3 Faild Trails \n\n";
				return false;
			}

			cout << "\nEnter AccountNumber : ";
			AccountNumber = clsInputValidate::ReadString();

			cout << "Enter Password      : ";
			Password = clsInputValidate::ReadString();

			CurrentClient = clsAtmSystem::FindClient(AccountNumber, Password);

			Login = CurrentClient.IsEmpty();

		} while (Login);

		CurrentClient.LoginRegister();

		clsAtmMainScreen::ShowAtmMainMenueScreen();

		return true;

	}

public:

	static bool ShowLoginScreen()
	{
		system("cls");

		clsScreen::_DrawScreenHeader("\t\tLogin Screen");

		return _Login();
	}


};

