#pragma once
#include "AttributeValues.h"
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
		static void DisplayMainMenu(DoublyLinkedList<Patient>* patientList, DoublyLinkedList<Patient>* visitedPatientList);
	};
	class NurseInterface {
	public:
		static void DisplayMainMenu(DoublyLinkedList<Patient>* tempPatient, DoublyLinkedList<User>* tempUser);
	};
	class PatientInterface {
	public:
		static void DisplayMainMenu();
		static void DisplaySortPatients();
		static void DisplaySearchPatients();
	};
};