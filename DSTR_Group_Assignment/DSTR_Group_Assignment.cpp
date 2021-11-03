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

	//DoublyLinkedList<User>* users = new DoublyLinkedList<User>();
	//ApplicationLists::Users->Sort(AttributeValues::User::FirstName)->DisplayPages(20);

	//int *i = new int;
	//*i = 5;

	//cout << i << endl;
	//cout << *i << endl;
	//cout << &i << endl;

	AddUsers(ApplicationLists::Users, 10, 1, 99);
	AddPatients(ApplicationLists::Users, ApplicationLists::Patients, 100, 18, 21);
	AddUsers(ApplicationLists::Users, 10, 1, 99);
	Interface::DoctorInterface::DisplayMainMenu(ApplicationLists::Patients);

	return 0;
}