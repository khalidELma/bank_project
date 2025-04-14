#pragma once
#include <iostream>
#include<vector>
#include"clsScreen.h"
#include"clsBinkClien.h"
class clsClientListScreen:protected clsScreen
{
    static void PrintClientRecordLine(clsBankClients Client)
    {

        cout << "| " << setw(15) << left << Client.AccountNumber;
        cout << "| " << setw(20) << left << Client.FullName();
        cout << "| " << setw(12) << left << Client.Phone;
        cout << "| " << setw(35) << left << Client.Email;
        cout << "| " << setw(10) << left << Client.PinCode;
        cout << "| " << setw(12) << left << Client.AccountBalance;
        cout << " | ";
    }

public:

    static void ShowClientsList()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pListCleint)) {
            return;
        }

        vector <clsBankClients> vClients = clsBankClients::GetClientsList();
        
        string Title = "\t\tClient List";
        string SupTitle = "\t\t(" + to_string( vClients.size()) + ") Client(s).";

        clsScreen::_DrawScreenHeader(Title, SupTitle);


        
        cout << "\n______________________________________________________________________";
        cout << "_______________________________________________" << endl;


        cout << "| " << left << setw(15) << "Account Number";
        cout << "| " << left << setw(20) << "Client Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(35) << "Email";
        cout << "| " << left << setw(10) << "Pin Code";
        cout << "| " << left << setw(12) << "Balance";
        cout << " |";

        cout << "\n_________________|_____________________|_____________|____________________________________|___________|______________|\n";
        if (vClients.size() == 0)
            cout << "\t\t\t\tNo Clients Available In the System!";
        else

            for (clsBankClients Client : vClients)
            {

                PrintClientRecordLine(Client);
                cout << endl;
            }
        cout << "_______________________________________________________________________";
        cout << "______________________________________________|" << endl;
    }

};

