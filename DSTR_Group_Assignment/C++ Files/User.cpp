#include "../Header Files/Interface.h"
#include "../Header Files/AttributeValues.h"
#include "../Header Files/Comparison.h"
#include "../Header Files/User.h"
#include <iostream>
#include <iomanip>
#include <regex>
#include <string>
using namespace std;

bool User::Equals(User leftUser, User rightUser) {
	bool match = true;
	match = leftUser.FirstName == rightUser.FirstName ? match : false;
	match = leftUser.LastName == rightUser.LastName ? match : false;
	match = leftUser.Age == rightUser.Age ? match : false;
	match = leftUser.Gender == rightUser.Gender ? match : false;
	match = leftUser.Phone == rightUser.Phone ? match : false;
	match = leftUser.Email == rightUser.Email ? match : false;
	match = leftUser.Address == rightUser.Address ? match : false;
	return match;
}
int User::CompareTo(User nextUser, int attributeValue) {
	int index = 0, value = 0;
	switch (attributeValue) {
		case AttributeValues::All:
		case AttributeValues::User::ID:
			return CompareStrings(this->ID, nextUser.ID);
		case AttributeValues::User::FirstName:
			value = CompareStrings(this->FirstName, nextUser.FirstName);
			break;
		case AttributeValues::User::LastName:
			value = CompareStrings(this->LastName, nextUser.LastName);
			break;
		case AttributeValues::User::Age:
			value = this->Age < nextUser.Age ? 0 : 2;
			value = this->Age == nextUser.Age ? 1 : value;
			break;
		case AttributeValues::User::Gender:
			value = CompareStrings(string(1, this->Gender), string(1, nextUser.Gender));
			break;
		case AttributeValues::User::Phone:
			value = CompareStrings(this->Phone, nextUser.Phone);
			break;
		case AttributeValues::User::Email:
			value = CompareStrings(this->Email, nextUser.Email);
			break;
		case AttributeValues::User::Address:
			value = CompareStrings(this->Address, nextUser.Address);
			break;
		default:
			return 1;
	}
	return value == 1 ? CompareStrings(this->ID, nextUser.ID) : value;
}
bool User::MatchesRegex(string regExp, int attributeValue) {
	if (attributeValue == AttributeValues::All) {
		if (regex_match(ID, regex(regExp)) || regex_match(FirstName, regex(regExp)) ||
			regex_match(LastName, regex(regExp)) || regex_match(to_string(Age), regex(regExp)) ||
			regex_match(string(1, Gender), regex(regExp)) || regex_match(Phone, regex(regExp)) ||
			regex_match(Email, regex(regExp)) || regex_match(Address, regex(regExp))) {
			return true;
		}
	}
	else {
		switch (attributeValue) {
			case AttributeValues::User::ID:
				if (regex_match(ID, regex(regExp))) return true;
				break;
			case AttributeValues::User::FirstName:
				if (regex_match(FirstName, regex(regExp))) return true;
				break;
			case AttributeValues::User::LastName:
				if (regex_match(LastName, regex(regExp))) return true;
				break;
			case AttributeValues::User::Age:
				if (regex_match(to_string(Age), regex(regExp))) return true;
				break;
			case AttributeValues::User::Gender:
				if (regex_match(string(1, Gender), regex(regExp))) return true;
				break;
			case AttributeValues::User::Phone:
				if (regex_match(Phone, regex(regExp))) return true;
				break;
			case AttributeValues::User::Email:
				if (regex_match(Email, regex(regExp))) return true;
				break;
			case AttributeValues::User::Address:
				if (regex_match(Address, regex(regExp))) return true;
				break;
			default:
				break;
		}
	}
	return false;
}

string User::GenerateID(int n) {
	string id = "USR-";
	for (int i = 0; i < 6 - ceil(log10(n + 1)); i++) id += "0";
	id += to_string(n);
	return id;
}
void User::Login() {
	string loginResult = "";
	do {
		//Cannot switch string in c++, unless using enum
		loginResult = Interface::User::DisplayLoginPage();
		if (loginResult == "Doctor") {
			Interface::Doctor::DisplayMainMenu();
			break;
		}
		else if (loginResult == "Nurse") {
			Interface::Nurse::DisplayMainMenu();
			break;
		}
		else if (loginResult == "Patient") {			
			Interface::Patient::DisplayMainMenu();
			break;
		}
		else if (loginResult == "Register") {
			loginResult = Interface::User::DisplayRegisterPage();
			break;
		}
		else if (loginResult == "Exit") {
			Interface::User::DisplayExitPage();
			break;
		}
	} while (loginResult != "Exit");
}
void User::Register() {
	string registerResult = Interface::User::DisplayRegisterPage();
	if (registerResult == "Doctor") {
		Interface::Doctor::DisplayMainMenu();
	}
	else if (registerResult == "Nurse") {
		Interface::Nurse::DisplayMainMenu();
	}
	else if (registerResult == "Patient") {
		Interface::Patient::DisplayMainMenu();
	}
	else if (registerResult == "Login") {
		User::Login();
	}
	else if (registerResult == "Exit") {
		Interface::User::DisplayExitPage();
	}
}
void User::Logout() {
	User::Login();
}
void User::ShowDetails() {
	cout << "User: " << ID << "; Name: " << FirstName << " " << LastName << endl;
}
void User::DisplayTableHeader(int startIndex, int tableLength) {
	if (startIndex >= 0) cout << setw(to_string(tableLength).length() + 2) << left << "No.";
	cout << setw(15) << left << "ID" <<
		setw(20) << "First Name" <<
		setw(20) << "Last Name" <<
		setw(5) << "Age" <<
		setw(5) << "M/F" <<
		setw(15) << "Phone" <<
		setw(20) << "Email" <<
		setw(30) << "Address" << endl;
}
void User::DisplayTableRow(int startIndex, int index, int tableLength) {
	if (startIndex >= 0) cout << setw(to_string(tableLength).length() + 2) << index + startIndex;
	cout << setw(15) << ID <<
		setw(20) << FirstName <<
		setw(20) << LastName <<
		setw(5) << Age <<
		setw(5) << Gender <<
		setw(15) << Phone <<
		setw(20) << Email <<
		setw(30) << Address << endl;
}