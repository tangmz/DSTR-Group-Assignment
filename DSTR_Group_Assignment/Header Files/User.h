#pragma once
#include <iostream>
#include <string>
using namespace std;

class User {
protected:
	string ID;
	string FirstName;
	string LastName;
	int Age;
	char Gender;
	string Phone;
	string Email;
	string Address;
	string Password;

	friend ostream& operator<<(ostream& output, const User& user) {
		return output << user.FirstName << " " << user.LastName;
	}
	friend bool operator==(User left, const User right) {
		return User::Equals(left, right);
	}
public:
	User(string id, string firstName, string lastName, int age, char gender, string phone, string email, string address) {
		ID = id;
		FirstName = firstName;
		LastName = lastName;
		Age = age;
		Gender = gender;
		Phone = phone;
		Email = email;
		Address = address;
	}
	User(string firstName, string lastName) : User(GenerateID(), firstName, lastName, 0, ' ', "", "", "") {

	}
	User() : User("", "") {

	}
	~User() {
		//cout << "User " << Name << " is deleted." << endl;
	}

	string GetID() { return ID; }
	string GetFirstName() { return FirstName; }
	string GetLastName() { return LastName; }
	int GetAge() { return Age; }
	char GetGender() { return Gender; }
	string GetPhone() { return Phone; }
	string GetEmail() { return Email; }
	string GetAddress() { return Address; }

	static bool Equals(User leftUser, User rightUser);
	int CompareTo(User nextUser, int attributeValue);
	bool MatchesRegex(string regExp, int attributeValue);

	static string GenerateID();
	static void Login();
	static void Register();
	void Logout();
	void ShowDetails();
	void DisplayTableHeader(int startIndex, int tableLength);
	void DisplayTableRow(int startIndex, int index, int tableLength);
};