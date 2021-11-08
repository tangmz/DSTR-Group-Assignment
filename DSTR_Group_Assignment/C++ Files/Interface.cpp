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

void ChooseSorting(DoublyLinkedList<Patient>* visitedPatientList) {
	int sortDecision = Doctor::sortPatientsDecision();
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
void Interface::UserInterface::DisplayRegisterPage(DoublyLinkedList<User>* userList, DoublyLinkedList<Doctor>* doctorList, DoublyLinkedList<Nurse>* nurseList){
	char answer;

	do {
		Interface::General::PrintLine('=', 100);
		cout << "REGISTER NEW DOCTOR / NURSE" << endl;
		Interface::General::PrintLine('=', 100);

		cout << "1 - Register New Doctor\n2 - Register New Nurse\n3 - Back to Login\n > ";
		cin >> answer;
		cin.ignore();

		char gender;
		string firstName, lastName, ageString, ic, email, password, phone, address;
		int age;
		bool inputPass = true;
		switch (answer) {
			case '1': //Doctor
			case '2': //Nurse
				cout << "First Name: ";
				getline(cin, firstName);
				cout << "Last Name: ";
				getline(cin, lastName);
				cout << "IC: ";
				getline(cin, ic);

				do {
					inputPass = true;
					cout << "Gender [(M)ale / (F)emale / (N)on-Binary]: ";
					cin >> gender;
					cin.ignore();

					gender = toupper(gender);
					if (gender != 'M' && gender != 'F' && gender != 'N') {
						inputPass = false;
						cout << "Invalid Gender Selected." << endl;
					}
				} while (!inputPass);

				do {
					inputPass = true;
					cout << "Age: ";
					getline(cin, ageString);
					try {
						age = stoi(ageString);
					}
					catch (...) {
						inputPass = false;
						cout << "Invalid Age Entered." << endl;
					}
				} while (!inputPass);

				cout << "Email: ";
				getline(cin, email);
				cout << "Password: ";
				getline(cin, password);
				cout << "Phone Number: ";
				getline(cin, phone);
				cout << "Address: ";
				getline(cin, address);
				if (answer == '1') {
					doctorList->AddToEnd(Doctor(
						Doctor::GenerateDoctorID(doctorList->GetLength() + 1),
						Doctor::GenerateID(userList->GetLength() + 1),
						firstName, lastName, age, gender, phone, email, address, password, ic
					))
				}
				else if (answer == '2') {
					nurseList->AddToEnd(Nurse(
						Nurse::GenerateNurseID(nurseList->GetLength() + 1),
						Nurse::GenerateID(userList->GetLength() + 1),
						firstName, lastName, age, gender, phone, email, address, password, ic
					))
				}
				else {
					cout << "Inputted Information Cannot Be Stored." << endl;
				}
				break;
			case '3': //Back to Login = Exit
			default:
				break;
		}
	} while (answer != '1' && answer != '2' && answer != '3');

	return;
}
void Interface::UserInterface::DisplayExitPage() {
	cout << "EXITED THE PROGRAM" << endl;
}

void Interface::DoctorInterface::DisplayMainMenu(DoublyLinkedList<Patient>* patientList, DoublyLinkedList<Patient>* visitedPatientList, Doctor* currentDoctor) {
	int decision = -1;
	int sortDecision = -1;
	int availableDecision = -1;
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
		cout << "6. Set Availability" << endl;
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
			{
				//View all patient
				DoublyLinkedList<Patient> combined = DoublyLinkedList<Patient>();
				for (int i = 0; i < patientList->GetLength(); i++) {
					combined.AddToEnd(patientList->Get(i));
				}
				for (int i = 0; i < visitedPatientList->GetLength(); i++) {
					combined.AddToEnd(visitedPatientList->Get(i));
				}
				combined.DisplayPages(10);
				Patient::ViewAllPatients(patientList);
				break;
			}
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
				//Set availability
				system("cls");
				Interface::General::PrintLine('=', 70);
				cout << "Current status is: " << currentDoctor->getIsAvailable() << endl;
				Interface::General::PrintLine('-', 70);
				cout << "1. Set to available" << endl;
				cout << "2. Set to not available" << endl;
				cin >> availableDecision;
				cin.ignore();
				switch (availableDecision)
				{
				case 1:
					currentDoctor->setIsAvailable(true);
					break;
				case 2:
					currentDoctor->setIsAvailable(false);
					break;
				default:
					cout << "Invalid input, aborting operation." << endl;
					cout << system("pause");
					break;
				}
				
				break;
			case 7:
				//View sorted list
				//Let user choose sort by what
				ChooseSorting(visitedPatientList);
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
	int i;
	Patient temp;
	while (decision != 0) {
		system("CLS");
		Interface::General::PrintLine('=', 70);
		cout << "Logged in as: Nurse" << endl;
		Interface::General::PrintLine('=', 70);
		cout << "Available Option: " << endl;
		cout << "1. Register New Walk-In Patient" << endl;
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
				//tempPatient->Sort(AttributeValues::User::Age)->DisplayPages(10);
				ChooseSorting(visitedPatientList);
				break;
			case 5:
				//Change priority
				i = tempPatient->DisplayPages(10);
				temp = tempPatient->Get(i);
				tempPatient->DeleteAtIndex(i);
				tempPatient->AddToStart(temp);
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
				Patient::SearchPatient(visitedPatientList, "0", AttributeValues::Patient::isPaid)->DisplayPages(10);
				temp = visitedPatientList->Get(visitedPatientList->Sort(AttributeValues::Patient::isPaid)->DisplayPages(10));
				temp.SetPaid(true);
				Patient::SearchPatient(visitedPatientList, "1", AttributeValues::Patient::isPaid)->DisplayPages(10);
				break;
			case 0:
				//exit and go back to login page

			default:
				break;
		}
	}
}

void Interface::PatientInterface::DisplayMainMenu(Patient* patientUser, DoublyLinkedList<Patient>* tempPatient, DoublyLinkedList<Doctor>* tempDoctor) {
	int decision = -1;
	do {
		system("CLS");
		Interface::General::PrintLine('=', 70);
		cout << "Logged in as: Patient" << endl;
		Interface::General::PrintLine('=', 70);
		cout << "Available Option: " << endl;
		cout << "1. Get Queue Number" << endl;
		cout << "2. View Current Patient Details" << endl;
		cout << "3. Logout" << endl;

		Interface::General::PrintLine('-', 70);
		cout << "Select Option: ";
		cin >> decision;
		cin.ignore();
		switch (decision)
		{
			case 1:
				//Get queue number
				Interface::PatientInterface::DisplayQueueNumber(patientUser, tempPatient);
				break;
			case 2:
				//View current patient details
				Interface::PatientInterface::DisplayCurrentDetails(patientUser);
				break;
			case 3: //exit and go back to login page
			default:
				break;
		}
		/*
		    UNUSED CODE
			case 1:
				//Create appointment
				//cout << "Today's Date: " << date::format("%F", std::chrono::system_clock::now()) << endl;
				Interface::PatientInterface::DisplayAppointmentCreate(patientUser);
				break;
			case 2:
				//Update appointment
				//Let user choose to update date, time, doctor (no need payment as unreasonable to let patient set payment for themselves)
				Interface::PatientInterface::DisplayAppointmentUpdate(patientUser);
				break;
			case 3:
				//Cancel appointment
				Interface::PatientInterface::DisplayAppointmentCancel(patientUser);
				break;
		*/
	} while (decision != 3);
}
void Interface::PatientInterface::DisplaySortPatients() {

}
void Interface::PatientInterface::DisplaySearchPatients() {

}
void Interface::PatientInterface::DisplayAppointmentCreate(Patient* patientUser) {
	if (patientUser->GetVisitTime() != "" && patientUser->GetVisitDate() != "") {
		cout << "Appointment Already Scheduled." << endl;
		system("pause");
		return;
	}

	string date, time;

	//Select Date
	/*cout << "Please enter the Appointment Date: " << endl;
	getline(cin, date);
	while (date.length() == 0)
	{
		cout << "No value entered, please enter the date: ";
		getline(cin, date);
		if (date.length() != 0)
			break;
	}*/
	bool datePassed = true, dayEntered = false;
	string dayString = "", monthString = "";
	int dayInt = 0, monthInt = 0;

	do {
		datePassed = true;
		dayEntered = false;
		dayString = "";
		monthString = "";
		dayInt = 0;
		monthInt = 0;

		system("cls");
		cout << "Enter Intended Visit Date (dd/mm): ";
		getline(cin, date);

		//Get day and month values
		for (int index = 0; index < int(date.length()); index++) {
			if (isdigit(date[index]) && !dayEntered) {
				dayString += date[index];
			}
			else if (isdigit(date[index]) && dayEntered) {
				monthString += date[index];
			}

			if (!isdigit(date[index]) && !dayEntered) dayEntered = true;
			else if (!isdigit(date[index]) && dayEntered) break;
		}
		try {
			dayInt = stoi(dayString);
			monthInt = stoi(monthString);
		}
		catch (...) {
			datePassed = false;
		}

		//Check if date values are valid
		if (monthInt <= 0 || monthInt > 12) datePassed = false;
		if ((monthInt <= 7 && monthInt % 2 == 1) || (monthInt >= 8 && monthInt % 2 == 0)) {
			//31-day month
			if (dayInt <= 0 || dayInt > 31) datePassed = false;
		}
		else if (((monthInt <= 7 && monthInt % 2 == 0) || (monthInt >= 8 && monthInt % 2 == 1)) && monthInt != 2) {
			//30-day month
			if (dayInt <= 0 || dayInt > 30) datePassed = false;
		}
		else if (monthInt == 2) {
			//February = 28-day month (no year included)
			if (dayInt <= 0 || dayInt > 29) datePassed = false;
		}
		else {
			//Invalid Month
			datePassed = false;
		}

		if (!datePassed) {
			cout << "Invalid Date Entered. Please Enter Again. [" << dayString << " and" << monthString << "]" << endl;
			system("pause");
		}
	} while (!datePassed);

	date = "";
	if (monthString.length() == 1) date += "0";
	date += monthString;
	date += "/";
	if (dayString.length() == 1) date += "0";
	date += dayString;

	//Select Time
	/*cout << "Available Time Slot:" << endl;
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
	}*/
	bool timePassed = true, hourEntered = false;
	string hourString = "", minuteString = "";
	int hourInt = 0, minuteInt = 0;

	do {
		timePassed = true;
		hourEntered = false;
		hourString = "";
		minuteString = "";
		hourInt = 0;
		minuteInt = 0;

		system("cls");
		cout << "Enter Intended Visit Time (hh:mm): ";
		getline(cin, time);

		//Get hour and minute values
		for (int index = 0; index < int(time.length()); index++) {
			if (isdigit(time[index]) && !hourEntered) {
				hourString += time[index];
			}
			else if (isdigit(time[index]) && hourEntered) {
				minuteString += time[index];
			}

			if (!isdigit(time[index]) && !hourEntered) hourEntered = true;
			else if (!isdigit(time[index]) && hourEntered) break;
		}
		try {
			hourInt = stoi(hourString);
			minuteInt = stoi(minuteString);
		}
		catch (...) {
			timePassed = false;
		}

		//Check if time values are valid
		if (hourInt < 0 || hourInt >= 24) timePassed = false;
		if (minuteInt < 0 || minuteInt >= 60) timePassed = false;

		if (!timePassed) {
			cout << "Invalid Time Entered. Please Enter Again. [" << hourString << " and" << minuteString << "]" << endl;
			system("pause");
		}
	} while (!timePassed);

	time = "";
	if (hourString.length() == 1) time += "0";
	time += hourString;
	time += ":";
	if (minuteString.length() == 1) time += "0";
	time += minuteString;

	//Create Appointment
	patientUser->CreateAppointment(date, time, NULL);
	cout << "Appointment Created on " << time << ", " << date << endl;
	system("pause");
}
void Interface::PatientInterface::DisplayAppointmentUpdate(Patient* patientUser) {
	if (patientUser->GetVisitTime() == "" || patientUser->GetVisitDate() == "") {
		cout << "Currently No Appointment Scheduled." << endl;
	}
	else {
		system("cls");
		cout << "Current Appointment Time and Date: " << patientUser->GetVisitTime() << ", " << patientUser->GetVisitDate() << endl;
		cout << "Update:\n1 - Date\n2 - Time\nOther - Cancel Changes\n > ";

		char answer;
		cin >> answer;
		cin.ignore();

		if (answer == '1') {
			string date;

			bool datePassed = true, dayEntered = false;
			string dayString = "", monthString = "";
			int dayInt = 0, monthInt = 0;

			do {
				datePassed = true;
				dayEntered = false;
				dayString = "";
				monthString = "";
				dayInt = 0;
				monthInt = 0;

				cout << "Enter Intended Visit Date (dd/mm): ";
				getline(cin, date);

				//Get day and month values
				for (int index = 0; index < int(date.length()); index++) {
					if (isdigit(date[index]) && !dayEntered) {
						dayString += date[index];
					}
					else if (isdigit(date[index]) && dayEntered) {
						monthString += date[index];
					}

					if (!isdigit(date[index]) && !dayEntered) dayEntered = true;
					else if (!isdigit(date[index]) && dayEntered) break;
				}
				try {
					dayInt = stoi(dayString);
					monthInt = stoi(monthString);
				}
				catch (...) {
					datePassed = false;
				}

				//Check if date values are valid
				if (monthInt <= 0 || monthInt > 12) datePassed = false;
				if ((monthInt <= 7 && monthInt % 2 == 1) || (monthInt >= 8 && monthInt % 2 == 0)) {
					//31-day month
					if (dayInt <= 0 || dayInt > 31) datePassed = false;
				}
				else if (((monthInt <= 7 && monthInt % 2 == 0) || (monthInt >= 8 && monthInt % 2 == 1)) && monthInt != 2) {
					//30-day month
					if (dayInt <= 0 || dayInt > 30) datePassed = false;
				}
				else if (monthInt == 2) {
					//February = 28-day month (no year included)
					if (dayInt <= 0 || dayInt > 29) datePassed = false;
				}
				else {
					//Invalid Month
					datePassed = false;
				}

				if (!datePassed) {
					cout << "Invalid Date Entered. Please Enter Again. [" << dayString << " and" << monthString << "]" << endl;
				}
			} while (!datePassed);

			date = "";
			if (monthString.length() == 1) date += "0";
			date += monthString;
			date += "/";
			if (dayString.length() == 1) date += "0";
			date += dayString;

			patientUser->SetVisitDate(date);
		}
		else if (answer == '2') {
			string time;

			bool timePassed = true, hourEntered = false;
			string hourString = "", minuteString = "";
			int hourInt = 0, minuteInt = 0;

			do {
				timePassed = true;
				hourEntered = false;
				hourString = "";
				minuteString = "";
				hourInt = 0;
				minuteInt = 0;

				cout << "Enter Intended Visit Time (hh:mm): ";
				getline(cin, time);

				//Get hour and minute values
				for (int index = 0; index < int(time.length()); index++) {
					if (isdigit(time[index]) && !hourEntered) {
						hourString += time[index];
					}
					else if (isdigit(time[index]) && hourEntered) {
						minuteString += time[index];
					}

					if (!isdigit(time[index]) && !hourEntered) hourEntered = true;
					else if (!isdigit(time[index]) && hourEntered) break;
				}
				try {
					hourInt = stoi(hourString);
					minuteInt = stoi(minuteString);
				}
				catch (...) {
					timePassed = false;
				}

				//Check if time values are valid
				if (hourInt < 0 || hourInt >= 24) timePassed = false;
				if (minuteInt < 0 || minuteInt >= 60) timePassed = false;

				if (!timePassed) {
					cout << "Invalid Time Entered. Please Enter Again. [" << hourString << " and" << minuteString << "]" << endl;
				}
			} while (!timePassed);

			time = "";
			if (hourString.length() == 1) time += "0";
			time += hourString;
			time += ":";
			if (minuteString.length() == 1) time += "0";
			time += minuteString;

			patientUser->SetVisitTime(time);
		}
	}
	system("pause");
}
void Interface::PatientInterface::DisplayAppointmentCancel(Patient* patientUser) {
	if (patientUser->GetVisitTime() == "" || patientUser->GetVisitDate() == "") {
		cout << "Currently No Appointment Scheduled." << endl;
	}
	else {
		system("cls");
		cout << "Current Appointment: Meeting at " << patientUser->GetVisitTime() << ", " << patientUser->GetVisitDate() << endl;
		cout << "Are you sure you want to cancel the appointment? [Enter \'Y\' to confirm]: ";

		char answer;
		cin >> answer;
		cin.ignore();

		answer = toupper(answer);
		if (answer == 'Y') {
			patientUser->SetVisitDate("");
			patientUser->SetVisitTime("");
			patientUser->SetAssignedDoctor(NULL);
			patientUser->SetPrescription(NULL);
			cout << "Appointment Cancelled." << endl;
		}
		else {
			cout << "Appointment Still Active." << endl;
		}
	}
	system("pause");
}
void Interface::PatientInterface::DisplayQueueNumber(Patient* patientUser, DoublyLinkedList<Patient>* patientList) {
	if (patientUser->GetVisitDate() == "" || patientUser->GetVisitTime() == "") {
		cout << "No Appointment Scheduled." << endl;
		system("pause");
		return;
	}

	DoublyLinkedList<Patient>* sameDayPatients = patientList
		->SearchByRegex(patientUser->GetVisitDate(), AttributeValues::Patient::VisitDate)
		->Sort(AttributeValues::Patient::VisitTime);
	cout << "Total patients on same date: " << sameDayPatients->GetLength() << endl;
	for (int i = 0; i < sameDayPatients->GetLength(); i++) {
		if (sameDayPatients->Get(i).GetPatientID() == patientUser->GetPatientID()) {
			cout << "Queue Number " << i + 1 << endl;
			system("pause");
			return;
		}
	}
	cout << "ERROR DISPLAY_QUEUE_NUMBER: No matching patient ID found." << endl;
	system("pause");
	return;
}
void Interface::PatientInterface::DisplayCurrentDetails(Patient* patientUser) {
	system("cls");
	patientUser->DisplayDetails();
	system("pause");
}