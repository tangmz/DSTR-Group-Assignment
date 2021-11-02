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
	public:
		static const int PatientID = 9;
		static const int Illness = 10;
		static const int VisitDate = 11;
		static const int VisitTime = 12;
		static const int Disability = 13;
		static const int AssignedDoctor = 14;
		static const int Prescription = 15;
		static const int Note = 16;
	};
	class Nurse : User {
	public:
		static const int NurseID = 9;
	};

	class Medicine {
	public:
		static const int MedicineID = 1;
	};
	class Appointment {
	public:
		static const int AppointmentID = 1;
		static const int Date = 2;
		static const int Time = 3;
		static const int Patient = 4;
		static const int Doctor = 5;
		static const int Paid = 6;
		static const int Cancelled = 7;
	};
};