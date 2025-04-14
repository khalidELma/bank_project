#pragma once
#include "clsScreen.h"
#include "clsInputValidation.h"
#include "clsUser.h"
class clsFindUsersScreen:public clsScreen
{

    static void _PrintUser(clsUser User) {
        cout << "\n________________________________________________\n";
        cout << "FirstName   : " << User.FirstName << endl;
        cout << "LastName    : " << User.LastName << endl;
        cout << "FullName    : " << User.FullName() << endl;
        cout << "Email       : " << User.Email << endl;
        cout << "Phone       : " << User.Phone << endl;
        cout << "UserName    : " << User.UserName << endl;
        cout << "Password    : " << User.Password << endl;
        cout << "Permissions : " << User.Permissions << endl;
        cout << "\n________________________________________________\n";
    }


public:

	static void _ShowFindUsersScreen() {


        _DrawScreenHeader("\t Find User ");

        string UserName = "";


        cout << "\nPlease Enter UserName: ";
        UserName = clsInputValidation::RaidString();


        while (!clsUser::IsAccountExist(UserName))
        {
            cout << "\nUserName Is Not Find , Choose another one: ";
            UserName = clsInputValidation::RaidString();
        }


        clsUser User = clsUser::Find(UserName);
       

        if (!User.IsEmpty()) {
            cout << "\nUser it's Found :)\n";
        }
        else {
            cout << "\nUser was Not Found :(\n";
        }
        
        _PrintUser(User);

	}
};

