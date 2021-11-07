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

int main() {
	//Storage for current active users
	static Doctor* currentDoctor;

	srand(unsigned(time(NULL)));
	AddPatients(ApplicationLists::Users, ApplicationLists::Patients, 150, 18, 21);
	AddDoctors(ApplicationLists::Users, ApplicationLists::Doctors, 10, 25, 30);
	AddNurses(ApplicationLists::Users, ApplicationLists::Nurses, 25, 23, 30);
	AddDrugs(ApplicationLists::Medicines, 50, 1, 60);

	ApplicationLists::CurrentLoginPatient = ApplicationLists::Patients->GetReference(0);
	ApplicationLists::CurrentLoginDoctor = ApplicationLists::Doctors->GetReference(0);
	ApplicationLists::CurrentLoginNurse = ApplicationLists::Nurses->GetReference(0);
	currentDoctor = ApplicationLists::Doctors->GetReference(0);
	cout << ApplicationLists::Doctors->GetReference(0)->GetFirstName() << endl;
	currentDoctor->setIsAvailable(true);

	ApplicationLists::Medicines->DisplayPages(15);

	//TEMPORARY: Quick access to main menu interfaces
	int answer = -1;
	do {
		system("cls");
		cout << "1 - Doctor Main Menu\n2 - Nurse Main Menu\n3 - Patient Main Menu\n4 - Exit\n > ";
		cin >> answer;
		cin.ignore();
		switch (answer) {
			case 1:
				Interface::DoctorInterface::DisplayMainMenu(ApplicationLists::Patients, ApplicationLists::VisitedPatients);
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
	return 0;
}