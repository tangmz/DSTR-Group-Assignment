#include "../Header Files/Doctor.h"
#include "../Header Files/LinkedList.h"
#include "../Header Files/Patient.h"
#include "../Header Files/User.h"
#include <iostream>
using namespace std;

void Doctor::viewAllPatients(DoublyLinkedList<Patient> *p) {
	/*
	for (int i = 0; i < p->GetLength(); i++) {
		Patient p1 = p->Get(i);
		cout << p1.GetFirstName() << " : " << p1.GetLastName() << endl;
	}
	*/
}
void Doctor::searchPatientsbyName(Patient target) {

}
void Doctor::searchPatientsbyIllness(string illness) {

}
void Doctor::modifyPatientRecord(Patient newPatient) {

}
void Doctor::sortPatientsbyVisit() {

}

//Interface
void PrintLine(char symbol, int length) {
	for (int i = 0; i < length; i++) {
		cout << symbol;
	}
	cout << endl;
}

void Doctor::DisplayMainMenu(){
	int decision = -1;
	while (decision != 0) {
		system("CLS");
		PrintLine('=', 70);
		cout << "Logged in as: Doctor" << endl;
		PrintLine('=', 70);
		cout << "Available Option: " << endl;
		cout << "1. View All Patients" << endl;
		cout << "2. Search Patient by Name" << endl;
		cout << "3. Search Patient by Illness" << endl;
		cout << "4. Modify Patient's Record" << endl;
		cout << "5. View Patient Based On Visiting Order" << endl;
		cout << "6. Notify Nurse" << endl;
		cout << "7. View Sorted List of Patient" << endl;
		cout << "0. Logout" << endl;
		PrintLine('-', 70);
		cout << "Select Option: ";
		cin >> decision;
		cin.ignore();

		switch (decision)
		{
			case 1:
				//View all patient

				break;
			case 2:
				//Search by name
				break;
			case 3:
				//Search by illness
				break;
			case 4:
				//Modify patient record
				//Let user choose which patient first
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
