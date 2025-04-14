#pragma once

#include<iostream>
#include<string>
#include<cstdbool>
#include<vector>
#include"clsDate.h"
using namespace std;



class clsString {



public:
	string _Value;
	char _C;

	clsString() {}

	clsString(string Value) {
		_Value = Value;
	}


	void setValue(string Value) {

		_Value = Value;

	}
	string getValue() {
		return _Value;
	}
	__declspec(property(get = getValue, put = setValue)) string value;

	static short stlength(string S1) {
		return S1.length();
	}
	short stlength() {
		return stlength(_Value);
	}


	static string UpperFirstLetterOfEachWord(string S1)
	{
		bool isFirstLetter = true;
		for (short i = 0; i < S1.length(); i++)
		{
			if (S1[i] != ' ' && isFirstLetter)
			{
				S1[i] = toupper(S1[i]);
			}
			isFirstLetter = (S1[i] == ' ' ? true : false);
		}
		return S1;
	}
	void UpperFirstLetterOfEachWord() {
		_Value = UpperFirstLetterOfEachWord(_Value);
	}
	static string LaterrAllString(string S1)
	{
		for (short i = 0; i < S1.length(); i++)
		{
			S1[i] = toupper(S1[i]);
		}
		return S1;
	}


	static string UpperListLetterOfEachWord(string S1)
	{
		bool isFirstLetter = true;
		for (short i = 0; i < S1.length(); i++)
		{
			if (S1[i] != ' ' && isFirstLetter)
			{
				S1[i] = tolower(S1[i]);
			}
			isFirstLetter = (S1[i] == ' ' ? true : false);
		}
		return S1;
	}
	void UpperListLetterOfEachWord() {
		_Value = UpperListLetterOfEachWord(_Value);
	}



	static string LowerAllString(string S1)
	{
		for (short i = 0; i < S1.length(); i++)
		{
			S1[i] = tolower(S1[i]);
		}
		return S1;
	}
	void LowerAllString() {
		_Value = LowerAllString(_Value);
	}



	static short CountCapital_Latters(string S1) {
		short counter = 0;
		for (int i = 0;i < S1.length();i++) {
			if (isupper(S1[i])) {
				counter++;
			}
		}
		return counter;
	}
	short CountCapital_Latters() {
		return CountCapital_Latters(_Value);
	}



	static short Countsmall_Latters(string S1) {
		short counter = 0;
		for (int i = 0;i < S1.length();i++) {
			if (islower(S1[i])) {
				counter++;
			}
		}
		return counter;
	}
	short Countsmall_Latters() {
		return Countsmall_Latters(_Value);
	}



	static short  CountCharinstring(string S1, char C1) {
		short count = 0;
		for (int i = 0; i < S1.length();i++) {
			if (S1[i] == C1) {
				count++;
			}
		}
		return count;
	}
	short CountCharinstring() {
		return CountCharinstring(_Value, _C);
	}



	short  CountCharinstring2(string S1, char C1) {
		short count = 0;
		for (int i = 0; i < S1.length();i++) {
			if (S1[i] == tolower(C1) || S1[i] == toupper(C1)) {
				count++;
			}
		}
		return count;
	}
	short CountCharinstring2() {
		return CountCharinstring2(_Value, _C);
	}


	static char Invertingcharacter(char C1) {
		return C1 == toupper(C1) ? tolower(C1) : toupper(C1);
	}
	char Invertingcharacter() {
		return Invertingcharacter(_C);
	}


	static  bool IsVowel(char Ch1)
	{
		Ch1 = tolower(Ch1);
		return ((Ch1 == 'a') || (Ch1 == 'e') || (Ch1 == 'i') || (Ch1 == 'o') || (Ch1 == 'u'));
	}


	static short CountVowels(string S1)
	{
		short Counter = 0;
		for (short i = 0; i < S1.length(); i++)
		{
			if (IsVowel(S1[i])) {
				Counter++;
			}

		}
		return Counter;
	}
	short CountVowels() {
		return CountVowels(_Value);
	}


	static void wordsbaywords(string S1) {

		for (int i = 0;i < S1.length();i++) {
			if (S1[i] != ' ') {
				cout << S1[i];
			}
			if (S1[i] == ' ' && S1[i - 1] != ' ') {
				cout << endl;
			}
		}
	}



	static int CountWords(string S1) {
		string delim = " ";
		short pos = 0, count = 1;
		string swords;
		while ((pos = S1.find(delim)) != std::string::npos) {
			swords = S1.substr(pos);
			if (swords != " ") {
				count++;
			}
			S1.erase(0, pos + delim.length());
		}
		return count;
	}
	int CountWords() {
		return 	CountWords(_Value);
	}


	static vector<string> Split(string S1, string Delim="#//#")
	{

		vector<string> vString;

		short pos = 0;
		string sWord; // define a string variable  

		// use find() function to get the position of the delimiters  
		while ((pos = S1.find(Delim)) != std::string::npos)
		{
			sWord = S1.substr(0, pos); // store the word   
			// if (sWord != "")
			// {
			vString.push_back(sWord);
			//}

			S1.erase(0, pos + Delim.length());  /* erase() until positon and move to next word. */
		}

		if (S1 != "")
		{
			vString.push_back(S1); // it adds last word of the string.
		}

		return vString;

	}
	

	static string JoinString(vector<string> vString, string Delim)
	{
		string S1;
		for (string& s : vString)
		{
			S1 = S1 + s + Delim;
		}
		return S1.substr(0, S1.length() - Delim.length());
	}
	static string JoinString(string arr[], string Delim, short length) {
		string S1 = "";
		for (int i = 0;i < length;i++) {
			S1 += arr[i];
		}
		return S1;
	}

	static	string TrimLeft(string S1)
	{
		for (short i = 0; i < S1.length(); i++)
		{
			if (S1[i] != ' ')
			{
				return S1.substr(i, S1.length() - i);
			}
		}
		return "";
	}
	void TrimLeft() {
		_Value = TrimLeft(_Value);
	}


	static	string TrimRight(string S1)
	{
		for (short i = S1.length() - 1; i >= 0; i--)
		{
			if (S1[i] != ' ')
			{
				return S1.substr(0, i + 1);
			}
		}
		return "";
	}
	void TrimRight() {
		_Value = TrimRight(_Value);
	}


	static	string Trim(string S1)
	{
		return (TrimLeft(TrimRight(S1)));
	}
	void Trim() {
		_Value = Trim(_Value);
	}




	static string deletedRemoveinString(string S1) {

		string S2 = "";
		for (int i = 0;i < S1.length();i++) {
			if (!ispunct(S1[i]))
				S2 += S1[i];
		}
		return S2;
	}
	void deletedRemoveinString() {
		_Value = deletedRemoveinString(_Value);
	}




	static string ReplaceWordInString(string S1, string StringToReplace, string sRepalceTo)
	{
		short pos = S1.find(StringToReplace);
		while (pos != std::string::npos)
		{
			S1 = S1.replace(pos, StringToReplace.length(),
				sRepalceTo);
			pos = S1.find(StringToReplace);//find next
		}
		return S1;
	}

	int TimesRepeated(int Number, int arr[100], int arrLength)
	{
		int count = 0;
		for (int i = 0; i <= arrLength - 1; i++)
		{
			if (Number == arr[i])
			{
				count++;
			}
		}
		return count;
	}

};