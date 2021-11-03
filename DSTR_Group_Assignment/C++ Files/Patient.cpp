#pragma once
#include "../Header Files/Patient.h"
#include "../Header Files/ApplicationLists.h"
using namespace std;

bool Patient::Equals(Patient nextPatient) {
	bool match = true;
	match = FirstName == nextPatient.FirstName ? match : false;
	match = LastName == nextPatient.LastName ? match : false;
	match = Age == nextPatient.Age ? match : false;
	match = Gender == nextPatient.Gender ? match : false;
	match = Phone == nextPatient.Phone ? match : false;
	match = Email == nextPatient.Email ? match : false;
	match = Address == nextPatient.Address ? match : false;
	match = Disability == nextPatient.Disability ? match : false;
	match = Note == nextPatient.Note ? match : false;
	return match;
}
int Patient::CompareTo(Patient nextPatient, int attributeValue) {
	int index = 0, value = 0;
	switch (attributeValue) {
		case AttributeValues::All:
		case AttributeValues::User::ID:
			return CompareStrings(this->ID, nextPatient.ID);
		case AttributeValues::User::FirstName:
			value = CompareStrings(this->FirstName, nextPatient.FirstName);
			break;
		case AttributeValues::User::LastName:
			value = CompareStrings(this->LastName, nextPatient.LastName);
			break;
		case AttributeValues::User::Age:
			value = this->Age < nextPatient.Age ? 0 : 2;
			value = this->Age == nextPatient.Age ? 1 : value;
			break;
		case AttributeValues::User::Gender:
			value = CompareStrings(string(1, this->Gender), string(1, nextPatient.Gender));
			break;
		case AttributeValues::User::Phone:
			value = CompareStrings(this->Phone, nextPatient.Phone);
			break;
		case AttributeValues::User::Email:
			value = CompareStrings(this->Email, nextPatient.Email);
			break;
		case AttributeValues::User::Address:
			value = CompareStrings(this->Address, nextPatient.Address);
			break;
		case AttributeValues::Patient::Disability:
			value = CompareStrings(this->Disability, nextPatient.Disability);
			break;
		case AttributeValues::Patient::Note:
			value = CompareStrings(this->Note, nextPatient.Note);
			break;
		default:
			return 1;
	}
	return value == 1 ? CompareStrings(this->ID, nextPatient.ID) : value;
}
bool Patient::MatchesRegex(string regExp, int attributeValue) {
	switch (attributeValue) {
		case AttributeValues::All:
			if (regex_match(ID, regex(regExp)) || regex_match(FirstName, regex(regExp)) ||
				regex_match(LastName, regex(regExp)) || regex_match(to_string(Age), regex(regExp)) ||
				regex_match(string(1, Gender), regex(regExp)) || regex_match(Phone, regex(regExp)) ||
				regex_match(Email, regex(regExp)) || regex_match(Address, regex(regExp))) {
				return true;
			}
			break;
		case AttributeValues::User::ID:
			if (regex_match(ID, regex(regExp))) return true;
			break;
		case AttributeValues::User::FirstName:
			if (regex_match(FirstName, regex(regExp))) return true;
			break;
		case AttributeValues::User::LastName:
			if (regex_match(LastName, regex(regExp))) return true;
			break;
		case AttributeValues::User::Age:
			if (regex_match(to_string(Age), regex(regExp))) return true;
			break;
		case AttributeValues::User::Gender:
			if (regex_match(string(1, Gender), regex(regExp))) return true;
			break;
		case AttributeValues::User::Phone:
			if (regex_match(Phone, regex(regExp))) return true;
			break;
		case AttributeValues::User::Email:
			if (regex_match(Email, regex(regExp))) return true;
			break;
		case AttributeValues::User::Address:
			if (regex_match(Address, regex(regExp))) return true;
			break;
		case AttributeValues::Patient::PatientID:
			if (regex_match(PatientID, regex(regExp))) return true;
			break;
		case AttributeValues::Patient::Disability:
			if (regex_match(Disability, regex(regExp))) return true;
			break;
		case AttributeValues::Patient::Note:
			if (regex_match(Note, regex(regExp))) return true;
			break;
		default:
			break;
	}
	return false;
}

string Patient::GeneratePatientID(int n) {
	string id = "PAT-";
	for (int i = 0; i < 6 - ceil(log10(n + 1)); i++) id += "0";
	id += to_string(n);
	return id;
}
void Patient::CreateAppointment(string date, string time, Doctor doctor) {
	//ApplicationLists::Appointments->AddToEnd(...)
}
void Patient::UpdateAppointmentDate(string appointmentID, string newDate) {
	//ApplicationLists::Appointments->SearchByRegex(appointmentID, AttributeValues::Appointment::AppointmentID)->Get(0)->SetDate(newDate);
}
void Patient::UpdateAppointmentTime(string appointmentID, string newTime) {
	//ApplicationLists::Appointments->SearchByRegex(appointmentID, AttributeValues::Appointment::AppointmentID)->Get(0)->SetTime(newTime);
}
void Patient::UpdateAppointmentDoctor(string appointmentID, Doctor newDoctor) {
	//ApplicationLists::Appointments->SearchByRegex(appointmentID, AttributeValues::Appointment::AppointmentID)->Get(0)->SetDoctor(newDoctor);
}
void Patient::UpdateAppointmentPayment(string appointmentID, bool newStatus) {
	//ApplicationLists::Appointments->SearchByRegex(appointmentID, AttributeValues::Appointment::AppointmentID)->Get(0)->SetStatus(newStatus);
}
void Patient::CancelAppointment(string appointmentID) {
	//ApplicationLists::Appointments->SearchByRegex(appointmentID, AttributeValues::Appointment::AppointmentID)->Get(0)->SetCancelled(true);
}
int Patient::GetQueueNumber(string appointmentID) {
	//Determine the appointment's date
	string targetDate = ApplicationLists::Appointments
		->SearchByRegex(appointmentID, AttributeValues::Appointment::AppointmentID)
		->Get(0)->GetDate();

	//Find all appointments on the same date, sorted by time
	DoublyLinkedList<Appointment>* dateAppointments = ApplicationLists::Appointments
		->SearchByRegex(targetDate, AttributeValues::Appointment::Date)
		->Sort(AttributeValues::Appointment::Time);

	//Find the queue number based on the appointment's time
	int queueNumber = 1;
	for (int i = 0; i < dateAppointments->GetLength(); i++) {
		if (dateAppointments->Get(i).GetAppointmentID() == appointmentID) break;
		queueNumber++;
	}
	if (queueNumber == dateAppointments->GetLength() + 1) queueNumber = -1;
	delete dateAppointments;

}

void Patient::DisplayAppointments() {
	ApplicationLists::Appointments
		->SearchByRegex(PatientID, AttributeValues::Patient::PatientID)
		->Sort(AttributeValues::Appointment::AppointmentID)
		->DisplayPages(25);
}
