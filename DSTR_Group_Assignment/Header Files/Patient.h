#pragma once
#include "Doctor.h"
#include "Medicine.h"
#include "User.h"
#include <iostream>
#include <string>
using namespace std;

class Doctor;
class Patient : User {
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
	Patient() {

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

	bool Equals(Patient nextPatient);
	int CompareTo(Patient nextPatient, int attributeValue);
	bool MatchesRegex(string regExp, int attributeValue);

	string GeneratePatientID(int n);
	void CreateAppointment(string date, string time, Doctor doctor);
	void UpdateAppointmentDate(string appointmentID, string newDate);
	void UpdateAppointmentTime(string appointmentID, string newTime);
	void UpdateAppointmentDoctor(string appointmentID, Doctor newDoctor);
	void UpdateAppointmentPayment(string appointmentID, bool newStatus);
	void CancelAppointment(string appointmentID);
	int GetQueueNumber(string appointmentID);

	void DisplayAppointments();

	//Interface
	static void DisplayMainMenu();
	static void DisplaySortPatients();
	static void DisplaySearchPatients();
};