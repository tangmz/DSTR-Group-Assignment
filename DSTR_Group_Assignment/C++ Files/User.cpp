//#pragma once
//#include "../Header Files/Interface.h"
//#include "../Header Files/AttributeValues.h"
//#include "../Header Files/Comparison.h"
//#include "../Header Files/User.h"
//#include <iostream>
//#include <iomanip>
//#include <regex>
//#include <string>
//using namespace std;
//
//bool User::Equals(User nextUser) {
//	bool match = true;
//	match = FirstName == nextUser.FirstName ? match : false;
//	match = LastName == nextUser.LastName ? match : false;
//	match = Age == nextUser.Age ? match : false;
//	match = Gender == nextUser.Gender ? match : false;
//	match = Phone == nextUser.Phone ? match : false;
//	match = Email == nextUser.Email ? match : false;
//	match = Address == nextUser.Address ? match : false;
//	match = IC == nextUser.IC ? match : false;
//	return match;
//}
//int User::CompareTo(User nextUser, int attributeValue) {
//	int index = 0, value = 0;
//	switch (attributeValue) {
//		case AttributeValues::All:
//		case AttributeValues::User::ID:
//			return CompareStrings(this->ID, nextUser.ID);
//		case AttributeValues::User::FirstName:
//			value = CompareStrings(this->FirstName, nextUser.FirstName);
//			break;
//		case AttributeValues::User::LastName:
//			value = CompareStrings(this->LastName, nextUser.LastName);
//			break;
//		case AttributeValues::User::Age:
//			value = this->Age < nextUser.Age ? 0 : 2;
//			value = this->Age == nextUser.Age ? 1 : value;
//			break;
//		case AttributeValues::User::Gender:
//			value = CompareStrings(string(1, this->Gender), string(1, nextUser.Gender));
//			break;
//		case AttributeValues::User::Phone:
//			value = CompareStrings(this->Phone, nextUser.Phone);
//			break;
//		case AttributeValues::User::Email:
//			value = CompareStrings(this->Email, nextUser.Email);
//			break;
//		case AttributeValues::User::Address:
//			value = CompareStrings(this->Address, nextUser.Address);
//			break;
//		case AttributeValues::User::IC:
//			value = CompareStrings(this->IC, nextUser.IC);
//			break;
//		default:
//			return 1;
//	}
//	return value == 1 ? CompareStrings(this->ID, nextUser.ID) : value;
//}
//bool User::MatchesRegex(string regExp, int attributeValue) {
//	switch (attributeValue) {
//		case AttributeValues::All:
//			if (regex_match(ID, regex(regExp)) || regex_match(FirstName, regex(regExp)) ||
//				regex_match(LastName, regex(regExp)) || regex_match(to_string(Age), regex(regExp)) ||
//				regex_match(string(1, Gender), regex(regExp)) || regex_match(Phone, regex(regExp)) ||
//				regex_match(Email, regex(regExp)) || regex_match(Address, regex(regExp)) || regex_match(IC, regex(regExp))) {
//				return true;
//			}
//			break;
//		case AttributeValues::User::ID:
//			if (regex_match(ID, regex(regExp))) return true;
//			break;
//		case AttributeValues::User::FirstName:
//			if (regex_match(FirstName, regex(regExp))) return true;
//			break;
//		case AttributeValues::User::LastName:
//			if (regex_match(LastName, regex(regExp))) return true;
//			break;
//		case AttributeValues::User::Age:
//			if (regex_match(to_string(Age), regex(regExp))) return true;
//			break;
//		case AttributeValues::User::Gender:
//			if (regex_match(string(1, Gender), regex(regExp))) return true;
//			break;
//		case AttributeValues::User::Phone:
//			if (regex_match(Phone, regex(regExp))) return true;
//			break;
//		case AttributeValues::User::Email:
//			if (regex_match(Email, regex(regExp))) return true;
//			break;
//		case AttributeValues::User::Address:
//			if (regex_match(Address, regex(regExp))) return true;
//			break;
//		case AttributeValues::User::IC:
//			if (regex_match(IC, regex(regExp))) return true;
//			break;
//		default:
//			break;
//	}
//	return false;
//}
//
//string User::GenerateID(int n) {
//	string id = "USR-";
//	for (int i = 0; i < 6 - ceil(log10(n + 1)); i++) id += "0";
//	id += to_string(n);
//	return id;
//}
//void User::Login() {
//	string loginResult = "";
//	do {
//		//Cannot switch string in c++, unless using enum
//		loginResult = Interface::User::DisplayLoginPage();
//		if (loginResult == "Doctor") {
//			Interface::Doctor::DisplayMainMenu();
//			break;
//		}
//		else if (loginResult == "Nurse") {
//			Interface::Nurse::DisplayMainMenu();
//			break;
//		}
//		else if (loginResult == "Patient") {			
//			Interface::Patient::DisplayMainMenu();
//			break;
//		}
//		else if (loginResult == "Register") {
//			loginResult = Interface::User::DisplayRegisterPage();
//			break;
//		}
//		else if (loginResult == "Exit") {
//			Interface::User::DisplayExitPage();
//			break;
//		}
//	} while (loginResult != "Exit");
//}
//void User::Register() {
//	string registerResult = Interface::User::DisplayRegisterPage();
//	if (registerResult == "Doctor") {
//		Interface::Doctor::DisplayMainMenu();
//	}
//	else if (registerResult == "Nurse") {
//		Interface::Nurse::DisplayMainMenu();
//	}
//	else if (registerResult == "Patient") {
//		Interface::Patient::DisplayMainMenu();
//	}
//	else if (registerResult == "Login") {
//		User::Login();
//	}
//	else if (registerResult == "Exit") {
//		Interface::User::DisplayExitPage();
//	}
//}
//void User::Logout() {
//	User::Login();
//}
//void User::ShowDetails() {
//	cout << "User: " << ID << "; Name: " << FirstName << " " << LastName << endl;
//}
//void User::DisplayTableHeader(int startIndex, int tableLength) {
//	if (startIndex >= 0) cout << setw(to_string(tableLength).length() + 2) << left << "No.";
//	cout << setw(15) << left << "ID" <<
//		setw(20) << "First Name" <<
//		setw(20) << "Last Name" <<
//		setw(5) << "Age" <<
//		setw(5) << "M/F" <<
//		setw(15) << "Phone" <<
//		setw(20) << "Email" <<
//		setw(30) << "Address" << endl;
//}
//void User::DisplayTableRow(int startIndex, int index, int tableLength) {
//	if (startIndex >= 0) cout << setw(to_string(tableLength).length() + 2) << index + startIndex;
//	cout << setw(15) << ID <<
//		setw(20) << FirstName <<
//		setw(20) << LastName <<
//		setw(5) << Age <<
//		setw(5) << Gender <<
//		setw(15) << Phone <<
//		setw(20) << Email <<
//		setw(30) << Address << endl;
//}
//
////Interface
//void PrintLine(char symbol, int length) {
//	for (int i = 0; i < length; i++) {
//		cout << symbol;
//	}
//	cout << endl;
//}
//
//void User::DisplayStartupPage() {
//	PrintLine('=', 100);
//	cout << "||" << setw(96) << left << "PATIENT QUEUE MANAGEMENT SYSTEM" << "||" << endl;
//	Interface::General::PrintLine('=', 100);
//}
//string User::DisplayLoginPage() {
//	//returns the login role as a string upon successful login, else return "Invalid"
//	/*Usage
//	* while((role = DisplayLoginPage()) == "Invalid"); //Perma loop login function
//	* simultaneously discover the role the user logged in as
//	* Once login successfully, while loop will break
//	*/
//
//	string user, pass = "";
//	system("CLS");
//	cout << "Hello, Welcome to Klinik Sulaiman Patient Management System." << endl << endl;
//	cout << "Keyword: \"Reg\" to register, \"Exit\" to exit" << endl;
//	cout << "Please enter your username: ";
//
//	cin >> user;
//	cin.ignore();
//	if (user == "Reg") return "Register";
//	if (user == "Exit") return "Exit";
//	if (user == "Doktah") {									//Hard coded Doctor's username
//		while (pass != "42069" || "0") {					//Hard coded pass: 42069, and 0 to return to login page again
//			cout << "Please enter password (or type 0 to return): ";
//			cin >> pass;
//			if (pass == "0") { return "Invalid"; }			//Will recur this function again from first login page (in main function)
//			if (pass == "42069") { return "Doctor"; }		//Login successful, return login role
//			system("CLS");
//			cout << "Wrong password, please try again." << endl << flush;
//		}
//	}
//	else if (user == "Nurse") {	//Same code as "Doctor" above
//		while (pass != "Nurse" || "0") {
//			cout << "Please enter password (or type 0 to return): ";
//			cin >> pass;
//			if (pass == "0") { return "Invalid"; }
//			if (pass == "Nurse") { return "Nurse"; }
//			system("CLS");
//			cout << "Wrong password, please try again." << endl << flush;
//		}
//	}
//	else { //patient
//		/*
//		* while loop to check if username exist
//		* if exist loop until password is correct, or 0 to cancel
//		* if does not exist, finish first while loop, go below to show username not found
//		*/
//		cout << endl << "Username not found.." << endl << "Returning to Login page." << endl;
//		system("PAUSE");
//		return "Invalid";
//	}
//	return "Invalid";
//} 
////Login for Patient is unfinished----------------------------------------------------------------------------------------
//string User::DisplayRegisterPage() {
//	return "";
//}
//void User::DisplayExitPage() {
//	cout << "EXITED THE PROGRAM" << endl;
//}