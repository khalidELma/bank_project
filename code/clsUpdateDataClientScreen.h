#pragma once
#include <iostream>
#include"clsScreen.h"
#include"clsBinkClien.h"
#include"clsInputValidation.h"

class clsUpdateDataClientScreen:protected clsScreen
{

	static void _ReadClientInfo(clsBankClients& Client) {
		cout << "\nEnter your FirstName : ";
		Client.FirstName = clsInputValidation::RaidString();
		cout << "\nEnter your LastName : ";
		Client.LastName = clsInputValidation::RaidString();
		cout << "\nEnter your Email : ";
		Client.Email = clsInputValidation::RaidString();
		cout << "\nEnter your Phone : ";
		Client.Phone = clsInputValidation::RaidString();
		cout << "\nEnter your PinCode : ";
		Client.PinCode = clsInputValidation::RaidString();
		cout << "\n Enter your Balance : ";
		Client.AccountBalance = clsInputValidation::ReidDoubleNumber();
	}

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

	static void ShoeUpdateClientData() {
		if (!CheckAccessRights(clsUser::enPermissions::pUpdateCleint)) {
			return;
		}
		_DrawScreenHeader("\t\tUpdate Client ");

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
		cout << "Are you sure do you want to Update this Account ? Y/N  ";
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y') {


			cout << "\n\n\n\tUpdate Client Info : \n";
			cout << "___________________________\n";
			_ReadClientInfo(Client1);
			clsBankClients::enSaveResulte Results;
			Results = Client1.Save();

			switch (Results)
			{
			case clsBankClients::svSucceeded: 
				cout << "\n\n\n\nAccount Update Successfully \n";
				_PrintClient(Client1);
				break;
			case clsBankClients::svFaildEmptyObject:
				cout << "\nError account was not saved because it's Empty";
				break;
			  
			}

		}

	}

};

