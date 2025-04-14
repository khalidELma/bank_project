#pragma once
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidation.h"
class clsUpdateUserScreen : protected clsScreen
{


    static void _ReadUserInfo(clsUser& User)
    {
        cout << "\n\nEnter FirstName: ";

        User.FirstName = clsInputValidation::RaidString();

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

        cout << "\n\nShow List Users ? Y/N ";
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

        return Permissions;

    }


    public:

        static void ShowUpdateUsersScreen() {


            _DrawScreenHeader("\t Update User Data ");

            string UserName = "";


            cout << "\nPlease Enter UserName: ";
            UserName = clsInputValidation::RaidString();


            while (!clsUser::IsAccountExist(UserName))
            {
                cout << "\nUserName Is Not Find , Choose another one: ";
                UserName = clsInputValidation::RaidString();
            }


            clsUser User = clsUser::Find(UserName);
            _PrintUser(User);


            char Answer = 'n';
            cout << "Are you sure do you want to Update This User Y/N  : ";
            cin >> Answer;

            if (Answer == 'Y' || Answer == 'y') {

                

                cout << " \n\nUpdate Data Info"<<endl;
                cout << "____________________\n";
                _ReadUserInfo(User);
                clsUser::enSaveResulte Result = User.Save();
                switch (Result)
                {
                case clsUser::svFaildEmptyObject:
                    cout << "Error User was Not Saved Because it's Empty :(\n";
                    break;
                case clsUser::svSucceeded:
                    cout << "User is Update Successfully :)\n";
                    _PrintUser(User);
                    break;
                }

            }




        }





};

