#pragma once
#include <iostream>
#include<vector>
#include <fstream>
#include<string>
#include "clsperson.h"
#include "clsString.h"
#include "clsDate.h"
#include "Global.h"
class clsBankClients :public clsPerson
{

private:
	enum eMode { EmptyMode = 0, UpdatMode = 1 ,AddNewMode=2};
	eMode _Mode;
	string _AccountNumber;
	string _PinCode;
	double  _AccountBalance;
	bool _MarkedForDelete=false;
	double _TotalBalance;

	struct StTransferLog;

	

	static StTransferLog _ConvertTransferLogLineToRecord(string Line,string Seperator = "#//#") {

		vector <string>TransferLogDataLine;
		StTransferLog TransferLog;


		TransferLogDataLine = clsString::Split(Line);

		TransferLog.DateTime = TransferLogDataLine[0];
		TransferLog.SourceAccountNumber = TransferLogDataLine[1];
		TransferLog.DestinationAccountNumber= TransferLogDataLine[2];
		TransferLog.Amount = stoi (TransferLogDataLine[3]) ;
		TransferLog.srcBalanceAfter = stoi(TransferLogDataLine[4]);
		TransferLog.destBalanceAfter = stoi(TransferLogDataLine[5]);
		TransferLog.UserName = TransferLogDataLine[6];
		return TransferLog;
	}

	static clsBankClients _ConvertLineToClientObject(string line, string Seperator = "#//#") {

		vector <string> vDataClient;

		vDataClient = clsString::Split(line, Seperator);

		return clsBankClients(eMode::UpdatMode , vDataClient[0], vDataClient[1], vDataClient[2], vDataClient[3], vDataClient[4], vDataClient[5], stoi(vDataClient[6]));
	}
	static string _ConvertClientObjectToLine(clsBankClients Client, string Seperator = "#//#") {
		string S1="";
		S1 += Client.FirstName+ Seperator;
		S1 += Client.LastName + Seperator;
		S1 += Client.Email + Seperator;
		S1 += Client.Phone + Seperator;
		S1 += Client.AccountNumber + Seperator;
		S1 += Client.PinCode + Seperator;
		S1 += to_string(Client.AccountBalance) + Seperator;
		return S1;
	}
	static string _ConvertTransLogToLine(double amount, clsBankClients SoursClient, clsBankClients DestinationClient,string Seperator = "#//#") {
		string S = "";
		S += clsDate::DateToString (clsDate()) + " - " + clsDate::TimeToString(clsDate())+ Seperator;
		S += SoursClient.AccountNumber + Seperator;
		S += DestinationClient.AccountNumber + Seperator;
		S += to_string(amount) + Seperator;
		S += to_string(SoursClient.AccountBalance) + Seperator;
		S+= to_string(DestinationClient.AccountBalance) + Seperator;
		S += CurrentUser.UserName;

		return S;
	}

	static vector <clsBankClients>  _LoadDataClientToFile() {

		vector<clsBankClients> vClient;
		
		fstream MyFile;
		MyFile.open("Client.txt", ios::in);

		if (MyFile.is_open()) {
			string line;
			while (getline(MyFile, line)) {
				clsBankClients Client = _ConvertLineToClientObject(line);
				vClient.push_back(Client);
			}

			MyFile.close();
		}
		return vClient;

	}
	 void _SaveClientDataToFile(vector <clsBankClients> Data) {

		fstream MyFile;
		MyFile.open("Client.txt", ios::out);

		if (MyFile.is_open()) {
			string Line;
			for (clsBankClients C : Data) {
				if (!C._MarkedForDelete) {
					Line = _ConvertClientObjectToLine(C);
					MyFile << Line << endl;
				}
			}
		}
		MyFile.close();
	}
	

	 
	 
	static clsBankClients _GetEmptyClientObject() {
		return clsBankClients(eMode::EmptyMode , "", "", "", "", "", "", 0);
	}

	void _Update() {
		vector <clsBankClients> vClient = _LoadDataClientToFile();

		for (clsBankClients& C : vClient) {
			if (C.AccountNumber == GetAccountNumber()) {
				C = *this;
				break;
			}


		}

		_SaveClientDataToFile(vClient);
	}

	void _AddNewClientToFile(string Line) {
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out | ios::app);
		if (MyFile.is_open()) {
			
			MyFile << Line << endl;

			MyFile.close();
		}
	}

	void _AddNew() {
		_AddNewClientToFile(_ConvertClientObjectToLine(*this));
	}

	static vector <StTransferLog> _loadTransferLogeToFile() {

		vector <StTransferLog> vTransferLog;

		fstream MyFile;
		MyFile.open("Transfer Login .txt", ios::in);
		if (MyFile.is_open()) {

			string Line;

			while (getline(MyFile, Line)) {

				vTransferLog.push_back(_ConvertTransferLogLineToRecord(Line));
			}
		}
		return vTransferLog;
	}
public:

	clsBankClients(eMode Mode, string _FirstName, string _lastName, string _Email, string _Phone, string AccountNumber, string PinCode, double AccountBalance)
		:clsPerson(_FirstName, _lastName, _Email, _Phone)
	{
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_AccountBalance = AccountBalance;
	}

	struct StTransferLog {
		string DateTime;
		string SourceAccountNumber;
		string DestinationAccountNumber;
		float Amount;
		float srcBalanceAfter;
		float destBalanceAfter;
		string UserName;
	};

	 bool IsEmpty() {
		return (_Mode == eMode::EmptyMode);
	}

	void setAccountNumber(string AccountNumber) {
		_AccountNumber = AccountNumber;
	}
	string GetAccountNumber() {
		return _AccountNumber;
	}
	__declspec(property(get = GetAccountNumber, put = setAccountNumber))string AccountNumber;

	void setPinCode(string PinCode) {
		_PinCode = PinCode;
	}
	string GetPinCode() {
		return _PinCode;
	}
	__declspec(property(get = GetPinCode, put = setPinCode))string PinCode;

	void setAccountBalance(double AccountBalance) {
		_AccountBalance = AccountBalance;
	}
	double GetAccountBalance() {
		return _AccountBalance;
	}
	__declspec(property(get = GetAccountBalance, put = setAccountBalance))double AccountBalance;

	static clsBankClients Find(string AccountNumber) {

		vector<clsBankClients> vClient;


		fstream MyFile;
		MyFile.open("Client.txt", ios::in);

		if (MyFile.is_open()) {

			string line;
			while (getline(MyFile, line)) {

				clsBankClients Client = _ConvertLineToClientObject(line);
				if (Client._AccountNumber == AccountNumber) {
					MyFile.close();
					return Client;
				}
				vClient.push_back(Client);

			}
			MyFile.close();

		}

		return _GetEmptyClientObject();

	}

	static clsBankClients Find(string AccountNumber, string PinCode) {

		vector<clsBankClients> vClient;


		fstream MyFile;
		MyFile.open("Client.txt", ios::in);

		if (MyFile.is_open()) {

			string line;
			while (getline(MyFile, line)) {

				clsBankClients Client = _ConvertLineToClientObject(line);
				if (Client._AccountNumber == AccountNumber && Client._PinCode == PinCode) {
					MyFile.close();
					return Client;
				}
				vClient.push_back(Client);

			}
			MyFile.close();

		}

		return _GetEmptyClientObject();

	}

	static bool IsClientExist(string AccountNumber)
	{

		clsBankClients Client1 = clsBankClients::Find(AccountNumber);
		return (!Client1.IsEmpty());
	}

	static clsBankClients GetAddNewClientObject(string AccountNumber) {
		return clsBankClients(eMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
	}

	enum enSaveResulte { svFaildEmptyObject = 0,svSucceeded=1,svFaildAccountNumberIsExist=3 };

	enSaveResulte Save() {
		
		switch (_Mode)
		{
		case clsBankClients::EmptyMode:
			
			if (IsEmpty()) 
			{
				return enSaveResulte::svFaildEmptyObject;
			}
			break;
		case clsBankClients::UpdatMode:
			
			
			_Update();
			return enSaveResulte::svSucceeded;
			break;
		
		
		case clsBankClients::AddNewMode:
			if (clsBankClients::IsClientExist(_AccountNumber)) {
				return enSaveResulte::svFaildAccountNumberIsExist;
			}
			else {
				_AddNew();
				_Mode = eMode::UpdatMode;
				return enSaveResulte::svSucceeded;
			}


			break;
		}

	}

	bool Delete() {

		vector <clsBankClients> _vClient;
		_vClient = _LoadDataClientToFile();

		for (clsBankClients& C : _vClient)
		{

			if (C.GetAccountNumber() == _AccountNumber ) {
				C._MarkedForDelete = true;
				break;
			}
		}

		_SaveClientDataToFile(_vClient);
		* this = _GetEmptyClientObject();
		return true;
	}

	static vector<clsBankClients> GetClientsList() {

		return _LoadDataClientToFile();
	}

	static double GetTotalBalance() {

		vector <clsBankClients> vClients;
		vClients = _LoadDataClientToFile();
		double TotalBalance=0;
		for (clsBankClients& C : vClients) {

			TotalBalance += C.AccountBalance;

		}

		return TotalBalance;

	}

	static string NumberToText(long Number)
	{
		if (Number == 0)
		{
			return "";
		}
		if (Number >= 1 && Number <= 19)
		{
			string arr[] = { "","One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };
			return arr[Number] + " ";
		}
		if (Number >= 20 && Number <= 99) {
			string arr[] = { "", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy","Eighty", "Ninety" };
			return arr[Number / 10] + NumberToText(Number % 10) + " ";
		}
		if (Number >= 100 && Number <= 199) {
			return "one Hundred " + NumberToText(Number % 100) + " ";
		}
		if (Number >= 200 && Number <= 999) {
			return NumberToText(Number / 100) + " Hundred" + NumberToText(Number % 100) + " ";
		}
		if (Number >= 1000 && Number <= 1999) {
			return "one Thousand " + NumberToText(Number % 1000) + " ";
		}
		if (Number >= 2000 && Number <= 999999) {
			return NumberToText(Number / 1000) + " Thousand " + NumberToText(Number % 1000);
		}

		if (Number >= 1000000 && Number <= 1999999)
		{
			return "One Million " + NumberToText(Number % 1000000) + " ";
		}
		if (Number >= 2000000 && Number <= 999999999) {
			return  NumberToText(Number / 1000000) + " Million " + NumberToText(Number % 1000000) + " ";
		}
	}

	void Deposit(double amount) {
		_AccountBalance += amount;
		Save();
	}

	bool withdraw(double amount) {
		if (amount > _AccountBalance) {
			return false;
		}

		else {
			_AccountBalance -= amount;
			Save();
			return true;
		}
	}



	bool Transfer(double amount, clsBankClients& DestinationCline) {

		if (amount > AccountBalance)
			return false;
			
		else {

			withdraw(amount);
			DestinationCline.Deposit(amount);
			SaveTransferLogToFile(amount, *this, DestinationCline);
			return true;
		}
	}


	static void SaveTransferLogToFile(double amount, clsBankClients SoursClient, clsBankClients DestinationClient) {

		fstream MyFile;

		MyFile.open("Transfer Login .txt", ios::in | ios::app);

		if (MyFile.is_open()) {
			MyFile << _ConvertTransLogToLine(amount, SoursClient, DestinationClient);
			MyFile << endl;


			MyFile.close();
		}
		
	}

	static vector <StTransferLog> GetTransferLogList() {
		return _loadTransferLogeToFile();
	}
	
};

