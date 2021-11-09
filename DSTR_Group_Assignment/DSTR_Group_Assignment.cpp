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
			Interface::NurseInterface::DisplayMainMenu(ApplicationLists::Patients, ApplicationLists::Users, ApplicationLists::VisitedPatients,ApplicationLists::Doctors);
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
	Doctor d1 = Doctor(Doctor::GenerateDoctorID(ApplicationLists::Doctors->GetLength() + 1),
		User::GenerateID(ApplicationLists::Users->GetLength() + 1),
		"John", "Smith", 21, 'M', "123", "mail", "addr", "pass", "010203040506");
	Nurse n1 = Nurse(Nurse::GenerateNurseID(ApplicationLists::Nurses->GetLength() + 1),
		User::GenerateID(ApplicationLists::Users->GetLength() + 1),
		"Jessie", "Carl", 1, 'F', "0123", "mail", "addr", "pass", "020304050607");
	Patient p1 = Patient(Patient::GeneratePatientID(ApplicationLists::Patients->GetLength() + 1),
		User::GenerateID(ApplicationLists::Users->GetLength() + 1),
		"Momi", "Poko", 2, 'M', "phone", "mail", "addr", "pass", "030405060708", "Injury", "visitD", "visitT");
	Medicine m1 = Medicine(Medicine::GenerateMedicineID(ApplicationLists::Medicines->GetLength() + 1),
		"Paracetamol", "01/01", 12.0, "None");
	ApplicationLists::Users->AddToEnd(d1);
	ApplicationLists::Users->AddToEnd(n1);
	ApplicationLists::Users->AddToEnd(p1);
	ApplicationLists::Doctors->AddToEnd(d1);
	ApplicationLists::Nurses->AddToEnd(n1);
	ApplicationLists::Patients->AddToEnd(p1);
	ApplicationLists::Medicines->AddToEnd(m1);
}

int main() {
	//Quick access to main menu interfaces
	//skipLogin();

	srand(unsigned(time(NULL)));
	addOwnSampleData();
	//AddPatients(ApplicationLists::Users, ApplicationLists::Patients, 150, 18, 21);
	//AddDoctors(ApplicationLists::Users, ApplicationLists::Doctors, 10, 25, 30);
	//AddNurses(ApplicationLists::Users, ApplicationLists::Nurses, 25, 23, 30);
	//AddDrugs(ApplicationLists::Medicines, 50, 1, 60);

	ApplicationLists::CurrentLoginPatient = ApplicationLists::Patients->GetReference(0);
	ApplicationLists::CurrentLoginDoctor = ApplicationLists::Doctors->GetReference(0);
	ApplicationLists::CurrentLoginNurse = ApplicationLists::Nurses->GetReference(0);

	//ApplicationLists::Medicines->DisplayPages(15);

	string role = "";
	while (role != "Invalid") {
		system("cls");
		role = Interface::UserInterface::DisplayLoginPage(ApplicationLists::Doctors, ApplicationLists::Nurses,
			ApplicationLists::Patients->combineList(ApplicationLists::VisitedPatients),
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
			Interface::NurseInterface::DisplayMainMenu(ApplicationLists::Patients, ApplicationLists::Users, ApplicationLists::VisitedPatients, ApplicationLists::Doctors);
		}
		else if (role == "Patient") {
			Interface::PatientInterface::DisplayMainMenu(ApplicationLists::CurrentLoginPatient,
				ApplicationLists::Patients->combineList(ApplicationLists::VisitedPatients), ApplicationLists::Doctors);
		}
	}

	
	
	return 0;
}

