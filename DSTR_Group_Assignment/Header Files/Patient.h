#pragma once
#include "Doctor.h"
//#include "Nurse.h"
#include "Medicine.h"
#include "User.h"
#include <iostream>
#include <string>
using namespace std;

class Patient : public User {
private:
	string PatientID;
	string Illness;
	string VisitDate;
	string VisitTime;
	string Disability;
	Doctor AssignedDoctor;
	Medicine* Prescription;
	string Note;
	bool isPaid;
public:
	Patient(string patientID, string id, string firstName, string lastName, int age, char gender,
		string phone, string email, string address, string password, string ic, string illness, string visitDate, string visitTime) {
		PatientID = patientID;
		ID = id;
		FirstName = firstName;
		LastName = lastName;
		Age = age;
		Gender = gender;
		Phone = phone;
		Email = email;
		Address = address;
		Password = password;
		IC = ic;

		Illness = illness;
		VisitDate = visitDate;
		VisitTime = visitTime;
		Disability = "";
		//AssignedDoctor = NULL;
		Prescription = NULL;
		Note = "";
		isPaid = false;
	}
	Patient() {

	}

	string GetPatientID() { return PatientID; }
	string GetIllness() { return Illness; }
	string GetVisitDate() { return VisitDate; }
	string GetVisitTime() { return VisitTime; }
	string GetDisability() { return Disability; }
	Doctor GetAssignedDoctor() { return AssignedDoctor; }
	Medicine* GetPrescription() { return Prescription; }
	string GetNote() { return Note; }
	bool GetPaid() { return isPaid; }

	void SetIllness(string illness) { Illness = illness; }
	void SetVisitDate(string visitDate) { VisitDate = visitDate; }
	void SetVisitTime(string visitTime) { VisitTime = visitTime; }
	void SetDisability(string disability) { Disability = disability; }
	void SetAssignedDoctor(Doctor doctor) { AssignedDoctor = doctor; }
	void SetPrescription(Medicine* medicine) { Prescription = medicine; }
	void SetPrescriptionName(string mediName) { 
		if (this->Prescription == NULL) {
			this->Prescription = new Medicine;
		}
		Prescription->SetName(mediName); 
	}
	void SetNote(string note) { Note = note; }
	void SetPaid(bool item) { isPaid = item; }

	bool Equals(Patient nextPatient);
	int CompareTo(Patient nextPatient, int attributeValue);
	bool MatchesRegex(string regExp, int attributeValue);
	void DisplayTableHeader(int startIndex, int tableLength);
	void DisplayTableRow(int startIndex, int index, int tableLength);
	void DisplayDetails();

	static string GeneratePatientID(int n);
	void CreateAppointment(string date, string time, Doctor* doctor);
	void UpdateAppointmentDate(DoublyLinkedList<Patient>* patientList, string newDate);
	void UpdateAppointmentTime(DoublyLinkedList<Patient>* patientList, string newTime);
	void UpdateAppointmentDoctor(string appointmentID, Doctor* newDoctor);
	int GetQueueNumber(DoublyLinkedList<Patient>* patientList);

	//Interface
	static void AddPatientToList(DoublyLinkedList<Patient>* patientList, Patient newPatient);
	static void ViewAllPatients(DoublyLinkedList<Patient>* patientList);
	static DoublyLinkedList<Patient>* SearchPatient(DoublyLinkedList<Patient>* patientList, string regExp, int attributeValue);
	static void SortRecords(DoublyLinkedList<Patient>* patientList, int attributeValue);
	static void ChangePatientPriority(DoublyLinkedList<Patient>* patientList, Patient targetPatient);
	static void NotifyNextPatient(DoublyLinkedList<Patient>* patientList, int nextPatientIndex);
	static void CollectPayment(DoublyLinkedList<Patient>* patientList, Patient targetPatient);
	static void ModifyPatientRecord(DoublyLinkedList<Patient>* patientList, DoublyLinkedList<Patient>* visitedPatientList);
	//static void DisplayMainMenu();
	//static void DisplaySortPatients();
	//static void DisplaySearchPatients();
};

//DoublyLinkedList<User>* Users;
//DoublyLinkedList<Doctor>* Doctors;
//DoublyLinkedList<Medicine>* Medicines;
//DoublyLinkedList<Nurse>* Nurses;
//DoublyLinkedList<Patient>* Patients;

