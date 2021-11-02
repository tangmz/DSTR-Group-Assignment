#pragma once
#include "Doctor.h"
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
	string GetAppointmentID() { return AppointmentID; }
	string GetDate() { return Date; }
	string GetTime() { return Time; }
	auto GetPatient() { return Patient; }
	auto GetDoctor() { return Doctor; }
	bool isPaid() { return Paid; }
	bool isCancelled() { return Cancelled; }

	void setPaid();
	void showDetails();
};