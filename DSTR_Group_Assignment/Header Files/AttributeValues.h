#pragma once
using namespace std;

class AttributeValues {
public:
	static const int All = 0;
	class User {
	public:
		static const int ID = 1;
		static const int FirstName = 2;
		static const int LastName = 3;
		static const int Age = 4;
		static const int Gender = 5;
		static const int Phone = 6;
		static const int Email = 7;
		static const int Address = 8;
	};
	class Doctor : User {
	public:
		static const int DoctorID = 9;
	};
	class Patient : User {

	};
	class Nurse : User {

	};
	class Medicine {

	};
	class Appointment {

	};
};