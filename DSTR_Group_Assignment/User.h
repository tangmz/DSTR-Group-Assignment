#pragma once
#include <iostream>
#include <string>
using namespace std;

class User {
protected:
	string ID;
	string Name;
	int Age;
	char Gender;
	string Phone;
	string Email;
	string Address;

	friend ostream& operator<<(ostream& output, const User& user) {
		return output << user.Name;
	}
	friend bool operator==(User left, const User right) {
		return User::Equals(left, right);
	}
public:
	User(string id, string name, int age, char gender, string phone, string email, string address);
	User(string name) : User("", name, 0, ' ', "", "", "") {

	}
	User() : User("", "", 0, ' ', "", "", "") {

	}
	~User() {
		//cout << "User " << Name << " is deleted." << endl;
	}

	string GetID() { return ID; }
	string GetName() { return Name; }
	int GetAge() { return Age; }
	char GetGender() { return Gender; }
	string GetPhone() { return Phone; }
	string GetEmail() { return Email; }
	string GetAddress() { return Address; }

	static bool Equals(User leftUser, User rightUser);

	string GenerateID();
	void ViewPatients();
	void ShowDetails();
	void Login();
	void Logout();
};