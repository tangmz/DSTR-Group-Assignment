#include "Header Files/AttributeValues.h"
#include "Header Files/Comparison.h"
#include "Header Files/User.h"
#include <iostream>
using namespace std;

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
int User::CompareTo(User nextUser, int attributeValue) {
	int index = 0, value = 0;
	switch (attributeValue) {
		case AttributeValues::All:
		case AttributeValues::User::ID:
			return CompareStrings(this->ID, nextUser.ID);
		case AttributeValues::User::Name:
			value = CompareStrings(this->Name, nextUser.Name);
			break;
		case AttributeValues::User::Age:
			value = this->Age < nextUser.Age ? 0 : 2;
			value = this->Age == nextUser.Age ? 1 : value;
			break;
		case AttributeValues::User::Gender:
			value = CompareStrings(string(1, this->Gender), string(1, nextUser.Gender));
			break;
		case AttributeValues::User::Phone:
			value = CompareStrings(this->Phone, nextUser.Phone);
			break;
		case AttributeValues::User::Email:
			value = CompareStrings(this->Email, nextUser.Email);
			break;
		case AttributeValues::User::Address:
			value = CompareStrings(this->Address, nextUser.Address);
			break;
		default:
			return 1;
	}
	return value == 1 ? CompareStrings(this->ID, nextUser.ID) : value;
}

string User::GenerateID(int n) {
	string id = "USR-";
	for (int i = 0; i < 6 - ceil(log10(n + 1)); i++) id += "0";
	id += to_string(n);
	return id;
}