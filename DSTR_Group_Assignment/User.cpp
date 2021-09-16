#include "User.h"
#include <iostream>
using namespace std;

User::User(string id, string name, int age, char gender, string phone, string email, string address) {
	ID = id;
	Name = name;
	Age = age;
	Gender = gender;
	Phone = phone;
	Email = email;
	Address = address;
}

bool User::Equals(User leftUser, User rightUser) {
	bool match = true;
	match = leftUser.Name == rightUser.Name ? match : false;
	match = leftUser.Age == rightUser.Age ? match : false;
	match = leftUser.Gender == rightUser.Gender ? match : false;
	match = leftUser.Phone == rightUser.Phone ? match : false;
	match = leftUser.Email == rightUser.Email ? match : false;
	match = leftUser.Address == rightUser.Address ? match : false;
	return match;
}