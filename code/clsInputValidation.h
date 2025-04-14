#pragma once
#include <iostream>
#include"clsDate.h"
using namespace std;

class clsInputValidation

{

public:
	static string RaidString() {
		string S1;
		getline(cin >> ws, S1);
		return S1;
	}
	

	static bool IsNumberBetween(int Number, int from, int to) {
		return (to >= Number && from <= Number);
	}

	static bool IsDateBetween(clsDate Date, clsDate fromDate, clsDate toDate) {
		return ((clsDate::IsDate1AfterDate2(Date, fromDate) || clsDate::IsDate1EqualDate2(Date, fromDate)) && 
			(clsDate::IsDate1BeforeDate2(Date, toDate) ||clsDate::IsDate1EqualDate2(Date, toDate)))        || 

			((clsDate::IsDate1AfterDate2(Date, toDate) || clsDate::IsDate1EqualDate2(Date, toDate))      &&
			(clsDate::IsDate1BeforeDate2(Date, fromDate) || clsDate::IsDate1EqualDate2(Date, fromDate)));
	}


	static int ReidIntNumber(string ErrorMessage= "Isvalid Number ,Enter again :\n") {
		int Number;
		cin >> Number;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			cout << ErrorMessage;
			cin >> Number;
		}
		return Number;
	}


	static double ReidDoubleNumber(string ErrorMessage= "Isvalid Number ,Enter again :\n") {
		double Number;
		cin >> Number;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			cout << ErrorMessage;
			cin >> Number;
		}
		return Number;
	}
	 
	static int ReidIntNumberBetween(int from, int to ,string ErrorMessage="Isvalid Number ,Enter again :\n") {
		int Number;
		while (true) {
			 Number = ReidIntNumber();
			 if (IsNumberBetween(Number,from, to)) {
				 return Number;
			}
				
		}
	}

	static double ReidDblNumberBetween(double from, double to, string ErrorMessage) {
		double Number;
		while (true) {
			Number = ReidDoubleNumber();
			if (IsNumberBetween(from, to, Number))
				return true;
		}
	}

    static bool IsValideDate(clsDate Date) {
		return clsDate::IsValid(Date);
	}

};

