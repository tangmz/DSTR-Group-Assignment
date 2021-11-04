#pragma once
#include "../Header Files/Interface.h"
#include <iostream>
#include <iomanip>
using namespace std;

void Interface::General::PrintLine(char symbol, int length) {
	for (int i = 0; i < length; i++) {
		cout << symbol;
	}
	cout << endl;
}

void Interface::UserInterface::DisplayStartupPage() {
	Interface::General::PrintLine('=', 100);
	cout << "||" << setw(96) << left << "PATIENT QUEUE MANAGEMENT SYSTEM" << "||" << endl;
	Interface::General::PrintLine('=', 100);
}
string Interface::UserInterface::DisplayLoginPage() {
	//returns the login role as a string upon successful login, else return "Invalid"
	/*Usage
	* while((role = DisplayLoginPage()) == "Invalid"); //Perma loop login function
	* simultaneously discover the role the user logged in as
	* Once login successfully, while loop will break
	*/

	string user, pass = "";
	system("CLS");
	cout << "Hello, Welcome to Klinik Sulaiman Patient Management System." << endl << endl;
	cout << "Keyword: \"Reg\" to register, \"Exit\" to exit" << endl;
	cout << "Please enter your username: ";

	cin >> user;
	cin.ignore();
	if (user == "Reg") return "Register";
	if (user == "Exit") return "Exit";
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
	return "Invalid";
}
string Interface::UserInterface::DisplayRegisterPage(){
	return "";
}
void Interface::UserInterface::DisplayExitPage() {
	cout << "EXITED THE PROGRAM" << endl;
}

void Interface::DoctorInterface::DisplayMainMenu(DoublyLinkedList<Patient>* patientList) {
	int decision = -1;
	while (decision != 0) {
		system("CLS");
		Interface::General::PrintLine('=', 70);
		cout << "Logged in as: Doctor" << endl;
		Interface::General::PrintLine('=', 70);
		cout << "Available Option: " << endl;
		cout << "1. View All Patients" << endl;
		cout << "2. Search Patient by Name" << endl;
		cout << "3. Search Patient by Illness" << endl;
		cout << "4. Modify Patient's Record" << endl;
		cout << "5. View Patient Based On Visiting Order" << endl;
		cout << "6. Notify Nurse" << endl;
		cout << "7. View Sorted List of Patient" << endl;
		cout << "0. Logout" << endl;
		Interface::General::PrintLine('-', 70);
		cout << "Select Option: ";
		cin >> decision;
		cin.ignore();
		string s;

		switch (decision)
		{
			case 1:
				//View all patient
				Patient::ViewAllPatients(patientList);
				break;
			case 2:
				//Search by name
				system("cls");				
				cout << "Enter Keyword: ";
				getline(cin, s);
				s = ".*" + s + ".*";
				Patient::SearchPatient(patientList, s, AttributeValues::User::FirstName)->DisplayPages(10);
				break;
			case 3:
				//Search by illness
				system("cls");
				cout << "Enter Keyword: ";
				getline(cin, s);
				s = ".*" + s + ".*";
				Patient::SearchPatient(patientList, s, AttributeValues::Patient::Illness)->DisplayPages(10);
				break;
			case 4:
				//Modify patient record
				//Let user choose which patient first
				Patient::ModifyPatientRecord(patientList);
				break;
			case 5:
				//View by visiting order
				break;
			case 6:
				//Notify nurse
				break;
			case 7:
				//View sorted list
				//Let user choose sort by what
				break;
			case 0:
				//exit and go back to login page
			default:
				break;
		}
	}
}

void Interface::NurseInterface::DisplayMainMenu() {
	int decision = -1;
	while (decision != 0) {
		system("CLS");
		Interface::General::PrintLine('=', 70);
		cout << "Logged in as: Nurse" << endl;
		Interface::General::PrintLine('=', 70);
		cout << "Available Option: " << endl;
		cout << "1. Add New Patient to List" << endl;
		cout << "2. View All Patients" << endl;
		cout << "3. Search Patient" << endl;
		cout << "4. View Sorted List of Patient" << endl;
		cout << "5. Change Patient's Priority" << endl;
		cout << "6. Notify Next Patient" << endl;
		cout << "7. Collect Payment" << endl;
		cout << "0. Logout" << endl;

		Interface::General::PrintLine('-', 70);
		cout << "Select Option: ";
		cin >> decision;

		switch (decision)
		{
			case 1:
				//Add patient
				break;
			case 2:
				//View all patient
				break;
			case 3:
				//Search patient
				break;
			case 4:
				//View sorted list (need to create another list for sorted data?)
				//Let user choose sort by what
				break;
			case 5:
				//Change priority
				break;
			case 6:
				//Notify patient
				break;
			case 7:
				//Collect payment
				break;
			case 0:
				//exit and go back to login page

			default:
				break;
		}
	}
}

void Interface::PatientInterface::DisplayMainMenu() {
	int decision = -1;
	while (decision != 0) {
		system("CLS");
		Interface::General::PrintLine('=', 70);
		cout << "Logged in as: Patient" << endl;
		Interface::General::PrintLine('=', 70);
		cout << "Available Option: " << endl;
		cout << "1. Create Appointment" << endl;
		cout << "2. Update Appointment" << endl;
		cout << "3. Cancel Appointment" << endl;
		cout << "4. Get Queue Number" << endl;
		cout << "0. Logout" << endl;


		Interface::General::PrintLine('-', 70);
		cout << "Select Option: ";
		cin >> decision;

		switch (decision)
		{
			case 1:
				//Create appointment
				break;
			case 2:
				//Update appointment
				//Let user choose to update date, time, doctor (no need payment as unreasonable to let patient set payment for themselves)
				break;
			case 3:
				//Cancel appointment
				break;
			case 4:
				//Get queue number
				break;
			case 0:
				//exit and go back to login page

			default:
				break;
		}
	}
}