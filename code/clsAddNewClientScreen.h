#pragma once
#include <iostream>
#include"clsScreen.h"
#include"clsBinkClien.h"
#include"clsInputValidation.h"

class clsAddNewClientScreen : protected clsScreen
{

	static void _ReadClientInfo(clsBankClients& Client) {
		cout << "\nEnter your FirstName : ";
		Client.FirstName=clsInputValidation::RaidString();
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

	static void ShowAddNewClientScreen() {

		if (!CheckAccessRights(clsUser::enPermissions::pAddNewCleint)) {
			return;
		}

		_DrawScreenHeader("\t\tAdd New Client ");

		string AccountNumber = "";

		cout << "Please Enter AccountNumber : ";
		AccountNumber = clsInputValidation::RaidString();

		while (clsBankClients::IsClientExist(AccountNumber)) {
			cout << "This Account Is Already Used , Please Enter Another one :  ";
			AccountNumber = clsInputValidation::RaidString();
		}

		clsBankClients NewClient = clsBankClients::GetAddNewClientObject(AccountNumber);
		_ReadClientInfo(NewClient);

		clsBankClients::enSaveResulte SaveResult;

		SaveResult = NewClient.Save();

		switch (SaveResult)
		{
		case  clsBankClients::enSaveResulte::svSucceeded:
		{
			cout << "\nAccount Added Successfully :-)\n";
			_PrintClient(NewClient);
			break;
		}
		case clsBankClients::enSaveResulte::svFaildEmptyObject:
		{
			cout << "\nError account was not saved because it's Empty";
			break;

		}
		case clsBankClients::enSaveResulte::svFaildAccountNumberIsExist:
		{
			cout << "\nError account was not saved because account number is used!\n";
			break;

		}
		}


	}



};

