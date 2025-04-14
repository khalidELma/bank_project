#pragma once
#include "clsperson.h"
#include "clsString.h"
#include <fstream>
#include "clsDate.h"
#include<string>
class clsUser:public clsPerson
{

	enum enMode{eEmptyMode = 1 , eUpdateMode = 2 , AddNewMode};
	
	enMode _Mode;
	string _UserName;
	string _Password;
	int _Permissions;
	bool _MarkedForDelete = false;

	struct stLoginRegisterScreenRecord;
	
	 static stLoginRegisterScreenRecord _ConvertLoginRegisterLineToRecord(string line, string Seperator = "#//#") {

		stLoginRegisterScreenRecord LoginRegisterRecord;

		vector<string> LoginRegisterDateLine = clsString::Split(line, Seperator);
		LoginRegisterRecord.DateTime = LoginRegisterDateLine[0];
		LoginRegisterRecord.UserName = LoginRegisterDateLine[1];
		LoginRegisterRecord.Password = DecryptText(LoginRegisterDateLine[2],2);
		LoginRegisterRecord.Permissions = stoi(LoginRegisterDateLine[3]);

		return LoginRegisterRecord;
	}


	static clsUser _ConvertLineToUserObject(string line, string Seperator = "#//#") {
		vector<string> vDataUser;

		vDataUser = clsString::Split(line, Seperator);

		return clsUser(enMode::eUpdateMode, vDataUser[0], vDataUser[1], vDataUser[2], vDataUser[3], vDataUser[4], DecryptText(vDataUser[5]), stoi(vDataUser[6]));
	}
	static clsUser _GetEmptyUserObject() {
		return clsUser(enMode::eEmptyMode, "", "", "", "","","", 0);
	}



	string _ConvertUsersObjectToLine(clsUser User, string Seperator = "#//#") {

		string S ="";
		S += User.FirstName + Seperator;
		S += User.LastName + Seperator;
		S += User.Email + Seperator;
		S += User.Phone + Seperator;
		S += User._UserName + Seperator;
		S += EncryptText(User._Password,2) + Seperator;
		S += to_string(User._Permissions) + Seperator;
		
		return S;
	}

	 string _ConvertUsersDateToLine(string Seperator = "#//#") {
		clsDate Date;
		string S = "";
		S = clsDate::GetSystemDateTameToString(Date) + Seperator;
		S += _UserName + Seperator;
		S += EncryptText(_Password) + Seperator;
		S += to_string(_Permissions);

		return S;
	}


	static vector<clsUser>  _LoadDataUsersToFile() {
		
		vector<clsUser> vUsers;
		fstream MyFile;

		MyFile.open("Users.txt", ios::in);

		if (MyFile.is_open()) {

			string Line;
			while (getline(MyFile, Line)) {

				clsUser User = _ConvertLineToUserObject(Line);
				vUsers.push_back(User);

			}

			MyFile.close();
		}
		return vUsers;
	}
	
	void _SaveUsersDataToFile(vector<clsUser> vUsers) {

		fstream MyFile;

		MyFile.open("Users.txt", ios::out);

		if (MyFile.is_open()) {


			for (clsUser User : vUsers) {
				
				if (!User._MarkedForDelete) {
					MyFile << _ConvertUsersObjectToLine(User);
					MyFile << endl;
				}
				
			}
			
			MyFile.close();
		}


	}

	void _Update() {

		vector<clsUser> vUser = _LoadDataUsersToFile();

		for (clsUser &U : vUser) {

			if (U._UserName == GetUserName()) {
				U = *this;
				break;
			}

		}

		_SaveUsersDataToFile(vUser);
	}

	void _AddNewUser(string Line) {
		
		fstream MyFile;

		MyFile.open("Users.txt", ios::in | ios::app);

		if (MyFile.is_open()) {

			MyFile << Line;
			MyFile << endl;

			MyFile.close();
		}
		

	}

	void AddNew() {
		_AddNewUser(_ConvertUsersObjectToLine(*this));
	}

	

	

public:


	enum enPermissions {
		pAll = -1, pListCleint = 1, pAddNewCleint = 2,
		pDeleteCleint = 4, pUpdateCleint = 8, pFind = 16,
		pTranaction = 32, pManageCleint = 64, pLogineRegister = 128,
		pCurrency = 256
	};

	struct stLoginRegisterScreenRecord
	{
		string DateTime;
		string UserName;
		string Password;
		int Permissions;

	};


	clsUser(enMode Mode, string _FirstName, string _lastName, string _Email,
		string _Phone, string UserName, string Password, int Permissions)
		:clsPerson(_FirstName, _lastName, _Email, _Phone)	{
		_Mode = Mode;
		_UserName = UserName;
		_Password = Password;
		_Permissions = Permissions;

	}


	void setUserName(string UserName) {
		_UserName = UserName;
	}
	string GetUserName() {
		return _UserName;
	}
	__declspec(property(get = GetUserName, put = setUserName)) string UserName;


	void setPassword(string Password) {
		_Password = Password;
	}
	string GetPassword() {
		return _Password;
	}
	__declspec(property(get = GetPassword, put = setPassword)) string Password;


	void setPermissions(int Permissions) {
		_Permissions = Permissions;
	}
	int GetPermissions() {
		return _Permissions;
	}
	__declspec(property(get = GetPermissions, put = setPermissions)) int Permissions;




	bool IsEmpty() {
		return (_Mode == enMode::eEmptyMode);
	}
	static clsUser Find(string UserName, string Password) {

		vector<clsUser> vUsers;

		fstream MyFile;

		MyFile.open("Users.txt", ios::in);

		if (MyFile.is_open()) {

			string Line;
			while (getline(MyFile, Line))
			{
				clsUser User = _ConvertLineToUserObject(Line);

				if (User._UserName == UserName && User._Password == Password)
				{
					MyFile.close();
					return User;
				}


			}

			MyFile.close();
		}

		return _GetEmptyUserObject();

	}
	static clsUser Find(string UserName) {

		vector<clsUser> vUsers;

		fstream MyFile;

		MyFile.open("Users.txt", ios::in);

		if (MyFile.is_open()) {

			string Line;
			while (getline(MyFile, Line))
			{
				clsUser User = _ConvertLineToUserObject(Line);

				if (User._UserName == UserName ){
					MyFile.close();
					return User;
				}


			}

			MyFile.close();
		}

		return _GetEmptyUserObject();

	}
	

	static bool IsAccountExist(string UserName) {
		clsUser User = clsUser::Find(UserName);
		return (!User.IsEmpty());
	}

	static clsUser GetAddNewUserObject(string UserName) {
		return clsUser(enMode::AddNewMode, "", "", "", "", UserName, "", 0);
	}

	enum enSaveResulte { svFaildEmptyObject = 0, svSucceeded = 1, svFaildAccountNumberIsExist = 3 };

	enSaveResulte Save() {

		switch (_Mode)
		{
	
		case clsUser::eEmptyMode:
			
			if (IsEmpty()) {

				return svFaildEmptyObject;
			}
			break;
		
		case clsUser::eUpdateMode:

			_Update();
			return enSaveResulte::svSucceeded;
			break;
		case clsUser::AddNewMode:

			if (clsUser::IsAccountExist(_UserName)) {

				return enSaveResulte::svFaildAccountNumberIsExist;
			}
			else {
				AddNew();
				_Mode = enMode::eUpdateMode;
				return enSaveResulte::svSucceeded;
			}
		}

	}


	bool Delete() {

		vector<clsUser> vUsers;

		vUsers = _LoadDataUsersToFile();

		for (clsUser& User : vUsers) {

			if (User.UserName == GetUserName()) {
				User._MarkedForDelete = true;
				break;
			}


		}

		_SaveUsersDataToFile(vUsers);
		*this = _GetEmptyUserObject();
		return true;

	}

	static vector<clsUser> GetUsersList() {
		return _LoadDataUsersToFile();
	}



	 bool CheckAccessPermissions(enPermissions Permissions) {

		if (this->_Permissions == enPermissions::pAll)
			return true;
		
		if ((Permissions & this->_Permissions) == Permissions)
			return true;
		else
			return false;

	}



	void outDataToFile() {

		 fstream MyFile;

		 MyFile.open("LoginRegister.txt", ios::in | ios::app);

		 if (MyFile.is_open()) {

			 MyFile << _ConvertUsersDateToLine() << endl;

			 MyFile.close();

		 }

	 }

	static vector<stLoginRegisterScreenRecord>  _LoadDataLoginToFile() {

		vector<stLoginRegisterScreenRecord> vLoginRegisterRecord;
		stLoginRegisterScreenRecord  LoginRegisterRecord;
		fstream MyFile;
		string Line;


		MyFile.open("LoginRegister.txt", ios::in);

		if (MyFile.is_open()) {


			while (getline(MyFile, Line)) {

				LoginRegisterRecord = _ConvertLoginRegisterLineToRecord(Line);

				vLoginRegisterRecord.push_back(LoginRegisterRecord);

			}
			MyFile.close();
		}
		return vLoginRegisterRecord;
	}


	static string EncryptText(string text, short Encryptionkey = 2) {

		for (int i = 0; i <= text.length();i++) {

			text[i] = char((int)text[i] + Encryptionkey);

		}

		return text;

	}
	
	static string DecryptText(string text, short Encryptionkey = 2) {

		for (int i = 0; i <= text.length();i++) {

			text[i] = char((int)text[i] - Encryptionkey);

		}

		return text;

	}



};