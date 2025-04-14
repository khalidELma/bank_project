#pragma once
#include<vector>
#include<fstream>
#include "clsString.h"
class clsCurrency
{

	enum enMode{ EmptyMode = 0,UpdateMode=1};
	
	enMode _Mode;

	string _Country;
	string _CurrencyCode;
	string _CurrencyName;
	float _Rate;

	static clsCurrency _ConvertLineToCurrencyObject(string Line, string Soperator = "#//#") {

		vector<string> Currency = clsString::Split(Line);
		return clsCurrency(enMode::UpdateMode, Currency[0], Currency[1], Currency[2], stod(Currency[3]));
	} 
	
	static clsCurrency _ConvertEmptyObject() {
		return clsCurrency(enMode::EmptyMode, "", "", "", 0);
	}

	static vector<clsCurrency> _LoadCurrencyDataToFile() {

		vector<clsCurrency> vCurrency;
		
		fstream MyFile;

		MyFile.open("Currencies.txt", ios::in);
		if (MyFile.is_open()) {

			string Line;

			while (getline(MyFile, Line)) {

				vCurrency.push_back(_ConvertLineToCurrencyObject(Line));

			}

			MyFile.close();
		}
		return vCurrency;
	}
	
	static string TransferObjectToLine(clsCurrency C,string Soperator="#//#") {
		string S = "";
		S += C._Country + Soperator;
		S += C._CurrencyCode + Soperator;
		S += C._CurrencyName + Soperator;
		S +=to_string(C._Rate )+ Soperator;
		return S;
	}
	
	static void _SaveDataToFile(vector<clsCurrency> vCurrency) {

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::out);
		if (MyFile.is_open()) {

			for (clsCurrency& C : vCurrency) {

				MyFile << TransferObjectToLine(C);
				MyFile << endl;
			}
			MyFile.close();
		}


	}

	void _Update() {

		vector<clsCurrency> vCurrency = _LoadCurrencyDataToFile();

		for (clsCurrency& C : vCurrency) {

			if (C.CurrencyCode() == CurrencyCode()) {

				C = *this;
				break;
			}

		}

		_SaveDataToFile(vCurrency);
	}


public:

	

	clsCurrency(enMode Mode, string Country, string CurrencyCode, string CurrencyName, float Rate) {

		_Mode = Mode;
		_Country = Country;
		_CurrencyCode = CurrencyCode;
		_CurrencyName = CurrencyName;
		_Rate = Rate;

	}


	bool IsEmpty() {
		return (_Mode == enMode::EmptyMode);
	}

	 string Country() {
		return _Country;
	}

	 string CurrencyCode() {
		 return _CurrencyCode;
	 }

	 string CurrencyName() {
		 return _CurrencyName;
	 }

	 float Rate() {
		 return _Rate;
	 }

	 void UpdateRate(float NewRate) {
		 _Rate = NewRate;
		 _Update();
	 }

	static clsCurrency FindByCode(string Code) {

		Code = clsString::LaterrAllString(Code);

		fstream MyFile;

		MyFile.open("Currencies.txt", ios::in);
		if (MyFile.is_open()) {

			string Line;

			while (getline(MyFile, Line)) {

				clsCurrency Currency =_ConvertLineToCurrencyObject(Line);

				if (Currency._CurrencyCode == Code)
					return Currency;

			}

			MyFile.close();
		}
		return _ConvertEmptyObject();

	}
	
	static clsCurrency FindByCountry(string Country) {

		fstream MyFile;
		Country = clsString::LaterrAllString(Country);
		MyFile.open("Currencies.txt", ios::in);
		if (MyFile.is_open()) {

			string Line;

			while (getline(MyFile, Line)) {

				clsCurrency Currency = _ConvertLineToCurrencyObject(Line);

				if (clsString::LaterrAllString(Currency.Country()) == Country)
					return Currency;

			}

			MyFile.close();
		}
		return _ConvertEmptyObject();
	}

	static bool IsCurranceyCodeExist(string code) {
		clsCurrency Currency = FindByCode(code);

		return !Currency.IsEmpty();
	}
	static bool IsCountryExist(string Country) {
		clsCurrency Currency = FindByCountry(Country);

		return !Currency.IsEmpty();
	}

	 static vector<clsCurrency> GetCurreciesList() {
		 return _LoadCurrencyDataToFile();
	 }

	 static clsCurrency GetEmptyMode(){
		return _ConvertEmptyObject();
	 } 


	  float ConvertCurrencyToDollar(float Amount) {
		 return Amount / _Rate;
	 }

	  float ConvertDollarToCurrenc(float Amount, clsCurrency Country) {

		  if (Country.CurrencyCode() == "USD")
			  return ConvertCurrencyToDollar(Amount);
		  else {
			  return ConvertCurrencyToDollar(Amount) * Country.Rate();
		  }
	  }


};

