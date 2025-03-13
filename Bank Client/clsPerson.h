#pragma once
#include<iostream>
#include <string>
using namespace std;
class clsPerson
{
private:
	string _FirstName;
	string _LastName;
	string _Email;
	string _Phone;




public:
	clsPerson(string FirstName,string LastName,string Email,string Phone) {
		_FirstName = FirstName;
		_LastName = LastName;
		_Email = Email;
		_Phone = Phone;
	}
	void setFirstName(string FirstName) {
		_FirstName = FirstName;
	}
	string GetFirstName() {
		return _FirstName;
	}
	__declspec(property(get = GetFirstName, put = setFirstName))string FirstName;

	void setLastName(string LastName) {
		_LastName = LastName;
	}
	string GetLastName() {
		return _LastName;
	}
	__declspec(property(get = GetLastName, put = setLastName))string LastName;
	void setEmail(string Email) {
		_Email = Email;
	}
	string GetEmail() {
		return _Email;
	}
	__declspec(property(get = GetEmail, put = setEmail))string Email;
	void setPhone(string phone) {
		_Phone = phone;
	}
	string GetPhone() {
		return _Phone;
	}
	__declspec(property(get = GetPhone, put = setPhone))string Phone;
	string FullName() {
		return _FirstName + " " + _LastName;
	}
};

