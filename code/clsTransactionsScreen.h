#pragma once
#include"iostream"
#include "clsScreen.h"
#include"clsInputValidation.h"
#include"clsDepositScreen.h"
#include"clsWithdrawScreen.h"
#include"clsTotalBalanceScreen.h"
#include"clsTransferScreen.h"
#include"clsTransfersLogScreen.h"
class clsTransactionsScreen :protected clsScreen
{

	enum enTransactionsMenueOption {
		eDeposit = 1, eWithdraw = 2,
		eShowTotalBalance = 3, eShowTransfer = 4,
		eShowTransferLog=5,eShowMaineMenue = 6
		
	};

	static int ReadTransactionsMenueOption() {
		cout << setw(32) << left <<""<< "choose what Do you want to do [1_6] ";
		return clsInputValidation::ReidIntNumberBetween(1, 6, "Enter Number Between from 1 to 6");
	}

	static  void _ShowDepositScreen() {
	//	cout << "Deposit Screen will be Here";
		clsDepositScreen::ShowDepositScreen();
	}

	static void _ShowWithdrawScreen() {
		//cout << "\nWithdraw Screen will be Here";
		clsWithdrawScreen::ShowWithdraw();
	}

	static void _ShowTotalBalanceScreen() {
		//cout << "\nTotal Balance Screen will be Here";
		clsTotalBalanceScreen::_ShowTotalBalanceScreen();
	}

	static void _ShowTransferScreen() {
		clsTransferScreen::ShowTransferScreen();
	}

	static void _ShowTransferLogScreen() {
		clsTransfersLogScreen::ShowTransferLogScreen();
	}

	static void _GoBackToTransactionsMenue() {
		//cout << "\nGo Back to Transactions Menue will be Here";
		system("pause>0");
		showTransactionsMenue();
	}


	/*void _ShowShowMaineMenueScreen() {

	}*/


	static void _PerfromTransactionsMenueOption(enTransactionsMenueOption TransactionsMenueOption) {

		switch (TransactionsMenueOption)
		{
		case clsTransactionsScreen::eDeposit:
			system("cls");
			_ShowDepositScreen();
			_GoBackToTransactionsMenue();
			break;
		case clsTransactionsScreen::eWithdraw:
			system("cls");
			_ShowWithdrawScreen();
			_GoBackToTransactionsMenue();
			break;
		case clsTransactionsScreen::eShowTotalBalance:
			system("cls");
			_ShowTotalBalanceScreen();
			_GoBackToTransactionsMenue();
			break;

		case clsTransactionsScreen::eShowTransfer:
			system("cls");
			_ShowTransferScreen();
			_GoBackToTransactionsMenue();
			break;


		case clsTransactionsScreen::eShowTransferLog:
			system("cls");
			_ShowTransferLogScreen();
			_GoBackToTransactionsMenue();
			break;

		case clsTransactionsScreen::eShowMaineMenue:
			break;

		
		}



	}


public:
	

	static void showTransactionsMenue() {

		if (!CheckAccessRights(clsUser::enPermissions::pTranaction)) {
			return;
		}

		system("cls");

		_DrawScreenHeader("\tTransactions Menue");

		cout << setw(32) << left <<""<< "========================================\n";
		cout << setw(32) << left <<""<< "\t\tTransactions\n";
		cout << setw(32) << left <<""<< "========================================\n";
		cout << setw(32) << left <<""<< "\t[1] Deposit\n";
		cout << setw(32) << left <<""<< "\t[2] Withdraw\n";
		cout << setw(32) << left <<""<< "\t[3] Total Balance\n";
		cout << setw(32) << left <<""<< "\t[4] Transfer\n";
		cout << setw(32) << left <<""<< "\t[5] Transfer Log\n";
		cout << setw(32) << left <<""<< "\t[6] Maine Menue \n";
		cout << setw(32) << left <<""<< "=========================================\n";

		_PerfromTransactionsMenueOption((enTransactionsMenueOption)ReadTransactionsMenueOption());

	}


};

