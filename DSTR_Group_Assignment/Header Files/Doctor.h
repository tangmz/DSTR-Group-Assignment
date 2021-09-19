#pragma once
#include "Patient.h"
#include "User.h"
#include <iostream>
#include <string>
using namespace std;

class Patient;
class Doctor : User {
private:
	string DoctorID;
	string Status;
public:
	string GetDoctorID() { return DoctorID; }
	string GetStatus() { return Status; }

	void viewAllPatient();
	void searchPatientbyName(Patient target);
	void searchPatientbyIllness(string illness);
	void modifyPatientRecord(Patient newPatient);
	void sortPatientbyVisit();

	//Optional
	void notifyNurse();
	void sortPatient(string criteria); //sort by name, id, disability, assigned doctor, or prescription
};