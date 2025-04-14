#pragma once
#include "clsScreen.h"
#include "clsBinkClien.h"
#include "clsInputValidation.h"

class clsTotalBalanceScreen:protected clsScreen
{
    
    static void PrintClientRecordLine(clsBankClients Client)
    {

        cout << setw(20) << left << ""<<"\t\t" << "| " << setw(15) << left << Client.AccountNumber;
        cout << "| " << setw(30) << left << Client.FullName();
        cout << "| " << setw(12) << left << Client.AccountBalance;
        cout << " | ";
    }


public:
    static void _ShowTotalBalanceScreen() {
        
        vector<clsBankClients> vClient = clsBankClients::GetClientsList();
   
        _DrawScreenHeader("\t\tTotal Balance ");

        cout << setw(20) << left <<"" << "\t\t_________________________________________________________________\n";
        cout << setw(20) << left << "" << "\t\t| "<<setw(15) << left << "AccountNumber"  ;
        cout << "| " << setw(30) << left << "Client Name"  ;
        cout << "| " << setw(12) << left << "Balance\n";
        cout << setw(20) << left << "" << "\t|_______________________________________________________________|\n";


        double TotalBalance = clsBankClients::GetTotalBalance();

        if(vClient.size()==0)
            cout << "\t\t\t\tNo Clients Available In the System!";
        else {
            for (clsBankClients C : vClient) {

                PrintClientRecordLine(C);
                cout << endl;
            }
            cout << setw(20) << left << "" << "\t\t|_______________________________________________________________\n";

            cout << endl ;
            cout << setw(8) << left << "" << "\t\t\t\t\t     Total Balances = " << TotalBalance << endl<< endl;
            cout << setw(8) << left << "" << "\t\t\t  ( " << clsBankClients::NumberToText(TotalBalance) << ")";


        }


    }

};

