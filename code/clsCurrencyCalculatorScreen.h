#pragma once
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidation.h"

class clsCurrencyCalculatorScreen :protected clsScreen
{
	static void PrintCurranceyCart(clsCurrency Currency, string text) {
		cout << "\n" << text;
		cout << "\n_______________________________\n";
		cout << "Country : " << Currency.Country() << endl;
		cout << "Code    : " << Currency.CurrencyCode() << endl;
		cout << "Country : " << Currency.CurrencyName() << endl;
		cout << "Code    : " << Currency.Rate() << endl;
		cout << "_______________________________\n\n";
	}
	static clsCurrency checkIsCurranceyCodeExist(string text) {
		cout << text;
		string CurrancyCode = clsInputValidation::RaidString();
		while (!clsCurrency::IsCurranceyCodeExist(CurrancyCode)) {
			cout << "\n\nthis CurranceyCode is Not found Please Enter another one  : ";
			CurrancyCode = clsInputValidation::RaidString();
		}

		return clsCurrency::FindByCode(CurrancyCode);
	}
	static float ReadAmount() {
		float Amount = 0;
		cout << "\nPlease Enter Amount : ";

		return clsInputValidation::ReidDoubleNumber();
	}
	static void _PrintCalculatorCurrency(float Amount, clsCurrency  CurrencyFrom, clsCurrency CurrencyTo) {

		system("cls");

		PrintCurranceyCart(CurrencyFrom, "\nConvert From\n\n");

		cout << "\n" << Amount << " " << CurrencyFrom.CurrencyCode() << " = "
			<< CurrencyFrom.ConvertCurrencyToDollar(Amount) << " $";

		
		if (CurrencyTo.CurrencyCode() == "USD")
			return;
		
		else {


			PrintCurranceyCart(CurrencyTo, "Convert From USD to \n\n To ");

			cout << "\n" << Amount << " " << CurrencyFrom.CurrencyCode() << " = " <<
			CurrencyFrom.ConvertDollarToCurrenc(Amount, CurrencyTo) << " " << CurrencyTo.CurrencyCode();


		}
		







	}

public:

	static void ShowCurrencyCalculatorScreen() {

		char Answer = 'y';

		while ( Answer == 'Y' ||  Answer == 'y') {

			system("cls");

			_DrawScreenHeader("\tCurrency Calculator ");

			clsCurrency CurrencyFrom = checkIsCurranceyCodeExist("\nPlease Enter CurrancyCode1 : ");
			clsCurrency CurrencyTo = checkIsCurranceyCodeExist("\nPlease Enter CurrancyCode2 : ");
			float Amount = ReadAmount();

			
			
			_PrintCalculatorCurrency(Amount, CurrencyFrom, CurrencyTo);

			cout << "\n\nDo you want To perform another Calculation Y/N ? ";
			cin >> Answer;

		}

	}


};

