#pragma once
#include <iostream>
#include <iomanip>
#include "clsperson.h"
#include "clsInputValidation.h"
#include "clsScreen.h"
#include "clsClientListScreen.h"
#include"clsAddNewClientScreen.h"
#include"clsDeleteScreen.h"
#include"clsUpdateDataClientScreen.h"
#include "clsFindScreen.h"
#include"clsTransactionsScreen.h"
#include "clsManageUsersScreen.h"
#include "Global.h"
#include "LoginRegister.h"
#include "clsLoginRegisterScreen.h"
#include"clsMainCurrancyScreen.h"
 
#define RED     "\x1b[31m"
#define YELLOW  "\x1b[33m"
#define RESET   "\x1b[0m"

using namespace std;

class clsMainScreen:protected clsScreen
{

	enum enMainMenueOptions {
		eListClinet = 1, eAddNewClinet = 2, DeleteClinet = 3,
		UpdateClient = 4, FindClient = 5, Transactions = 6,
		ManageUsers = 7, LoginRegister = 8, CurrancyExchange=9,
		Logout = 10

	};

	static void _goBacToMaineMenue() {
		system("pause");
		ShowMainMenue();
	}
	
	static short _ReadMainMenueOptions() {
		cout <<setw(32)<<left << "" << "Choose What do  you want to Do [1 _10] ";
		return clsInputValidation::ReidIntNumberBetween(1, 10);
	}
	
	
	static void _ShowAllClientsScreen() {
		/*cout << "\nClient List Screen Will be here...\n";*/
		clsClientListScreen::ShowClientsList();
		
	}
	
	static void _ShowAddNewClientScreen() {
	//	cout << "\nAdd New Client Screen Will be here...\n";
		clsAddNewClientScreen::ShowAddNewClientScreen();
	}
	
	static void _ShowDeleteClientScreen(){
		//cout << "\nDelete Client Screen Will be here...\n";
		clsDeleteScreen::_ShowDeleteClientScreen();
	}
	
	static void _ShowUpdateClientScreen(){
		//cout << "\nUpdate Client Screen Will be here...\n";
		clsUpdateDataClientScreen::ShoeUpdateClientData();
	}
	
	static void _ShowFindClientScreen(){
		//cout << "\nFind Client Screen Will be here...\n";
		clsFindScreen::_ShowFindScreen();
	}
	
	static void _ShowTransactionsMenue(){
		//cout << "\nTransactions Menue Will be here...\n";
		clsTransactionsScreen::showTransactionsMenue();
	}
	
	static void _ShowManageUsersMenue(){
		//cout << "\nUsers Menue Will be here...\n";
		clsManageUsersScreen::_ShowManageMenueScreen();
	
	}

	static void _ShowLoginRegisterMenue() {

		//cout << "Login Register Screen will be here \n";
		clsLoginRegisterScreen::_ShowLoginRegisterRecord();

	}
	
	/*static void _ShowEndScreen() {
		cout << "\nEnd Screen Will be here...\n";
	} */
	
	static void _Login() {

		
		CurrentUser = clsUser::Find("", "");

	}

	static void _ShowCurrancyExchange() {
		clsMainCurrancyScreen::_ShowMainCurranc();
	}

	static void _PerfromMainMenueOption(enMainMenueOptions MainMenueOptions) {
		switch (MainMenueOptions)
		{
		case enMainMenueOptions::eListClinet:
			system("cls");
			_ShowAllClientsScreen();
			_goBacToMaineMenue();
			break;
		case enMainMenueOptions::eAddNewClinet:
			system("cls");
			_ShowAddNewClientScreen();
			_goBacToMaineMenue();
			break;
		case enMainMenueOptions::DeleteClinet:
			system("cls");
			_ShowDeleteClientScreen();
			_goBacToMaineMenue();
			break;
		case enMainMenueOptions::UpdateClient:
			system("cls");
			_ShowUpdateClientScreen();
			_goBacToMaineMenue();
			break;
		case enMainMenueOptions::FindClient:
			system("cls");
			_ShowFindClientScreen();
			_goBacToMaineMenue();
			break;
		case enMainMenueOptions::Transactions:
			system("cls");
			_ShowTransactionsMenue();
			_goBacToMaineMenue();
			break;
		case enMainMenueOptions::ManageUsers:
			system("cls");
			_ShowManageUsersMenue();
			_goBacToMaineMenue();
			break;
		

		case enMainMenueOptions::LoginRegister:
			system("cls");
			_ShowLoginRegisterMenue();
			_goBacToMaineMenue();
			break;
		
		case enMainMenueOptions::CurrancyExchange:
			system("cls");
			_ShowCurrancyExchange();
			_goBacToMaineMenue();
			break;

		case enMainMenueOptions::Logout:
			system("cls");
			_Login();
			break;
		
		
		}


	} 
	
	
public:
	
	static void ShowMainMenue() {
		system("cls");
		_DrawScreenHeader("\t\tMaine Menue");

		cout << setw(32) << left << "";printf(YELLOW "========== Main Menu Screen ==========\n" RESET);

		cout<<setw(32)<<left<<"";printf(RED "[1]" RESET " Show Clients List\n");
		cout<<setw(32)<<left<<"";printf(RED "[2]" RESET " Add New Client\n");
		cout<<setw(32)<<left<<"";printf(RED "[3]" RESET " Delete Client\n");
		cout<<setw(32)<<left<<"";printf(RED "[4]" RESET " Update Client\n");
		cout<<setw(32)<<left<<"";printf(RED "[5]" RESET " Find Client\n");
		cout<<setw(32)<<left<<"";printf(RED "[6]" RESET " Transactions\n");
		cout<<setw(32)<<left<<"";printf(RED "[7]" RESET " Manage Users\n");
		cout<<setw(32)<<left<<"";printf(RED "[8]" RESET " Logine Register\n");
		cout<<setw(32)<<left<<"";printf(RED "[9]" RESET " Currancy Exchange\n");
		cout<<setw(32)<<left<<"";printf(RED "[10]" RESET " Logout\n\n");
		cout<<setw(32)<<left<<"";printf(YELLOW "=================================\n" RESET);

	
		_PerfromMainMenueOption((enMainMenueOptions)_ReadMainMenueOptions());
		
		

	}

};

