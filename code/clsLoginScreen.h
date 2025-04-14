#pragma once


#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>
#include "clsMainScrren.h"
#include "Global.h"

class clsLoginScreen :protected clsScreen
{

private:

    static  bool _Login()
    {
        bool LoginFaild = false;
        int TRY = 3;
        string Username, Password;
        do
        {

            if (LoginFaild)
            {
                cout << "______________________________________\n";
                cout << "\nInvlaid Username/Password!\n";
                cout << "You Have " << --TRY <<"Trails to login " << endl;
                cout << "______________________________________\n\n";

                if (TRY == 0) {
                    return false;
                }

            }

            cout << "Enter Username? ";
            cin >> Username;

            cout << "Enter Password? ";
            cin >> Password;

            CurrentUser = clsUser::Find(Username, Password);

            LoginFaild = CurrentUser.IsEmpty();

        } while (LoginFaild);

        CurrentUser.outDataToFile();
        clsMainScreen::ShowMainMenue();
        return true;
    }

public:


    static bool ShowLoginScreen()
    {
        system("cls");
        _DrawScreenHeader("\t  Login Screen");
        return _Login();

    }

};

