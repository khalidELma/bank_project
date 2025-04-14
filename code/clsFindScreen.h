#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBinkClien.h"
#include"clsInputValidation.h"
class clsFindScreen:protected clsScreen
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


	static void _ShowFindScreen() {

		if (!CheckAccessRights(clsUser::enPermissions::pFind)) {
			return;
		}

		_DrawScreenHeader("\tFind Client Screen");

		string AccountNumber = "";
		cout << "Please Enter AccountNumber ? ";
		AccountNumber = clsInputValidation::RaidString();

		while (!clsBankClients::IsClientExist(AccountNumber)) {
			cout << "\nThis Account is not Found , Please Enter Another one : ";
			AccountNumber = clsInputValidation::RaidString();
		}


		clsBankClients Client1 = clsBankClients::Find(AccountNumber);

		if (!Client1.IsEmpty()) {
			cout << "Account Is Find :-)\n";
		}
		else {
			cout << "Account is Not Find :(\n";
		}

		_PrintClient(Client1);
	}



};

