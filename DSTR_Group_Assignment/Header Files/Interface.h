#pragma once
#include "AttributeValues.h"
#include "Appointment.h"
#include "LinkedList.h"
#include "Patient.h"
#include "Doctor.h"
#include "Nurse.h"
#include <string>


class Interface {
public:	
	class General {
	public:
		static void PrintLine(char symbol, int length);
	};
	class UserInterface {
	public:
		static void DisplayStartupPage();
		static std::string DisplayLoginPage();
		static std::string DisplayRegisterPage();
		static void DisplayExitPage();
	};
	class DoctorInterface {
	public:
		static void DisplayMainMenu(DoublyLinkedList<Patient>* patientList, DoublyLinkedList<Patient>* visitedPatientList, Doctor* currentDoctor);
	};
	class NurseInterface {
	public:
		static void DisplayMainMenu(DoublyLinkedList<Patient>* tempPatient, DoublyLinkedList<User>* tempUser, DoublyLinkedList<Patient>* visitedPatientList);
	};
	class PatientInterface {
	public:
		static void DisplayMainMenu(DoublyLinkedList<Patient>* tempPatient, DoublyLinkedList<Doctor>* tempDoctor);
		static void DisplaySortPatients();
		static void DisplaySearchPatients();
	};
	class Validator {
	public:
		static bool isEmptyString(string item);
	};
};