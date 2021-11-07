#pragma once
#include "Doctor.h"
#include "LinkedList.h"
#include <iostream>
#include <string>
using namespace std;

class Appointment {
private:
	string AppointmentID;
	string Date;
	string Time;
	Patient* Patient;
	Doctor* Doctor;
	bool Paid;
	bool Cancelled;
public:
	Appointment(string ID,string date,string time) {
		AppointmentID = ID;
		Date = date;
		Time = time;
		Patient = NULL;
		Doctor = NULL;
		Paid = false;
		Cancelled = false;

	}
	string GetAppointmentID() { return AppointmentID; }
	string GetDate() { return Date; }
	string GetTime() { return Time; }
	auto GetPatient() { return Patient; }
	auto GetDoctor() { return Doctor; }
	bool isPaid() { return Paid; }
	bool isCancelled() { return Cancelled; }

	void setPaid();
	void showDetails();
	void setDoctor(Doctor* doc);
	void setPatient();

	static string GenerateAppointmentID(int n);
};