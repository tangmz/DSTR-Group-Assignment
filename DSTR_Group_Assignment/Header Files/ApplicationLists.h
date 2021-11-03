#pragma once
#include "Appointment.h"
#include "Doctor.h"
#include "LinkedList.h"
#include "Medicine.h"
#include "Nurse.h"
#include "Patient.h"
using namespace std;

class ApplicationLists {
public:
	static DoublyLinkedList<Patient>* Patients;
	static DoublyLinkedList<Doctor>* Doctors;
	static DoublyLinkedList<Nurse>* Nurses;
	static DoublyLinkedList<Appointment>* Appointments;
	static DoublyLinkedList<Medicine>* Medicines;
};

DoublyLinkedList<Appointment>* ApplicationLists::Appointments = new DoublyLinkedList<Appointment>();
DoublyLinkedList<Doctor>* ApplicationLists::Doctors = new DoublyLinkedList<Doctor>();
DoublyLinkedList<Medicine>* ApplicationLists::Medicines = new DoublyLinkedList<Medicine>();
DoublyLinkedList<Nurse>* ApplicationLists::Nurses = new DoublyLinkedList<Nurse>();
DoublyLinkedList<Patient>* ApplicationLists::Patients = new DoublyLinkedList<Patient>();