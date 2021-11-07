#pragma once
#include "../Header Files/Interface.h"
#include <iostream>
#include <iomanip>
#include <chrono>
#include <ctime>
using namespace std;

void Interface::General::PrintLine(char symbol, int length) {
	for (int i = 0; i < length; i++) {
		cout << symbol;
	}
	cout << endl;
}

bool Interface::Validator::isEmptyString(string item) {
	try {
		if (item.length() == 0)
			return false; // item is empty
		return true; // item is valid
	}
	catch(exception e){
		return false;
	}
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

void Interface::DoctorInterface::DisplayMainMenu(DoublyLinkedList<Patient>* patientList, DoublyLinkedList<Patient>* visitedPatientList) {
	int decision = -1;
	int sortDecision;
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
		cout << "8. View Patients' Details" << endl;
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
				patientList->combineList(visitedPatientList)->DisplayPages(10);
				Patient::ViewAllPatients(patientList);
				break;
			case 2:
				//Search by name
				system("cls");				
				cout << "Enter Keyword: ";
				getline(cin, s);
				s = ".*" + s + ".*";
				Patient::SearchPatient(visitedPatientList, s, AttributeValues::User::FirstName)->DisplayPages(10);
				break;
			case 3:
				//Search by illness
				system("cls");
				cout << "Enter Keyword: ";
				getline(cin, s);
				s = ".*" + s + ".*";
				Patient::SearchPatient(visitedPatientList, s, AttributeValues::Patient::Illness)->DisplayPages(10);
				break;
			case 4:
				//Modify patient record
				//Let user choose which patient first
				Patient::ModifyPatientRecord(patientList, visitedPatientList);
				break;
			case 5:
				//View by visiting order
				patientList->Sort(AttributeValues::Patient::VisitTime)->Sort(AttributeValues::Patient::VisitDate)->DisplayPages(10);
				break;
			case 6:
				//Notify nurse
				break;
			case 7:
				//View sorted list
				//Let user choose sort by what
				sortDecision = Doctor::sortPatientsDecision();
				system("cls");
				switch (sortDecision) {
				case 1:
					visitedPatientList->Sort(AttributeValues::User::FirstName)->DisplayPages(10);
					break;
				case 2:
					visitedPatientList->Sort(AttributeValues::User::LastName)->DisplayPages(10);
					break;
				case 3:
					visitedPatientList->Sort(AttributeValues::User::Age)->DisplayPages(10);
					break;
				case 4:
					visitedPatientList->Sort(AttributeValues::User::Gender)->DisplayPages(10);
					break;
				case 5:
					visitedPatientList->Sort(AttributeValues::User::Phone)->DisplayPages(10);
					break;
				case 6:
					visitedPatientList->Sort(AttributeValues::User::Email)->DisplayPages(10);
					break;
				case 7:
					visitedPatientList->Sort(AttributeValues::Patient::Illness)->DisplayPages(10);
					break;
				case 0:
					break;
				default:
					cout << "Invalid Input" << endl;
					system("pause");
					break;
				}
				break;
			case 8:
				patientList->Sort(AttributeValues::Patient::VisitTime)->Sort(AttributeValues::Patient::VisitDate)->DisplayDetails();
				//system("pause");
				break;
			case 0:
				//exit and go back to login page
			default:
				break;
		}
	}
}

void Interface::NurseInterface::DisplayMainMenu(DoublyLinkedList<Patient>* tempPatient, DoublyLinkedList<User>* tempUser, 
	DoublyLinkedList<Patient>* visitedPatientList) {
	string patientID, id, firstName, lastName,
		phone, email, address, password, ic, illness, visitDate, visitTime;
	int age;
	char gender;
	Patient p;
	int decision = -1;
	int decision1 = -1;
	int targetIndex;
	string keyword;
	while (decision != 0) {
		system("CLS");
		Interface::General::PrintLine('=', 70);
		cout << "Logged in as: Nurse" << endl;
		Interface::General::PrintLine('=', 70);
		cout << "Available Option: " << endl;
		cout << "1. Add New Patient to Waiting List" << endl;
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
				patientID = Patient::GeneratePatientID(tempPatient->GetLength() + visitedPatientList->GetLength());
				id = User::GenerateID(tempUser->GetLength());
				cout << "First Name: ";
				getline(cin, firstName);
				cout << "Last Name: ";
				getline(cin, lastName);
				cout << "Age: ";
				cin >> age;
				cin.ignore();
				cout << "Gender: ";
				cin >> gender;
				cin.ignore();
				cout << "Phone: ";
				getline(cin, phone);
				cout << "e-mail: ";
				getline(cin, email);
				cout << "Address: ";
				getline(cin, address);
				cout << "Password: ";
				getline(cin, password);
				cout << "I.C. Number: ";
				getline(cin, ic);
				cout << "Illness: ";
				getline(cin, illness);
				cout << "Visit Date: ";
				getline(cin, visitDate);
				cout << "Visit Time: ";
				getline(cin, visitTime);
				p = Patient(patientID, id, firstName, lastName, age, gender,
					phone, email, address, password, ic, illness, visitDate, visitTime);
				tempPatient->AddToEnd(p);
				break;
			case 2:
				//View all patient
				Patient::ViewAllPatients(tempPatient);
				break;
			case 3:
				//Search patient
				while (decision1 > 0 && decision1 < 9) {
					system("CLS");
					Interface::General::PrintLine('=', 70);
					cout << "Patient Record Search Engine" << endl;
					Interface::General::PrintLine('=', 70);
					cout << "Search By: " << endl;
					cout << "1. Patient ID" << endl;
					cout << "2. First Name" << endl;
					cout << "3. Last Name" << endl;
					cout << "4. Age" << endl;
					cout << "5. Phone" << endl;
					cout << "6. e-mail" << endl;
					cout << "7. House Address" << endl;
					cout << "8. I.C. Number" << endl;

					Interface::General::PrintLine('=', 70);
					cout << "Select Option: ";
					cin >> decision;
				}
				switch (decision1) {
					case 1:
						cout << "Keyword: ";
						getline(cin, keyword);
						Patient::SearchPatient(tempPatient, keyword, AttributeValues::Patient::PatientID)->DisplayDetails();
						break;
					case 2:
						cout << "Keyword: ";
						getline(cin, keyword);
						Patient::SearchPatient(tempPatient, keyword, AttributeValues::Patient::FirstName)->DisplayDetails();
						break;
					case 3:
						cout << "Keyword: ";
						getline(cin, keyword);
						Patient::SearchPatient(tempPatient, keyword, AttributeValues::Patient::LastName)->DisplayDetails();
						break;
					case 4:
						cout << "Keyword: ";
						getline(cin, keyword);
						Patient::SearchPatient(tempPatient, keyword, AttributeValues::Patient::Age)->DisplayDetails();
						break;
					case 5:
						cout << "Keyword: ";
						getline(cin, keyword);
						Patient::SearchPatient(tempPatient, keyword, AttributeValues::Patient::Phone)->DisplayDetails();
						break;
					case 6:
						cout << "Keyword: ";
						getline(cin, keyword);
						Patient::SearchPatient(tempPatient, keyword, AttributeValues::Patient::Email)->DisplayDetails();
						break;
					case 7:
						cout << "Keyword: ";
						getline(cin, keyword);
						Patient::SearchPatient(tempPatient, keyword, AttributeValues::Patient::Address)->DisplayDetails();
						break;
					case 8:
						cout << "Keyword: ";
						getline(cin, keyword);
						Patient::SearchPatient(tempPatient, keyword, AttributeValues::Patient::IC)->DisplayDetails();
						break;
				}
			case 4:
				//View sorted list (need to create another list for sorted data?)
				//Let user choose sort by what
				tempPatient->Sort(AttributeValues::User::Age)->DisplayPages(10);
				break;
			case 5:
				//Change priority
				break;
			case 6:
				//Notify patient
				//Remove from waiting list, move to visit list
				targetIndex = tempPatient->DisplayPages(10);
				visitedPatientList->AddToStart(tempPatient->Get(targetIndex));
				tempPatient->DeleteAtIndex(targetIndex);
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

void Interface::PatientInterface::DisplayMainMenu(DoublyLinkedList<Patient>* tempPatient, DoublyLinkedList<Doctor>* tempDoctor) {
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
		string date, time;
		switch (decision)
		{
			case 1:
				//Create appointment
				//cout << "Today's Date: " << date::format("%F", std::chrono::system_clock::now()) << endl;
				cout << "Please enter the Appointment Date: " << endl;
				getline(cin, date);
				while (time.length() == 0)
				{
					cout << "No value entered, please enter the date: ";
					getline(cin, date);
					if (date.length() != 0)
						break;
				}
				cout << "Available Time Slot:" << endl;
				for (int i = 10; i < 18; i++) {
					if (i < 12) {
						cout << i << ":00" << "am" << "\t";
						cout << i << ":30" << "am" << endl;
					}
					else if (i > 12) {
						cout << i << ":00" << "pm" << "\t";
						cout << i << ":30" << "pm" << endl;
					}
				}
				cout << "Please enter the Appointment Time: ";
				getline(cin, time);
				while (time.length() == 0)
				{
					cout << "No value entered, please enter the time: ";
					getline(cin, time);
					if (time.length() != 0)
						break;
				}

				//Patient::CreateAppointment(date, time, tempDoctor);
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