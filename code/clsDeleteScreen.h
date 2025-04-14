#pragma once
#include <iostream>
#include<vector>
#include"clsScreen.h"
#include"clsBinkClien.h"
#include"clsInputValidation.h"
using namespace std;
class clsDeleteScreen:protected clsScreen
{

	static void _PrintClient(clsBankClients Client) {
		cout << "\nClient Card:";
		cout << "\n___________________________________________________________";
		cout << "\nFirstName   : " << Client.FirstName;
		cout << "\nLastName    : " << Client.LastName;
		cout << "\nFull Name   : " << Client.FullName();
		cout << "\nEmail       : " << Client.Email;
		cout << "\nPhone       : " << Client.Phone;
		cout << "\nAcc. Number : " << Client.AccountNumber;
		cout << "\nPassword    : " << Client.PinCode;
		cout << "\nBalance     : " << Client.AccountBalance;
		cout << "\n___________________________________________________________\n";
	}

public:


	static void _ShowDeleteClientScreen() {

		if (!CheckAccessRights(clsUser::enPermissions::pDeleteCleint)) {
			return;
		}


		_DrawScreenHeader("\t\tDelete Client ");

		string AccountNumber = "";
		cout << "Please Enter AccountNumber ? ";
		AccountNumber = clsInputValidation::RaidString();

		while (!clsBankClients::IsClientExist(AccountNumber)) {
			cout << "\nThis Account is not Found , Please Enter Another one : ";
			AccountNumber = clsInputValidation::RaidString();
		}


		clsBankClients Client1 = clsBankClients::Find(AccountNumber);
		_PrintClient(Client1);
		
		char Answer = 'n';
		cout << "Are you sure do you want to Delete this Account ? Y/N  ";
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y') {

			if (Client1.Delete()) {

				cout << "This Account is Delete Successfully ";
				_PrintClient(Client1);
			}
			else {
				cout << "Error This Account is not Delete , Please Try Again ";
			}

		}


	}



};

