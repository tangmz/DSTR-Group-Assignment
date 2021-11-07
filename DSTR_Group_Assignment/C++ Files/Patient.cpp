#pragma once
#include "../Header Files/Patient.h"
#include "../Header Files/Doctor.h"
#include "../Header Files/Nurse.h"
#include "../Header Files/User.h"
#include "../Header Files/Medicine.h"
#include "../Header Files/LinkedList.h"
#include "../Header Files/Comparison.h"
using namespace std;

void PrintLine(char symbol, int length) {
	for (int i = 0; i < length; i++) {
		cout << symbol;
	}
	cout << endl;
}

//---Patient--------
bool Patient::Equals(Patient nextPatient) {
	bool match = true;
	match = FirstName == nextPatient.FirstName ? match : false;
	match = LastName == nextPatient.LastName ? match : false;
	match = Age == nextPatient.Age ? match : false;
	match = Gender == nextPatient.Gender ? match : false;
	match = Phone == nextPatient.Phone ? match : false;
	match = Email == nextPatient.Email ? match : false;
	match = Address == nextPatient.Address ? match : false;
	match = Password == nextPatient.Password ? match : false;
	match = IC == nextPatient.IC ? match : false;
	match = Illness == nextPatient.Illness ? match : false;
	match = VisitDate == nextPatient.VisitDate ? match : false;
	match = VisitTime == nextPatient.VisitTime ? match : false;
	match = Disability == nextPatient.Disability ? match : false;
	match = AssignedDoctor->GetDoctorID() == nextPatient.AssignedDoctor->GetDoctorID() ? match : false;
	match = Prescription->GetMedicineID() == nextPatient.Prescription->GetMedicineID() ? match : false;
	match = Note == nextPatient.Note ? match : false;
	return match;
}
int Patient::CompareTo(Patient nextPatient, int attributeValue) {
	int index = 0, value = 0;
	switch (attributeValue) {
		case AttributeValues::All:
		case AttributeValues::Patient::UserID:
			return CompareStrings(this->ID, nextPatient.ID);
		case AttributeValues::Patient::FirstName:
			value = CompareStrings(this->FirstName, nextPatient.FirstName);
			break;
		case AttributeValues::Patient::LastName:
			value = CompareStrings(this->LastName, nextPatient.LastName);
			break;
		case AttributeValues::Patient::Age:
			value = this->Age < nextPatient.Age ? 0 : 2;
			value = this->Age == nextPatient.Age ? 1 : value;
			break;
		case AttributeValues::Patient::Gender:
			value = CompareStrings(string(1, this->Gender), string(1, nextPatient.Gender));
			break;
		case AttributeValues::Patient::Phone:
			value = CompareStrings(this->Phone, nextPatient.Phone);
			break;
		case AttributeValues::Patient::Email:
			value = CompareStrings(this->Email, nextPatient.Email);
			break;
		case AttributeValues::Patient::Address:
			value = CompareStrings(this->Address, nextPatient.Address);
			break;
		case AttributeValues::Patient::Password:
			value = CompareStrings(this->Password, nextPatient.Password);
			break;
		case AttributeValues::Patient::IC:
			value = CompareStrings(this->IC, nextPatient.IC);
			break;
		case AttributeValues::Patient::PatientID:
			value = CompareStrings(this->PatientID, nextPatient.PatientID);
			break;
		case AttributeValues::Patient::Illness:
			value = CompareStrings(this->Illness, nextPatient.Illness);
			break;
		case AttributeValues::Patient::VisitDate:
			value = CompareStrings(this->VisitDate, nextPatient.VisitDate);
			break;
		case AttributeValues::Patient::VisitTime:
			value = CompareStrings(this->VisitTime, nextPatient.VisitTime);
			break;
		case AttributeValues::Patient::Disability:
			value = CompareStrings(this->Disability, nextPatient.Disability);
			break;
		case AttributeValues::Patient::AssignedDoctor:
			value = CompareStrings(this->AssignedDoctor->GetDoctorID(), nextPatient.AssignedDoctor->GetDoctorID());
			break;
		case AttributeValues::Patient::Prescription:
			value = CompareStrings(this->Prescription->GetMedicineID(), nextPatient.Prescription->GetMedicineID());
			break;
		case AttributeValues::Patient::Note:
			value = CompareStrings(this->Note, nextPatient.Note);
			break;
		default:
			return 1;
	}
	return value;
}
bool Patient::MatchesRegex(string regExp, int attributeValue) {
	switch (attributeValue) {
		case AttributeValues::All:
			if (regex_match(ID, regex(regExp)) || regex_match(FirstName, regex(regExp)) ||
				regex_match(LastName, regex(regExp)) || regex_match(to_string(Age), regex(regExp)) ||
				regex_match(string(1, Gender), regex(regExp)) || regex_match(Phone, regex(regExp)) ||
				regex_match(Email, regex(regExp)) || regex_match(Address, regex(regExp)) ||
				regex_match(Password, regex(regExp)) || regex_match(IC, regex(regExp)) ||
				regex_match(PatientID, regex(regExp)) || regex_match(Illness, regex(regExp)) ||
				regex_match(VisitDate, regex(regExp)) || regex_match(VisitTime, regex(regExp)) ||
				regex_match(Disability, regex(regExp)) ||
				regex_match(AssignedDoctor->GetDoctorID(), regex(regExp)) ||
				regex_match(Prescription->GetMedicineID(), regex(regExp)) ||
				regex_match(Note, regex(regExp))) {
				return true;
			}
			break;
		case AttributeValues::Patient::UserID:
			if (regex_match(ID, regex(regExp))) return true;
			break;
		case AttributeValues::Patient::FirstName:
			if (regex_match(FirstName, regex(regExp))) return true;
			break;
		case AttributeValues::Patient::LastName:
			if (regex_match(LastName, regex(regExp))) return true;
			break;
		case AttributeValues::Patient::Age:
			if (regex_match(to_string(Age), regex(regExp))) return true;
			break;
		case AttributeValues::Patient::Gender:
			if (regex_match(string(1, Gender), regex(regExp))) return true;
			break;
		case AttributeValues::Patient::Phone:
			if (regex_match(Phone, regex(regExp))) return true;
			break;
		case AttributeValues::Patient::Email:
			if (regex_match(Email, regex(regExp))) return true;
			break;
		case AttributeValues::Patient::Address:
			if (regex_match(Address, regex(regExp))) return true;
			break;
		case AttributeValues::Patient::Password:
			if (regex_match(Password, regex(regExp))) return true;
			break;
		case AttributeValues::Patient::IC:
			if (regex_match(IC, regex(regExp))) return true;
			break;
		case AttributeValues::Patient::PatientID:
			if (regex_match(PatientID, regex(regExp))) return true;
			break;
		case AttributeValues::Patient::Illness:
			if (regex_match(Illness, regex(regExp))) return true;
			break;
		case AttributeValues::Patient::VisitDate:
			if (regex_match(VisitDate, regex(regExp))) return true;
			break;
		case AttributeValues::Patient::VisitTime:
			if (regex_match(VisitTime, regex(regExp))) return true;
			break;
		case AttributeValues::Patient::Disability:
			if (regex_match(Disability, regex(regExp))) return true;
			break;
		case AttributeValues::Patient::AssignedDoctor:
			if (regex_match(AssignedDoctor->GetDoctorID(), regex(regExp))) return true;
			break;
		case AttributeValues::Patient::Prescription:
			if (regex_match(Prescription->GetMedicineID(), regex(regExp))) return true;
			break;
		case AttributeValues::Patient::Note:
			if (regex_match(Note, regex(regExp))) return true;
			break;
		default:
			break;
	}
	return false;
}
void Patient::DisplayTableHeader(int startIndex, int tableLength) {
	PrintLine('=', 185);
	if (startIndex >= 0) cout << setw(to_string(startIndex + tableLength).length() + 2) << left << "No.";
	cout << setw(15) << left << "ID" <<
		setw(15) << left << "Patient ID" <<
		setw(20) << "First Name" <<
		setw(20) << "Last Name" <<
		setw(5) << "Age" <<
		setw(5) << "M/F" <<
		setw(15) << "Phone" <<
		setw(20) << "Email" <<
		setw(20) << "Illness" << 
		setw(20) << "Visit Date (MM/DD)" <<
		setw(20) << "Visit Date (hh:mm)" << endl;
	PrintLine('-', 185);
}
void Patient::DisplayTableRow(int startIndex, int index, int tableLength) {
	if (startIndex >= 0) cout << setw(to_string(startIndex + tableLength).length() + 2) << index + startIndex;
	cout << setw(15) << ID <<
		setw(15) << PatientID <<
		setw(20) << FirstName <<
		setw(20) << LastName <<
		setw(5) << Age <<
		setw(5) << Gender <<
		setw(15) << Phone <<
		setw(20) << Email <<
		setw(20) << Illness <<
		setw(20) << VisitDate <<
		setw(20) << VisitTime << endl;
}
void Patient::DisplayDetails() {
	PrintLine('=', 100);

	cout << "User ID: " << ID << endl;
	cout << "Patient ID: " << PatientID << endl << endl;

	PrintLine('-', 100);

	cout << "Name: " << FirstName << " " << LastName << endl;
	cout << "IC: " << IC << endl;
	cout << "Age: " << Age << endl;
	cout << "Gender: " << Gender << endl;
	cout << "Phone: " << Phone << endl;
	cout << "Email: " << Email << endl;
	cout << "Address: " << Address << endl;

	PrintLine('-', 100);

	cout << "Illness: ";
	if (Illness == "") cout << "NOT DIAGNOSED YET" << endl;
	else cout << Illness << endl;
	cout << "Visit Date and Time: ";
	if (VisitDate == "" || VisitTime == "") cout << "NO APPOINTMENT SCHEDULED" << endl;
	else cout << VisitDate << ", " << VisitTime << endl;
	cout << "Disability: ";
	if (Disability == "") cout << "UNDEFINED" << endl;
	else cout << Disability << endl;
	cout << "Assigned Doctor: ";
	if (AssignedDoctor == NULL) cout << "NO DOCTOR ASSIGNED" << endl;
	else cout << "Dr. " << AssignedDoctor->GetFirstName() << endl;
	cout << "Prescription: ";
	if (Prescription == NULL) cout << "NO PRESCRIPTION" << endl;
	else cout << Prescription->GetName() << endl;
	cout << "Notes: ";
	if (Note == "") cout << "NONE" << endl;
	else cout << Note << endl << endl;

	PrintLine('=', 100);
}

string Patient::GeneratePatientID(int n) {
	string id = "PAT-";
	for (int i = 0; i < 6 - ceil(log10(n + 1)); i++) id += "0";
	id += to_string(n);
	return id;
}
void Patient::UpdateAppointmentDate(DoublyLinkedList<Patient>* patientList, string newDate) {
	//ApplicationLists::Appointments->SearchByRegex(appointmentID, AttributeValues::Appointment::AppointmentID)->Get(0)->SetDate(newDate);
}
void Patient::UpdateAppointmentTime(DoublyLinkedList<Patient>* patientList, string newTime) {
	//ApplicationLists::Appointments->SearchByRegex(appointmentID, AttributeValues::Appointment::AppointmentID)->Get(0)->SetTime(newTime);
}
int Patient::GetQueueNumber(DoublyLinkedList<Patient>* patientList) {
	//Get patient's visit date and find all patients visiting on the same day
	string targetDate = VisitDate;
	DoublyLinkedList<Patient>* dayPatients = new DoublyLinkedList<Patient>();
	for (int i = 0; i < patientList->GetLength(); i++) {
		if (patientList->Get(0).VisitDate == targetDate) dayPatients->AddToEnd(patientList->Get(i));
	}

	//Find the position of the patient in the day's patient list, sorted by time
	dayPatients = dayPatients->Sort(AttributeValues::Patient::VisitTime);
	for (int i = 0; i < dayPatients->GetLength(); i++) {
		if (dayPatients->Get(0).PatientID == PatientID) return i + 1;
	}
	return 0;
}
void Patient::ViewAllPatients(DoublyLinkedList<Patient>* patientList) {
	/*for (int i = 0; i < p->GetLength(); i++) {
		Patient p1 = p->Get(i);
		cout << p1.GetFirstName() << " : " << p1.GetLastName() << endl;
	}*/
	patientList->DisplayPages(10);
	//system("pause");
}
DoublyLinkedList<Patient>* Patient::SearchPatient(DoublyLinkedList<Patient>* patientList, string regExp, int attributeValue) {
	return patientList->SearchByRegex(regExp, attributeValue);
}
void Patient::ModifyPatientRecord(DoublyLinkedList<Patient>* patientList, DoublyLinkedList<Patient>* visitedPatientList) {
	//Here will return a Doubly linked list with only 1 (the selected) item inside, retains all operation of DoublyLL
	string name;
	system("cls");
	cout << "Enter Keyword: ";
	getline(cin, name);
	name = ".*" + name + ".*";
	//cout << patientList->GetLength() << endl;
	//system("pause");
	DoublyLinkedList<Patient>* filteredPatient = Patient::SearchPatient(patientList, name, AttributeValues::User::FirstName);
	int selectedIndex = filteredPatient->DisplayPages(10);
	if (selectedIndex == -1) return;
	Patient selectedPatients = filteredPatient->Get(selectedIndex);
	Patient oldPatient = filteredPatient->Get(selectedIndex);
	
	system("cls");
	string s;
	DoublyLinkedList<Medicine> selectedMed;
	int decision = -1;
	while (decision != 0) {
		PrintLine('-', 100);
		selectedPatients.DisplayDetails();
		//PrintLine('-', 100);
		cout << "1. Update Patient's First Name" << endl;
		cout << "2. Update Patient's Last Name" << endl;
		cout << "3. Update Patient's Age" << endl;
		cout << "4. Update Patient's Gender" << endl;
		cout << "5. Update Patient's Phone" << endl;
		cout << "6. Update Patient's Email" << endl;
		cout << "7. Update Patient's Address" << endl;
		cout << "8. Update Patient's Illness" << endl;
		cout << "9. Update Patient's Visit Date" << endl;
		cout << "10. Update Patient's Visit Time" << endl;
		cout << "11. Update Patient's Disability" << endl;
		cout << "12. Update Patient's Prescription" << endl;
		cout << "13. Update Patient's Note" << endl;
		cout << "0. Exit Modifying Patient" << endl;
		PrintLine('-', 70);
		cout << "Select Option: ";
		cin >> decision;
		cin.ignore();
		int age = -1;
		switch (decision)
		{
		case 1:
			cout << "Enter new first name: ";
			getline(cin, s);
			selectedPatients.SetFirstName(s);
			break;
		case 2:
			cout << "Enter new last name: ";
			getline(cin, s);
			selectedPatients.SetLastName(s);
			break;
		case 3:
			cout << "Enter new age: ";
			getline(cin, s);
		
			while (age < 0) {
				cout << "Enter new age: ";
				getline(cin, s);
			}
			selectedPatients.SetAge(age);
			break;
		case 4:
			cout << "Enter new gender: ";
			cin >> s;
			cin.ignore();
			selectedPatients.SetGender(s[0]);
			break;
		case 5:
			cout << "Enter new phone: ";
			getline(cin, s);
			selectedPatients.SetPhone(s);
			break;
		case 6:
			cout << "Enter new email: ";
			getline(cin, s);
			selectedPatients.SetEmail(s);
			break;
		case 7:
			cout << "Enter new Address: ";
			getline(cin, s);
			selectedPatients.SetAddress(s);
			break;
		case 8:
			cout << "Enter new illness: ";
			getline(cin, s);
			selectedPatients.SetIllness(s);
			break;
		case 9:
			cout << "Enter new visit date: ";
			getline(cin, s);
			selectedPatients.SetVisitDate(s);
			break;
		case 10:
			cout << "Enter new visit time: ";
			getline(cin, s);
			selectedPatients.SetVisitTime(s);
			break;
		case 11:
			cout << "Enter new disability: ";
			getline(cin, s);
			selectedPatients.SetDisability(s);
			break;
		case 12:
			cout << "Enter new prescription: ";
			getline(cin, s);
			selectedPatients.SetPrescriptionName(s);
			break;
		case 13:
			cout << "Enter new patient note: ";
			getline(cin, s);
			selectedPatients.SetNote(s);
			break;
		default:
			break;
		}
		//cout << "Name " << selectedPatients->FirstName << endl;
		//Patient pNew = Patient(selectedPatients->PatientID, selectedPatients->ID, selectedPatients->FirstName)
		//cout << *selectedPatients->LastName
		patientList->ReplaceNthValue(oldPatient, selectedPatients, 1);
		system("cls");

	}
	
	//system("pause");
}
void Patient::SortRecords(DoublyLinkedList<Patient>* patientList, int attributeValue) {
	patientList = patientList->Sort(attributeValue);
}

//---Doctor--------
bool Doctor::Equals(Doctor nextDoctor) {
	bool match = true;
	match = FirstName == nextDoctor.FirstName ? match : false;
	match = LastName == nextDoctor.LastName ? match : false;
	match = Age == nextDoctor.Age ? match : false;
	match = Gender == nextDoctor.Gender ? match : false;
	match = Phone == nextDoctor.Phone ? match : false;
	match = Email == nextDoctor.Email ? match : false;
	match = Address == nextDoctor.Address ? match : false;
	match = Password == nextDoctor.Password ? match : false;
	match = IC == nextDoctor.IC ? match : false;
	match = DoctorID == nextDoctor.DoctorID ? match : false;
	return match;
}
int Doctor::CompareTo(Doctor nextDoctor, int attributeValue) {
	int index = 0, value = 0;
	switch (attributeValue) {
		case AttributeValues::All:
		case AttributeValues::Doctor::UserID:
			return CompareStrings(this->ID, nextDoctor.ID);
		case AttributeValues::Doctor::FirstName:
			value = CompareStrings(this->FirstName, nextDoctor.FirstName);
			break;
		case AttributeValues::Doctor::LastName:
			value = CompareStrings(this->LastName, nextDoctor.LastName);
			break;
		case AttributeValues::Doctor::Age:
			value = this->Age < nextDoctor.Age ? 0 : 2;
			value = this->Age == nextDoctor.Age ? 1 : value;
			break;
		case AttributeValues::Doctor::Gender:
			value = CompareStrings(string(1, this->Gender), string(1, nextDoctor.Gender));
			break;
		case AttributeValues::Doctor::Phone:
			value = CompareStrings(this->Phone, nextDoctor.Phone);
			break;
		case AttributeValues::Doctor::Email:
			value = CompareStrings(this->Email, nextDoctor.Email);
			break;
		case AttributeValues::Doctor::Address:
			value = CompareStrings(this->Address, nextDoctor.Address);
			break;
		case AttributeValues::Doctor::Password:
			value = CompareStrings(this->Password, nextDoctor.Password);
			break;
		case AttributeValues::Doctor::IC:
			value = CompareStrings(this->IC, nextDoctor.IC);
			break;
		case AttributeValues::Doctor::DoctorID:
			value = CompareStrings(this->DoctorID, nextDoctor.DoctorID);
			break;
		default:
			return 1;
	}
	return value;
}
bool Doctor::MatchesRegex(string regExp, int attributeValue) {
	switch (attributeValue) {
		case AttributeValues::All:
			if (regex_match(ID, regex(regExp)) || regex_match(FirstName, regex(regExp)) ||
				regex_match(LastName, regex(regExp)) || regex_match(to_string(Age), regex(regExp)) ||
				regex_match(string(1, Gender), regex(regExp)) || regex_match(Phone, regex(regExp)) ||
				regex_match(Email, regex(regExp)) || regex_match(Address, regex(regExp)) ||
				regex_match(Password, regex(regExp)) || regex_match(IC, regex(regExp)) ||
				regex_match(DoctorID, regex(regExp))) {
				return true;
			}
			break;
		case AttributeValues::Doctor::UserID:
			if (regex_match(ID, regex(regExp))) return true;
			break;
		case AttributeValues::Doctor::FirstName:
			if (regex_match(FirstName, regex(regExp))) return true;
			break;
		case AttributeValues::Doctor::LastName:
			if (regex_match(LastName, regex(regExp))) return true;
			break;
		case AttributeValues::Doctor::Age:
			if (regex_match(to_string(Age), regex(regExp))) return true;
			break;
		case AttributeValues::Doctor::Gender:
			if (regex_match(string(1, Gender), regex(regExp))) return true;
			break;
		case AttributeValues::Doctor::Phone:
			if (regex_match(Phone, regex(regExp))) return true;
			break;
		case AttributeValues::Doctor::Email:
			if (regex_match(Email, regex(regExp))) return true;
			break;
		case AttributeValues::Doctor::Address:
			if (regex_match(Address, regex(regExp))) return true;
			break;
		case AttributeValues::Doctor::Password:
			if (regex_match(Password, regex(regExp))) return true;
			break;
		case AttributeValues::Doctor::IC:
			if (regex_match(IC, regex(regExp))) return true;
			break;
		case AttributeValues::Doctor::DoctorID:
			if (regex_match(DoctorID, regex(regExp))) return true;
			break;
		default:
			break;
	}
	return false;
}
void Doctor::DisplayTableHeader(int startIndex, int tableLength) {
	PrintLine('=', 135);
	if (startIndex >= 0) cout << setw(to_string(startIndex + tableLength).length() + 2) << left << "No.";
	cout << setw(15) << left << "ID" <<
		setw(15) << left << "Doctor ID" <<
		setw(20) << "First Name" <<
		setw(20) << "Last Name" <<
		setw(5) << "Age" <<
		setw(5) << "M/F" <<
		setw(15) << "Phone" <<
		setw(20) << "Email" <<
		setw(20) << "Password" << endl;
	PrintLine('-', 135);
}
void Doctor::DisplayTableRow(int startIndex, int index, int tableLength) {
	if (startIndex >= 0) cout << setw(to_string(startIndex + tableLength).length() + 2) << index + startIndex;
	cout << setw(15) << ID <<
		setw(15) << DoctorID <<
		setw(20) << FirstName <<
		setw(20) << LastName <<
		setw(5) << Age <<
		setw(5) << Gender <<
		setw(15) << Phone <<
		setw(20) << Email <<
		setw(20) << Password << endl;
}
void Doctor::DisplayDetails() {
	PrintLine('=', 100);

	cout << "User ID: " << ID << endl;
	cout << "Doctor ID: " << DoctorID << endl << endl;

	PrintLine('-', 100);

	cout << "Name: " << FirstName << " " << LastName << endl;
	cout << "IC: " << IC << endl;
	cout << "Age: " << Age << endl;
	cout << "Gender: " << Gender << endl;
	cout << "Phone: " << Phone << endl;
	cout << "Email: " << Email << endl;
	cout << "Address: " << Address << endl;

	PrintLine('=', 100);
}

int Doctor::sortPatientsDecision() {
	system("cls");
	int sortDecision = -1;
	PrintLine('=', 70);
	cout << "Sorting Patient List:" << endl;
	PrintLine('=', 70);
	cout << "Available Option: " << endl;
	cout << "1. First Name" << endl;
	cout << "2. Last Name" << endl;
	cout << "3. Age" << endl;
	cout << "4. Gender" << endl;
	cout << "5. Phone" << endl;
	cout << "6. Email" << endl;
	cout << "7. Illness" << endl;
	PrintLine('-', 70);
	cout << "Select Option: ";
	cin >> sortDecision;
	cin.ignore();
	return sortDecision;
}

string Doctor::GenerateDoctorID(int n) {
	string id = "DOC-";
	for (int i = 0; i < 6 - ceil(log10(n + 1)); i++) id += "0";
	id += to_string(n);
	return id;
}

//---Nurse--------
bool Nurse::Equals(Nurse nextNurse) {
	bool match = true;
	match = FirstName == nextNurse.FirstName ? match : false;
	match = LastName == nextNurse.LastName ? match : false;
	match = Age == nextNurse.Age ? match : false;
	match = Gender == nextNurse.Gender ? match : false;
	match = Phone == nextNurse.Phone ? match : false;
	match = Email == nextNurse.Email ? match : false;
	match = Address == nextNurse.Address ? match : false;
	match = Password == nextNurse.Password ? match : false;
	match = IC == nextNurse.IC ? match : false;
	match = NurseID == nextNurse.NurseID ? match : false;
	return match;
}
int Nurse::CompareTo(Nurse nextNurse, int attributeValue) {
	int index = 0, value = 0;
	switch (attributeValue) {
		case AttributeValues::All:
		case AttributeValues::Nurse::UserID:
			return CompareStrings(this->ID, nextNurse.ID);
		case AttributeValues::Nurse::FirstName:
			value = CompareStrings(this->FirstName, nextNurse.FirstName);
			break;
		case AttributeValues::Nurse::LastName:
			value = CompareStrings(this->LastName, nextNurse.LastName);
			break;
		case AttributeValues::Nurse::Age:
			value = this->Age < nextNurse.Age ? 0 : 2;
			value = this->Age == nextNurse.Age ? 1 : value;
			break;
		case AttributeValues::Nurse::Gender:
			value = CompareStrings(string(1, this->Gender), string(1, nextNurse.Gender));
			break;
		case AttributeValues::Nurse::Phone:
			value = CompareStrings(this->Phone, nextNurse.Phone);
			break;
		case AttributeValues::Nurse::Email:
			value = CompareStrings(this->Email, nextNurse.Email);
			break;
		case AttributeValues::Nurse::Address:
			value = CompareStrings(this->Address, nextNurse.Address);
			break;
		case AttributeValues::Nurse::Password:
			value = CompareStrings(this->Password, nextNurse.Password);
			break;
		case AttributeValues::Nurse::IC:
			value = CompareStrings(this->IC, nextNurse.IC);
			break;
		case AttributeValues::Nurse::NurseID:
			value = CompareStrings(this->NurseID, nextNurse.NurseID);
			break;
		default:
			return 1;
	}
	return value;
}
bool Nurse::MatchesRegex(string regExp, int attributeValue) {
	switch (attributeValue) {
		case AttributeValues::All:
			if (regex_match(ID, regex(regExp)) || regex_match(FirstName, regex(regExp)) ||
				regex_match(LastName, regex(regExp)) || regex_match(to_string(Age), regex(regExp)) ||
				regex_match(string(1, Gender), regex(regExp)) || regex_match(Phone, regex(regExp)) ||
				regex_match(Email, regex(regExp)) || regex_match(Address, regex(regExp)) ||
				regex_match(Password, regex(regExp)) || regex_match(IC, regex(regExp)) ||
				regex_match(NurseID, regex(regExp))) {
				return true;
			}
			break;
		case AttributeValues::Nurse::UserID:
			if (regex_match(ID, regex(regExp))) return true;
			break;
		case AttributeValues::Nurse::FirstName:
			if (regex_match(FirstName, regex(regExp))) return true;
			break;
		case AttributeValues::Nurse::LastName:
			if (regex_match(LastName, regex(regExp))) return true;
			break;
		case AttributeValues::Nurse::Age:
			if (regex_match(to_string(Age), regex(regExp))) return true;
			break;
		case AttributeValues::Nurse::Gender:
			if (regex_match(string(1, Gender), regex(regExp))) return true;
			break;
		case AttributeValues::Nurse::Phone:
			if (regex_match(Phone, regex(regExp))) return true;
			break;
		case AttributeValues::Nurse::Email:
			if (regex_match(Email, regex(regExp))) return true;
			break;
		case AttributeValues::Nurse::Address:
			if (regex_match(Address, regex(regExp))) return true;
			break;
		case AttributeValues::Nurse::Password:
			if (regex_match(Password, regex(regExp))) return true;
			break;
		case AttributeValues::Nurse::IC:
			if (regex_match(IC, regex(regExp))) return true;
			break;
		case AttributeValues::Nurse::NurseID:
			if (regex_match(NurseID, regex(regExp))) return true;
			break;
		default:
			break;
	}
	return false;
}
void Nurse::DisplayTableHeader(int startIndex, int tableLength) {
	PrintLine('=', 135);
	if (startIndex >= 0) cout << setw(to_string(startIndex + tableLength).length() + 2) << left << "No.";
	cout << setw(15) << left << "ID" <<
		setw(15) << left << "Nurse ID" <<
		setw(20) << "First Name" <<
		setw(20) << "Last Name" <<
		setw(5) << "Age" <<
		setw(5) << "M/F" <<
		setw(15) << "Phone" <<
		setw(20) << "Email" <<
		setw(20) << "Password" << endl;
	PrintLine('-', 135);
}
void Nurse::DisplayTableRow(int startIndex, int index, int tableLength) {
	if (startIndex >= 0) cout << setw(to_string(startIndex + tableLength).length() + 2) << index + startIndex;
	cout << setw(15) << ID <<
		setw(15) << NurseID <<
		setw(20) << FirstName <<
		setw(20) << LastName <<
		setw(5) << Age <<
		setw(5) << Gender <<
		setw(15) << Phone <<
		setw(20) << Email <<
		setw(20) << Password << endl;
}
void Nurse::DisplayDetails() {
	PrintLine('=', 100);

	cout << "User ID: " << ID << endl;
	cout << "Nurse ID: " << NurseID << endl << endl;

	PrintLine('-', 100);

	cout << "Name: " << FirstName << " " << LastName << endl;
	cout << "IC: " << IC << endl;
	cout << "Age: " << Age << endl;
	cout << "Gender: " << Gender << endl;
	cout << "Phone: " << Phone << endl;
	cout << "Email: " << Email << endl;
	cout << "Address: " << Address << endl;

	PrintLine('=', 100);
}

string Nurse::GenerateNurseID(int n) {
	string id = "NUR-";
	for (int i = 0; i < 6 - ceil(log10(n + 1)); i++) id += "0";
	id += to_string(n);
	return id;
}

//---User--------
bool User::Equals(User nextUser) {
	bool match = true;
	match = FirstName == nextUser.FirstName ? match : false;
	match = LastName == nextUser.LastName ? match : false;
	match = Age == nextUser.Age ? match : false;
	match = Gender == nextUser.Gender ? match : false;
	match = Phone == nextUser.Phone ? match : false;
	match = Email == nextUser.Email ? match : false;
	match = Address == nextUser.Address ? match : false;
	match = Password == nextUser.Password ? match : false;
	match = IC == nextUser.IC ? match : false;
	return match;
}
int User::CompareTo(User nextUser, int attributeValue) {
	int index = 0, value = 0;
	switch (attributeValue) {
	case AttributeValues::All:
	case AttributeValues::User::UserID:
		return CompareStrings(this->ID, nextUser.ID);
	case AttributeValues::User::FirstName:
		value = CompareStrings(this->FirstName, nextUser.FirstName);
		break;
	case AttributeValues::User::LastName:
		value = CompareStrings(this->LastName, nextUser.LastName);
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
	case AttributeValues::User::Password:
		value = CompareStrings(this->Password, nextUser.Password);
		break;
	case AttributeValues::User::IC:
		value = CompareStrings(this->IC, nextUser.IC);
		break;
	default:
		return 1;
	}
	return value;
}
bool User::MatchesRegex(string regExp, int attributeValue) {
	switch (attributeValue) {
	case AttributeValues::All:
		if (regex_match(ID, regex(regExp)) || regex_match(FirstName, regex(regExp)) ||
			regex_match(LastName, regex(regExp)) || regex_match(to_string(Age), regex(regExp)) ||
			regex_match(string(1, Gender), regex(regExp)) || regex_match(Phone, regex(regExp)) ||
			regex_match(Email, regex(regExp)) || regex_match(Address, regex(regExp)) ||
			regex_match(Password, regex(regExp)) || regex_match(IC, regex(regExp))) {
			return true;
		}
		break;
	case AttributeValues::User::UserID:
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
	case AttributeValues::User::Password:
		if (regex_match(Password, regex(regExp))) return true;
		break;
	case AttributeValues::User::IC:
		if (regex_match(IC, regex(regExp))) return true;
		break;
	default:
		break;
	}
	return false;
}

string User::GenerateID(int n) {
	string id = "USR-";
	for (int i = 0; i < 6 - ceil(log10(n + 1)); i++) id += "0";
	id += to_string(n);
	return id;
}
//void User::Login() {
//	string loginResult = "";
//	do {
//		//Cannot switch string in c++, unless using enum
//		loginResult = User::DisplayLoginPage();
//		if (loginResult == "Doctor") {
//			Doctor::DisplayMainMenu();
//			break;
//		}
//		else if (loginResult == "Nurse") {
//			Nurse::DisplayMainMenu();
//			break;
//		}
//		else if (loginResult == "Patient") {
//			Patient::DisplayMainMenu();
//			break;
//		}
//		else if (loginResult == "Register") {
//			loginResult = ::User::DisplayRegisterPage();
//			break;
//		}
//		else if (loginResult == "Exit") {
//			User::DisplayExitPage();
//			break;
//		}
//	} while (loginResult != "Exit");
//}
//void User::Register() {
//	string registerResult = User::DisplayRegisterPage();
//	if (registerResult == "Doctor") {
//		Doctor::DisplayMainMenu();
//	}
//	else if (registerResult == "Nurse") {
//		Nurse::DisplayMainMenu();
//	}
//	else if (registerResult == "Patient") {
//		Patient::DisplayMainMenu();
//	}
//	else if (registerResult == "Login") {
//		User::Login();
//	}
//	else if (registerResult == "Exit") {
//		User::DisplayExitPage();
//	}
//}
//void User::Logout() {
//	User::Login();
//}
void User::ShowDetails() {
	cout << "User: " << ID << "; Name: " << FirstName << " " << LastName << endl;
}
void User::DisplayTableHeader(int startIndex, int tableLength) {
	PrintLine('=', 120);
	if (startIndex >= 0) cout << setw(to_string(startIndex + tableLength).length() + 2) << left << "No.";
	cout << setw(15) << left << "ID" <<
		setw(20) << "First Name" <<
		setw(20) << "Last Name" <<
		setw(5) << "Age" <<
		setw(5) << "M/F" <<
		setw(15) << "Phone" <<
		setw(20) << "Email" <<
		setw(20) << "Password" << endl;
	PrintLine('-', 120);
}
void User::DisplayTableRow(int startIndex, int index, int tableLength) {
	if (startIndex >= 0) cout << setw(to_string(startIndex + tableLength).length() + 2) << index + startIndex;
	cout << setw(15) << ID <<
		setw(20) << FirstName <<
		setw(20) << LastName <<
		setw(5) << Age <<
		setw(5) << Gender <<
		setw(15) << Phone <<
		setw(20) << Email <<
		setw(20) << Password << endl;
}

//---Medicine----------
bool Medicine::Equals(Medicine nextMedicine) {
	bool match = true;
	match = MedicineID == nextMedicine.MedicineID ? match : false;
	match = Name == nextMedicine.Name ? match : false;
	match = DatePurchased == nextMedicine.DatePurchased ? match : false;
	match = ShelfLife == nextMedicine.ShelfLife ? match : false;
	match = SideEffects == nextMedicine.SideEffects ? match : false;
	return match;
}
int Medicine::CompareTo(Medicine nextMedicine, int attributeValue) {
	int index = 0, value = 0;
	switch (attributeValue) {
		case AttributeValues::All:
		case AttributeValues::Medicine::MedicineID:
			return CompareStrings(this->MedicineID, nextMedicine.MedicineID);
		case AttributeValues::Medicine::Name:
			value = CompareStrings(this->Name, nextMedicine.Name);
			break;
		case AttributeValues::Medicine::DatePurchased:
			value = CompareStrings(this->DatePurchased, nextMedicine.DatePurchased);
			break;
		case AttributeValues::Medicine::ShelfLife:
			value = this->ShelfLife < nextMedicine.ShelfLife ? 0 : 2;
			value = this->ShelfLife == nextMedicine.ShelfLife ? 1 : value;
			break;
		case AttributeValues::Medicine::SideEffects:
			value = CompareStrings(this->SideEffects, nextMedicine.SideEffects);
			break;
		default:
			return 1;
	}
	return value;
}
bool Medicine::MatchesRegex(string regExp, int attributeValue) {
	switch (attributeValue) {
		case AttributeValues::All:
			if (regex_match(MedicineID, regex(regExp)) || regex_match(Name, regex(regExp)) ||
				regex_match(DatePurchased, regex(regExp)) || regex_match(to_string(ShelfLife), regex(regExp)) ||
				regex_match(SideEffects, regex(regExp))) {
				return true;
			}
			break;
		case AttributeValues::Medicine::MedicineID:
			if (regex_match(MedicineID, regex(regExp))) return true;
			break;
		case AttributeValues::Medicine::Name:
			if (regex_match(Name, regex(regExp))) return true;
			break;
		case AttributeValues::Medicine::DatePurchased:
			if (regex_match(DatePurchased, regex(regExp))) return true;
			break;
		case AttributeValues::Medicine::ShelfLife:
			if (regex_match(to_string(ShelfLife), regex(regExp))) return true;
			break;
		case AttributeValues::Medicine::SideEffects:
			if (regex_match(SideEffects, regex(regExp))) return true;
			break;
		default:
			break;
	}
	return false;
}
void Medicine::DisplayTableHeader(int startIndex, int tableLength) {
	PrintLine('=', 110);
	if (startIndex >= 0) cout << setw(to_string(startIndex + tableLength).length() + 2) << left << "No.";
	cout << setw(15) << left << "Medicine ID" <<
		setw(30) << "Name" <<
		setw(20) << "Date Purchased" <<
		setw(15) << "Shelf Life" <<
		setw(30) << "Side Effects" << endl;
	PrintLine('-', 110);
}
void Medicine::DisplayTableRow(int startIndex, int index, int tableLength) {
	if (startIndex >= 0) cout << setw(to_string(startIndex + tableLength).length() + 2) << index + startIndex;
	cout << setw(15) << MedicineID <<
		setw(30) << Name <<
		setw(20) << DatePurchased <<
		setw(15) << ShelfLife <<
		setw(30) << SideEffects << endl;
}
void Medicine::DisplayDetails() {
	PrintLine('=', 100);

	cout << "Medicine ID: " << MedicineID << endl << endl;

	PrintLine('-', 100);

	cout << "Name: " << Name << endl;
	cout << "Date Purchased: " << DatePurchased << endl;
	cout << "Shelf Life (Months): " << ShelfLife << endl;
	cout << "Side Effects: " << SideEffects << endl;

	PrintLine('=', 100);
}

string Medicine::GenerateMedicineID(int n) {
	string id = "MED-";
	for (int i = 0; i < 6 - ceil(log10(n + 1)); i++) id += "0";
	id += to_string(n);
	return id;
}