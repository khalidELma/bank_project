#pragma once
#include<iostream>
#include"clsDate.h"
using namespace std;
template<class T >


class clsUtili
{
	
protected:
	static void AddArrayelement(int Number, int array[], int& length) {
		length++;
		array[length - 1] = Number;
	}
public:
	
	enum enChartaype { smalletter = 1, CapitalLatter = 2, SpecialCharacter = 3, Digit = 4, MixcharTayp=5 };
	
	

	static void PrintArray(int array[100], int Length)
	{
		for (int i = 0; i < Length; i++)
			cout << array[i] << " ";
		cout << "\n";
	}
	


	static int RandomNumber(int From, int To) {
		int randNum = rand() % (To - From + 1) + From;
		return randNum;
	}

	static int ReadPositiveNumber(string Message) {
		int Number = 0;
		do
		{
			cout << Message << endl;
			cin >> Number;
		} while (Number <= 0);
		return Number;
	}

	static int sum(int a, int b) {
		return (a + b);
	}

	static int sum(int a, int b, int c) {
		return (a + b + c);
	}

	static int sum(int a, int b, int c, int d) {
		return (a + b + c);
	}

	static int sum(int a, int b, int c, int d, int e) {
		return (a + b + c + d);
	}

	static double sum(double a, double b) {
		return (a + b);
	}

	static double sum(double a, double b, double c) {
		return (a + b + c);
	}

	static double sum(double a, double b, double c, double d) {
		return (a + b + c + d);
	}

	static double sum(double a, double b, double c, double d, double e) {
		return (a + b + c + d);
	}


	
	static void Swap(int &A, int& B) {
		int swap;
		swap = A;
		A = B;
		B = swap;
	}

	static void Swap(bool& A, bool& B) {
		bool swap;
		swap = A;
		A = B;
		B = swap;
	}

	static void Swap(float & A, float& B) {
		float swap;
		swap = A;
		A = B;
		B = swap;
	}

	static void  Swap(string & A, string & B) {
		string swap;
		swap = A;
		A = B;
		B = swap;
	}

	static void  Swap(clsDate & A, clsDate& B) {
		clsDate swap;
		swap = A;
		A = B;
		B = swap;
	}



	static void FillArrayWithRandomNumbers(int arr[], int& arrLength,int from ,int to)
	{
		cout << "\nEnter number of elements:\n";
		cin >> arrLength;
		for (int i = 0; i < arrLength; i++)
			arr[i] = RandomNumber(from, to);
	}

	/*static void PrintArray(int arr[], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
			cout << arr[i] << " ";
		cout << "\n";
	}*/

	static int OddCount(int arr[], int arrLength)
	{
		int counter = 0;
		for (int i = 0;i < arrLength;i++) {
			if (arr[i] % 2 == 0) {
				counter++;
			}
		}
		return counter;
	}

	static int ReverseNumber(int Number)
	{
		int Remainder = 0, Number2 = 0;
		while (Number > 0)
		{
			Remainder = Number % 10;
			Number = Number / 10;
			Number2 = Number2 * 10 + Remainder;
		}
		return Number2;
	}

	static void PrintDigits(int Number)
	{
		int Remainder = 0;
		while (Number > 0)
		{
			Remainder = Number % 10;
			Number = Number / 10;
			cout << Remainder << endl;
		}
	}

	static bool IsPalindromeNumber(int Number)
	{
		return Number == ReverseNumber(Number);
	}

	static void PrintInvertedNumberPattern(int Number)
	{
		cout << "\n";
		for (int i = Number; i >= 1; i--)
		{
			for (int j = 1; j <= i; j++)
			{
				cout << i;
			}
			cout << "\n";
		}
	}

	static void PrintNumberPattern(int Number) {


		for (int j = 1;j <= Number;j++) {

			for (int i = 1;i <= j;i++) {
				cout << j;
			}
			cout << endl;
		}
	}

	static void PrintInvertedcharPattern(int Number) {

		int  A = 65;
		for (int j = 1;j <= Number;j++) {

			for (int i = 1;i <= j;i++) {
				cout << static_cast<char>(A);

			}
			cout << endl;
			A++;
		}
	}

	static void PrintcharPattern(int Number) {

		int  A = 65 + Number;
		for (int j = 1;j <= Number;j++) {
			A--;
			for (int i = j;i > 0;i--) {
				cout << static_cast<char>(A);

			}
			cout << endl;

		}
	}

	static void PrintWordsFromAAAtoZZZ()
	{
		cout << "\n";
		string word = "";
		for (int i = 65; i <= 90; i++)
		{
			for (int j = 65; j <= 90; j++)
			{
				for (int k = 65; k <= 90; k++)
				{
					word = word + char(i);
					word = word + char(j);
					word = word + char(k);
					cout << word << endl;
					word = "";
				}
			}
			cout << "\n____________________________\n";
		}
	}

	static bool GuessPassword(string OriginalPassword)
	{
		string word = "";
		int Counter = 0;
		cout << "\n";
		for (int i = 65; i <= 90; i++)
		{
			for (int j = 65; j <= 90; j++)
			{
				for (int k = 65; k <= 90; k++)
				{
					word = word + char(i);
					word = word + char(j);
					word = word + char(k);
					Counter++;
					cout << "Trial [" << Counter << "] : ";
					cout << word << endl;
					if (word == OriginalPassword)
					{
						cout << "\nPassword is " << word << "\n";
						cout << "Found after ";
						cout << Counter << " Trial(s)\n";
						return true;
					}
					word = "";
				}
			}
		}
		return false;
	}

	static string EncryptText(string Text, short EncryptionKey) {
		for (int i = 0;i <= Text.length();i++) {
			Text[i] = char((int)Text[i] + EncryptionKey);
		}
		return Text;
	}
	static string DecryptText(string Text, short EncryptionKey) {
		for (int i = 0;i <= Text.length();i++) {
			Text[i] = char((int)Text[i] - EncryptionKey);
		}
		return Text;
	}

	static char GetRandomCharacter(enChartaype CharType) {
		switch (CharType)
		{
		case enChartaype::MixcharTayp:
			GetRandomCharacter((enChartaype)RandomNumber(1, 4));
			break;
		case enChartaype::smalletter:
			return char(RandomNumber(97, 122));
			break;
		case enChartaype::CapitalLatter:
			return char(RandomNumber(65, 90));
			break;
		case enChartaype::SpecialCharacter:
			return char(RandomNumber(33, 47));
			break;
		case enChartaype::Digit:
			return char(RandomNumber(48, 57));
			break;

		}
	}
	
	static string GenerateWord(enChartaype CharType, short Length) {
		string Word;
		for (int i = 0;i < Length;i++) {
			Word += GetRandomCharacter(CharType);
		}
		return Word;
	}
	
	static string Generateke() {
		string Key = "";
		Key = GenerateWord(enChartaype::CapitalLatter, 4) + '-';
		Key += GenerateWord(enChartaype::CapitalLatter, 4) + '-';
		Key += GenerateWord(enChartaype::CapitalLatter, 4) + '-';
		Key += GenerateWord(enChartaype::CapitalLatter, 4);
		return Key;
	}
	
	static void  Generatekey(int Numbre) {
		for (int i = 0;i < Numbre;i++) {
			cout << "array [" << i + 1 << "] : " << Generateke() << endl;

		}
	}


	static int TimesRepeated(int Number, int arr[], int arrLength)
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

	static void Randamarr(int arr[], int arrLength,int from ,int to) {

		for (int i = 0;i < arrLength;i++) {
			arr[i] = RandomNumber(from, to);

		}
	}

	static void MaxElementsinarr(int array[], int length) {
		int Max = 1;
		cout << "array Elements : ";
		for (int i = 0;i < length;i++) {

			cout << array[i] << " ";
			if (array[i] > Max) {
				Max = array[i];
			}
		}
		cout << "\nMax Number is " << Max;
	}

	static void MinElementsinarr(int array[], int length) {
		int Min=array[0], j;
		cout << "array Elements : ";
		for (int i = 0;i < length;i++) {
			
			cout << array[i] << " ";
			if (array[i] < Min) {
				Min = array[i];

			}
		}
		cout << "\nMin Number is " << Min;
	}

	static void SumOfAllElementsToArr(int array[], int length) {
		int sum = 0;
		cout << "array Elements : ";
		for (int i = 0;i < length;i++) {

			cout << array[i] << " ";

			sum += array[i];

		}
		cout << "\n sum of all Number sum =  " << sum;
	}

	static void AverageOfAllElementsToArr(int array[], int length) {
		int sum = 0;
		cout << "array Elements : ";
		for (int i = 0;i < length;i++) {

			cout << array[i] << " ";

			sum += array[i];

		}
		cout << "\n Average of all Number Ave =  " << sum/ length;
	}

	static enum enPrinNotPrime { Prime = 1, NoPrime = 2 };
	static enPrinNotPrime checkPrim(int Number) {
		int M = round(Number / 2);
		for (int Counter = 2; Counter <= M; Counter++)
		{
			if (Number % Counter == 0)
				return enPrinNotPrime::NoPrime;
		}
		return enPrinNotPrime::Prime;
	}
	static void CopyPrimeNumberarray(int arry[], int cont) {
		int copyarry[100];

		cout << ("\nPrime numbre array2 : ");
		for (int i = 0;i < cont;i++) {
			if (checkPrim(arry[i]) == enPrinNotPrime::Prime) {
				cout << arry[i] << (" ");
			}

		}
	}


	static int  sumOfelementOfArray1andArray2(int arry1[], int array2[], int array3[], int length) {
		for (int i = 0;i < length;i++) {
			array3[i] = arry1[i] + array2[i];
		}
		return array3[100];
	}

	static void ShuffleArray(int arr[100], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
		{
			swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
		}
	}

	static void FillArrayWithKeys(string arr[100], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
			arr[i] = Generateke();
	}

	static void SearchNumber(int array[100], int length,int Search) {
		for (int i = 0; i < length;i++) {
			if (array[i] == Search) {
				cout << "Number you are looking for is :" << Search << endl;
				cout << "The Number found at position:" << i << endl;
				cout << "The Number Found its order :" << i + 1 << endl;
				return;
			}
		}
		    cout << "\nNumber you are looking for is: " << Search << endl;
			cout << "The number is Not found :(" << endl;
	}
	
	static void copyarrelement(int array1[], int array2[], int arr1length, int& arr2length) {
		for (int i = 0;i < arr1length;i++) {
			AddArrayelement(array1[i], array2, arr2length);
		}
	}

	static void CopyOddNumbers(int array1[100], int array2[100], int arr1length, int& arr2length) {
		for (int i = 0;i < arr1length;i++) {
			if (array1[i] % 2 != 0) {
				AddArrayelement(array1[i], array2, arr2length);

			}

		}
	}

	static void CopyPrimeNumbers(int arrSource[100], int arrDestination[100],int arrLength, int& arrDestinationLength)
	{
		for (int i = 0; i < arrLength; i++)
			if (checkPrim(arrSource[i]) == enPrinNotPrime::Prime)
			{
				AddArrayelement(arrSource[i], arrDestination,arrDestinationLength);
			}
	}

	static bool IsPalindromeArray(int arr[100], int arrLength) {
		for (int i = 0;i < arrLength;i++) {
			if (arr[i] != arr[arrLength - 1 - i]) {
				return false;
			}
		};
		return true;
	}

	/*static int OddCount(int arr[100], int arrLength)
	{
		int counter = 0;
		for (int i = 0;i < arrLength;i++) {
			if (arr[i] % 2 != 0) {
				counter++;
			}
		}
		return counter;
	}*/

	static int CountPositivecount(int arr[100], int arrLength)
	{
		int counter = 0;
		for (int i = 0;i < arrLength;i++) {
			if (arr[i] >= 0) {
				counter++;
			}
		}
		return counter;
	}

	static int CountNigativecount(int arr[100], int arrLength)
	{
		int counter = 0;
		for (int i = 0;i < arrLength;i++) {
			if (arr[i] < 0) {
				counter++;
			}
		}
		return counter;
	}

	

};

