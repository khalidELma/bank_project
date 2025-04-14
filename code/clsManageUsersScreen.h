#pragma once
#include "clsScreen.h"
#include "clsInputValidation.h"
#include "clsListUser.h"
#include "clsAddNewUser.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdatUserScreen.h"
#include "clsFindUserScreen.h"

class clsManageUsersScreen:protected clsScreen
{
	enum eneManageUsersMenueOptions {
		eListUsers = 1 , eAddNewUser = 2 , eDeleteUser = 3,
	    eUpdateUser = 4 , eFindUser = 5 , Logout = 6
	};

	static void _goBacToManageMenue() {
		system("pause");

	}

	static short _ReadManageMenueOptions() {
		cout << setw(32) << left << "" << "Choose What do  you want to Do [1 _ 8] ";
		return clsInputValidation::ReidIntNumberBetween(1, 6);
	}

	static void _ShowAllUsersScreen() {
	//	cout << "Users List Screen will Be here\n";
		clsListUsersScreen::ShowUsersList();
	}
	
	static void _ShowAddNewUserScreen() {
		//cout << "Add New User Screen will Be here\n";
		clsAddNewUserScreen::ShowAddNewUserScreen();
	
	}
	
	static void _ShowDeleteUserScreen() {
		//cout << "Delete User Screen will Be here\n";
		clsDeleteUserScreen::ShowDeleteUserScreen();
	}
	
	static void _ShowUpdateUserScreen() {
		//cout << "Update Screen will Be here\n";
		clsUpdateUserScreen::ShowUpdateUsersScreen();
	}

	static void _ShowFindUserScreen() {
		//cout << "Find User Screen will Be here\n";
		clsFindUsersScreen::_ShowFindUsersScreen();
	}

	static void _PerFromManageMenueOption(eneManageUsersMenueOptions MenueManageUsersOptions) {

		switch (MenueManageUsersOptions)
		{
		case clsManageUsersScreen::eListUsers:
			system("cls");
			_ShowAllUsersScreen();
			_goBacToManageMenue();
			break;
		case clsManageUsersScreen::eAddNewUser:
			system("cls");
			_ShowAddNewUserScreen();
			_goBacToManageMenue();
			break;
		case clsManageUsersScreen::eDeleteUser:
			system("cls");
			_ShowDeleteUserScreen();
			_goBacToManageMenue();
			break;
		case clsManageUsersScreen::eUpdateUser:
			system("cls");
			_ShowUpdateUserScreen();
			_goBacToManageMenue();
			break;

		case clsManageUsersScreen::eFindUser:
			system("cls");
			_ShowFindUserScreen();
			_goBacToManageMenue();
			break;
		case clsManageUsersScreen::Logout:
			
			break;
		
		}


	}





public:

	static void _ShowManageMenueScreen() {

		if (!CheckAccessRights(clsUser::enPermissions::pManageCleint)) {
			return;
		}

		system("cls");
		_DrawScreenHeader("\t\tManage Menue");
		cout << setw(32) << left << "" << "================================================\n";
		cout << setw(32) << left << "" << "              Manage  Menue   Screen\n";
		cout << setw(32) << left << "" << "================================================\n";
		cout << setw(32) << left << "" << " \t[1] show Users list .\n";
		cout << setw(32) << left << "" << " \t[2] add New User .\n";
		cout << setw(32) << left << "" << " \t[3] Delete User  .\n";
		cout << setw(32) << left << "" << " \t[4] Update User info .\n";
		cout << setw(32) << left << "" << " \t[5] Fin User . \n";
		cout << setw(32) << left << "" << " \t[6] Logout \n";
		cout << setw(32) << left << "" << "================================================\n";

		_PerFromManageMenueOption((eneManageUsersMenueOptions)_ReadManageMenueOptions());
		
	}



};

