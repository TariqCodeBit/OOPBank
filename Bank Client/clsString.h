#pragma once

#include<iostream>
#include <vector>
using namespace std;


class clsString {
private:
	string _Value;
public:
	clsString() {
		_Value = "";
	}
	clsString(string Value) {
		_Value = Value;
	}
	void SetValue(string Value) {
		_Value = Value;
	}
	string GetValue() {
		return _Value;
	}
	__declspec(property(get = GetValue, put = SetValue))string Value;

	static void PrintFirstLetterOfEachWord(string st) {
		bool IsFirstLetter = true;
		cout << "\n First Letters of This String\n";
		for (int i = 0; i < st.length(); i++) {
			if (st[i] != ' ' && IsFirstLetter)
			{
				cout << st[i] << endl;
			}
			IsFirstLetter = (st[i] == ' ' ? true : false);
		}
	}
	void  PrintFirstLetterOfEachWord() {
		 PrintFirstLetterOfEachWord(_Value);
	}

	static string UpeerFirstLetterOfEachWord(string st) {
		bool IsFirstLetter = true;
		for (int i = 0; i < st.length(); i++) {
			if (st[i] != ' ' && IsFirstLetter) {
				st[i] = toupper(st[i]);
			}
			IsFirstLetter = (st[i] == ' ' ? true : false);
		}
		return st;
		
	}
	void UpeerFirstLetterOfEachWord() {
		_Value= UpeerFirstLetterOfEachWord(_Value);
	}

	static string LowerFirstLetterOfEachWord(string st) {
		bool IsFirstLetter = true;
		for (int i = 1; i < st.length(); i++) {
			if (st[i] != ' ' && IsFirstLetter) {
				st[i] = tolower(st[i]);
				IsFirstLetter = (st[i] == ' ' ? true : false);
			}
		}
		return st;
	}
	void LowerFirstLetterOfEachWord() {
		_Value= LowerFirstLetterOfEachWord(_Value);
	}

	static string UpperAllString(string st) {
		for (int i = 0; i < st.length(); i++) {
			st[i] = toupper(st[i]);
		}
		return st;
	}
	void UpperAllString() {
		_Value= UpperAllString(_Value);
	}

	static string LowerAllString(string st) {
		for (int i = 0; i < st.length(); i++) {
			st[i] = tolower(st[i]);

		}
		return st;
	}
	void LowerAllString() {
		_Value= LowerAllString(_Value);
	}

	static char InvertLetterCase(char ch) {
		return isupper(ch) ? tolower(ch) : toupper(ch);
	}

	static string IncertAllStringLetterCase(string st) {
		for (int i = 0; i < st.length(); i++) {
			st[i] = InvertLetterCase(st[i]);
		}
		return st;
	}
	void IncertAllStringLetterCase() {
		_Value= IncertAllStringLetterCase(_Value);
	}

	static short CountCapitalLetters(string st) {
		short counter = 0;
		for (int i = 0; i < st.length(); i++) {
			if (isupper(st[i])) {
				counter++;
			}
		}
		return counter;
	}
	short CountCapitalLetters() {
		return CountCapitalLetters(_Value);
	}


	static short CountSmallLetters(string st) {
		short counter = 0;
		for (int i = 0; i < st.length(); i++) {
			if (islower(st[i])) {
				counter++;
			}
		}
		return counter;
	}
	short  CountSmallLetters() {
		return  CountSmallLetters(_Value);
	}

	static short CountLetterNoMatchCase(string st, char Letter) {
		//only chosse Small or Capital  you need count
		short counter = 0;
		for (int i = 0; i < st.length(); i++) {
			if (st[i] == Letter) {
				counter++;
			}
		}
		return counter;
	}
	short CountLetterNoMatchCase(char Letter) {
		
		return CountLetterNoMatchCase(_Value,Letter ); 
	}

	static short CountLetter(string S6, char Letter, bool MatchCase = true){
		short Counter = 0;
		for (short i = 0; i < S6.length(); i++)
		{
			if (MatchCase)
			{
				if (S6[i] == Letter)
					Counter++;
			}
			else
			{
				if (tolower(S6[i]) == tolower(Letter))
					Counter++;
			}
		}
		return Counter;
	}
	short CountLetter() {
		return CountLetter();
	}

	 static bool IsVowel(char Ch) {
		Ch = tolower(Ch);
		return ((Ch == 'a') || (Ch == 'e') || (Ch == 'i') || (Ch == 'o') || (Ch == 'u'));
	}

	static short CountVowels(string st) {
		short counter = 0;
		for (int i = 0; i < st.length(); i++) {
			if (IsVowel(st[i])) {
				counter++;
			}
		}
		return counter;
	}
	short CountVowels() {
		return CountVowels(_Value);
	}


	static void PrintVowels(string S8){
		cout << "\nVowels in string are : ";
		for (short i = 0; i < S8.length(); i++)
		{
			if (IsVowel(S8[i]))
			{
				cout << S8[i] << "   ";
			}
		}
	}

	void PrintVowels() {
		return PrintVowels(_Value);
	}


	static void PrintEachWordInString(string S9)
	{
		string delim = " "; // Delimiter 

		cout << "\nYour string words are : \n\n";
		short pos = 0;
		string sWord;
		while ((pos = S9.find(delim)) !=std::string::npos)
		{
			sWord = S9.substr(0, pos);

			if (sWord != "")
			{
				cout << sWord << endl;
			}
			S9.erase(0, pos + delim.length());
		}
		if (S9 != "")
		{
			cout << S9 << endl;
		}
	}
	void PrintEachWordInString() {
		PrintEachWordInString(_Value);
	}

	static short CountWords(string st) {
		string delim = " ";
		short counter = 0;
		short pos = 0;
		string sWord;
		while ((pos = st.find(delim)) != std::string::npos) {
			sWord = st.substr(0, pos);
			if (sWord != "") {
				counter++;
			}
			st.erase(0, pos + delim.length());
		}
		if (st != "") {
			counter++;
		}
		return counter++;
	}
	short CountWords() {
		return CountWords(_Value);
	}

	static vector <string>Split(string st,string Delim) {
		
		 vector<string>vString;
		short pos = 0;
		string sWord;
		while ((pos = st.find(Delim)) != std::string::npos) {
			sWord = st.substr(0, pos);
			//if (sWord != "") {
				vString.push_back(sWord);
			//}
			st.erase(0, pos + Delim.length());
		}
		if (st != "") {
			vString.push_back(st);
		}
		return vString;
	}

	vector<string>Split(string Delim) {
		return Split(_Value, Delim);
	}

	static string TrimLeft(string S10)
	{
		for (short i = 0; i < S10.length(); i++)
		{
			if (S10[i] != ' ')
			{
				return  S10.substr(i,
					S10.length() - i);

			}
		}
		return "";

	}
	void TrimLeft() {
		_Value= TrimLeft(_Value);
	}

	static string TrimRight(string S10)
	{
		for (short i = S10.length() - 1; i >= 0; i--)
		{
			if (S10[i] != ' ')
			{
				return  S10.substr(0, i + 1);
			}
		}
		return "";

	}
	void TrimRight() {
		_Value=TrimRight(_Value);
	}
	static string Trim(string S10)
	{
		return TrimLeft(TrimRight(S10));

	}
	void Trim() {
		_Value= Trim(_Value);
	}
	static string JoinString(vector <string> vString, string Delim) {

		string S1 = "";
		for (string& s : vString)
		{
			S1 = S1 + s + Delim;
		}
		
		return S1.substr(0, S1.length() - Delim.length());

	}
	static string JoinString(string arrString[], short Length, string Delim)
	{
		string S1 = "";
		for (short i = 0; i < Length; i++)
		{
			S1 = S1 + arrString[i] + Delim;
		}
		return S1.substr(0, S1.length() - Delim.length());
	}
	

	static string RemovePunctuationsFromString(string S14)
	{
		string S2 = "";

		for (short i = 0; i < S14.length(); i++)
		{
			if (!ispunct(S14[i]))
			{
				S2 += S14[i];
			}
		}

		return S2;
	}
	void RemovePunctuationsFromString() {
		_Value= RemovePunctuationsFromString(_Value);
	}
	
	static string ReverseWordsInString(string S1)
	{

		vector<string> vString;
		string S2 = "";

		vString = Split(S1, " ");

		// declare iterator
		vector<string>::iterator iter = vString.end();

		while (iter != vString.begin())
		{

			--iter;

			S2 += *iter + " ";

		}

		S2 = S2.substr(0, S2.length() - 1); //remove last space.

		return S2;
	}

	void ReverseWordsInString()
	{
		_Value = ReverseWordsInString(_Value);
	}

	static string ReplaceWord(string S1, string StringToReplace, string sRepalceTo, bool MatchCase = true)
	{

		vector<string> vString = Split(S1, " ");

		for (string& s : vString)
		{

			if (MatchCase)
			{
				if (s == StringToReplace)
				{
					s = sRepalceTo;
				}

			}
			else
			{
				if (LowerAllString(s) == LowerAllString(StringToReplace))
				{
					s = sRepalceTo;
				}

			}

		}

		return JoinString(vString, " ");
	}

	string ReplaceWord(string StringToReplace, string sRepalceTo)
	{
		return ReplaceWord(_Value, StringToReplace, sRepalceTo);
	}

};