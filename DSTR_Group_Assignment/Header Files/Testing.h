#pragma once
#include "ApplicationLists.h"
#include "Appointment.h"
#include "Doctor.h"
//#include "Interface.h"
#include "LinkedList.h"
#include "Medicine.h"
#include "Nurse.h"
#include "Patient.h"
#include "SampleData.h"
#include "User.h"
#include <iostream>
using namespace std;

void AddUsers(DoublyLinkedList<User>* users, int n = 100, int minAge = 20, int maxAge = 60) {
	DoublyLinkedList<string>* NameList = LoadNames();
	for (int i = 0; i < n; i++) {
		cout << "Adding User: " << i << endl;
		users->AddToEnd(User(
			User::GenerateID(ApplicationLists::Users->GetLength() + 1),
			GetRandomName(NameList),
			GetRandomName(NameList),
			rand() % (maxAge - minAge + 1) + minAge,
			GetRandomGender(),
			GetRandomPhone(),
			GetRandomName(NameList),
			GetRandomName(NameList),
			GetRandomPhone()
		));
	}
}
void AddPatients(DoublyLinkedList<User>* users, DoublyLinkedList<Patient>* patients, int n = 100, int minAge = 20, int maxAge = 60) {
	DoublyLinkedList<string>* NameList = LoadNames();
	for (int i = 0; i < n; i++) {
		cout << "Adding User: " << i << endl;
		User newUser = User(
			User::GenerateID(ApplicationLists::Users->GetLength() + 1),
			GetRandomName(NameList),
			GetRandomName(NameList),
			rand() % (maxAge - minAge + 1) + minAge,
			GetRandomGender(),
			GetRandomPhone(),
			GetRandomName(NameList),
			GetRandomName(NameList),
			GetRandomPhone()
		);
		Patient newPatient = Patient(
			Patient::GeneratePatientID(ApplicationLists::Patients->GetLength() + 1),
			newUser.GetID(),
			newUser.GetFirstName(),
			newUser.GetLastName(),
			newUser.GetAge(),
			newUser.GetGender(),
			newUser.GetPhone(),
			newUser.GetEmail(),
			newUser.GetAddress(),
			newUser.GetIC(),
			rand() % (maxAge - minAge + 1) + minAge
		);
		//Parent* p2 = (Child*)pChild;
		users->AddToEnd(newUser);
		patients->AddToEnd(newPatient);
	}
}
void DeleteUsers(DoublyLinkedList<User>* users) {
	users->PopEnd();
	users->PopStart();
	users->DeleteAtIndex(1);
	//users->DeleteNthValue(User("User A"), 2);
	//users->DeleteValues(User("User B"));
}
void ReplaceUsers(DoublyLinkedList<User>* users) {
	//users->ReplaceAtIndex(5, User("User P"));
	//users->ReplaceNthValue(User("User B"), User("User Q"), 2);
	//users->ReplaceAllValues(User("User A"), User("User R"));
	//users->ReplaceAtIndex(0, User("User S"));
	//users->ReplaceAtIndex(users->GetLength() - 1, User("User T"));
	//users->ReplaceAll(User("User T"));
}
void FilterUsers(DoublyLinkedList<User>* users) {
	//Setup the Regular Expression and Attribute Value to filter
	string regExp = ".*A.*";
	int attribute = AttributeValues::All;

	DoublyLinkedList<User>* allFilter = users->SearchByRegex(regExp, attribute);
	cout << endl << "Filter with Regular Expression " << regExp << " at attribute value " << attribute << ":" << endl;
	allFilter->PrintList();
	cout << endl;

	delete allFilter;
}
void SortUsers(DoublyLinkedList<User>* users) {
	cout << "Sort by First Name:" << endl;
	users->Sort(AttributeValues::User::FirstName)->PrintList(1);
	cout << "Sort by Last Name:" << endl;
	users->Sort(AttributeValues::User::LastName)->PrintList(1);
	cout << "Sort by Age:" << endl;
	users->Sort(AttributeValues::User::Age)->PrintList(1);
	cout << "Sort by Gender:" << endl;
	users->Sort(AttributeValues::User::Gender)->PrintList(1);
	cout << "Sort by Phone:" << endl;
	users->Sort(AttributeValues::User::Phone)->PrintList(1);
	cout << "Sort by Email:" << endl;
	users->Sort(AttributeValues::User::Email)->PrintList(1);
	cout << "Sort by Address:" << endl;
	users->Sort(AttributeValues::User::Address)->PrintList(1);
}
