#pragma once
#include <iostream>
#include "Global.h"
#include "clsUser.h"
#include <iomanip>
#include "clsDate.h"

#define RED     "\x1b[31m"
#define YELLOW  "\x1b[33m"
#define RESET   "\x1b[0m"

using namespace std;

class clsScreen
{
protected:




    static void _DrawScreenHeader(string Title, string SubTitle = "")
    {
        system("cls");
        printf(YELLOW "\t\t\t\t\t______________________________________ " RESET);
       
        cout << "\n\n\t\t\t\t\t  " << Title;
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t  " << SubTitle;
        }
        printf(YELLOW "\n\t\t\t\t\t______________________________________ \n\n" RESET);

        cout << setw(32) << left << "" << "\t User : " << CurrentUser.UserName << endl;
        cout << setw(32) << left << "" << "\t Date : " << clsDate::DateToString(clsDate()) << endl << endl;

    }

    static bool CheckAccessRights(clsUser::enPermissions Permissions) {
        if (!CurrentUser.CheckAccessPermissions(Permissions)) {
            _DrawScreenHeader("  Access Denied! Contact your Admin");
            return false;
        }
        else {
            return true;
        }
    }

};