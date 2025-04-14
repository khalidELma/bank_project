#pragma once
#include "clsScreen.h"
#include "clsMainCurrancyScreen.h"
#include "clsCurrency.h"
#include "clsInputValidation.h"
class clsCurrenciesListScreen : protected clsScreen
{
    static void PrintCurranciesRecordLine(clsCurrency Currancy) {
        cout << "| " << setw(30) << left << Currancy.Country();
        cout << "| " << setw(20) << left << Currancy.CurrencyCode();
        cout << "| " << setw(40) << left << Currancy.CurrencyName();
        cout << "| " << setw(10) << left << Currancy.Rate();
        cout << " | ";
	}

public:

    static void ShowListCurrancies() {

        vector<clsCurrency> vCurrancy = clsCurrency::GetCurreciesList();
        string Title = "Currancies List ";
        string SubTitle = "(" + to_string(vCurrancy.size()) + ") Country";
        _DrawScreenHeader(Title, SubTitle);

        cout << "\n______________________________________________________________________________________________________________\n";

        cout << "| " << left << setw(30)  << "Country ";
        cout << "| " << left << setw(20) << " Code ";
        cout << "| " << left << setw(40) << " Name ";
        cout << "| " << left << setw(10) << " Rate (1$) ";
        cout << "\n______________________________________________________________________________________________________________\n";

        if (vCurrancy.size() == 0) {

            cout << "No Currancies Available In the System!";

        }
        else {

            for (clsCurrency Currancy : vCurrancy) {
                PrintCurranciesRecordLine(Currancy);
                cout << endl;
            }
        }
        cout << "______________________________________________________________________________________________________________\n";
    }

};

