#pragma once
#include "User.h"
#include <iostream>
#include <string>
using namespace std;

class Nurse : User {
private:
	string NurseID;
public:
	string GetNurseID() { return NurseID; }

	void addPatientToList();
	void viewAllPatient();
	void searchPatient(Patient target);
	void sortRecord();
	void changePatientPriority(Patient newPatient, int priority);
	void notiifyNextPatient(Patient nextPatient);
	void collectPayment(int total);
};