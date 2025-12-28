#pragma once

#include<iostream>
#include"clsGlobal.h"
#include"clsScreen.h"


class clsCheckBalanceScreen:protected clsScreen
{

public:

	static void ShowCheckBalanceScreen()
	{
		clsScreen::_DrawScreenHeader("\t  Check Balance Screen");

		cout << "\n\n\nYour Balance = " << CurrentClient.GetAccountBalance() << endl;
		
		CurrentClient.TransactionRegister("Check Balance");

	}


};

