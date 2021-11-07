#pragma once
//#include "Appointment.h"
#include "Doctor.h"
#include "LinkedList.h"
#include "Medicine.h"
#include "Nurse.h"
#include "Patient.h"
#include "User.h"
using namespace std;

class ApplicationLists {
public:
	static Patient* CurrentLoginPatient;
	static Doctor* CurrentLoginDoctor;
	static Nurse* CurrentLoginNurse;

	static DoublyLinkedList<Patient>* Patients;
	static DoublyLinkedList<Patient>* VisitedPatients;
	static DoublyLinkedList<Doctor>* Doctors;
	static DoublyLinkedList<Nurse>* Nurses;
	//static DoublyLinkedList<Appointment>* Appointments;
	static DoublyLinkedList<Medicine>* Medicines;
	static DoublyLinkedList<User>* Users;
};

//DoublyLinkedList<Appointment>* ApplicationLists::Appointments = new DoublyLinkedList<Appointment>();
Patient* ApplicationLists::CurrentLoginPatient = new Patient();
Doctor* ApplicationLists::CurrentLoginDoctor = new Doctor();
Nurse* ApplicationLists::CurrentLoginNurse = new Nurse();

DoublyLinkedList<User>* ApplicationLists::Users = new DoublyLinkedList<User>();
DoublyLinkedList<Doctor>* ApplicationLists::Doctors = new DoublyLinkedList<Doctor>();
DoublyLinkedList<Medicine>* ApplicationLists::Medicines = new DoublyLinkedList<Medicine>();
DoublyLinkedList<Nurse>* ApplicationLists::Nurses = new DoublyLinkedList<Nurse>();
DoublyLinkedList<Patient>* ApplicationLists::Patients = new DoublyLinkedList<Patient>();
DoublyLinkedList<Patient>* ApplicationLists::VisitedPatients = new DoublyLinkedList<Patient>();