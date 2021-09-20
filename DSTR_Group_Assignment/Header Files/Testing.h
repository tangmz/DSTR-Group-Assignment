#include "Appointment.h"
#include "Doctor.h"
#include "Interface.h"
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
		users->AddToEnd(User(
			User::GenerateID(users->GetLength() + 1),
			GetRandomName(NameList),
			rand() % (maxAge - minAge + 1) + minAge,
			GetRandomGender(),
			GetRandomPhone(),
			GetRandomName(NameList),
			GetRandomName(NameList)));
	}
}
void DeleteUsers(DoublyLinkedList<User>* users) {
	users->PopEnd();
	users->PopStart();
	users->DeleteAtIndex(1);
	users->DeleteNthValue(User("User A"), 2);
	users->DeleteValues(User("User B"));
}
void ReplaceUsers(DoublyLinkedList<User>* users) {
	users->ReplaceAtIndex(5, User("User P"));
	users->ReplaceNthValue(User("User B"), User("User Q"), 2);
	users->ReplaceAllValues(User("User A"), User("User R"));
	users->ReplaceAtIndex(0, User("User S"));
	users->ReplaceAtIndex(users->GetLength() - 1, User("User T"));
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
	DoublyLinkedList<User>* sortedUsers = new DoublyLinkedList<User>();
	/*
	sortedUsers = users->Sort(AttributeValues::User::Name);
	cout << "Sort by Name:" << endl;
	sortedUsers->PrintList();
	cout << endl;
	*/
	sortedUsers = users->Sort(AttributeValues::User::Age);
	cout << "Sort by Age:" << endl;
	sortedUsers->PrintList();
	cout << endl;
	/*
	sortedUsers = users->Sort(AttributeValues::User::Gender);
	cout << "Sort by Gender:" << endl;
	sortedUsers->PrintList();
	cout << endl;
	sortedUsers = users->Sort(AttributeValues::User::Phone);
	cout << "Sort by Phone:" << endl;
	sortedUsers->PrintList();
	cout << endl;
	sortedUsers = users->Sort(AttributeValues::User::Email);
	cout << "Sort by Email:" << endl;
	sortedUsers->PrintList();
	cout << endl;
	sortedUsers = users->Sort(AttributeValues::User::Address);
	cout << "Sort by Address:" << endl;
	sortedUsers->PrintList();
	cout << endl;
	*/
}
