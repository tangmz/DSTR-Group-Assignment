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
	int Priority;
public:
	Patient(string patientID, string id, string firstName, string lastName, int age, char gender, string phone, string email, string address, string ic, int priority) {
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
	int GetPriority() { return Priority; }

	void SetIllness(string illness) { Illness = illness; }
	void SetVisitDate(string visitDate) { VisitDate = visitDate; }
	void SetVisitTime(string visitTime) { VisitTime = visitTime; }
	void SetDisability(string disability) { Disability = disability; }
	void SetAssignedDoctor(Doctor* doctor) { AssignedDoctor = doctor; }
	void SetPrescription(Medicine* medicine) { Prescription = medicine; }
	void SetNote(string note) { Note = note; }

	bool Equals(Patient nextPatient);
	int CompareTo(Patient nextPatient, int attributeValue);
	bool MatchesRegex(string regExp, int attributeValue);

	string GeneratePatientID(int n);
	void CreateAppointment(string date, string time, Doctor* doctor);
	void UpdateAppointmentDate(string appointmentID, string newDate);
	void UpdateAppointmentTime(string appointmentID, string newTime);
	void UpdateAppointmentDoctor(string appointmentID, Doctor* newDoctor);
	int GetQueueNumber(DoublyLinkedList<Patient>* patientList);

	//Interface
	static void AddPatientToList(DoublyLinkedList<Patient>* patientList, Patient newPatient);
	static void ViewAllPatients(DoublyLinkedList<Patient>* patientList);
	static void SearchPatient(DoublyLinkedList<Patient>* patientList, string regExp, int attributeValue);
	static void SortRecords(DoublyLinkedList<Patient>* patientList, int attributeValue);
	static void ChangePatientPriority(DoublyLinkedList<Patient>* patientList, Patient targetPatient);
	static void NotifyNextPatient(DoublyLinkedList<Patient>* patientList, int nextPatientIndex);
	static void CollectPayment(DoublyLinkedList<Patient>* patientList, Patient targetPatient);
	static void ModifyPatientRecord(DoublyLinkedList<Patient>* patientList, Patient targetPatient);
};