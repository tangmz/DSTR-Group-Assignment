#include "Header Files/Interface.h"
#include <iostream>
#include <iomanip>

using namespace std;

void Interface::General::PrintLine(char symbol, int length) {
	for (int i = 0; i < length; i++) {
		cout << symbol;
	}
	cout << endl;
}

void Interface::User::DisplayStartupPage() {
	Interface::General::PrintLine('=', 100);
	cout << "||" << setw(96) << left << "PATIENT QUEUE MANAGEMENT SYSTEM" << "||" << endl;
	Interface::General::PrintLine('=', 100);

}

string Interface::User::DisplayLoginPage() {
	//returns the login role as a string upon successful login, else return "Invalid"
	/*Usage
	* while((role = DisplayLoginPage()) == "Invalid"); //Perma loop login function
	* simultaneously discover the role the user logged in as
	* Once login successfully, while loop will break
	*/

	string user, pass = "";
	system("CLS");
	cout << "Hello, Welcome to Klinik Sulaiman Patient Management System." << endl << endl;
	cout << "Please enter your username: ";

	cin >> user;
	if (user == "Doktah") {									//Hard coded Doctor's username
		while (pass != "42069" || "0") {					//Hard coded pass: 42069, and 0 to return to login page again
			cout << "Please enter password (or type 0 to return): ";
			cin >> pass;
			if (pass == "0") { return "Invalid"; }			//Will recur this function again from first login page (in main function)
			if (pass == "42069") { return "Doctor"; }		//Login successful, return login role
			system("CLS");
			cout << "Wrong password, please try again." << endl << flush;
		}
	}
	else if (user == "Nurse") {	//Same code as "Doctor" above
		while (pass != "Nurse" || "0") {
			cout << "Please enter password (or type 0 to return): ";
			cin >> pass;
			if (pass == "0") { return "Invalid"; }
			if (pass == "Nurse") { return "Nurse"; }
			system("CLS");
			cout << "Wrong password, please try again." << endl << flush;
		}
	}
	else { //patient
		/*
		* while loop to check if username exist
		* if exist loop until password is correct, or 0 to cancel
		* if does not exist, finish first while loop, go below to show username not found
		*/
		cout << endl << "Username not found.." << endl << "Returning to Login page." << endl;
		system("PAUSE");
		return "Invalid";
	}
}