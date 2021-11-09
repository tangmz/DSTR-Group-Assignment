#pragma once
#include "User.h"
#include "LinkedList.h"
#include <iostream>
#include <string>
using namespace std;

class Doctor : public User {
private:
	string DoctorID;
	bool isAvailable;
public:
	Doctor(string doctorID, string userID, string firstName, string lastName, int age, char gender,
		string phone, string email, string address, string password, string ic) {
		DoctorID = doctorID;
		ID = userID;
		FirstName = firstName;
		LastName = lastName;
		Age = age;
		Gender = gender;
		Phone = phone;
		Email = email;
		Address = address;
		Password = password;
		IC = ic;
		isAvailable = true;
	}
	Doctor() {

	}

	string GetDoctorID() { return DoctorID; }

	bool Equals(Doctor nextDoctor);
	int CompareTo(Doctor nextDoctor, int attributeValue);
	bool MatchesRegex(string regExp, int attributeValue);
	void DisplayTableHeader(int startIndex, int tableLength);
	void DisplayTableRow(int startIndex, int index, int tableLength);
	void DisplayDetails();

	//void viewAllPatients(DoublyLinkedList<Patient> *p);
	//void searchPatientsbyName(Patient target);
	//void searchPatientsbyIllness(string illness);
	//void modifyPatientRecord(Patient newPatient);
	static string GenerateDoctorID(int n);
	void sortPatientsbyVisit();
	void setIsAvailable(bool available) {
		this->isAvailable = available;
	}
	bool getIsAvailable(){
		return isAvailable;
	}

	//Optional
	void notifyNurse();
	

	//Interface
	static void DisplayMainMenu();
	static int sortPatientsDecision(); //sort by name, id, disability, assigned doctor, or prescription
};