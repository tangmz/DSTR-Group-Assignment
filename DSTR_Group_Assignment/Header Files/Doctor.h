#pragma once
#include "Patient.h"
#include "LinkedList.h"
#include <iostream>
#include <string>
using namespace std;

class Doctor : User {
private:
	string DoctorID;
	string Status;
public:
	string GetDoctorID() { return DoctorID; }
	string GetStatus() { return Status; }

	void viewAllPatients(DoublyLinkedList<Patient> *p);
	void searchPatientsbyName(Patient target);
	void searchPatientsbyIllness(string illness);
	void modifyPatientRecord(Patient newPatient);
	void sortPatientsbyVisit();

	//Optional
	void notifyNurse();
	void sortPatients(string criteria); //sort by name, id, disability, assigned doctor, or prescription
};