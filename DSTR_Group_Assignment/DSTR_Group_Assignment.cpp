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
	srand(unsigned(time(NULL)));
	/*
	Doctor d = Doctor();
	int id = 0;
	for (int i = 0; i < 5; i++) {
		string idS = "P-00" + id;
		Patient p = Patient(idS, "Jeanne", "D'Arc", 500, 'F', "012-3456789", "", "address");
		patients->AddToEnd(p);
	}

	d.viewAllPatients(patients);
	*/
	AddPatients(ApplicationLists::Users, ApplicationLists::Patients, 150, 1, 90);
	AddDoctors(ApplicationLists::Users, ApplicationLists::Doctors, 10, 25, 60);
	AddNurses(ApplicationLists::Users, ApplicationLists::Nurses, 25, 23, 60);

	ApplicationLists::Users->DisplayPages(30);
	ApplicationLists::Patients->DisplayPages(25);
	ApplicationLists::Doctors->DisplayPages(8);
	ApplicationLists::Nurses->DisplayPages(15);

	//int *i = new int;
	//*i = 5;

	//cout << i << endl;
	//cout << *i << endl;
	//cout << &i << endl;

	//AddUsers(ApplicationLists::Users, 5, 1, 99);
	//AddPatients(ApplicationLists::Users, ApplicationLists::Patients, 15, 18, 21);
	//AddUsers(ApplicationLists::Users, 5, 1, 99);
	//Interface::DoctorInterface::DisplayMainMenu(ApplicationLists::Patients);

	AddUsers(ApplicationLists::Users, 50000, 10, 21);
	//".*Adam.*" = Adam1, 1Adam, Adam, 1Adam2
	//"Adam" = Adam ONLY
	//ApplicationLists::Users->SearchByRegex(".*e{2}.*", AttributeValues::User::FirstName)->Sort(AttributeValues::User::Age)->DisplayPages(25);
	/*ApplicationLists::Users->DisplayPages(10);*/
	ApplicationLists::Users
		->Sort(AttributeValues::User::LastName)
		->Sort(AttributeValues::User::FirstName)
		->Sort(AttributeValues::User::Age)
		->Sort(AttributeValues::User::Gender)
		->DisplayPages(100);
	///*ApplicationLists::Users
	//	->Sort(AttributeValues::User::LastName)
	//	->Sort(AttributeValues::User::FirstName)
	//	->Sort(AttributeValues::User::Gender)
	//	->Sort(AttributeValues::User::Age)
	//	->DisplayPages(100);*/

	//Interface::UserInterface::DisplayLoginPage();
	return 0;
}