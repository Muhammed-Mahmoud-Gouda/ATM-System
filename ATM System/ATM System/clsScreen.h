#pragma once

#include<iostream>
#include"clsDate.h"
#include"clsGlobal.h"
using namespace std;

class clsScreen
{
protected:

	static void _DrawScreenHeader(string Title, string Subtitle = "")
	{

		cout << "\n\t\t\t\t___________________________________________\n\n";
		cout << "\t\t\t\t" << Title << endl;
		if(Subtitle != "")
		{
			cout << "\t\t\t\t" << Subtitle << endl;
		}
		cout << "\t\t\t\t___________________________________________\n\n";

		cout << "\t\t\t\tAccount Number : " << CurrentClient.GetAccountNumber() << "\n";
		cout << "\t\t\t\tPhone          : " << CurrentClient.GetPhone() << "\n";
		cout << "\t\t\t\tName           : " << CurrentClient.FullName() << "\n";
		cout << "\t\t\t\tDate           : " << clsDate::DateToString(clsDate()) << "\n";
	}


};

