#pragma once
using namespace std;

class AttributeValues {
public:
	static const int All = 0;
	class User {
	public:
		static const int ID = 1;
		static const int Name = 2;
		static const int Age = 3;
		static const int Gender = 4;
		static const int Phone = 5;
		static const int Email = 6;
		static const int Address = 7;
	};
	class Doctor : User {
	public:
		static const int DoctorID = 8;
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