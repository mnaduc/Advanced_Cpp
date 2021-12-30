#include "Setting.h"
#include <regex>
#include <iostream>
#include <iomanip>

Setting::Setting(string personal_key)
{
	personal_key_ = personal_key;
	owner_name_ = "";
	email_ = "";
	odo_number_ = 0;
	remind_service_ = 0;
}

void Setting::info()
{
	cout << left;
	cout << "    "
		<< setw(20) << "Owner name"
		<< setw(25) << "Email"
		<< setw(15) << "Key number"
		<< setw(15) << "ODO number"
		<< setw(15) << "Remind service(km)" << endl;
	cout << "    "
		<< setw(20) << owner_name_
		<< setw(25) << email_
		<< setw(15) << personal_key_
		<< setw(15) << odo_number_
		<< setw(15) << remind_service_  << endl;
}

void Setting::inputData()
{
	string owner_name = "";
	string email = "";
	string odo = "";
	string remind_service_str = "";
	// Nhập và kiểm tra Owner name
	cout << "   Owner name: ";
	getline(cin, owner_name);
	while (!setOwnerName(owner_name))
	{
		cout << "     * Invalid! Owner name: ";
		getline(cin, owner_name);
	}
	// Nhập và kiểm tra email
	cout << "   Email: ";
	getline(cin, email);
	while (!setEmail(email))
	{
		cout << "     * Invalid! Email: ";
		getline(cin, email);
	}
	// Nhập và kiểm tra ODO number
	cout << "   ODO number: ";
	getline(cin, odo);
	while (!setODO(odo))
	{
		cout << "     * Invalid! ODO number: ";
		getline(cin, odo);
	}
	// Nhập và kiểm tra Remind service
	cout << "   Remind service: ";
	getline(cin, remind_service_str);
	while (!setRemindService(remind_service_str))
	{
		cout << "     * Invalid! Remind service: ";
		getline(cin, remind_service_str);
	}
}

bool Setting::setOwnerName(string owner_name)
{
	if (checkOwnerName(owner_name))
	{
		owner_name_ = owner_name;
		return true;
	}
	return false;
}

bool Setting::setEmail(string email)
{
	if (checkEmail(email))
	{
		email_ = email;
		return true;
	}
	return false;
}

bool Setting::setODO(string odo_number)
{
	if (checkUnsignedNumber(odo_number))
	{
		odo_number_ = stoi(odo_number);
		return true;
	}
	return false;
}

bool Setting::setRemindService(string remind_service)
{
	if (checkUnsignedNumber(remind_service))
	{
		remind_service_ = stoi(remind_service);
		return true;
	}
	return false;
}

void Setting::setODO(unsigned int odo_number)
{
	odo_number_ = odo_number;
}

void Setting::setRemindService(unsigned int remind_service)
{
	remind_service_ = remind_service;
}

string Setting::getPersonalKey()
{
	return personal_key_;
}

string Setting::getOwnerName()
{
	return owner_name_;
}

string Setting::getEmail()
{
	return email_;
}

int Setting::getODO()
{
	return odo_number_;
}

int Setting::getRemindService()
{
	return remind_service_;
}

bool Setting::checkOwnerName(string& str)
{
	// uppercase chuỗi str
	for (size_t i = 0; i < str.length(); i++)
		str[i] = toupper(str[i]);
	// kiểm tra định dạng tên 
	if (regex_match(str, regex("[A-Z]+( ?[A-Z]+)*"))) return true;
	return false;
}

bool Setting::checkPersonalKey(string str)
{
	// Kiểm tra mã cá nhân, str là số có đủ 8 chữ số kể cả số 0
	if (regex_match(str, regex("[0-9]{8}"))) return true;
	return false;
}

bool Setting::checkEmail(string str)
{
	// Kiểm tra định dạng email abcde@xyz.def
	if (regex_match(str, regex("[a-z0-9]{5,30}@[a-z0-9]{3,}(\.[a-z0-9]{2,}){1,2}")))
		return true;
	return false;
}

bool Setting::checkUnsignedNumber(string str)
{
	// Kiểm tra str là số nguyên không âm
	if (regex_match(str, regex("[0-9]+")))
		return true;
	return false;
}

int Setting::inputLevelNumber(string data_name)
{
	string str_input;
	cout << "   " << data_name << ": ";
	getline(cin, str_input);
	while (!checkUnsignedNumber(str_input))
	{
		cout << "     * Invalid! " << data_name << ": ";
		getline(cin, str_input);
	}
	return stoi(str_input);
}
