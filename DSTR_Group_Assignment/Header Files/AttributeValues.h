#pragma once
using namespace std;

class AttributeValues {
public:
	static const int All = 0;
	class User {
	public:
		static const int UserID = 1;
		static const int FirstName = 2;
		static const int LastName = 3;
		static const int Age = 4;
		static const int Gender = 5;
		static const int Phone = 6;
		static const int Email = 7;
		static const int Address = 8;
		static const int Password = 9;
		static const int IC = 10;
	};
	class Doctor : public User {
	public:
		static const int DoctorID = 11;
	};
	class Nurse : public User {
	public:
		static const int NurseID = 12;
	};
	class Patient : public User {
	public:
		static const int PatientID = 13;
		static const int Illness = 14;
		static const int VisitDate = 15;
		static const int VisitTime = 16;
		static const int Disability = 17;
		static const int AssignedDoctor = 18;
		static const int Prescription = 19;
		static const int Note = 20;
		static const int isPaid = 21;
	};

	class Medicine {
	public:
		static const int MedicineID = 22;
		static const int Name = 23;
		static const int DatePurchased = 24;
		static const int ShelfLife = 25;
		static const int SideEffects = 26;
	};
	class Appointment {
	public:
		static const int AppointmentID = 27;
		static const int Date = 28;
		static const int Time = 29;
		static const int Patient = 30;
		static const int Doctor = 31;
		static const int Paid = 32;
		static const int Cancelled = 33;
	};
};