#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsBinkClien.h"
#include"clsInputValidation.h"

class clsWithdrawScreen : protected clsScreen
{
private:

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
	static string ReadAccountNumber() {
		cout << "Please Enter your Account Number ? ";
		return clsInputValidation::RaidString();
	}


public:

	static void ShowWithdraw() {


		_DrawScreenHeader("\t  Withdraw Screen ");

		string AccountNumber = ReadAccountNumber();
		while (!clsBankClients::IsClientExist(AccountNumber)) {
			cout << "This Account is Not Found ,Enter Another one : ";
			AccountNumber = ReadAccountNumber();
		}

		clsBankClients Client = clsBankClients::Find(AccountNumber);
		_PrintClient(Client);

		double Amount = 0;
		cout << "\nPlease Enter Withdraw amount : ";
		Amount = clsInputValidation::ReidDoubleNumber();

		char Answer = 'n';
		cout << "\nAre you Sure Do you want to perform this Transaction  Y/N ";
		cin>>Answer;

		if (Answer == 'Y' || Answer == 'y') {

			if (!Client.IsEmpty()) {
				if (Client.withdraw(Amount)) {
					cout << "\nWithdraw is Successfully :-) \n";
					cout << "\nNew Balance is " << Client.AccountBalance<<endl;
				}
				else{
					cout << "\nCannot Withdraw , Insufficient Balance ? " << endl;
					cout << "\nAmount to Withdraw is " << Amount << endl;
				}
			}


		}
		else{
			cout << "\nOperation was cancelled . \n";
		}


	}

};