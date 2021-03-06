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
	string IC;

	friend ostream& operator<<(ostream& output, const User user) {
		return output << user.FirstName << " " << user.LastName;
	}
	friend bool operator==(User& left, User& right) {
		return (left).Equals(right);
	}
public:
	User(string id, string firstName, string lastName, int age, char gender, string phone, string email, string address, string password, string ic) {
		ID = id;
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
	User() {

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
	string GetPassword() { return Password; }
	string GetIC() { return IC; }

	void SetFirstName(string firstName) { FirstName = firstName; }
	void SetLastName(string lastName) { LastName = lastName; }
	void SetAge(int age) { Age = age; }
	void SetGender(char gender) { Gender = gender; }
	void SetPhone(string phone) { Phone = phone; }
	void SetEmail(string email) { Email = email; }
	void SetAddress(string address) { Address = address; }

	bool Equals(User nextUser);
	int CompareTo(User nextUser, int attributeValue);
	bool MatchesRegex(string regExp, int attributeValue);
	void DisplayTableHeader(int startIndex, int tableLength);
	void DisplayTableRow(int startIndex, int index, int tableLength);

	static string GenerateID(int n);
	static void Login();
	static void Register();
	void Logout();
	void ShowDetails();

	//Interface stuff
	static void DisplayStartupPage();
	static std::string DisplayLoginPage();
	static std::string DisplayRegisterPage();
	static void DisplayExitPage();
};