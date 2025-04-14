#pragma once
#pragma warning(disable : 4996)
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <ctime>
#include "clsString.h";


class clsDate
{
	struct sDate {
		short _Year;
		short _month;
		short _Day;
		short _hour;
		short _Min;
		short _Sec;

	};

	struct sPeriode {
		sDate StartDate;
		sDate EndtDate;
	};

protected:
	
	
	static bool IsDate1BeforeDate2(sDate Date1, sDate Date2)
	{
		return (Date1._Year < Date2._Year) ? true : ((Date1._Year ==
			Date2._Year) ? (Date1._month < Date2._month ? true : (Date1._month ==
				Date2._month ? Date1._Day < Date2._Day : false)) : false);
	}
	bool IsDate1EqualDate2(sDate Date1, sDate Date2)
	{
		return (Date1._Year == Date2._Year) ? ((Date1._month ==
			Date2._month) ? ((Date1._Day == Date2._Day) ? true : false) : false)
			: false;
	}
	bool IsDate1AfterDate2(sDate Date1, sDate Date2)
	{
		return (!IsDate1BeforeDate2(Date1, Date2) &&
			!IsDate1EqualDate2(Date1, Date2));
	}
	static void tcheck(short Year, short month, short Day) {
		int Numday = NumberOfDay(Year, month, Day);
		int i;
		for (i = 0;i <Numday;i++)
			cout << "      ";
		for (int j = 1;j <= NumberTheMonth(month, Year);j++) {
			cout << setw(3) << j << "   ";
			if (++i == 7) {
				cout << '\n';
				i = 0;
			}
		}
	}
	enum enDateCompare { Before = -1, Equal = 0, After = 1 };
	enDateCompare CompareDates(clsDate Date1, clsDate Date2)
	{
		if (IsDate1BeforeDate2(Date1, Date2))
			return enDateCompare::Before;
		if (IsDate1EqualDate2(Date1, Date2))
			return enDateCompare::Equal;

		return enDateCompare::After;
	}
	enDateCompare CompareDates(sDate Date1, sDate Date2)
	{
		if (IsDate1BeforeDate2(Date1, Date2))
			return enDateCompare::Before;
		if (IsDate1EqualDate2(Date1, Date2))
			return enDateCompare::Equal;
		/* if (IsDate1AfterDate2(Date1,Date2))
		return enDateCompare::After;*/
		//this is faster
		return enDateCompare::After;
	}
	

	

	sDate Date;
	sPeriode Peroid;
public:

	clsDate() {
		time_t t = time(0);
		tm* Now = localtime(&t);
		Date._Year = Now->tm_year + 1900;
		Date._month = Now->tm_mon + 1;
		Date._Day = Now->tm_mday;
		Date._hour = Now->tm_hour;
		Date._Min = Now->tm_min;
		Date._Sec = Now->tm_sec;

	}

	clsDate(  short Day, short month, short Year ) {
		Date._Year = Year;
		Date._month = month;
		Date._Day = Day;
	}
	clsDate( short NumofDayInYear, short Year) {
		ConvertnumberToData(Year,NumofDayInYear);
	}
	clsDate(string DateFormat ) {
		StringToDate(Date ,DateFormat);
	}


    void setDay(short Day)
	{
		Date._Day = Day;
		
	}
	short GetDay() {
		return Date._Day;
	}

	__declspec(property(get = GetDay, put = setDay)) short Day;

	void setMonth(short Month)
	{
		Date._month = Month;

	}
	short GetMonth() {
		return Date._month;
	}

	__declspec(property(get = GetMonth, put = setMonth)) short month;

	void setYear(short Year )
	{
		Date._Year = Year;

	}
	short GetYear() {
		return Date._Year;
	}
	__declspec(property(get = GetYear, put = setYear)) short Year;


	void sethour(short hour)
	{
		Date._Day = Day;

	}
	short Gethour() {
		return Date._hour;
	}

	__declspec(property(get = Gethour, put = sethour)) short hour;

	void setMin(short Min)
	{
		Date._Min = Min;

	}
	short GetMin() {
		return Date._Min;
	}
	__declspec(property(get = GetMin, put = setMin)) short Min;

	void setSec(short Sec)
	{
		Date._Sec = Sec;

	}
	short GetSec() {
		return Date._Sec;
	}
	__declspec(property(get = GetSec, put = setSec)) short Sec ;




	static string DateToString(clsDate Date) {

		return  to_string(Date.Day) + "/" + to_string(Date.month) + "/" + to_string(Date.Year);
	}
	string print() {
	 
		return DateToString(*this);
	}

	static string TimeToString(clsDate sDate) {
		return  to_string(sDate.hour) + ":" + to_string(sDate.Min) + ":" + to_string(sDate.Sec);
	}

	static string GetSystemDateTameToString(clsDate sDate) {

		return  to_string(sDate.Day) + "/" + to_string(sDate.month) + "/" + to_string(sDate.Year) + " - " + to_string(sDate.hour) + ":" + to_string(sDate.Min) + ":" + to_string(sDate.Sec);
	}

	static bool isLeapYear(int Year) {
		return (Year % 4 == 0 && Year % 10 != 0) ? true : (Year % 400 == 0) ? true : false;
	}

	static int NumberOfDayinYear(int Year) {
		return isLeapYear(Year) ? 366 : 365;
	}
	int NumberOfDayinYear() {
		return NumberOfDayinYear(Date._Year);
	}


	static int NumberOfHoursinDay(int Day) {
		return Day * 24;
	}
	int NumberOfHoursinDay() {
		return NumberOfHoursinDay(Date._Day);
	}


	static int NumberOfMinutesinHours(int Hours) {
		return NumberOfHoursinDay(Hours) * 60;
	}

	static int NumberOfSecondsInMinutes(int Minutes) {
		return NumberOfMinutesinHours(Minutes) * 60;
	}

	static int NumberTheMonth(int Month, int Year) {
		switch (Month) {
		case 2:return isLeapYear(Year) ? 29 : 28;break;

		case 1:case 3:case 5:case 7:case 8:case 10:case 12:return 31;
		}
		return 30;
	}
	int NumberTheMonth() {
		return NumberTheMonth(Date._month, Date._Year);
	}

	static int NumberOfDay(short Year, short month, short Day) {
		int a = (14 - month) / 12;
		int y = Year - a;
		int m = month + 12 * a - 2;
		int d = (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
		return d;
	}

	static string DayName(short Year, short month, short Day) {
		string arr[7] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
		return arr[NumberOfDay(Year, month, Day)];
	}
	string DayName() {
		return DayName(Date._Year, Date._month, Date._Day);
	}

	static string manthNane(short month) {
		string arr[12] = { "Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
		return arr[month - 1];
	}
	string manthNane() {
		return manthNane(Date._month);
	}

	static void PrintallDayofMonth(short Year, short month) {
		cout << "__________________" << manthNane(month) << "___________________" << endl;
		cout << "Sun   Mon   Tue   Wed   Thu   Fri   Sat" << endl;
		tcheck(Year, month, 1);
		cout << "\n_______________________________________" << endl;
	}
	void PrintallDayofMonth() {
		PrintallDayofMonth(Date._Year, Date._month);
	}


	static void PrintYearCalendar(short Yaer) {

		for (int i = 1;i <= 12;i++) {
			PrintallDayofMonth(Yaer, i);
		}
	}
	void PrintYearCalendar() {
		 PrintYearCalendar(Date._Year);
	}

	static short NumberOfDaysFromTheBeginingOfTheYear(short Day, short Month, short Year) {
		short count = 0;
		for (int i = 1;i < Month;i++) {
			count += NumberTheMonth(i, Year);

		}
		return count + Day;
	}
	short NumberOfDaysFromTheBeginingOfTheYear() {
		return NumberOfDaysFromTheBeginingOfTheYear(Date._Day, Date._month, Date._Year);
	}

	sDate ConvertnumberToData(short Year, short DaysofYear) {
		
		Date._Year = Year;
		Date._month = 1;

		while (true) {
			short tcheck = NumberTheMonth(Date._month, Year);
			if (DaysofYear >= tcheck) {
				Date._month++;

				DaysofYear -= tcheck;
			}
			else {
				Date._Day = DaysofYear;
				break;
			}
		}
		return Date;
	}

	static bool checkisLastMonth(clsDate cldate) {
		return (cldate.Date._month == 12) ? true : false;
	}
	bool checkisLastMonth() {
		return  checkisLastMonth(*this);
	}

	static bool checkisLastDay(clsDate cldate) {
		return (cldate.Date._Day == NumberTheMonth(cldate.Date._month, cldate.Date._Year)) ? true : false;
	}
	bool checkisLastDay() {
		return  checkisLastDay(*this);
	}



	static bool checkisFirstDay(clsDate cldate) {
		return (cldate.Date._Day == 1) ? true : false;
	}
	bool checkisFirstDay() {
		return  checkisFirstDay(*this);
	}


	static bool checkisFirstmonth(clsDate cldate) {
		return (cldate.Date._month == 1) ? true : false;
	}
	bool checkisFirstmonth() {
		return  checkisFirstmonth(*this);
	}


	static sDate addingOneDay(clsDate date) {


		if (checkisLastDay(date) && checkisLastMonth(date)) {
			date.Date._Day = 1;
			date.Date._month = 1;
			date.Date._Year++;
		}
		else if (checkisLastDay(date)) {
			date.Date._Day = 1;
			date.Date._month++;
		}
		else {
			date.Date._Day++;
		}

		if (checkisLastMonth(date)) {
			date.Date._month = 1;
			date.Date._Year++;
		}

		return date.Date;

	}

	static	short DiffrenceFromDateToDate(sDate Date, sDate LastDate) {

		short NumberDoday;

		if (Date._Year == LastDate._Year) {
			NumberDoday = NumberOfDaysFromTheBeginingOfTheYear(LastDate._Day, LastDate._month, LastDate._Year)
				- NumberOfDaysFromTheBeginingOfTheYear(Date._Day, Date._month, Date._Year);
			return NumberDoday;
		}
		else {
			NumberDoday = NumberOfDayinYear(Date._Year) - NumberOfDaysFromTheBeginingOfTheYear(Date._Day, Date._month, Date._Year);
		}
		if (Date._Year != LastDate._Year) {
			NumberDoday += NumberOfDaysFromTheBeginingOfTheYear(LastDate._Day, LastDate._month, LastDate._Year);
		}
		if (LastDate._Year - Date._Year > 1) {
			Date._Year++;
			NumberDoday += NumberOfDayinYear(Date._Year);
		}
		return NumberDoday;
	}

	short DiffrenceFromDateToDate(sDate LastDate) {
		return DiffrenceFromDateToDate(Date, LastDate);
	}
	static short CalculateMyAgeInDays(clsDate DateOfBirth)
	{
		return GetDifferenceInDays(DateOfBirth,clsDate::GetSystemDateofDay(), true);
	}

	static short NumberOfDaysInAMonth(short Month, short Year)
	{
		if (Month < 1 || Month>12)
			return 0;
		int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
		return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) :
			days[Month - 1];
	}
	short NumberOfDaysInAMonth() {
		return NumberOfDaysInAMonth(Date._month, Date._Year);
	}

	static sDate IncreaseDateByOneDay(clsDate date)
	{
		if (checkisLastDay(date))
		{
			if (checkisLastMonth(date))
			{
				date.Date._month = 1;
				date.Date._Day = 1;
				date.Date._Year++;
			}
			else
			{
				date.Date._Day = 1;
				date.Date._month++;
			}
		}
		else
		{
			date.Date._Day++;
		}
		return date.Date;
	}
	sDate IncreaseDateByOneDay() {
		return IncreaseDateByOneDay(*this);
	}

	static int GetDifferenceInDays(clsDate Date1, clsDate Date2, bool IncludeEndDay = false)
	{
		int Days = 0;
		while (IsDate1BeforeDate2(Date1.Date, Date2.Date))
		{
			Days++;
			Date1.Date = IncreaseDateByOneDay(Date1);
		}
		return IncludeEndDay ? ++Days : Days;
	}
	int GetDifferenceInDays(clsDate& Date2) {
		return GetDifferenceInDays(*this, Date2);
	}


	static	void addingXDays(clsDate& cldate, short Day) {
		int i = 0;
		while (i != Day) {
			addingOneDay(cldate);
			i++;
		}
	}
	void addingXDays(short Day) {
		addingXDays(*this, Day);
	}

	static void addingOneweek(clsDate& cldate) {
		int i = 0;
		while (i != 7) {
			addingOneDay(cldate);
			i++;
		}

	}
	void addingOneweek() {
		addingOneweek(*this);
	}


	static void addingXweeks(clsDate& cldate, short week) {
		int i = 0;
		while (i != week) {
			addingOneweek(cldate);
			i++;
		}
	}
	void addingXweeks(short week) {
		addingXweeks(*this, week);
	}

	static void addingOneMonth(clsDate& cldate) {
		if (cldate.Date._month == 12) {
			cldate.Date._month = 1;
			cldate.Date._Year++;
		}
		else {
			cldate.Date._month++;
		}
		short NumberOfDaysInCurrentMonth = NumberTheMonth(cldate.Date._month, cldate.Date._Year);
		if (cldate.Date._Day > NumberOfDaysInCurrentMonth)
		{
			cldate.Date._Day = NumberOfDaysInCurrentMonth;
		}
	}
	void addingOneMonth() {
		addingOneMonth(*this);
	}


	static void addingXMonths(clsDate& cldate, short months) {
		int i = 0;
		while (i != months) {
			addingOneMonth(cldate);
			i++;
		}
	}
	void addingXMonths(short months) {
		addingXMonths(*this, months);
	}


	static void addingOneYear(clsDate& cldate) {
		cldate.Date._Year++;
	}
	void addingOneYear() {
		addingOneYear(*this);
	}


	static void addingXYear(clsDate& cldate, short Year) {
		int i = 0;
		while (i != Year) {
			addingOneYear(cldate);
			i++;
		}
	}
	void addingXYear(short Year) {
		addingXYear(*this, Year);
	}


	static void adding_X_Years_Faster(clsDate& cldate, short Year) {
		cldate.Date._Year += Year;
	}
	void adding_X_Years_Faster(short Year) {
		adding_X_Years_Faster(*this, Year);
	}


	static void addingOneDecad(clsDate& cldate) {
		cldate.Date._Year += 10;
	}
	void addingOneDecad() {
		addingOneDecad(*this);
	}


	static void addingXDecad(clsDate& cldate, short Deceds) {
		int i = 0;
		while (i != Deceds * 10) {
			addingOneYear(cldate);
			i++;
		}
	}
	void addingXDecad(short Deceds) {
		addingXDecad(*this, Deceds);
	}


	static void adding_X_Decad_Faster(clsDate& cldate, short decats) {
		cldate.Date._Year += 10 * decats;
	}
	void adding_X_Decad_Faster(short Deceds) {
		adding_X_Decad_Faster(*this, Deceds);
	}

	static void addingXCentruy(clsDate& cldate, short Centruy) {
		cldate.Date._Year += 100 * Centruy;
	}
	void addingXCentruy(short Centruy) {
		addingXDecad(*this, Centruy);
	}

	void addingXMillennium(clsDate& cldate, short Millennium) {
		cldate.Date._Year += 1000 * Millennium;
	}
	void addingXMillennium(short Millennium) {
		addingXMillennium(*this, Millennium);
	}


	static void DecreaseneDay(clsDate& cldate) {
		if (checkisFirstmonth(cldate) && checkisFirstDay(cldate)) {
			cldate.Date._Day = 31;
			cldate.Date._month = 12;
			cldate.Date._Year--;
		}
		else if (checkisFirstDay(cldate)) {
			cldate.Date._Day = NumberTheMonth(cldate.Date._month - 1, cldate.Date._Year);
			cldate.Date._month--;
		}
		else {
			cldate.Date._Day--;
		}
	}



	static void DecreaseXDays(clsDate& cldate, short Day) {
		int i = 0;
		while (i != Day) {
			DecreaseneDay(cldate);
			i++;
		}
	}
	void DecreaseXDays(short Day) {
		DecreaseXDays(*this, Day);
	}


	static void DecreaseOneweek(clsDate& cldate) {
		int i = 0;
		while (i != 7) {
			DecreaseneDay(cldate);
			i++;
		}

	}
	void DecreaseOneweek() {
		DecreaseOneweek(*this);
	}


	static void DecreaseXweeks(clsDate& cldate, short week) {
		int i = 0;
		while (i != week) {
			DecreaseOneweek(cldate);
			i++;
		}
	}
	void DecreaseXweeks(short week) {
		DecreaseXweeks(*this, week);
	}


	static void DecreaseOneMonth(clsDate& cldate) {
		if (cldate.Date._month == 1) {
			cldate.Date._month = 12;
			cldate.Date._Year--;
		}
		else {
			cldate.Date._month--;
		}
		short NumberOfDaysInCurrentMonth = NumberTheMonth(cldate.Date._month, cldate.Date._Year);
		if (cldate.Date._Day > NumberOfDaysInCurrentMonth)
		{
			cldate.Date._Day = NumberOfDaysInCurrentMonth;
		}
	}
	void DecreaseOneMonth() {
		DecreaseOneMonth(*this);
	}


	void DecreaseXMonths(clsDate& cldate, short months) {
		int i = 0;
		while (i != months) {
			DecreaseOneMonth(cldate);
			i++;
		}
	}
	void DecreaseXMonths(short months) {
		DecreaseXMonths(*this, months);
	}


	static void DecreaseOneYear(clsDate& cldate) {
		cldate.Date._Year--;
	}
	void DecreaseOneYear() {
		DecreaseOneYear(*this);
	}



	static void DecreaseXYear(clsDate& cldate, short Year) {
		int i = 0;
		while (i != Year) {
			DecreaseOneYear(cldate);
			i++;
		}
	}
	void DecreaseXYear(short Year) {
		DecreaseXYear(*this, Year);
	}


	static void Decrease_X_Years_Faster(clsDate& cldate, short Year) {
		cldate.Date._Year += -Year;
	}
	void Decrease_X_Years_Faster(short Year) {
		Decrease_X_Years_Faster(*this, Year);
	}


	static void DecreaseOneDecad(clsDate& cldate) {
		cldate.Date._Year += -10;
	}
	void DecreaseOneDecad() {
		DecreaseOneDecad(*this);
	}


	static void DecreaseXDecad(clsDate& cldate, short Deceds) {
		int i = 0;
		while (i != Deceds * 10) {
			DecreaseOneYear(cldate);
			i++;
		}
	}
	void DecreaseXDecad(short Deceds) {
		DecreaseXDecad(*this, Deceds);
	}


	static void Decrease_X_Decad_Faster(clsDate& cldate, short decats) {
		cldate.Date._Year += -10 * decats;
	}
	void Decrease_X_Decad_Faster(short Deceds) {
		Decrease_X_Decad_Faster(*this, Deceds);
	}


	static void DecreaseXCentruy(clsDate& cldate, short Centruy) {
		cldate.Date._Year += -100 * Centruy;
	}
	void DecreaseXCentruy(short Centruy) {
		DecreaseXDecad(*this, Centruy);
	}


	static void DecreaseXMillennium(clsDate& cldate, short Millennium) {
		cldate.Date._Year += -1000 * Millennium;
	}
	void DecreaseXMillennium(short Millennium) {
		DecreaseXMillennium(*this, Millennium);
	}


	static void SwapDates(clsDate& Date1, clsDate& Date2)
	{
		clsDate TempDate;
		TempDate = Date1;
		Date1 = Date2;
		Date2 = TempDate;
	}


	static bool IsitEndofWeek(clsDate clsDate) {
		if (clsDate.Date._Day== 6) {
			return true;
		}
		return false;
	}
	bool IsitEndofWeek() {
		return IsitEndofWeek(*this);
	}


	static bool IsitWeekend( short NumberToDay) {
		if (NumberToDay == 6 || NumberToDay == 0) {
			return true;
		}
		return false;
	}
	static bool IsitWeekend(clsDate clDate) {
		if (clDate.Date._Day == 6 || clDate.Date._Day == 0) {
			return true;
		}
		return false;
	}

	
	static bool IsitBusinessDay(clsDate cldate) {
		if (!IsitWeekend(cldate)) {
			return true;
		}
		return false;
	}
	bool IsitBusinessDay(short NumberToDay) {
		return IsitBusinessDay(NumberToDay);
	}


	short DaysUnthelTheEndOfWeek(short NumberToDay) {
		short count = 0;
		while (NumberToDay != 6) {
			NumberToDay++;
			count++;
		}
		return count;
	}

	
	static short DaysUnthelTheEndOfYear(clsDate  cldate) {
		return NumberOfDayinYear(cldate.Date._Year) - 
		NumberOfDaysFromTheBeginingOfTheYear(cldate.Date._Day, cldate.Date._month, cldate.Date._Year);
	}
	short DaysUnthelTheEndOfYear() {
		return  DaysUnthelTheEndOfYear(*this);
	}


	static short DaysUnthelTheEndOfmonth(clsDate cldate) {
		short count = 0;
		while (cldate.Date._Day != NumberTheMonth(cldate.Date._month, cldate.Date._Year)) {
			cldate.Date._Day++;
			count++;
		}
		return count;
	}
	short DaysUnthelTheEndOfmonth() {
		return DaysUnthelTheEndOfmonth(*this);
	}

	static bool IsDate1BeforeDate2(clsDate Date1, clsDate Date2) {

		return (Date1.Date._Year < Date2.Date._Year) ? true : ((Date1.Date._Year == Date2.Date._Year) ? 
			(Date1.Date._month < Date2.Date._month ? true : 
			(Date1.Date._month == Date2.Date._month ? Date1.Date._Day < Date2.Date._Day : false)) : false);

	}
	bool IsDate1BeforeDate2(clsDate Date2) {
		return IsDate1BeforeDate2(*this, Date2);
	}
	

	static bool IsDate1EqualDate2(clsDate Date1, clsDate Date2)
	{
		return (Date1.Date._Year == Date2.
			Date._Year) ? ((Date1.Date._month ==
			Date2.Date._month) ? ((Date1.Date._Day == Date2.Date._Day) ? true : false) : false): false;
	}
	bool IsDate1EqualDate2(clsDate Date2) {
		return IsDate1EqualDate2(*this, Date2);
	}
	
	
	static bool IsDate1AfterDate2(clsDate Date1, clsDate Date2)
	{
		return (!IsDate1BeforeDate2(Date1, Date2) &&
			!IsDate1EqualDate2(Date1, Date2));
	}
	bool IsDate1AfterDate2(clsDate Date2) {
		return IsDate1AfterDate2(*this, Date2);
	}


	static short VacantionDay(clsDate DateFrom, clsDate DateTo) {
		short count = 0, NumberToDay;
		while (IsDate1BeforeDate2(DateFrom, DateTo)) {
			NumberToDay = NumberOfDay(DateFrom.Date._Year, DateFrom.Date._month, DateFrom.Date._Day);
			if (!IsitWeekend(NumberToDay)) {
				count++;
			}
			addingOneDay(DateFrom);
		}
		return count;
	}
	short VacantionDay(clsDate DateTo) {
		return VacantionDay(*this, DateTo);
	}
	
	static void Lastvacation(clsDate& DateFrom, short NumberToDay) {

		while (NumberToDay != 0) {
			int NumberOfDayinWeek = NumberOfDay(DateFrom.Date._Year, DateFrom.Date._month, DateFrom.Date._Day);
			if (!IsitWeekend(NumberOfDayinWeek)) {
				addingOneDay(DateFrom);
				NumberToDay--;
			}
			else {
				addingOneDay(DateFrom);
			}
		}
	}
	void Lastvacation(short NumberToDay) {
		Lastvacation(*this, NumberToDay);
	}


	bool PeriodOverlap(clsDate Period1, clsDate Period2) {

		if (CompareDates(Period1, Period2) != enDateCompare::After
			|| CompareDates(Period1, Period2) != enDateCompare::Before) {
			return false;
		}
		else {
			return true;
		}

	}

	static clsDate GetSystemDateofDay() {
		short Year, month, Day;
		time_t t = time(0);
		tm* Now = localtime(&t);
		Year = Now->tm_year + 1900;
		month = Now->tm_mon + 1;
		Day = Now->tm_mday;
		return clsDate(Day, month,Year);
	}
	 vector<string> Split(string S1, string Delim)
	{
		vector<string> vString;
		short pos = 0;
		string sWord;
		while ((pos = S1.find(Delim)) != std::string::npos)
		{
			sWord = S1.substr(0, pos);

			S1.erase(0, pos + Delim.length());
		}
		if (S1 != "")
		{
			vString.push_back(S1);
		}
		return vString;
	}
	void StringToDate(sDate &Date,string StrDate) {

		
		vector<string> vDate = Split(StrDate, "/");
		Date._Day = stoi(vDate[0]);
		Date._month = stoi(vDate[1]);
		Date._Year = stoi(vDate[2]);

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
	string FormateDate(sDate Date, string DateFormat = "dd/mm/yyyy")
	{
		string FormattedDateString = "";
		FormattedDateString = ReplaceWordInString(DateFormat, "dd",to_string(Date._Day));
		FormattedDateString = ReplaceWordInString(FormattedDateString,"mm", to_string(Date._month));
		FormattedDateString = ReplaceWordInString(FormattedDateString,"yyyy", to_string(Date._Year));
		return FormattedDateString;
	}


	static bool IsValid(clsDate Date) {


		if (Date.Date._month >= 1 && Date.Date._month <= 12) {
			if (Date.Date._Day >= 1 && Date.Date._Day < NumberTheMonth(Date.Date._month, Date.Date._Year))
				if(Date.Date._Year > 0 && Date.Date._Year < 5000)
				return true;
		}
		return false;
	}
	bool IsValid() {
		return  IsValid(*this);
	}

};