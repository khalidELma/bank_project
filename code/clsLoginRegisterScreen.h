#pragma once
#include"clsUser.h"
#include "clsScreen.h"

class clsLoginRegisterScreen:protected clsScreen
{

    static void _PrintLoginRegisterRecordLine(clsUser::stLoginRegisterScreenRecord LoginRegisterScreenRecord)
    {

        cout << setw(8) << left << "" << "| " << setw(30) << left << LoginRegisterScreenRecord.DateTime;
        cout << " | " << setw(15) << left << LoginRegisterScreenRecord.UserName;
        cout << " | " << setw(15) << left << LoginRegisterScreenRecord.Password;
        cout << " | " << setw(15) << left << LoginRegisterScreenRecord.Permissions;
       

    }


public:

    static void _ShowLoginRegisterRecord() {


        if (!CheckAccessRights(clsUser::enPermissions::pLogineRegister)) {
            return;
        }
        vector<clsUser::stLoginRegisterScreenRecord> vstLoginRegisterScreenRecord = clsUser::_LoadDataLoginToFile();

        string Title = "\tLogin Register List Screen";
        string SubTile = "("+to_string(vstLoginRegisterScreenRecord.size()) + ") Record(s)";
        _DrawScreenHeader(Title, SubTile);



        cout << setw(8) << left << "" << "_____________________________________________________________________________________\n";
        cout << setw(8) << "" <<"|" << setw(30) << left << "  Date/Time " << "  |";
        cout << setw(15) << left << "  UserName " << "  |";
        cout << setw(15) << left << "  Password " << "  |";
        cout << setw(15) << left << "  Permissions"  ;
        cout << endl;
        cout << setw(8) << left << "" << "|________________________________|_________________|_________________|________________\n";

        

       

        

        if (vstLoginRegisterScreenRecord.size() == 0) {
            cout << "\t\tNo Logine Available In the System!";
        }
        else {
            for (clsUser::stLoginRegisterScreenRecord stLoginRegisterScreenRecord : vstLoginRegisterScreenRecord) {

                _PrintLoginRegisterRecordLine(stLoginRegisterScreenRecord);
                cout << endl;
            }
        }
        
        cout << setw(8) << left<<"" << "_____________________________________________________________________________________\n";

    }

};

