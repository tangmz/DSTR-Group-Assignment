#pragma once
#include "../Header Files/Patient.h"
#include "../ApplicationLists.cpp"
using namespace std;

string Patient::GeneratePatientID() {
	int n = ApplicationLists::Patients->GetLength() + 1;
	string id = "USR-";
	for (int i = 0; i < 6 - ceil(log10(n + 1)); i++) id += "0";
	id += to_string(n);
	return id;
}
void Patient::CreateAppointment(string date, string time, Doctor doctor) {
	//ApplicationLists::Appointments->AddToEnd(...)
}
void Patient::UpdateAppointmentDate(string newDate) {

}
void Patient::UpdateAppointmentTime(string newTime) {

}
void Patient::UpdateAppointmentDoctor(Doctor newDoctor) {

}
void Patient::UpdateAppointmentPayment(bool newStatus) {

}
void Patient::CancelAppointment() {

}
int Patient::GetQueueNumber() {
	return 0;
}

void Patient::DisplayAppointments() {
	DoublyLinkedList<Appointment>* patientAppointments = ApplicationLists::Appointments->SearchByRegex(PatientID, AttributeValues::Patient::PatientID);

}