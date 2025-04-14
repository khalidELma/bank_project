#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsBinkClien.h"
#include"clsInputValidation.h"

class clsDepositScreen:protected clsScreen
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

	static string ReadAccountNumber() {
		cout << "Please Enter your Account Number ? ";
		return clsInputValidation::RaidString();
	}



public :

	static void ShowDepositScreen() {

		_DrawScreenHeader("\t   Deposit Screen");


		string AccountNumber = ReadAccountNumber();

		while (!clsBankClients::IsClientExist(AccountNumber)) {
			cout << "This Account Is Not Exist , Enter Another one : ";
			AccountNumber = ReadAccountNumber();
		}


		clsBankClients Client1 = clsBankClients::Find(AccountNumber);
		_PrintClient(Client1);




		double amount = 0;
		cout << "Please Enter deposit amount ? ";
		cin >> amount;



		char Answer = 'n';
		cout << "\nAre you Sure Do you want to perform this Transaction : ";
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y') {

			Client1.Deposit(amount);
			
			cout << "Amount Deposit Successfully \n ";
			cout << "New Balance = " << Client1.AccountBalance << endl;



		}

	}



};

