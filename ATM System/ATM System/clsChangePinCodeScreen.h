#pragma once

#include<iostream>
#include"clsInputValidate.h"
#include"clsScreen.h"
#include"clsAtmSystem.h"
using namespace std;

class clsChangePinCodeScreen:protected clsScreen
{

public:


	static void ShowChangePinCode()
	{
		clsScreen::_DrawScreenHeader("\t  Change PinCode Screen");

		string NewPinCode;
		cout << "\n\nPlease Eater A New PinCode : ";
		NewPinCode = clsInputValidate::ReadString();

		char Answer;
		cout << "\nAre You Sure Do You Want To Do This Transaction ? y/n ? ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			CurrentClient.ChangePinCode(NewPinCode);

			cout << "\nPinCode Changed Successfully.";

		}
		else
		{
			cout << "\nThis Opeartion Is Cancelled.";
		}
	}


};

