#pragma once
#include <iostream>
#include "clsperson.h"
using namespace std;
class clsEmployee :public clsPerson {
	string _Title;
	string _Department;
	float _Salary;

public:

	clsEmployee( string FirstName, string LastName, string Email, string Phone, string Title, string Department, float Salary) : clsPerson( FirstName, LastName, Email, Phone) {
		_Title = Title;
		_Department = Department;
		_Salary = Salary;

	}

	void setTitle(string Title) {
		_Title = Title;
	}
	string Title() {
		return _Title;
	}

	float setSalary(float Salary) {
		_Salary = Salary;
	}
	float Salary() {
		return _Salary;
	}

	void setDepartment(string Department) {
		_Department = Department;
	}
	string Department() {
		return _Department;
	}

	void Print() {
		cout << "\tINFO : " << endl;
		cout << "______________________________________________" << endl;
		
		cout << "Forst Name : " << FirstName << endl;
		cout << "Last Name  : " << LastName << endl;
		cout << "Email      : " << Email << endl;
		cout << "Phone      : " << Phone << endl;
		cout << "Title      : " << _Title << endl;
		cout << "Department : " << _Department << endl;
		cout << "salary     : " << _Salary << endl;
		cout << "______________________________________________" << endl << endl << endl;
	}

};


