#pragma once
#include <iostream>
using namespace std;
template <class T>
class clsCalculator
{
private:
	T _X =0;
	T _LastNumbe =0;
	T _Num =0;
	string TypCalculator(int Num) {
		switch (Num)
		{
		case 1:return "Adding";
		case 2:return "Subtracting";
		case 3:return "dividing";
		case 4:return "Multiplying";
		}
	}

public:
	void Clear() {
		_X =0;
		_LastNumbe=0;
		_Num =0;
	}

	T Adding(T Num) {
		_LastNumbe = Num;
		_Num = 1;
		return _X += Num;
	}

	T Subtract(T Num) {
		_LastNumbe = Num;
		_Num = 2;
		return _X += -Num;
	}

	T Divide(T Num) {
		if (Num == 0) {
			Num = 1;
		}
		_LastNumbe = Num;
		_Num = 3;
		return _X /= Num;
	}

	T Multiply(T Num) {
		_LastNumbe = Num;
		_Num = 4;
		return _X *= Num;
	}

	void PrintResult() {
		cout << "Result After " << TypCalculator(_Num) << " " << _LastNumbe << " is :" << _X << endl;
	}


};
