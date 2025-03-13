#pragma once
#include <iostream>
#include <string>
#include "clsString.h"
#include "clsDate.h"
using namespace std;
class clsInputValidate
{



public:
	static bool IsNumerBetween(short Num, short From, short To) {
		return (Num >= From && Num <= To) ? true : false;
	}
	static bool IsNumberBetween(int Num, int From, int To) {
		return (Num >= From && Num <= To) ? true : false;
	}
	static bool IsNumberBetween(double Num, double From, double To) {
		return  (Num >= From && Num <= To) ? true : false;
	}
	static bool IsNumberBerween(float Num, float From, float To) {
		return  (Num >= From && Num <= To) ? true:false;
	}

	static bool IsDateBetween(clsDate DateNow , clsDate DateFrom, clsDate DateTo) {
	// DateNow >= DateFrom && DateNow<=DateTo
		if ((clsDate::IsDate1AfterDate2(DateNow, DateFrom) || clsDate::IsDate1EqualDate2(DateNow, DateFrom))&&(clsDate::IsDate1BeforeDate2(DateNow, DateTo )|| clsDate::IsDate1EqualDate2(DateNow, DateTo))) {
			return true;
		}

		//DateNow>=DateTo && DateNow<=DateFrom
		if ((clsDate::IsDate1AfterDate2(DateNow, DateTo) || clsDate::IsDate1EqualDate2(DateNow, DateTo)
			&&
			clsDate::IsDate1BeforeDate2(DateNow, DateFrom) || clsDate::IsDate1EqualDate2(DateNow, DateTo))) {
			return true;
		}
		return false;
	}
	


	static int ReadIntNumber(string Massage="Invalid Number,Enter Again:\n") {
		int Number = 0;
	
		while (!(cin>>Number)) {
			cin.clear();
			cin.ignore((std::numeric_limits < std::streamsize>::max(), '\n'));
			cout << Massage;
		
		}
		return Number;
	}
	static short ReadShortNumber(string ErrorMessage = "Invalid Number, Enter again\n")
	{
		short Number;
		while (!(cin >> Number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return Number;
	}
	static float ReadFloatNumber(string Massage = "Invalid Number,Enter Again:\n") {
		float Number = 0;

		while (!(cin >> Number)) {
			cin.clear();
			cin.ignore((std::numeric_limits < std::streamsize>::max(), '\n'));
			cout << Massage;

		}
		return Number;
	}
	static int ReadIntNumberberween(int From, int To, string Massage="Invalid Number, Enter again:\n") {
		int Number = ReadIntNumber();
		while (!IsNumberBerween(Number, From, To)) {
			cout << Massage;
			Number = ReadIntNumber();
	}
		return Number;
	}
	static short ReadShortNumberBetween(short From, short To, string ErrorMessage = "Number is not within range, Enter again:\n")
	{
		int Number = ReadShortNumber();

		while (!IsNumberBetween(Number, From, To))
		{
			cout << ErrorMessage;
			Number = ReadShortNumber();
		}
		return Number;
	}



	static double ReadDblNumber(string Massage="Invalid Number, Enter again:\n") {
		double Number = 0;
		
		while (!(cin >> Number)) {
			cin.clear();
			cin.ignore((std::numeric_limits < std::streamsize > ::max(), '\n'));
			cout << Massage;
	
		}
		return Number;
	}
	static double ReadDblNumberBetween(double From, double To, string Massage = "Invalid Number, Enter again:\n") {
		double Number = ReadDblNumber();
		while (!IsNumberBerween(Number, From, To)) {
			cout << Massage;
			Number = ReadDblNumber();
		}
		return Number;
	}

	static bool IsValideDate(clsDate Date) {
		return clsDate::IsValidDate(Date);
	}
	static string ReadString() {
		string str = "";
		getline(cin >> ws, str);
		return str;
	}
};

