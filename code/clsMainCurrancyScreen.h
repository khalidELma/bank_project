#pragma once
#include "clsCurrency.h"
#include "clsInputValidation.h"
#include "clsScreen.h"
#include "clsCurrenciesListScreen.h"
#include "clsFindCurrancey.h"
#include "clsUpdateRate.h"
#include "clsCurrencyCalculatorScreen.h"


class clsMainCurrancyScreen:protected clsScreen
{

	enum enMainCurrancyOptions {
		eListCurraencies = 1, FindCurrancy = 2,
		eUpdateRate = 3, eCurrancyCalculator = 4,
		eMainMenue = 5
	};

	static void _GoBackToMainCurranc() {
		//cout << "Go back To Mine Curranc will be here";
		system("pause>0");
		_ShowMainCurranc();
	}
	static int ReadMainCurrancyOptions() {

		cout << setw(32) << left << "" << "Choose what do you want to do [1_5] ";
		return clsInputValidation::ReidIntNumberBetween(1, 5);
	}
	static void _ShowListCurraencies() {
		//cout << "Curraencies Lise Will be Here \n";
		clsCurrenciesListScreen::ShowListCurrancies();
	}
	static void _ShowFindCurrancy() {
		//cout << "Find Curraency Will be Here \n";
		clsFindCurrancey::ShowFindCurrancey();
	}
	static void _ShowUpdateRate() {
		//cout << "Updat Rate Will be Here \n";
		clsUpdateRate::_ShowUpateRate();
	}
	static void _ShowCurrancyCalculator() {
		//cout << "Currancy Calculator Will be Here \n";
		clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
	}

	static void _PerfromMainCurrancyOptions(enMainCurrancyOptions MainCurrancyOptions) {
		
		switch (MainCurrancyOptions)
		{
		case clsMainCurrancyScreen::eListCurraencies:
			system("cls");
			_ShowListCurraencies();
			_GoBackToMainCurranc();
			break;
		case clsMainCurrancyScreen::FindCurrancy:
			system("cls");
			_ShowFindCurrancy();
			_GoBackToMainCurranc();
			break;
		case clsMainCurrancyScreen::eUpdateRate:
			system("cls");
			_ShowUpdateRate();
			_GoBackToMainCurranc();
			break;
		case clsMainCurrancyScreen::eCurrancyCalculator:
			system("cls");
			_ShowCurrancyCalculator();
			_GoBackToMainCurranc();
			break;
		case clsMainCurrancyScreen::eMainMenue:
			break;
		}

	}

public:

	static void _ShowMainCurranc() {
	
		if (!CheckAccessRights(clsUser::enPermissions::pCurrency)) {
			return;
		}
		system("cls");
		_DrawScreenHeader("Currancy Exhange Main Screen ");

		cout << setw(32) << left << "" << "===========================================\n";
		cout << setw(32) << left << "" << "\tCurrancy Exhange\n";
		cout << setw(32) << left << "" << "===========================================\n";
		cout << setw(32) << left << "" << " [1] List Curraencies \n";
		cout << setw(32) << left << "" << " [2] Find Curraency \n";
		cout << setw(32) << left << "" << " [3] Update Rate \n";
		cout << setw(32) << left << "" << " [4] Curraency Calculator\n";
		cout << setw(32) << left << "" << " [5] Mine Menue \n";
		cout << setw(32) << left << "" << "===========================================\n";

		_PerfromMainCurrancyOptions((enMainCurrancyOptions)ReadMainCurrancyOptions());
	}

};

