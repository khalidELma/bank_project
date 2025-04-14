#pragma once
#include "clsScreen.h"
#include "clsInputValidation.h"
#include "clsUser.h"

class clsAddNewUserScreen:protected clsScreen
{

    static void _ReadUserInfo(clsUser& User)
    {
        cout << "\nEnter FirstName: ";
        
        User.FirstName= clsInputValidation::RaidString();

        cout << "\nEnter LastName: ";
        User.LastName = clsInputValidation::RaidString();

        cout << "\nEnter Email: ";
        User.Email = clsInputValidation::RaidString();

        cout << "\nEnter Phone: ";
        User.Phone = clsInputValidation::RaidString();

        cout << "\nEnter Password: ";
        User.Password = clsInputValidation::RaidString();

        cout << "\nEnter Permission: ";
        User.Permissions = _RaidPermissionsToSet();
    }

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

    static int _RaidPermissionsToSet() {

        int Permissions = 0;
        char Answer = 'n';

        cout << "\nDo you want to give full access? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            return -1;
        }

        cout << "\n\nDO YOU WANT TO GIVE ACCESS TO : " << endl;

        cout << "Show List Users ? Y/N ";
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pListCleint;
            Answer = 'n';
        }
       
        cout << "\n\nAdd New User ? Y/N ";
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {
            Answer = 'n';
            Permissions += clsUser::enPermissions::pAddNewCleint;
        }
       
        cout << "\n\nDelete Users ? Y/N ";
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pDeleteCleint;
            Answer = 'n';
        }
       
        cout << "\n\nFind User ? Y/N ";
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {
            Answer = 'n';
            Permissions += clsUser::enPermissions::pFind;
        }

        cout << "\n\nTranaction Users ? Y/N ";
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pTranaction;
            Answer = 'n';
        }

        cout << "\n\nManage User ? Y/N ";
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {
            Answer = 'n';
            Permissions += clsUser::enPermissions::pManageCleint;
        }

        cout << "\n\nLogin Register ? Y/N";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Answer = 'n';
            Permissions += clsUser::enPermissions::pLogineRegister;
        }

        cout << "\n\nCurrency ? Y/N";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Answer = 'n';
            Permissions += clsUser::enPermissions::pCurrency;
        }


        return Permissions;

    }


    public:

        static void ShowAddNewUserScreen()
        {

            _DrawScreenHeader("\t  Add New User Screen");

            string UserName = "";
            

            cout << "\nPlease Enter UserName: ";
            UserName = clsInputValidation::RaidString();

           
            while (clsUser::IsAccountExist(UserName))
            {
                cout << "\nUserName Is Already Used, Choose another one: ";
                UserName = clsInputValidation::RaidString();
            }


            clsUser User = clsUser::GetAddNewUserObject(UserName);
            _ReadUserInfo(User);

            clsUser::enSaveResulte SaveResult;

            SaveResult= User.Save();

            switch (SaveResult)
            {
            case clsUser::svFaildEmptyObject:
                cout << "\nError  User was not Save because it's Empty ";
                break;
            case clsUser::svSucceeded:
                cout << "\nUser Addeded Is Successfully  :-) \n";
                _PrintUser(User);

                break;
            case clsUser::svFaildAccountNumberIsExist:
                cout << "\nError User was not saved because UserName is used!\n";
                break;
            }


        }


};

