#pragma once
#include "clsCurrency.h"
#include "clsScreen.h"
#include "clsInputValidation.h"
class clsUpdateRate:protected clsScreen
{
	static void PrintCurranceyCart(clsCurrency Currency) {
		cout << "\nCurrance Cart \n";
		cout << "\n_______________________________\n";
		cout << "Country : " << Currency.Country() << endl;
		cout << "Code    : " << Currency.CurrencyCode() << endl;
		cout << "Country : " << Currency.CurrencyName() << endl;
		cout << "Code    : " << Currency.Rate() << endl;
		cout << "_______________________________\n\n";
	}
	
	static clsCurrency checkIsCurranceyCodeExist(string CurranceyCode) {

		while (!clsCurrency::IsCurranceyCodeExist(CurranceyCode)) {
			cout << "\n\nthis CurranceyCode is Not found Please Enter another one  : ";
			CurranceyCode = clsInputValidation::RaidString();
		}

		return clsCurrency::FindByCode(CurranceyCode);
	}
	
	static void _showResults(clsCurrency Currency) {

		if (!Currency.IsEmpty()) {

			cout << "\nThis Currancey Is Found :)";
			PrintCurranceyCart(Currency);

		}
		else {

			cout << "\nErour Your chosse is not Exist :(";

		}
	}

public:

	static void _ShowUpateRate() {

		_DrawScreenHeader("Update Rate Screen ");

		string CurranceyCode = "";

		cout << "\n\nPlease Enter CurranceyCode : ";
		CurranceyCode = clsInputValidation::RaidString();
		clsCurrency  Currency = checkIsCurranceyCodeExist(CurranceyCode);
		_showResults(Currency);

		char Answer = 'n';

		cout << "\n\nAre you Sure do you want to Update the Rate of this Country ? ";
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y') {
			
			float NewRate = 0;

			cout << "\n\nUpdate Currancey Ret";
			cout << "\n______________________";
			cout << "\nEnter New Rate : ";
			NewRate = clsInputValidation::ReidDoubleNumber();

			Currency.UpdateRate(NewRate);

			cout << "Currency Rate  Update Is Successfully ";
			
			PrintCurranceyCart(Currency);

		}
	}


};

