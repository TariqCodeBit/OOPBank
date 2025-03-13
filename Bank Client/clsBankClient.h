#pragma once
#include <iostream>
#include <string>
#include "clsString.h"
#include "clsPerson.h"
#include <fstream>
#include <vector>
using namespace std;
class clsBankClient: public clsPerson
{
private:
	enum enMode{EmptyMode=0,UpdateMode=1,AddNewMode=2};

	enMode _Mode;
	string _AccountNumber;
	string _PINCode;
	float _AccountBalance;
	bool _MarkedForDelete = false;

	static clsBankClient _ConvertLinetoClientObject(string LineC,string Seperatoe="#//#") {
		vector<string>vClientData = clsString::Split(LineC, Seperatoe);
		return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2],
			vClientData[3], vClientData[4], vClientData[5], stod(vClientData[6]));
	 }
	static string _ConverClientObjectToLine(clsBankClient client,string Seperator ="#//#") {
		string stClientRecord = "";
		stClientRecord += client.FirstName + Seperator;
		stClientRecord += client.LastName + Seperator;
		stClientRecord += client.Email + Seperator;
		stClientRecord += client.Phone + Seperator;
		stClientRecord += client.GetAccountNumber () + Seperator;
		stClientRecord += client.PINCode + Seperator;
		stClientRecord += to_string(client.AccountBalance);

		return stClientRecord;

	}  

		static void _SaveCleintsDataToFile(vector <clsBankClient> vClients)
		{

			fstream MyFile;
			MyFile.open("Clients.txt", ios::out);//overwrite

			string DataLine;

			if (MyFile.is_open())
			{

				for (clsBankClient C : vClients)
				{
					if (C._MarkedForDelete== false)
					{
						//we only write records that are not marked for delete.  
						DataLine = _ConverClientObjectToLine(C);
						MyFile << DataLine << endl;

					}

				}

				MyFile.close();

			}

		}
	static vector<clsBankClient>_LoadClientsDataFromFile() {
		vector<clsBankClient>vClients;
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);
		if (MyFile.is_open()) {
			string Line;
			while (getline(MyFile, Line)) {
				clsBankClient cclient = _ConvertLinetoClientObject(Line);

				vClients.push_back(cclient);
			}
			MyFile.close();
		}
		return vClients;
	}

	static clsBankClient _GetEmptyClientObject() {
		return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

	void _AddNew()
	{

		_AddDataLineToFile(_ConverClientObjectToLine(*this));
	}

	void _AddDataLineToFile(string  stDataLine)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{

			MyFile << stDataLine << endl;

			MyFile.close();
		}

	}
	struct stTrnsferLogRecord;
	static stTrnsferLogRecord _ConvertTransferLogLineToRecord(string Line, string Seperator = "#//#")
	{
		stTrnsferLogRecord TrnsferLogRecord;

		vector <string> vTrnsferLogRecordLine = clsString::Split(Line, Seperator);
		TrnsferLogRecord.DateTime = vTrnsferLogRecordLine[0];
		TrnsferLogRecord.SourceAccountNumber = vTrnsferLogRecordLine[1];
		TrnsferLogRecord.DestinationAccountNumber = vTrnsferLogRecordLine[2];
		TrnsferLogRecord.Amount = stod(vTrnsferLogRecordLine[3]);
		TrnsferLogRecord.srcBalanceAfter = stod(vTrnsferLogRecordLine[4]);
		TrnsferLogRecord.destBalanceAfter = stod(vTrnsferLogRecordLine[5]);
		TrnsferLogRecord.UserName = vTrnsferLogRecordLine[6];

		return TrnsferLogRecord;

	}

	void _Update() {
		vector<clsBankClient>_vClients;
		_vClients = _LoadClientsDataFromFile();
		for (clsBankClient& C : _vClients) {
			if (C.GetAccountNumber() == GetAccountNumber()) {
				C = *this;
				break;
			}
		}
		_SaveCleintsDataToFile(_vClients);
	} 
	string _PrepareTransferLogRecord(float Amount, clsBankClient DestinationClient,
		string UserName, string Seperator = "#//#")
	{
		string TransferLogRecord = "";
		TransferLogRecord += clsDate::GetSystemDateTimeString() + Seperator;
		TransferLogRecord += GetAccountNumber() + Seperator;
		TransferLogRecord += DestinationClient.GetAccountNumber() + Seperator;
		TransferLogRecord += to_string(Amount) + Seperator;
		TransferLogRecord += to_string(AccountBalance) + Seperator;
		TransferLogRecord += to_string(DestinationClient.AccountBalance) + Seperator;
		TransferLogRecord += UserName;
		return TransferLogRecord;
	}
	void _RegisterTransferLog(float Amount, clsBankClient DestinationClient, string UserName)
	{

		string stDataLine = _PrepareTransferLogRecord(Amount, DestinationClient, UserName);

		fstream MyFile;
		MyFile.open("TransferLog.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{

			MyFile << stDataLine << endl;

			MyFile.close();
		}

	}

public:

	struct stTrnsferLogRecord
	{
		string DateTime;
		string SourceAccountNumber;
		string DestinationAccountNumber;
		float Amount;
		float srcBalanceAfter;
		float destBalanceAfter;
		string UserName;

	};

	clsBankClient(enMode Mode,string FirstName, string LastName, string Email, string Phone, string AccountNumber, string PINcode
		, float AccountBalance) : clsPerson(FirstName, LastName, Email, Phone ) {
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PINCode = PINcode;
		_AccountBalance = AccountBalance;
	}
	bool IsEmpty() {
		return (_Mode == enMode::EmptyMode);
	}
	
	string GetAccountNumber() {
		return _AccountNumber;
	}

	void setPinCode(string PIncode) {
		_PINCode = PIncode;
	}
	string GetPinCode() {
		return _PINCode;
	}
	__declspec(property(get = GetPinCode, put = setPinCode))string PINCode;
	void setAccountBalance(float AccountBalance) {
		_AccountBalance = AccountBalance;
	}
	float GetAccountBalance() {
		return _AccountBalance;
	}
	__declspec(property(get = GetAccountBalance, put = setAccountBalance))float AccountBalance;
	
	/*void Print() {
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName       : " << FirstName;
		cout << "\nLastName        : " << LastName;
		cout << "\nFull Name       : " << FullName();
		cout << "\nEmail           : " << Email;
		cout << "\nPhone           : " << Phone;
		cout << "\nAcc. Number     : " << _AccountNumber;
		cout << "\nPassword        : " << _PINCode;
		cout << "\nBalance         : " << _AccountBalance;
		cout << "\n___________________\n";
	}*/
	static clsBankClient Find(string AccountNumber) {
		vector<clsBankClient>VClient;
		fstream MyClient;
		MyClient.open("Clients.txt", ios::in);
		if (MyClient.is_open()) {
			string Line;
			while (getline(MyClient,Line)) {
				clsBankClient Client = _ConvertLinetoClientObject(Line);
				if (Client.GetAccountNumber() == AccountNumber) {
					MyClient.close();
					return Client;
				}
				VClient.push_back(Client);
			}
			MyClient. close();
		}
		return _GetEmptyClientObject();
	}
	static clsBankClient Find(string AccountNumber,string pinCode) {
		vector<clsBankClient>VClient;
		fstream MyClient;
		MyClient.open("Clients.txt", ios::in);
		if (MyClient.is_open()) {
			string Line;
			while (getline(MyClient, Line)) {
				clsBankClient Client = _ConvertLinetoClientObject(Line);
				if (Client.GetAccountNumber() == AccountNumber && Client.PINCode == pinCode) {
					MyClient.close();
					return Client;
				}
				VClient.push_back(Client);
			}
			MyClient.close();
		}
		return _GetEmptyClientObject();
	}
	

	enum enSaveResults {svFaildEmptyObject=0,svSucceeded=1, svFaildAccountNumberExists
	=2};
	enSaveResults Save()
	{

		switch (_Mode)
		{
		case enMode::EmptyMode:
		{
			if (IsEmpty())
			{

				return enSaveResults::svFaildEmptyObject;

			}

		}

		case enMode::UpdateMode:
		{


			_Update();

			return enSaveResults::svSucceeded;

			break;
		}

		case enMode::AddNewMode:
		{
			//This will add new record to file or database
			if (clsBankClient::IsClientExist(_AccountNumber))
			{
				return enSaveResults::svFaildAccountNumberExists;
			}
			else
			{
				_AddNew();

				//We need to set the mode to update after add new
				_Mode = enMode::UpdateMode;
				return enSaveResults::svSucceeded;
			}

			break;
		}
		}

	}
	static bool IsClientExist(string AccountNumber) {
		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		return (!Client1.IsEmpty());
	}

	bool Delete()
	{
		vector <clsBankClient> _vClients;
		_vClients = _LoadClientsDataFromFile();

		for (clsBankClient& C : _vClients)
		{
			if (C.GetAccountNumber() == _AccountNumber)
			{
				C._MarkedForDelete = true;
				break;
			}

		}

		_SaveCleintsDataToFile(_vClients);

		*this = _GetEmptyClientObject();

		return true;

	}

	static clsBankClient GetAddNewClientObject(string AccountNumber)
	{
		return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
	}




	static vector <clsBankClient> GetClientsList()
	{
		return _LoadClientsDataFromFile();
	}

	static float GetTotalBalances()
	{
		vector <clsBankClient> vClients = clsBankClient::GetClientsList();

		double TotalBalances = 0;

		for (clsBankClient Client : vClients)
		{

			TotalBalances += Client.AccountBalance;
		}

		return TotalBalances;

	}
	void Deposit(double Amount)
	{
		_AccountBalance += Amount;
		Save();
	}

	bool Withdraw(double Amount)
	{
		if (Amount > _AccountBalance)
		{
			return false;
		}
		else
		{
			_AccountBalance -= Amount;
			Save();
			return true;
		}

	}
	bool Transfer(float Amount, clsBankClient& DestinationClient,string UserName)
	{
		if (Amount > AccountBalance)
		{
			return false;
		}

		Withdraw(Amount);
		DestinationClient.Deposit(Amount);
		_RegisterTransferLog(Amount, DestinationClient, UserName);
		return true;
	}

	static  vector <stTrnsferLogRecord> GetTransfersLogList()
	{
		vector <stTrnsferLogRecord> vTransferLogRecord;

		fstream MyFile;
		MyFile.open("TransferLog.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{

			string Line;

			stTrnsferLogRecord TransferRecord;

			while (getline(MyFile, Line))
			{

				TransferRecord = _ConvertTransferLogLineToRecord(Line);

				vTransferLogRecord.push_back(TransferRecord);

			}

			MyFile.close();

		}

		return vTransferLogRecord;

	}



};

