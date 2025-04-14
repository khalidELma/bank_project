#pragma once
#include"clsScreen.h"
#include"clsCurrency.h"
#include"clsInputValidation.h"

class clsFindCurrancey :protected clsScreen
{
	
	static int FindBy() {	
			cout << "\nFind By : [1] code , [2] Cuntry ? ";
			int Answer = clsInputValidation::ReidIntNumberBetween(1,2);
		return Answer;
	}
	static void PrintCurranceyCart(clsCurrency Currency) {
		cout << "\nCurrance Cart \n";
		cout << "\n_______________________________\n";
		cout << "Country : " << Currency.Country()<<endl;
		cout << "Code    : " << Currency.CurrencyCode() << endl;
		cout << "Country : " << Currency.CurrencyName() << endl;
		cout << "Code    : " << Currency.Rate() << endl;
		cout << "_______________________________\n\n";
	}
	static clsCurrency checkIsCurranceyCodeExist(string  CurranceyCode) {

		while (!clsCurrency::IsCurranceyCodeExist(CurranceyCode)) {
				cout << "\n\nthis CurranceyCode is Not found Please Enter another one  : ";
				CurranceyCode = clsInputValidation::RaidString();
		}
		
		return clsCurrency::FindByCode(CurranceyCode);
	}
	static clsCurrency checkIsCountryExist(string Country) {

		while (!clsCurrency::IsCountryExist(Country)) {
			cout << "\n\nthis Country is Not found Please Enter another one  : ";

			Country = clsInputValidation::RaidString();
		}

		return clsCurrency::FindByCountry(Country);
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
	static void ShowFindCurrancey() {

		string CurranceyCode = "";
		string Country = "";
		_DrawScreenHeader("Find Currancey");
		if (FindBy() == 1) {

			cout << "\n\ntPlease Enter CurranceyCode : ";
			CurranceyCode = clsInputValidation::RaidString();
			clsCurrency  Currency = checkIsCurranceyCodeExist(CurranceyCode);
			_showResults(Currency);

		}
		else {
			
			cout << "\n\ntPlease Enter Country code: ";
			Country = clsInputValidation::RaidString();
			clsCurrency  Currency = checkIsCountryExist(Country);
			_showResults(Currency);
			
		}

		
		


	}
};

