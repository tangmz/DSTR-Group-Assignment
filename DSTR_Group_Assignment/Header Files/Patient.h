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
	Patient(string patientID, string id, string firstName, string lastName, int age, char gender, string phone, string email, string address) {
		PatientID = patientID;
		ID = id;
		FirstName = firstName;
		LastName = lastName;
		Age = age;
		Gender = gender;
		Phone = phone;
		Email = email;
		Address = address;

		Illness = "";
		VisitDate = "";
		VisitTime = "";
		Disability = "";
		AssignedDoctor = NULL;
		Prescription = NULL;
		Note = "";
	}
	Patient(string id, string firstName, string lastName, int age, char gender, string phone, string email, string address) :
		Patient(GeneratePatientID(), id, firstName, lastName, age, generate, phone, email, address) {

	}
	Patient(string firstName, string lastName, int age, char gender, string phone, string email, string address) :
		Patient(User::GenerateID(), firstName, lastName, age, gender, phone, email, address) {

	}
	Patient(string firstName, string lastName) : Patient(firstName, lastName, "", ' ', "", "", "") {

	}

	string GetPatientID() { return PatientID; }
	string GetIllness() { return Illness; }
	string GetVisitDate() { return VisitDate; }
	string GetVisitTime() { return VisitTime; }
	string GetDisability() { return Disability; }
	Doctor* GetAssignedDoctor() { return AssignedDoctor; }
	Medicine* GetPrescription() { return Prescription; }
	string GetNote() { return Note; }

	void SetIllness(string illness) { Illness = illness; }
	void SetNote(string note) { Note = note; }
	void SetPrescription(Medicine* medicine) { Prescription = medicine; }

	string GeneratePatientID();
	void CreateAppointment(string date, string time, Doctor doctor);
	void UpdateAppointmentDate(string newDate);
	void UpdateAppointmentTime(string newTime);
	void UpdateAppointmentDoctor(Doctor newDoctor);
	void UpdateAppointmentPayment(bool newStatus);
	void CancelAppointment();
	int GetQueueNumber();

	void DisplayAppointments();
};