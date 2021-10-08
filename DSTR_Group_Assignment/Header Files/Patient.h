#pragma once
#include "Doctor.h"
#include "Medicine.h"
#include "User.h"
#include <iostream>
#include <string>
using namespace std;

class Doctor;
class Patient : public User {
private:
	string PatientID;
	string Illness;
	string VisitDate;
	string VisitTime;
	string Disability;
	Doctor* AssignedDoctor;
	Medicine* Prescription;
	string Note;
public:
	Patient(string id, string firstName, string lastName, int age, char gender, string phone, string email, string address) {
		ID = id;
		FirstName = firstName;
		LastName = lastName;
		Age = age;
		Gender = gender;
		Phone = phone;
		Email = email;
		Address = address;
	}
	Patient(string firstName, string lastName, string illness) {
		FirstName = firstName;
		LastName = lastName;
		Illness = illness;
	}
	Patient(string firstName, string lastName) : Patient(firstName, lastName, "") {

	}
	Patient() : Patient("", "", "") {

	}

	string GetPatientID() { return PatientID; }
	string GetIllness() { return Illness; }
	string GetVisitDate() { return VisitDate; }
	string GetVisitTime() { return VisitTime; }
	string GetDisability() { return Disability; }
	Doctor* GetAssignedDoctor() { return AssignedDoctor; }
	Medicine* GetPrescription() { return Prescription; }
	string GetNote() { return Note; }

	void CreateAppointment();
	void UpdateAppointmentDate(string newDate);
	void UpdateAppointmentTime(string newTime);
	void UpdateAppointmentDoctor(Doctor newDoctor);
	void UpdateAppointmentPayment(bool newStatus);
	void CancelAppointment();
	int GetQueueNumber();
};