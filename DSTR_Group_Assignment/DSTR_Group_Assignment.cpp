#pragma once
//#include "Header Files/Appointment.h"
#include "Header Files/Doctor.h"
#include "Header Files/LinkedList.h"
#include "Header Files/Medicine.h"
#include "Header Files/Nurse.h"
#include "Header Files/Patient.h"
#include "Header Files/Testing.h"
#include "Header Files/User.h"
#include "Header Files/Interface.h"
#include "Header Files/SampleData.h"
#include "Header Files/ApplicationLists.h"
using namespace std;

void skipLogin() {
	int answer = -1;
	do {
		system("cls");
		cout << "1 - Doctor Main Menu\n2 - Nurse Main Menu\n3 - Patient Main Menu\n4 - Exit\n > ";
		cin >> answer;
		cin.ignore();
		switch (answer) {
		case 1:
			Interface::DoctorInterface::DisplayMainMenu(ApplicationLists::Patients, ApplicationLists::VisitedPatients, ApplicationLists::CurrentLoginDoctor);
			break;
		case 2:
			Interface::NurseInterface::DisplayMainMenu(ApplicationLists::Patients, ApplicationLists::Users, ApplicationLists::VisitedPatients);
			break;
		case 3:
			Interface::PatientInterface::DisplayMainMenu(ApplicationLists::CurrentLoginPatient, ApplicationLists::Patients, ApplicationLists::Doctors);
			break;
		case 4:
		default:
			break;
		}
	} while (answer != 4);
}

void addOwnSampleData() {
	Doctor d1 = Doctor("Doktah", "UserID", "Fname", "lname", 21, 'M', "123", "mail", "addr", "pass", "IC");
	Nurse n1 = Nurse("Nurse", "UseID", "NFname", "NLname", 1, 'F', "0123", "mail", "addr", "pass", "ic");
	Patient p1 = Patient("Patient", "UserID", "PFname", "PLname", 2, 'M', "phone", "mail", "addr", "pass", "ic", "illness", "visitD", "visitT");
	ApplicationLists::Doctors->AddToEnd(d1);
	ApplicationLists::Nurses->AddToEnd(n1);
	ApplicationLists::Patients->AddToEnd(p1);
}

int main() {
	//Quick access to main menu interfaces
	//skipLogin();

	srand(unsigned(time(NULL)));
	AddPatients(ApplicationLists::Users, ApplicationLists::Patients, 150, 18, 21);
	AddDoctors(ApplicationLists::Users, ApplicationLists::Doctors, 10, 25, 30);
	AddNurses(ApplicationLists::Users, ApplicationLists::Nurses, 25, 23, 30);
	AddDrugs(ApplicationLists::Medicines, 50, 1, 60);

	ApplicationLists::CurrentLoginPatient = ApplicationLists::Patients->GetReference(0);
	ApplicationLists::CurrentLoginDoctor = ApplicationLists::Doctors->GetReference(0);
	ApplicationLists::CurrentLoginNurse = ApplicationLists::Nurses->GetReference(0);

	//ApplicationLists::Medicines->DisplayPages(15);
	addOwnSampleData();

	string role = "";
	while (role != "Invalid") {
		system("cls");
		Interface::UserInterface::DisplayStartupPage();
		role = Interface::UserInterface::DisplayLoginPage(ApplicationLists::Doctors, ApplicationLists::Nurses, ApplicationLists::Patients,
			ApplicationLists::CurrentLoginDoctor, ApplicationLists::CurrentLoginNurse, ApplicationLists::CurrentLoginPatient);

		if (role == "Invalid") {
			break; //Change to system exit later
		}
		else if (role == "Register") {
			Interface::UserInterface::DisplayRegisterPage(ApplicationLists::Users, ApplicationLists::Doctors, ApplicationLists::Nurses);
		}
		else if (role == "Doctor") {
			Interface::DoctorInterface::DisplayMainMenu(ApplicationLists::Patients, ApplicationLists::VisitedPatients, ApplicationLists::CurrentLoginDoctor);
		}
		else if (role == "Nurse") {
			Interface::NurseInterface::DisplayMainMenu(ApplicationLists::Patients, ApplicationLists::Users, ApplicationLists::VisitedPatients);
		}
		else if (role == "Patient") {
			Interface::PatientInterface::DisplayMainMenu(ApplicationLists::CurrentLoginPatient, ApplicationLists::Patients, ApplicationLists::Doctors);
		}
	}

	
	
	return 0;
}

