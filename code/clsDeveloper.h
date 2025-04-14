#pragma once

#include <iostream>
#include "clsEmployee.h";

using namespace std;
class clsDeveloper :public clsEmployee {
	string _MainProgrammingLanguage;
public:
	clsDeveloper( string FirstName, string LastName, string Email, string Phone, string Title, string Department, float Salary, string MainProgrammingLanguage)

		:clsEmployee( FirstName, LastName, Email, Phone, Title, Department, Salary) {

		_MainProgrammingLanguage = MainProgrammingLanguage;

	}


	void setMainProgrammingLanguage(string MainProgrammingLanguage) {
		_MainProgrammingLanguage = MainProgrammingLanguage;
	}


	string MainProgrammingLanguage() {
		return _MainProgrammingLanguage;
	}



	void Print() {
		cout << "\tINFO : " << endl;
		cout << "______________________________________________" << endl;
		cout << "Forst Name                : " << FirstName << endl;
		cout << "Last Name                 : " << LastName << endl;
		cout << "Email                     : " << Email<< endl;
		cout << "Phone                     : " << Phone << endl;
		cout << "Title                     : " << Title() << endl;
		cout << "Department                : " << Department() << endl;
		cout << "salary                    : " << Salary() << endl;
		cout << "Main Programming Language : " << _MainProgrammingLanguage << endl;
		cout << "______________________________________________" << endl << endl << endl;
	}


};