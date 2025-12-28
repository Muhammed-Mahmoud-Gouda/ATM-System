#pragma once
#include<iostream>
#include"clsAtmSystem.h"
#include"clsInputValidate.h"
#include"clsScreen.h"

using namespace std;

class clsQuickWithDrawScreen:protected clsScreen
{
private:

    static int _ReadQuickWithdrawOption()
    {
        int Number = 0;
        cout << "\n\nChoose What Do You Want To Do ? [1 to 9] ?  ";
        Number = clsInputValidate::ReadIntNumberBetween(1, 9);
        return Number;
    }

    static short _GetQuickWithDrawAmount(short QuickWithDrawOption)
    {
        switch (QuickWithDrawOption)
        {
        case 1:
            return  20;
        case 2:
            return 50;
        case 3:
            return 100;
        case 4:
            return 200;
        case 5:
            return 400;
        case 6:
            return 600;
        case 7:
            return 800;
        case 8:
            return 1000;
        default:
            return 0;

        }

    }

    static void _PerformQuickWithdrawOption()
    {
        short QuickWithdarwOption = _ReadQuickWithdrawOption();

        if (QuickWithdarwOption == 9)
            return;

        short QuickWithdrawAmount = _GetQuickWithDrawAmount(QuickWithdarwOption);


        while (QuickWithdrawAmount > CurrentClient.GetAccountBalance())
        {
            cout << "\nThe amount exceeds your balance, make another choice. ";

            QuickWithdarwOption = _ReadQuickWithdrawOption();

            if (QuickWithdarwOption == 9)
                return;

            QuickWithdrawAmount = _GetQuickWithDrawAmount(QuickWithdarwOption);
        }


        char Answer = 'n';
        cout << "\n\nAre you sure you want perfrom this transaction? y/n ? ";
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {
            if (CurrentClient.Withdraw(QuickWithdrawAmount))
            {
                cout << "\nDone Successfully , New Balance is = " << CurrentClient.GetAccountBalance()<<" ." << endl;
            }
            else
            {
                cout << "\nThis Operation Not Completed.";

            }

        }
        else
        {
            cout << "\nThis Operation is Cancelled.";
        }
    }

public:

    static void ShowQuickWithDrawScreen()
    {
        clsScreen::_DrawScreenHeader("\t   Quick WithDraw Screen");

        cout << "\n\t\t\t\t===========================================\n";
        cout << "\t\t\t\t\t\tQucik Withdraw\n";
        cout << "\t\t\t\t===========================================\n";
        cout << "\t\t\t\t\t[1] 20\t\t[2] 50\n";
        cout << "\t\t\t\t\t[3] 100\t\t[4] 200\n";
        cout << "\t\t\t\t\t[5] 400\t\t[6] 600\n";
        cout << "\t\t\t\t\t[7] 800\t\t[8] 1000\n";
        cout << "\t\t\t\t\t[9] Exit\n";
        cout << "\t\t\t\t===========================================\n";

        cout << "\n\t\t\t\t\tYour Balance = " << CurrentClient.AccountBalance;

        if (CurrentClient.GetAccountBalance() == 0)
        {
            cout << "\n\nYour Balance is Zero Not Can WithDraw.\n";
            return;
        }

        _PerformQuickWithdrawOption();
    }

};

