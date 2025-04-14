#pragma once
#include "clsBinkClien.h"
#include "clsScreen.h"
class clsTransfersLogScreen:protected clsScreen
{



    static void _PrintTransferLogRecordLine(clsBankClients::StTransferLog TransferLogScreenRecord)
    {

        cout << setw(8) << left << "" << "| " << setw(20) << left << TransferLogScreenRecord.DateTime;
        cout << " | " << setw(10) << left << TransferLogScreenRecord.SourceAccountNumber;
        cout << " | " << setw(10) << left << TransferLogScreenRecord.DestinationAccountNumber;
        cout << " | " << setw(10) << left << TransferLogScreenRecord.Amount;
        cout << " | " << setw(10) << left << TransferLogScreenRecord.srcBalanceAfter;
        cout << " | " << setw(10) << left << TransferLogScreenRecord.destBalanceAfter;
        cout << " | " << setw(10) << left << TransferLogScreenRecord.UserName<< " | " ;

    }


public:

   static void ShowTransferLogScreen(){
    



        vector<clsBankClients::StTransferLog> vTransferLog = clsBankClients::GetTransferLogList();

        string Title = "Transfer Log Screen";
        string SupTitle = "(" + to_string(vTransferLog.size()) + ") Record(s).";
        _DrawScreenHeader(Title, SupTitle);


       

        cout << setw(8) << left << "" << "______________________________________________________________________________________________________\n";
        cout << setw(8) << "" << "|" << setw(20) << left << "  Date/Time " << "  |";
        cout << setw(10) << left << " s.Acct " << "  |";
        cout << setw(10) << left << " d.Acct " << "  |";
        cout << setw(10) << left << " Amount " << "  |";
        cout << setw(10) << left << " s.Balance " << " |";
        cout << setw(10) << left << " d.Balance " << " |";
        cout << setw(10) << left << " UserName " << "  |";
        cout << endl;
        cout << setw(8) << left << "" << "|______________________|____________|____________|____________|____________|____________|____________|\n";
       
        if (vTransferLog.size() == 0) {
            cout << "No transfer has been made.";
        }
        else {

            for (clsBankClients::StTransferLog TransferLog : vTransferLog) {
                _PrintTransferLogRecordLine(TransferLog);
                cout << endl;
            }

        }
        cout << setw(8) << left << "" << "|______________________|____________|____________|____________|____________|____________|____________|\n";

    
    
    
    }






};

