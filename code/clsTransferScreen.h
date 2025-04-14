#pragma once
#include"clsUser.h"
#include "clsBinkClien.h"
#include "clsInputValidation.h"
#include "clsScreen.h"
class clsTransferScreen : clsScreen
{
    static void _PrintUser(clsBankClients DestinationCline) {
        cout << "\nClient Card\n";
        cout << "\n\n________________________________________________\n";
        cout << "FullName      : " << DestinationCline.FullName() << endl;
        cout << "Acc.Number    : " << DestinationCline.AccountNumber << endl;
        cout << "Balance       : " << DestinationCline.AccountBalance << endl;
        cout << "\n________________________________________________\n\n";
    }
    static string ReadAccountNumber() {
        string AccountNumber = "";
        AccountNumber = clsInputValidation::RaidString();

        while (!clsBankClients::IsClientExist(AccountNumber)) {

            cout << "\n\nThis Account was not found ,Please Enter another one : ";
            AccountNumber = clsInputValidation::RaidString();

        }
        return AccountNumber;
    }
    
    static double ReadAmount(clsBankClients DestinationCline) {

        double amount = 0;

        cout << "\nPlease Enter Transfer amount ? ";
        amount = clsInputValidation::ReidDoubleNumber();

        while (amount > DestinationCline.AccountBalance) {

            cout << "Your Balance Is " << DestinationCline.AccountBalance;

            cout << "\nPlease Enter Transfer amount ? ";
            amount = clsInputValidation::ReidDoubleNumber();

        }
        return amount;
    }

public:

    static void ShowTransferScreen() {


        _DrawScreenHeader("\t\tTransfer");

        cout << "Please Enter Account Number to Transfer from : ";
        clsBankClients SoursClient1 = clsBankClients::Find(ReadAccountNumber());
        _PrintUser(SoursClient1);


        cout << "\n\nPlease Enter Account Number to Transfer to : ";
        clsBankClients DestinationCline = clsBankClients::Find(ReadAccountNumber());
        _PrintUser(DestinationCline);

        
        double amount = ReadAmount(SoursClient1);


        char Answer = 'n';
        cout << "\nAre you Sure Do you want to perform this operation Y/N ";
        cin >> Answer;
        
        bool IsWithdrewIsExiste = false;
        if (Answer == 'Y' || Answer == 'y') {

            if (SoursClient1.Transfer(amount, DestinationCline)) {
                cout << "\nTransfer Is Succsessfully :)\n";
              
            }
            else
                cout << "\nTransfer Faild  :(\n";


            _PrintUser(SoursClient1);
            _PrintUser(DestinationCline);
        }

        
        

            
       

    }


};

