#pragma once
#include "User.h"
#include <iostream>
#include <string>
using namespace std;

class Nurse : User {
private:
	string NurseID;
public:
	Nurse(string nurseID, string userID, string firstName, string lastName, int age, char gender,
		string phone, string email, string address, string password, string ic) {
		NurseID = nurseID;
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
	}
	Nurse() {

	}

	string GetNurseID() { return NurseID; }

	bool Equals(Nurse nextNurse);
	int CompareTo(Nurse nextNurse, int attributeValue);
	bool MatchesRegex(string regExp, int attributeValue);
	void DisplayTableHeader(int startIndex, int tableLength);
	void DisplayTableRow(int startIndex, int index, int tableLength);
	void DisplayDetails();

	static string GenerateNurseID(int n);
	void addPatientToList();
	void viewAllPatient();
	//void searchPatient(Patient target);
	//void sortRecord();
	//void changePatientPriority(Patient newPatient, int priority);
	//void notiifyNextPatient(Patient nextPatient);
	void collectPayment(int total);

	//Interface
	static void DisplayMainMenu();
};