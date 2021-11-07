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

	currentDoctor = ApplicationLists::Doctors->GetReference(0);
	cout << ApplicationLists::Doctors->GetReference(0)->GetFirstName() << endl;
	currentDoctor->setIsAvailable(true);

	ApplicationLists::Medicines->DisplayPages(15);

	Interface::DoctorInterface::DisplayMainMenu(ApplicationLists::Patients, ApplicationLists::VisitedPatients, currentDoctor);

	return 0;
}